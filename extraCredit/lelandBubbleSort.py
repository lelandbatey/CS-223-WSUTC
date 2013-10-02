from __future__ import print_function
from random import randint

# So, I put this horrible thing down as an answer on a test for sorting via
# bubble sort. I wanted to test to see if it works.

def bubSort(array):
    aryCopy = array
    for i in range(0,len(array)-1):
        if aryCopy[i] > aryCopy[i+1]:

            # Do the swap
            temp = aryCopy[i]
            aryCopy[i] = aryCopy[i+1]
            aryCopy[i+1] = temp
            
            # RECURSE!
            aryCopy = bubSort(aryCopy)
            break

    return aryCopy

print(bubSort([2,1,2,1]))
print(bubSort([21,43,43,48,29,23,41,44,8,33,7,32,17,46,4,11,44,34,22,47,2,28,38,19,41]))


def main():
    
    print("[",end="")
    for i in range(0,25):
        print(randint(0,50),",", sep="", end="")
    print("]")



# main()