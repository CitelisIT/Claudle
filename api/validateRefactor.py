import csv

##################################################
##################################################
###                                            ###
###  TODO: Verify that word is in dictionary   ###
###        Rewrite test file to fit the new    ###
###        functions                           ###
###        Optimize old "acceptable" imple-    ###
###        mentation                           ###
###                                            ###
##################################################
##################################################


def parseWord():
    """
    Depending on how we get the word from the app, 
    we'll hve to parse the word in order to work with it.
    """
    return

def getWords(length, language):
    words = []

    with open(f'./Databases/{language}/dico{length}.csv',"r") as csv_file:
        csv_reader = csv.DictReader(csv_file)

        for row in csv_reader:
            words.append(row["word"])
    return words

#Temp
english = "english"
words = getWords(5, english)

def validWord(word):
    return word in words

def verification(word, target):
    output = []
    hint = -1

    for index, character in enumerate(word):
        if not(character in list(target)):
            hint = 0
        else:
            for targetIndex, targetCharacter in enumerate(target):
                if character == targetCharacter and index == targetIndex:
                    hint = 2

                    #Change targetCharacter to $ to treat duplicate letter case
                    targetList = list(target)
                    targetList[targetIndex] = '$'
                    target = ''.join(targetList)

                    break
                else:
                    #The character must be in target
                    hint = 1

                    targetList = list(target)
                    targetList[targetList.index(character)] = '$'
                    target = ''.join(targetList)

                    break

        output.append(hint)

    return output


##Testing

#target = "about"
#word11 = "local"
#word12 = "black"
#word13 = "areas"
#word14 = "offer"
#
#print(verification(word11, target))
#print(verification(word12, target))
#print(verification(word13, target))
#print(verification(word14, target))
#
#target = "ABCDE"
#
#word1 = "AXXXX"
#word2 = "XAXXX"
#word3 = "AAXXX"
#word4 = "XAAXX"
#word5 = "AXBXX"
#word6 = "EDCBA"
#
#print(verification(word1, target))
#print(verification(word2, target))
#print(verification(word3, target))
#print(verification(word4, target))
#print(verification(word5, target))
#print(verification(word6, target))