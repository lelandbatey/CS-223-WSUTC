#include <stdio.h>
#include <iostream>
using namespace std;

template <class myClass>
int divUp(myClass a, myClass b){
    int ia = int(a);
    int ib = int(b);

    // cout << "New nums:"<< endl;

    // cout << a << endl;
    // cout << b << endl;
    // cout << ia << endl;
    // cout << ib << endl;

    // cout << (ia / ib) << endl;
    // cout << bool(ia % ib) << endl;

    return (ia / ib) + bool( ia % ib );
}

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 3;
    double n = 20.5;
    double d = 11.7;
    float p = 33.33;
    float q = 22.13;

    cout << divUp(x,y) << endl;
    cout << divUp(n,d) << endl;
    cout << divUp(q,p) << endl;

    return 0;
}