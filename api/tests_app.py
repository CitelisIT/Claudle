from validateRefactor import *
from wordSelect import *
from globalStats import *
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask import request, session
import json




app = Flask(__name__)
app.secret_key = '60a725867b515697115ccb2c561c2fee5694f2bc0d96372a4a033880702fa4a4'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

from models import * 

db.create_all()



def test_validate():
    args = {'word': 'test','language': 'english','target': 'test'}
    word = args['word']
    language = args['language']
    target = args['target']
    words = getWords(len(target), language)
    result = [0 in range (len(target))]
    if not validWord(word,words):
        if language == "francais":
            return "Ce mot n'est pas dans notre dictionnaire"
        if language == "english":
            return "this word isn't in our dictionnary"
    else:
        result = verification(word, target)
    response_body = {
        "hint": result
    }
    return json.dumps(response_body)

print(test_validate())

def getword(language,length,user_id):
    if user_id is None:
        wordsMet = []
        result = select(length, language, wordsMet)
        response_body = {"words": result }
        return response_body
    wordsMet = [r.Word for r in Games.query.filter( Games.User_Id == user_id).distinct().all()]
    result = select(length, language, wordsMet)
    response_body = {"words": result }
    return json.dumps(response_body)

print(getword("english",4,1))

def test_profile(userID):
    if userID is None:
        return json.dumps({"results": "error, not connected"})
    user = User.query.filter(User.Id==userID).first()
    username = user.Username
    percGamesWon = percentageOfWonGamesByUser(userID)
    nbGamesWon = numberOfWonGamesByUser(userID)
    currentStreak = currentStreakByUser(userID)
    bestStreak = bestStreakByUser(userID)
    winsByTries = [numberOfWonGamesTriesNumberByUser(userID,i) for i in range (1,10)]

    response_body={"username":username,
                    "nbGamesWon": nbGamesWon,
                    "percGamesWon": percGamesWon,
                    "currentStreak": currentStreak,
                    "bestStreak": bestStreak,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)

print(test_profile(1))


def test_getStats():
    nbUsers = numberOfUsers()
    nbGames = numberOfGames()
    percGamesWon = percentageOfWonGames()
    nbGamesWon = numberOfWonGames()
    bStreak,BestUser = BestStreak()
    winsByTries = [numberOfWonGamesTriesNumber(i) for i in range (1,10)]

    response_body={"nbGamesWon": nbGamesWon,
                    "percGamesWon":percGamesWon,
                    "bestStreak": bStreak,
                    "bestUser":BestUser,
                    "winsByTries": winsByTries}
    return json.dumps(response_body)



print(test_getStats())