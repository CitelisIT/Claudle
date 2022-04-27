from flask import Flask, abort
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS
from flask import request, session
import json
from hashlib import sha256
from flask_jwt_extended import JWTManager, create_access_token, jwt_required, get_jwt_identity


app = Flask(__name__)
cors = CORS(app, resources={r"/api/*": {"origins": "*"}})
app.secret_key = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config["JWT_SECRET_KEY"] = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
jwt = JWTManager(app)

from api.models import * 

db.create_all()

from api.validateRefactor import *
from api.globalStats import *
from api.wordSelect import *
from api.saveStats import *


@app.route('/api/validate', methods=['GET'])
def validate():
    args = request.args
    word = args['word']
    language = args['language']
    target = args['target']
    words = getWords(len(target), language)
    result = [0 in range (len(target))]
    if not validWord(word,words):
        if language == "francais":
            return abort(500, "Ce mot n'est pas dans notre dictionnaire")
        if language == "english":
            return abort(500, "This word isn't in our dictionnary")
    else:
        result = verification(word, target)
    response_body = {
        "hint": result
    }
    return json.dumps(response_body)


@app.route('/api/getword', methods=['GET'])
def getword():
    args = request.args
    language = args['language']
    length = args['length']
    if session.get('user_id') is None:
        wordsMet = []
        result = select(length, language, wordsMet)
        response_body = {"words": result }
        return response_body
    wordsMet = [r.Word for r in Games.query.filter( Games.User_Id == session.get('user_id')).distinct().all()]
    result = select(length, language, wordsMet)
    response_body = {"words": result }
    return json.dumps(response_body)

@app.route('/api/saveStats', methods=['POST'])
@jwt_required(optional=True)
def saveStat():
    token_id = get_jwt_identity()
    print(token_id)
    args = request.json
    target = args['target']
    nbTries = args['nbTries']
    words = args['words']
    stringTries = ""
    w=""
    for word in words:
        for l in word:
            w+= l
        if not w =="":
            stringTries+= w+"/"
            w=""

    if token_id is None:
        saveStats(0,target,nbTries,stringTries)
        return {}
    else :
        user = User.query.filter(User.Id==token_id).first()
        saveStats(user.Id,target,nbTries,stringTries)
        return {}



@app.route('/api/register', methods=['POST'])
def register():
    args = request.json
    username = args['username']
    password = args['password'].encode("utf-8")
    h = sha256()
    h.update(password)
    h_pwd = h.hexdigest()
    user = User(Username=username, Password_Hash=h_pwd)
    db.session.add(user)
    db.session.commit()
    token = create_access_token(identity=user.Id)
    return {"result": "ok", "token": token}

@app.route('/api/login', methods=['POST'])
def login():
    args = request.json
    username = args['username']
    password = args['password'].encode("utf-8")
    h = sha256()
    h.update(password)
    h_pwd = h.hexdigest()
    user = User.query.filter(User.Username==username).first()
    if user is None:
        return abort(500, "Ce nom d'utilisateur n'existe pas")
    if user.Password_Hash != h_pwd:
        return abort(500, "Le mot de passe est incorrect")
    token = create_access_token(identity=user.Id)
    return {"result": "ok", "token": token}

@app.route('/api/profile', methods=['GET'])
def profile():
    if session.get('user_id') is None:
        return json.dumps({"results": "error, not connected"})
    user = User.query.filter(User.Id==session.get('user_id')).first()
    username = user.Username
    percGamesWon = percentageOfWonGamesByUser(user.Id)
    nbGamesWon = numberOfWonGamesByUser(user.Id)
    currentStreak = currentStreakByUser(user.Id)
    bestStreak = bestStreakByUser(user.Id)
    winsByTries = [numberOfWonGamesTriesNumberByUser(user.Id,i) for i in range (1,10)]

    response_body={"user_id":user.Id,
                    "username":username,
                    "nbGamesWon": nbGamesWon,
                    "percGamesWon": percGamesWon,
                    "currentStreak": currentStreak,
                    "bestStreak": bestStreak,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)


@app.route('/api/stats', methods=['GET'])
def getStats():
    percGamesWon = percentageOfWonGames()
    nbGamesPlayed = numberOfGames()
    bStreak,BestUser = BestStreak()
    winsByTries = [numberOfWonGamesTriesNumber(i) for i in range (10)]

    response_body={"nbGamesPlayed": nbGamesPlayed,
                    "percGamesWon":percGamesWon,
                    "bestStreak": bStreak,
                    "bestUser":BestUser,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)
