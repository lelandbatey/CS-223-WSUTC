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

def main():
    namesToGenerate = 15

    animalArray = ["CAT,{},25,25,6,6","COW,{},3,3,28,28","DOG,{},22,22,9,9"]

    for i in range(namesToGenerate):
        k = random.randint(0,len(animalArray)-1)
        newString = animalArray[k]
        print( newString.format(buildRandName(random.randint(3,10))) )

main()