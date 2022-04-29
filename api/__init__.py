from flask import Flask, abort, jsonify
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS
from flask import request
import json
from hashlib import sha256
from flask_jwt_extended import JWTManager, create_access_token, jwt_required, get_jwt, get_jwt_identity, set_access_cookies, unset_access_cookies, verify_jwt_in_request
from datetime import datetime, timedelta, timezone


app = Flask(__name__)
cors = CORS(app, resources={r"/api/*": {"origins": "*"}})
app.secret_key = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config["JWT_SECRET_KEY"] = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config["JWT_ACCESS_TOKEN_EXPIRES"] = timedelta(hours=2)
app.config["JWT_TOKEN_LOCATION"] = ["cookies"]
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SQLALCHEMY_BINDS'] = {
    "dico": "sqlite:///dico.db",
}

db = SQLAlchemy(app)
jwt = JWTManager(app)
db = SQLAlchemy(app)
jwt = JWTManager(app)

from api.models import * 

db.create_all()

from api.validate import *
from api.globalStats import *
from api.wordSelect import *
from api.saveStats import *
from api.history import *


@app.route('/api/validate', methods=['GET'])
def validate():
    args = request.args
    word = args['word']
    language = args['language']
    target = args['target']
    words = getWords(len(target), language)
    result = [0 in range (len(target))]
    if language == "cloclo":
        wordsFR = getWords(len(target), "francais")
        if not validWord(word,wordsFR):
            return jsonify(error = "Ce mot n'est pas dans notre dictionnaire"), 404
        else:
            result = verification(word, target)
            response_body = {
            "hint": result
            }
    else:
        if not validWord(word,words):
            if language == "francais":
                return jsonify(error = "Ce mot n'est pas dans notre dictionnaire"), 404
            if language == "english":
                return jsonify(error = "This word isn't in our dictionnary"), 404
        else:
            result = verification(word, target)
        response_body = {
            "hint": result
        }
    return json.dumps(response_body)


@app.route('/api/getword', methods=['GET'])
@jwt_required(optional=True)
def getword():
    token_id = get_jwt_identity()
    args = request.args
    language = args['language']
    length = args['length']
    if token_id is None:
        wordsMet = []
        result = select(length, language, wordsMet)
        response_body = {"words": result }
        return response_body
    wordsMet = [r.Word for r in Games.query.filter( Games.User_Id == token_id).distinct().all()]
    result = select(length, language, wordsMet)
    response_body = {"words": result }
    return json.dumps(response_body)


@app.route('/api/saveStats', methods=['POST'])
@jwt_required(optional=True)
def saveStat():
    token_id = get_jwt_identity()
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
    response = jsonify({"register": "ok"})
    set_access_cookies(response, token)
    return response

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
        return jsonify(error = "Ce nom d'utilisateur n'existe pas"), 401
    if user.Password_Hash != h_pwd:
        return jsonify(error = "Mot de passe incorrect"), 401
    token = create_access_token(identity=user.Id)
    response = jsonify({"login": "ok"})
    set_access_cookies(response, token)
    return response

@app.route("/api/logout", methods=["POST"])
def logout():
    response = jsonify({"logout": "ok"})
    unset_access_cookies(response)
    return response

@app.route('/api/profile', methods=['GET'])
@jwt_required()
def profile():
    token_id = get_jwt_identity()
    user = User.query.filter(User.Id==token_id).first()
    username = user.Username
    percGamesWon = percentageOfWonGamesByUser(user.Id)
    nbGamesWon = numberOfWonGamesByUser(user.Id)
    currentStreak = currentStreakByUser(user.Id)
    bestStreak = bestStreakByUser(user.Id)
    winsByTries = [numberOfWonGamesTriesNumberByUser(user.Id,i) for i in range (1,11)]

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
    winsByTries = [numberOfWonGamesTriesNumber(i+1) for i in range (10)]

    response_body={"nbGamesPlayed": nbGamesPlayed,
                    "percGamesWon":percGamesWon,
                    "bestStreak": bStreak,
                    "bestUser":BestUser,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)

@app.after_request
def refresh_token(response):
    try:
        exp_timestamp = get_jwt()["exp"]
        curr_time = datetime.now(timezone.utc)
        target_timestamp = timedelta(curr_time + timedelta(minutes=15))
        if target_timestamp > exp_timestamp:
            token_id = get_jwt_identity()
            token = create_access_token(identity=token_id)
            set_access_cookies(response, token)
        return response
    except Exception as e:
        return response

@app.route("/api/history", methods=['GET'])
@jwt_required()
def histo():
    token_id = get_jwt_identity()
    reponse = json.dumps({"histo":getHistory(token_id)})
    return reponse

    

@app.route("/api/delUser", methods=['DELETE'])
@jwt_required()
def delUser():
    token_id = get_jwt_identity()
    User.query.filter(User.Id==token_id).delete()
    Games.query.filter(Games.User_Id==token_id).delete()
    db.session.commit()
    response = jsonify({"logout": "ok"})
    unset_access_cookies(response)
    return response