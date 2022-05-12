from api.models import *


#Global Stats

def numberOfUsers():
    number = User.query.count()
    return number

def numberOfGames():
    number = Games.query.count()
    return number

def numberOfWonGames():
    number = Games.query.filter(Games.Tries_Num != -1).count()
    return number

def percentageOfWonGames():
    number = Games.query.filter(Games.Tries_Num != -1).count()
    winrate = round(number/numberOfGames()*100,2) if numberOfGames != 0 else 0
    return winrate

def numberOfWonGamesTriesNumber(TriesNumber):
    number = Games.query.filter(Games.Tries_Num == TriesNumber).count()
    return number

def BestStreak():
    BestStreak = 0
    BestStreakUser = ""
    for i in range(1, numberOfUsers()+1):
        if bestStreakByUser(i) > BestStreak:
            BestStreak = bestStreakByUser(i)
            BestStreakUser = User.query.filter(User.Id == i).first().Username
    return (BestStreak, BestStreakUser)


#User Stats

def numberOfGamesByUser(UserId):
    number = Games.query.filter(Games.User_Id == UserId).count()
    return number

def numberOfWonGamesByUser(UserId):
    number = Games.query.filter(Games.User_Id == UserId).filter(Games.Tries_Num != -1).count()
    return number

def percentageOfWonGamesByUser(UserId):
    number = Games.query.filter(Games.User_Id == UserId).filter(Games.Tries_Num != -1).count()
    userWinrate = round(number/numberOfGamesByUser(UserId)*100,2) if numberOfGamesByUser(UserId) != 0 else 0
    return userWinrate

def numberOfWonGamesTriesNumberByUser(UserId, TriesNumber):
    number = Games.query.filter(Games.User_Id == UserId).filter(Games.Tries_Num == TriesNumber).count()
    return number

def currentStreakByUser(UserId):
    streak = 0
    result = Games.query.filter(Games.User_Id == UserId).order_by(Games.Game_Id.desc()).all()
    for el in result:
        if el.Tries_Num != -1:
            streak += 1
        else:
            break
    return streak

def bestStreakByUser(UserId):
    BestStreak = 0
    Streak = 0
    result = Games.query.filter(Games.User_Id == UserId).order_by(Games.Game_Id.desc()).all()
    for el in result:
        if el.Tries_Num != -1:
            Streak += 1
        else:
            BestStreak = Streak if Streak > BestStreak else BestStreak
            Streak = 0
    return BestStreak if BestStreak > Streak else Streak

