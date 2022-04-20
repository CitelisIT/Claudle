from validateRefactor import *

#def parseWord_test():
    #TODO




def testvalidWordEnglish():
    words = getWords(5,'english')
    assert validWord('surge', words) == True, "surge is in the dictionnary"
    assert validWord('diana', words) == True, "diana is in the dictionnary (And in the tunnel...)"
    assert validWord('travel', words) == False, "travel has 6 letters"
    assert validWord('', words) == False, "There is no word..."
    assert validWord('finir', words) == False, "finir is french"




def testvalidWordFrench():
    words = getWords(7, 'francais')
    assert validWord('travel', words) == False, "travel is english"
    assert validWord('', words) == False, "There is no word..."
    assert validWord('allumer', words) == True, "allumer is in the dictionnary"
    assert validWord('besoin', words) == False, 'besoin has 6 letters'
    assert validWord('chemise', words) == True, "chemise is in the dictionnary"


def testverification():
    assert verification("needs", "event") == [1, 1, 2, 0, 0]
    assert verification("event", "needs") == [1, 0, 2, 1, 0]
    assert verification("black", "brand") == [2, 0, 2, 0, 0]
    assert verification("about", "black") == [1, 1, 0, 0, 0]
    assert verification("brand", "cable") == [1, 0, 1, 0, 0]
    assert verification("about", "table") == [1, 1, 0, 0, 1]
    assert verification("about", "about") == [2, 2, 2, 2, 2]
    assert verification("about", "") == [0, 0, 0, 0, 0]


if __name__ == '__main__':
    testvalidWordEnglish()
    testvalidWordFrench()
    testverification()
    print("All tests passed with success")