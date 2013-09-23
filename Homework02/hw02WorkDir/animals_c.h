

class animals_c
{

private:
    std::string name;
    std::string trueName; // True name will be set during creation, and is NOT 
                          // unique. Is used as the "base" when creating the 
                          // derived name, which is unique, and uses roman 
                          // numerals for it's representation.
    double weight;
    double friendliness;
    double hunger;
    double age;
    double duplicate;
    double numName; // Num name will be used as the numerical representation of
                    // an animals name in the BST.
    int dupNum; // Integer representing decimal form of number appended to the 
                // name to build the unique derived name. 

public:
    
    void setWeight(double d){
        weight = d;
    };
    void setName(std::string str){
        name = str;
    };
    void setAge(double d){
        age = d;
    };
    void setFriendliness(double d){
        friendliness = d;
    };
    void setHunger(double d){
        hunger = d;
    };

    void weightInc(double d){
        weight = weight + d;
    };
    // void weightDec(double); // According to the spec, the weight is never decremented


    void friendlyInc(double d){
        friendliness = friendliness + d;
    };
    // We don't need a "decrementFriendliness()" method since the friendliness
    // of an animal never decreases (according to the spec)

    void feed(double amnt) {
        hunger = hunger - 1;
        weight = weight + (0.1 * weight * amnt); 
        // The 0.1 means %10. As in, increase the amount they weigh by 
        // (10% of weight * number of food items)
    };

    void print(){
        // Prints out the attributes of the instance of this animal.
        // uses "std::cout.width" to set the appropriate width.

        std::cout.width(10);

        std::cout << getGreeting() << ",";
        std::cout.width(10);
        std::cout << getType() << ",";
        std::cout.width(10);
        std::cout << getName() << ",";
        std::cout.width(10);
        std::cout << getAge() << ",";
        std::cout.width(10);
        std::cout << getFriendly() << ",";
        std::cout.width(10);
        std::cout << getWeight() << ",";
        std::cout.width(10);
        std::cout << getHunger() << std::endl;

    }


    double getHunger(){   return hunger; };
    double getFriendly(){ return friendliness; };
    double getWeight(){   return weight; };
    double getAge(){      return age; };

    std::string getName(){ return name; };

    virtual std::string getType(){ return std::string("I AM AN ANIMAL B)"); };
    virtual std::string getGreeting(){ return std::string("WAZZUUUUUP!?");};

    /* data */
};



// Class "cat_c" inherits from base class "animals_c"
class cat_c: public animals_c {
public:
    virtual std::string getType() {
        return std::string("CAT");
    };

    virtual std::string getGreeting(){
        return std::string("meow");
    };
};



// Dog_c inherits from animals_c
class dog_c: public animals_c {
public:
    virtual std::string getType() {
        return std::string("DOG");
    };

    virtual std::string getGreeting(){
        return std::string("bow-wow");
    };
};


// cow_c inherits from animals_c
class cow_c: public animals_c {
public:
    virtual std::string getType() {
        return std::string("COW");
    };

    virtual std::string getGreeting(){
        return std::string("moo");
    };
};

/*
//         _______   ______     ____  ______   ________    ___   __________ ___________
//        / ____/ | / / __ \   / __ \/ ____/  / ____/ /   /   | / ___/ ___// ____/ ___/
//       / __/ /  |/ / / / /  / / / / /_     / /   / /   / /| | \__ \\__ \/ __/  \__ \ 
//      / /___/ /|  / /_/ /  / /_/ / __/    / /___/ /___/ ___ |___/ /__/ / /___ ___/ / 
//     /_____/_/ |_/_____/   \____/_/       \____/_____/_/  |_/____/____/_____//____/  
*/                                                                                 

// // Reverses the order of the zoo. Primarily used after we sort by pecking order.
// std::vector<animals_c*> reverseZoo(std::std::vector<animals_c*> zoo) {

// }


bool weightComp(animals_c* const& animal1, animals_c* const& animal2 ) {
    return animal1->getWeight() < animal2->getWeight();
}

bool friendComp(animals_c* const& animal1, animals_c* const& animal2 ) {
    return animal1->getFriendly() < animal2->getFriendly();
}

// Returns copy of zoo where it's sorted from least heavy to most heavy
std::vector<animals_c*> sortZooWeight(std::vector<animals_c*> zoo) {
    std::sort( zoo.begin(), zoo.end(), weightComp);
    return zoo;
}

// Returns a copy of the zoo where it's been sorted from least friendly to most friendly
std::vector<animals_c*> sortZooFriendly(std::vector<animals_c*> zoo) {
    std::sort( zoo.begin(), zoo.end(), friendComp);
    return zoo;
}

// "Feeds" all the animals in the zoo
void feedAll( std::vector<animals_c*> zoo, double amount) {
    for (unsigned int i = 0; i < zoo.size(); ++i) {
        zoo[i]->feed(amount);
    }
}

// "Pets" all the animals in the zoo
void petAll( std::vector<animals_c*> zoo) {
    for (unsigned int i = 0; i < zoo.size(); ++i) {
        zoo[i]->friendlyInc(1);
    }
}


// Returns vector of pointers to instances of classes derived from the
// abstract class "animals_c"
std::vector<animals_c*> buildZoo(std::vector<animal_ts> animals){


    int totalAnimals = actualAnimals(animals);
    std::vector<animals_c*> zoo(totalAnimals);

    for (int i = 0; i < totalAnimals; i++ ) {
        
        // Instantiate the correct animal type.
        if        (animals[i].type == "DOG") {
            zoo[i] = new dog_c;
        } else if (animals[i].type == "CAT") {
            zoo[i] = new cat_c;
        } else if (animals[i].type == "COW") {
            zoo[i] = new cow_c;
        }

        // Populate the appropriate feilds for our animal.
        zoo[i]->setAge(         strToDub(animals[i].age));
        zoo[i]->setName(                 animals[i].name);
        zoo[i]->setWeight(      strToDub(animals[i].weight));
        zoo[i]->setHunger(      strToDub(animals[i].hunger));
        zoo[i]->setFriendliness(strToDub(animals[i].friendliness));
        
    }


    return zoo;
};