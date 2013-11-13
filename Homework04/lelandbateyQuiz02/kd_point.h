#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "lfbMap.h"

#pragma once

class kd_point
{
private:
    double peptideToMass(std::string str){
        double toReturn = 0;
        lfbMap pepMap;

        for (unsigned int i = 0; i < str.size(); ++i){
            // I realize this is a monstrous piece of horribleness. I would
            // have done it a much better way, but it's not the worst thing I
            // could have done, and it is easy.

            toReturn = toReturn + pepMap.find(str.c_str()[i]);
        }
        return toReturn;
    }

    std::string peptide;
    double mass;
    double NET;
    int id;
    double oMass;
    double oNET;

public:

    bool (*compCheck[2])(kd_point*,kd_point*);

    kd_point(){
        oMass = oNET = NET = mass = 0;
        id = 0;
    };
    kd_point(double m, double n){
        NET = n;
        mass = m;
        oMass = oNET = 0;
        id = 0;
    }
    kd_point(std::string str, double n){
        NET = n;
        peptide = str;
        mass = peptideToMass(str);
        oMass = oNET = 0;
        id = 0;
    }
    kd_point(std::string str, double m, double n){
        NET = n;
        mass = m;
        peptide = str;
        oMass = oNET = 0;
        id = 0;
    }

    // Just our boilerplate getters and setters.
    double getNET(){
        return NET;
    }
    double getMass(){
        return mass;
    }
    double getObservedMass(){
        return oMass;
    }
    double getObservedNET(){
        return oNET;
    }
    int getID(){
        return id;
    }
    void setObservedMass(double m){
        oMass = m;
    }

    void setObservedNET(double n){
        oNET = n;
    }

    void setID(int i){
        id = i;
    }

    std::string getPep(){
        return peptide;
    }

};

/*

## Why Are These Functions Here? ##

All of these functions are used in some part of the tree. Each "pair" of
functions is stored in an array of pointers to functions that's then used to
compare different objects at the various regions where they are needed.

For example, the pair of functions:
    
    oCompMass
    oCompNET

Are stored in an array, `oCompCheck`, in the kd-tree. These functions are then
used to compare the `observed (mass/NET)` against the `mass/net` that is
recorded in the point in the peptide database.

They're stored as a arrays of pointers to functions so we can then call the
correct comparison function just by saying:

    d = current_dimension
    array_of_comparison_functions[d](point1, point2)

I don't know if this is the "correct" way to do this, but it works and I think
it's a neat idea. If there's a "better", or more correct way to do this, I'd
love to know what that is.

Also, since pretty much all of these are doing some kind of operation
(comparison or math) on either the mass or the NET, it's important that they
be ordered consistently so that the same aspects are always compared on the
same 'level'. Because of that, the rule is:

> The function dealing with `mass` is always in the `0` index, and the
> function dealing with NET is always the `1` index.

*/
bool oCompMass(kd_point* pnt1, kd_point* pnt2){
    return pnt1->getObservedMass() < pnt2->getMass();
}
// True if observed NET is smaller than known NET, false if bigger.
bool oCompNET(kd_point* pnt1, kd_point* pnt2){
    return pnt1->getObservedNET() < pnt2->getNET();
}
bool compMass(kd_point* pnt1, kd_point* pnt2 ){
    return pnt1->getMass() < pnt2->getMass();
}
bool compNET(kd_point* pnt1, kd_point* pnt2 ){
    return pnt1->getNET() < pnt2->getNET();
}
double distMass(kd_point* oPnt, kd_point* knownPoint){
    return std::abs(oPnt->getObservedMass() - knownPoint->getMass());
}
double distNET(kd_point* oPnt, kd_point* knownPoint){
    return std::abs(oPnt->getObservedNET() - knownPoint->getNET());
}

double oCalcDistance(kd_point* oPnt, kd_point* knownPoint){
    double dist = 0;
    // Whoooo Pythagorean theorem!
    dist = sqrt( pow(std::abs(knownPoint->getMass() - oPnt->getObservedMass()), 2.0)+pow(std::abs(knownPoint->getNET() - oPnt->getObservedNET()), 2.0) );
    return dist;

}

/*
Something to note about the way this works:

This function was is fundamentally misguided in that it will always catch
something that is in fact inside of the hypersphere, but it also has a very
high false positive rate. This is the original hypersphere check, but
you'll notice that it isn't actually used anywhere in the program. I would
remove it, but I feel it might be an important reflection on my programming.
*/
bool isInsideHyperSphere(double nnDist, kd_point* nn, kd_point* checkNode){
    if (abs(nn->getMass() - checkNode->getMass()) > nnDist ){
        return true;
    }
    if (abs(nn->getNET() - checkNode->getNET()) > nnDist){
        return true;
    }
    return false;
}
