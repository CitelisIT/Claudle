from validate import *

gamemode1 = "english"
target1 = "what"
letters1 = 4
word11 = "sfdg"
word12 = "talk"
word13 = "what"


gamemode2 = "francais"
target2 = "poche"
letters2 = 5
word21 = "pluie"
word22 = "eaikdd"
word23 = "force"
word24 = "poche"

def test_acceptable():
    print(acceptable(word11, gamemode1, letters1))
    print(acceptable(word12, gamemode1, letters1))
    print(acceptable(word13, gamemode1, letters1))
    print(acceptable(word21, gamemode2, letters2))
    print(acceptable(word22, gamemode2, letters2))
    print(acceptable(word23, gamemode2, letters2))
    print(acceptable(word24, gamemode2, letters2))

def test_verification():
    print(verification(word11, gamemode1, letters1, target1))
    print(verification(word12, gamemode1, letters1, target1))
    print(verification(word13, gamemode1, letters1, target1))
    print(verification(word21, gamemode2, letters2, target2))
    print(verification(word22, gamemode2, letters2, target2))
    print(verification(word23, gamemode2, letters2, target2))
    print(verification(word24, gamemode2, letters2, target2))

test_verification()