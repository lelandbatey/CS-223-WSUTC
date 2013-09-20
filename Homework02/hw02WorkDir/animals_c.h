

class animals_c
{

private:
    std::string name;
    double weight;
    double friendliness;
    double hunger;
    double age;

public:
    // animals_c(arguments);
    // ~animals_c();
    
    void weightInc(double);
    // void weightDec(double); // According to the spec, the weight is never decremented


    void friendlyInc(double);
    // We don't need a "decrementFriendliness()" method since the friendliness of an animal never decreases (according to the spec)

    void feed(int);

    double getHunger();
    double getFriendly();
    double getWeight();
    
    std::string getName();

    virtual std::string getType();
    virtual std::string getGreeting();

    /* data */
};

// Class "cat_c" inherits from base class "animals_c"
class cat_c: public animals_c {

public:
    std::string getType();
    std::string getGreeting();
};

class dog_c: public animals_c {

public:
    std::string getType();
    std::string getGreeting();

};

class cow_c: public animals_c {

public:
    std::string getType();
    std::string getGreeting();

};

