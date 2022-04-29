from api.models import * 
from api.validate import *

separator = '/' #Can be changed depending on what we decide to use when saving in the database

def getHistory(userId):
    """Given an user id and a count, returns a list consisting of count lists of words used by the user in its last count games"""
    query = Games.query.filter(Games.User_Id == userId).order_by(Games.Game_Id.desc()).all()
    
    history = [{"listWord":[list(l) for l in game.Tries.split(separator)], "target": game.Word, "hints":[], "status":("Victoire" if game.Tries_Num > 0 else "Défaite")} for game in query ]
    for el in history:
        el["hints"] = [verification("".join(word), el["target"]) for word in el["listWord"]]
    
    return history


