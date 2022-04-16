##Considering we are already connected to the DB and c is a cursor


#Global Stats
def numberOfGames():
    c.execute("SELECT COUNT(*) FROM Games")
    return c.fetchone()[0]

def percentageOfWonGames():
    c.execute("SELECT COUNT(*) FROM Games WHERE Tries_Num != -1")
    return c.fetchone()[0]/numberOfGames()*100

def numberOfWonGamesTriesNumber(TriesNumber):
    c.execute("SELECT COUNT(*) FROM Games WHERE Tries_Num = %s" % TriesNumber)
    return c.fetchone()[0]


#User Stats

def numberOfGamesByUser(UserId):
    c.execute("SELECT COUNT(*) FROM Games WHERE User_Id = %s" % UserId)
    return c.fetchone()[0]

def percentageOfWonGamesByUser(UserId):
    c.execute("SELECT COUNT(*) FROM Games WHERE Tries_Num != -1 AND User_Id = %s" % UserId)
    return c.fetchone()[0]/numberOfGamesByUser(UserId)*100

def numberOfWonGamesTriesNumberByUser(UserId, TriesNumber):
    c.execute("SELECT COUNT(*) FROM Games WHERE Tries_Num = %s AND User_Id = %s" % (TriesNumber, UserId))
    return c.fetchone()[0]

def currentStreakByUser(UserId):
    streak = 0
    c.execute("SELECT Tries_Num FROM Games WHERE User_Id = %s ORDER BY Game_Id DESC" % UserId)
    for i in range(len(c.fetchall())):
        if c.fetchone()[0] != -1:
            streak += 1
        else:
            break
    return streak

def bestStreakByUser(UserId):
    BestStreak = 0
    Streak = 0
    c.execute("SELECT Tries_Num FROM Games WHERE User_Id = %s ORDER BY Game_Id DESC" % UserId)
    for i in range(len(c.fetchall())):
        if c.fetchall()[i] != -1:
            Streak += 1
        else:
            BestStreak = Streak if Streak > BestStreak else BestStreak
            Streak = 0
    return BestStreak if BestStreak > Streak else Streak


