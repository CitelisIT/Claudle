

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
    we'll have to parse the word in order to work with it.
    """
    return

def getWords(length, language):
    words = []

    with open(f'./Databases/{language}/dico{length}.txt',"r") as file:
        for line in file:
            words.append(line.rstrip())
    return words

#Temp
#english = "english"
#words = getWords(5, english)

def validWord(word,words):
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
                
                elif character == target[index]:
                    hint = 2
                    
                    targetList = list(target)
                    targetList[index] = '$'
                    target = ''.join(targetList)

                elif targetCharacter == '$' or character != targetCharacter:
                    continue

                else:
                    #The character must be in target
                    hint = 1

                    targetList = list(target)
                    targetList[targetList.index(character)] = '$'
                    target = ''.join(targetList)

                    break

        output.append(hint)

    return output
