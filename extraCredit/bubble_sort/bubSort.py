from __future__ import print_function

# Python implementation of bubblesort, with both iterative and recursive
# versions of both.

# Written by Leland Batey

def recBubSort(array):
    aryCopy = array
    for i in range(0,len(array)-1):
        if aryCopy[i] > aryCopy[i+1]:

            # Do the swap
            temp = aryCopy[i]
            aryCopy[i] = aryCopy[i+1]
            aryCopy[i+1] = temp
            
            # RECURSE!
            aryCopy = recBubSort(aryCopy)
            break

    return aryCopy

def itBubSort(N):
    swap = True
    while swap:
        swap = False
        for i in range(0,len(N)-1):
            if N[i] > N[i+1]:
                # Do the swap:
                temp = N[i]
                N[i] = N[i+1]
                N[i+1] = N[i]

                swap = True

    return N

def main():

    array = range(45,0,-1)

    print(recBubSort(array))
    print(itBubSort(array))

main()



