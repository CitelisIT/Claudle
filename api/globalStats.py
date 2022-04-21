from models import *

#Global Stats
def numberOfGames():
    number = Games.query.count()
    return number

def percentageOfWonGames():
    number = Games.query.filter(Games.Tries_Num != -1).count()
    return number/numberOfGames()*100

def numberOfWonGamesTriesNumber(TriesNumber):
    number = Games.query.filter(Games.Tries_Num == TriesNumber).count()
    return number



#User Stats

def numberOfGamesByUser(UserId):
    number = Games.query.filter(Games.User_Id == UserId).count()
    return number


def percentageOfWonGamesByUser(UserId):
    number = Games.query.filter(Games.User_Id == UserId).filter(Games.Tries_Num != -1).count()
    return number/numberOfGamesByUser(UserId)*100

def numberOfWonGamesTriesNumberByUser(UserId, TriesNumber):
    number = Games.query.filter(Games.User_Id == UserId).filter(Games.Tries_Num == TriesNumber).count()
    return number

def currentStreakByUser(UserId):
    streak = 0
    result = Games.query.filter(Games.Tries_Num).filter(Games.User_Id == UserId).order_by(Games.Game_Id.desc()).all()
    for el in result:
        if el.Tries_Num != -1:
            streak += 1
        else:
            break
    return streak

def bestStreakByUser(UserId):
    BestStreak = 0
    Streak = 0
    result = Games.query.filter(Games.Tries_Num).filter(Games.User_Id == UserId).order_by(Games.Game_Id.desc()).all()
    for i in range(len(result)):
        if result[i] != -1:
            Streak += 1
        else:
            BestStreak = Streak if Streak > BestStreak else BestStreak
            Streak = 0
    return BestStreak if BestStreak > Streak else Streak

