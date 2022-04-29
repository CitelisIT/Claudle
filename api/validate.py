

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


def validWord(word,words):
    return word in words

def verification(input, target):
    """Given a input, return the hint about each character in the input
    0 means character not in word target
    1 in target but not at the right spot
    2 in target and at the right spot

    Args:
        input (String): word suggested by user
        target (String): word that we compare the input to
    """
    
    targetList = list(target)
    output = [-1] * len(targetList)
    
    #Treating the case where the character might be in the right spot
    for index, character in enumerate(input):
        if character == targetList[index]:
            output[index] = 2
            
            #Treated cases are not considered anymore -- we remove them
            targetList[index] = '$'
            
    #Treating every other cases
    for index, character in enumerate(input):
        if character in targetList and output[index] != 2:
            output[index] = 1
            targetList[targetList.index(character)] = '$'
        
        elif output[index] == 2:
            continue
        
        else:
            output[index] = 0
    
    
    return output
