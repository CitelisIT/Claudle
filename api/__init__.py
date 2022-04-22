from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS
from flask import request, session
import json



app = Flask(__name__)
cors = CORS(app, resources={r"/api/*": {"origins": "*"}})
app.secret_key = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

from api.models import * 

db.create_all()

from api.validateRefactor import *
from api.globalStats import *
from api.wordSelect import *


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
            return "Ce mot n'est pas dans notre dictionnaire"
        if language == "english":
            return "This word isn't in our dictionnary"
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

@app.route('/api/register', methods=['POST'])
@app.route('/api/login', methods=['POST'])
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

    response_body={"username":username,
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
    winsByTries = [numberOfWonGamesTriesNumber(i) for i in range (1,10)]

    response_body={"nbGamesPlayed": nbGamesPlayed,
                    "percGamesWon":percGamesWon,
                    "bestStreak": bStreak,
                    "bestUser":BestUser,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)
