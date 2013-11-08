// #include <algorithm>
// #include <vector>
// #include <iostream>


class kd_point
{
private:
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

    // ~kd_point();
};


bool compMass(kd_point* pnt1, kd_point* pnt2 ){
    // std::cout << "compMass successfully called!" << std::endl;
    return pnt1->mass < pnt2->mass;
}

bool compNET(kd_point* pnt1, kd_point* pnt2 ){
    return pnt1->NET < pnt2->NET;
}


