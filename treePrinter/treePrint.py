from __future__ import print_function
#     _   ______  ______   ____  _________    __       ______  __________  ______  _   ____
#    / | / / __ \/_  __/  / __ \/ ____/   |  / /      / __ \ \/ /_  __/ / / / __ \/ | / / /
#   /  |/ / / / / / /    / /_/ / __/ / /| | / /      / /_/ /\  / / / / /_/ / / / /  |/ / / 
#  / /|  / /_/ / / /    / _, _/ /___/ ___ |/ /___   / ____/ / / / / / __  / /_/ / /|  /_/  
# /_/ |_/\____/ /_/    /_/ |_/_____/_/  |_/_____/  /_/     /_/ /_/ /_/ /_/\____/_/ |_(_)   

# Be aware, this isn't real python, it's just pseudocode.

tempLevel = 3
maxHeight = 7

GRID_DIM = (2**maxHeight)-1
root_pos = GRID_DIM/2.0
wconst = 1

print("Grid dimensions:", GRID_DIM, "wide x", maxHeight, "tall")

# Computes the maximum width of a line for tree with given maximum distance from root                                            
def findMaxWidth(distance, nodeWidth=2):
    maxNodes = ( (2 ** (abs(distance)+1) ) -1 )
    maxWidth = (maxNodes*nodeWidth) + maxNodes
    return maxWidth



def levelOffset(distance, level):
    toReturn = (( root_pos/(2*level) ) //1.0)  * distance
    return toReturn//1.0

def nodesPerLevel(level):
    return 2**(level)

def spacesPerLevel(level):
    return GRID_DIM - nodesPerLevel(level)

def spacesBetweenNodes(level):
    return GRID_DIM//nodesPerLevel(level)

def endPadding(level):
    nodeCount = nodesPerLevel(level)
    curCharCount = spacesBetweenNodes(level)*(nodeCount-1) + nodeCount
    # print("Cur Char Count:", curCharCount)
    return (GRID_DIM-curCharCount)/2



# print("Nodes on level       :", nodesPerLevel(tempLevel))
# print("Spaces on level      :", spacesPerLevel(tempLevel))
# print("Spaces between nodes :", spacesBetweenNodes(tempLevel))
# print("Padding start of line:", endPadding(tempLevel))

def prnt(char="\n",mul=1):
    print(char*mul*wconst,end="")

def printpadding(level):
    # print(" "*endPadding(level),end="")
    # print(level,"padding")
    prnt(" ",endPadding(level))

def printNodes(level):
    levelNodes = nodesPerLevel(level)
    for i in range(0, levelNodes):
        print('O',end="")
        if i < levelNodes-1:
            print(" "*spacesBetweenNodes(level),end="")

def printSlashes(level):
    pass
    floor = maxHeight - level
    endgeLines = 2**( max(floor-1, 0) )
    firstSpaces = (2**floor) - 1    

    for i in range(1,endgeLines+1):
        for j in range(0,nodesPerLevel(level)):
            print(" "*(firstSpaces-i),end="")
            print("/",end='')
            print(' '*(i+i-1),end='')
            print("\\",end='')
            print(" "*(endgeLines -1), end="")
        print()

def slashPlacer(level):
    # print(level)
    level = min(level+1,maxHeight)
    if level == maxHeight: return
    # print(level)

    spaceCount = spacesBetweenNodes(level)
    charArray = " "*spaceCount
    k = 1

    print()
    printpadding(level)

    # Prints out the top-bar of the treebranch
    levelNodes = nodesPerLevel(level)
    prnt(" ")
    for i in range(0, levelNodes):
        if i < levelNodes-1:
            if k:
                prnt("=",spaceCount)
                prnt(" ")
                k = 0
            else:
                prnt(" ",spaceCount)
                prnt(" ")
                k = 1
    

    # Prints the stems of the treebranch
    print()
    printpadding(level)
    k = 1
    for i in range(0, levelNodes):
        prnt("|")
        if i < levelNodes-1:
            prnt(" ",spaceCount)

    print()



def printLevel(level):
    printpadding(level)
    printNodes(level)
    # print()
    # printSlashes(level)
    slashPlacer(level)
    

for i in range(maxHeight):
    printLevel(i)

print()

# print(levelOffset(4, 6))

# Steps to build the ascii tree:



