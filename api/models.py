from api import db

db.metadata.clear()

class User(db.Model):
    Id = db.Column(db.Integer, primary_key=True)
    Username = db.Column(db.String(32))
    Password_Hash = db.Column(db.String(64))

    
class Games(db.Model):
    Game_Id = db.Column(db.Integer, primary_key=True)
    User_Id= db.Column(db.Integer,db.ForeignKey(User.Id))
    Word = db.Column(db.String(10))
    Tries_Num = db.Column(db.Integer)
    Tries = db.Column(db.String(109))
    
db.create_all()