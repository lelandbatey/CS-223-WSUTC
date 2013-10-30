from __future__ import print_function
from random import randint


def hashStr(inStr="Leland Batey is a dude who really really needed a hair cut but then he got one, and now it's all cool"):
    tmpStr = ""
    finalNum = 0
    for x in xrange(0,len(inStr)):
        tempNum = ord(inStr[x])
        tempNum = (tempNum+x**3)**2
        finalNum += tempNum
        # tmpStr +=str(ord(inStr[x]))

    # print(finalNum)

    return finalNum
    # print(type(int(tmpStr)))

# hashStr()
def buildRandStr(strLen=15):
    strLen=max(3,strLen)
    toReturn = ""
    for i in xrange(0,randint(3,strLen)):
        if randint(0,1) == 1:
            toReturn += chr(randint(97,122))
        else:
            toReturn += chr(randint(48,57))
    return toReturn


def test(testSize=500):
    numArray = []

    for i in xrange(0,testSize):
        tmpStr = buildRandStr(50)
        numStr = hashStr(tmpStr)
        print("Str is:",tmpStr)
        print("Num is:",numStr)
        numArray.append(numStr)

    print(numArray)

    print('Duplicates:',set([x for x in numArray if numArray.count(x) > 1]))


# test(20000)
print(hashStr("176"))
print(hashStr("806"))
print(hashStr("815"))
print(hashStr("52ll3d80"))
print(hashStr('hj3bc871'))

