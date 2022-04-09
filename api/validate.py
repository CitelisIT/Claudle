import csv

def acceptable(word, gamemode, letters):
    dico = []
    with open(f'./Databases/{gamemode}/dico{letters}.csv',"r") as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for row in csv_reader:
            dico.append(row["word"])            
    if word in dico:
        return True
    return False

def verification(word, gamemode, letters, target):
    result = [0 for i in range(letters)]
    if acceptable(word, gamemode, letters):
        for i in range (letters):
            if word[i]==target[i]:
                result[i]=2
            else:
                for j in range(letters):
                    if word[i]==target[j] and i!=j:
                        result[i]=1
    return result
            
