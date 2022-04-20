from webbrowser import get
from models import * 

separator = '-' #Can be changed depending on what we decide to use when saving in the database

def getHistory(UserId, count):
    """Given an user id and a count, returns a list consisting of count lists of words used by the user in its last count games"""
    Query = Games.query.filter(Games.User_Id == UserId).order_by(Games.Game_Id.desc()).limit(count).all()
    GamesHistory = []
    History = []
    for i in range(len(Query)):
        GamesHistory.append(Query[i].Tries)
    for j in range(len(GamesHistory)):
        History.append(GamesHistory[j].split(separator))
    return History


