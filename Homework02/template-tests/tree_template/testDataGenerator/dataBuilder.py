from __future__ import print_function

def divUp(num,den):
    return (num//den) + int(bool(num % den))


def buildTreeInput(inList):

    if len(inList) > 1:
        mini = 0
        maxi = len(inList)
        mid = divUp(maxi,2)

        # print("max:",maxi,"mid:",mid)
        # max:
        #     mid    : 
        #     i[0]   :
        #     i[max] :
        # print("max:",maxi,"\n\tmid     :",mid,"\n\ti[0]    :",inList[0],"\n\ti[maxi] :",inList[maxi-1])


        print(inList[mid])

        lower = inList[0:mid]
        upper = inList[mid+1:]
        buildTreeInput(lower)
        buildTreeInput(upper)

    if len(inList) == 1:
        print(inList[0])

def main(size=10):
    i = [i for i in range(size)]
    print(i)
    buildTreeInput(i)

main(30)