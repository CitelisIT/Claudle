from models import *

def saveStats(userID, word, numberTries, stringTries):
    """
    This function doesn't return anything as it only saves
    player progress in the database.
    """
    
    statement = (
        Games(
            User_Id = userID,
            Word = word,
            Tries_Num = numberTries,
            Tries = stringTries
        )
    )

    db.session.add(statement)
    db.session.commit()
