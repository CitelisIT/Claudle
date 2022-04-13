from getopt import getopt
from msvcrt import getwch
from wordSelect import *

def testjustNewWords():
    assert justNewWords(5, "english", getWords(5, "english")[2:]) == ["about", "other"]
    assert justNewWords(6, "english", getWords(6, "english")[:4]) == getWords(6, "english")[4:]
    assert justNewWords(6, "english", getWords(6, "english")) == []
    assert justNewWords(8, "francais", ["accepter"]) == getWords(8, "francais")[1:]
    assert justNewWords(8, "francais", getWords(8, "francais")[:75]) == getWords(8, "francais")[75:]
    assert justNewWords(4, "francais", []) == getWords(4, "francais")
    assert justNewWords(7, "francais", getWords(7, "francais")) == []

if __name__ == '__main__':
    testjustNewWords()
    print("All tests passed with success")