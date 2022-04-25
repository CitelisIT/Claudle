import csv
import random

def parseWord():
    """
    Depending on how we get the word from the app, 
    we'll hve to parse the word in order to work with it.
    """
    return

def getWords(length, language):
    words = []

    with open(f'./Databases/{language}/dico{length}.txt',"r") as file:
        for line in file:
            words.append(line.rstrip())

    return words




def justNewWords(lenght, language, wordsMet):
    #select word not encountered by the player
    allWords = getWords(lenght, language)
    newWords = []
    for word in allWords:
        if not word in wordsMet:
            newWords.append(word)
    return newWords
    
def select(lenght, language, wordsMet):
    words = justNewWords(lenght, language, wordsMet)
    return  words[random.randint(0,len(words))]

#Tests
# wordmets=["word", "what"]
# english = "english"
# words = getWords(5, english)
# print(justNewWords(4,english, wordmets))
# print(select(4,english,wordmets))