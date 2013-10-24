from __future__ import print_function
import random

def buildRandName(nameLen=8):
    toReturn = ""
    for i in range(nameLen):
        toReturn += chr(random.randint(97,122))

    return toReturn


# print(buildRandName())

# for i in range(10):
#     print(random.randint(1,3))

def buildOutStr():
    

    animalArray = ["CAT,{},25,25,6,6","COW,{},3,3,28,28","DOG,{},22,22,9,9"]

    # for i in range(namesToGenerate):
    k = random.randint(0,len(animalArray)-1)
    newString = animalArray[k]
    newName = buildRandName(random.randint(3,10))
    return newString.format(newName), newName

def getRandType():
    n = random.randint(0,2)
    typeArray = ["CAT",'DOG','COW']

    return typeArray[n]

def rndN():
    return random.randint(1,30)

def randName():
    randAttrStr = "{},{},{},{},{},{}"

    randAttrStr = randAttrStr.format(getRandType(),rndN(),rndN(),rndN(),rndN(),rndN())
    return randAttrStr

def oddPrint(myStr):
    temp = 0
    for i in range(0,len(myStr)):
        # print("Cur character:",ord(myStr[i]))
        # print("Cur char sqrd:",ord(myStr[i])**2)
        temp += ((ord(myStr[i])-1)**2)+ord(myStr[i])+i 
    return temp

def main():
    namesToGenerate = 500
    numName = []


    for i in range(namesToGenerate):
        # oddStr, newName = buildOutStr()
        # print(oddPrint(newName),', ',newName,sep="")
        # numName.append(oddPrint(newName))
        # print(oddStr)
        print(randName())

    # if (len(numName) == len(set(numName))):
    #     print("No duplicates!")
    # else:
    #     print("There were duplicates")
    #     print(numName)
    #     print(set(numName))
        
    # xs = [1, 2, 1]
    # s = set()
    # tSet = set()
    # any(x in tSet or tSet.add(x) for x in numName)
    # You can use a similar approach to actually retrieve the duplicates.
    ts = set()
    duplicates = set(x for x in numName if x in ts or ts.add(x))
    # print(duplicates)

    # any(numName.count(x) > 1 for x in numName)

# print( oddPrint("mxenka") )
# print( oddPrint("rcumal") )
main()