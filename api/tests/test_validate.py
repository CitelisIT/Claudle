from api.validate import *

gamemode1 = "english"
target1 = "watt"
letters1 = 4
word11 = "that"
word12 = "what"
word13 = "watt"
word14 = "join"


gamemode2 = "francais"
target2 = "poche"
letters2 = 5
word21 = "pluie"
word22 = "eaikdd"
word23 = "force"
word24 = "poche"

def test_acceptable():
    assert acceptable(word11, gamemode1, letters1) == True
    assert acceptable(word12, gamemode1, letters1) == True
    assert acceptable(word13, gamemode1, letters1) == True
    assert acceptable(word21, gamemode2, letters2) == True
    assert acceptable(word22, gamemode2, letters2) == False
    assert acceptable(word23, gamemode2, letters2) == True
    assert acceptable(word24, gamemode2, letters2) == True

def test_verification():
    assert verification(word11, gamemode1, letters1, target1) == [1,0,1,2]
    assert verification(word12, gamemode1, letters1, target1) == [2,0,1,2]
    assert verification(word13, gamemode1, letters1, target1)  == [2,2,2,2]
    assert verification(word14,gamemode1, letters1, target1) == [0,0,0,0]
    assert verification(word21, gamemode2, letters2, target2) == [2, 0, 0, 0, 2]
    assert verification(word22, gamemode2, letters2, target2) == [0, 0, 0, 0, 0]
    assert verification(word23, gamemode2, letters2, target2) == [0, 2, 0, 1, 2]
    assert verification(word24, gamemode2, letters2, target2) == [2, 2, 2, 2, 2]


test_acceptable()
test_verification()
print("All tests passed with success \n")