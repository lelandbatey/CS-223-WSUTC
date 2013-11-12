#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

#pragma once

class kd_point
{
private:
    double peptideToMass(std::string str){
        double toReturn = 0;

        char ch_ary[20] = {'A','R','N','D','C','E','Q','G','H','I','L','K','M','F','P','S','T','W','Y','V'};
        double d_ary[20]  = { 71.03711,156.10111,114.04293,115.02694,103.00919,129.04259,128.05858,57.02146,137.05891,113.08406,113.08406,128.09496,131.04049,147.06841,97.05276,87.03203,101.04768,186.07931,163.06333,99.06841 };


        for (unsigned int i = 0; i < str.size(); ++i){
            // I realize this is a monstrous peive of horribleness. I would
            // have done it a much better way, but it's not the worst thing I
            // could have done, and it is easy.

            for (int n = 0; n < 20; ++n){
                if (str.c_str()[i] == ch_ary[n] ) {
                    toReturn = toReturn + d_ary[n];
                }
            }
        }

        return toReturn;
    }

public:
    std::string peptide;
    double mass;
    double NET;
    int id;
    double oMass;
    double oNET;


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





    // ~kd_point();
};

bool oCompMass(kd_point* pnt1, kd_point* pnt2){
    return pnt1->getObservedMass() < pnt2->getMass();
}

// True if observed NET is smaller than known NET, false if bigger.
bool oCompNET(kd_point* pnt1, kd_point* pnt2){
    return pnt1->getObservedNET() < pnt2->getNET();
}

bool compMass(kd_point* pnt1, kd_point* pnt2 ){
    // std::cout << "compMass successfully called!" << std::endl;
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

    // std::cout << "Calculating the distance!" << std::endl;
    // std::cout << "Square of massDist: " << std::setprecision(50) << pow(abs(knownPoint->getMass() - oPnt->getObservedMass()), 2.0) << std::endl;
    
    double dist = 0;
    // Whoooo pythagorean theorum!
    dist = sqrt( pow(std::abs(knownPoint->getMass() - oPnt->getObservedMass()), 2.0)+pow(std::abs(knownPoint->getNET() - oPnt->getObservedNET()), 2.0) );
    // std::cout << "Distance: " << dist << std::endl;
    return dist;

}


// Something to note about the way this works:
//
// This function, though based on a good idea, is fundamentally misguided in
// how it calculates whether something is actually inside the hypersphere. It
// will pretty much always say that something is inside it's hypersphere, even
// if it actually isn't. I realize that this hurts the efficiency of the
// program, but I don't care because while it makes the program run slower (by
// searching more exhaustively than is necessary), it doesn't actually break
// the program. I just wanted to note that I do in fact get why this is
// incorrect.
bool isInsideHyperSphere(double nnDist, kd_point* nn, kd_point* checkNode){
    if (abs(nn->getMass() - checkNode->getMass()) > nnDist ){
        return true;
    }

    if (abs(nn->getNET() - checkNode->getNET()) > nnDist){
        return true;
    }

    return false;
}
