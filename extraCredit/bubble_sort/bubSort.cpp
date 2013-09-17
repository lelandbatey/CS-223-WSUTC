#include <time.h>
#include <iostream>
#include <sys/resource.h>

// #define ARRAY_SIZE 293 // The largest array that can be sorted via recursive bubblesort on my machine.
#define ARRAY_SIZE 2000000

using namespace std;

//  GOAL:
// Do bubblesort recursively and iteratively on an array of 2 million integers.

// RESULTS
// -------

// So, doing this has been a quite humbling experience. I've implemented both
// iterative and recursive bubbleSort functions, and it's taught me why
// trivially recursive implementations are to be avoided:

// Since they introduce needless overhead and complexity. This is evident if
// try to run this program; the recursive implementation of bubbleSort is **so
// inefficient** that even just passing the address of an array, it still has
// to do this so many times that it causes a stack overflow (at least it does
// for me).


// Iterative bubble sort
int* itBubSort(int* N){
    int temp,i;
    int swap = 1;
    while (swap){
        
        swap = 0;
        for (i = 0; i < ARRAY_SIZE-1; ++i)
        {
            // cout << N[i] << ", " << N[i+1] << endl;
            if (N[i] > N[i+1]){
                temp = N[i]; N[i] = N[i+1]; N[i+1] = temp;// Do the swap
                swap = 1;
            }
        }
    }
    return N;
}

// Recursive bubble sort
int* recBubSort(int* N, int x){
    int temp,i;
    for (i = 0; i < ARRAY_SIZE-1; ++i){
        if (N[i] > N[i+1]){
            temp = N[i]; N[i] = N[i+1]; N[i+1] = temp;// Do the swap
            N = recBubSort(N,x+1);
            break;
        }
    }
    return N;
}


int main(int argc, char const *argv[])
{
    int* array1;
    int* array2;
    array1 = new int[ARRAY_SIZE];
    array2 = new int[ARRAY_SIZE];

    // populate the arrays;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array1[i] = ARRAY_SIZE-i;
        array2[i] = ARRAY_SIZE-i;
    }

    itBubSort(array1);
    cout << "Iterative" << endl;
    recBubSort(array2,0);
    cout << "Recursive" << endl;

    return 0;
}