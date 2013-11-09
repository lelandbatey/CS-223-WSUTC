// #include <algorithm>
// #include <vector>
// #include <iostream>

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
    bool (*compCheck[2])(kd_point*,kd_point*);

    kd_point(){
        NET = mass = 0;
    };
    kd_point(double m, double n){
        NET = n;
        mass = m;
    }
    kd_point(std::string str, double n){
        NET = n;
        peptide = str;
        mass = peptideToMass(str);
    }

    // ~kd_point();
};


bool compMass(kd_point* pnt1, kd_point* pnt2 ){
    // std::cout << "compMass successfully called!" << std::endl;
    return pnt1->mass < pnt2->mass;
}

bool compNET(kd_point* pnt1, kd_point* pnt2 ){
    return pnt1->NET < pnt2->NET;
}


