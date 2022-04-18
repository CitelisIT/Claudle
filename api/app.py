from validateRefactor import *
from wordSelect import *
from flask import Flask
from flask.helpers import flash
from flask_sqlalchemy import SQLAlchemy
from flask import render_template, request, abort, url_for, session, redirect
from hashlib import sha256
from datetime import datetime
from sqlalchemy import or_, desc
import pickle


from sqlalchemy.orm import query
from sqlalchemy.sql.functions import current_timestamp
from sqlalchemy.sql.expression import func


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
            return "this word isn't in our dictionnary"
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
    user = User.query.filter(User.user_id==session.get('user_id')).first()
    wordsMet = Games.query.join(user, Games.user_Id == User.Id).add_columns(Games.word).filter(User.Id==Games.user_Id).all()
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