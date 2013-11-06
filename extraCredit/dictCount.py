from __future__ import print_function
from pprint import pprint

myList = [0,2,1,3,4,5,6,7,2,3,4,2,4,7,8,4,7,6,9,8,4,5,5,6,7,8,4,5,6,4,4,4,4]

myDict = {}


for x in myList:
    
    if x not in myDict.keys():
        myDict[x] = 1
    else:
        myDict[x] = myDict[x]+1


pprint(myDict)

