from models import *
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


db.create_all()


@app.route('/api/validate', methods=['GET'])
def validate():
    args = request.args
    word = args['word']
    mode = args['mode']
    target = args['target']


@app.route('/api/getword', methods=['GET'])
@app.route('/api/register', methods=['POST'])
@app.route('/api/login', methods=['POST'])
@app.route('/api/profile', methods=['GET'])
def profile():
    args = request.args
    username = args['username']
    return username


@app.route('/api/stats', methods=['GET'])
