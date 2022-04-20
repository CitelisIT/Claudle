from validateRefactor import *
from wordSelect import *
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
    return response_body


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
    return response_body

@app.route('/api/register', methods=['POST'])
@app.route('/api/login', methods=['POST'])
@app.route('/api/profile', methods=['GET'])
def profile():
    args = request.args
    username = args['username']
    return username


@app.route('/api/stats', methods=['GET'])
def getStats():
    args = request.args