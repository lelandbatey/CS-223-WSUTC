

class animals_c
{

private:
    std::string name;
    std::string baseName; // True name will be set during creation, and is NOT 
                          // unique. Is used as the "base" when creating the 
                          // derived name, which is unique, and uses roman 
                          // numerals for it's representation.
    double weight;
    double friendliness;
    double hunger;
    double age;
    double duplicate;
    int numName; // Num name will be used as the numerical representation of
                 // an animals name in the BST.
    
    int dupNum; // Integer representing decimal form of number appended to the 
                // name to build the unique derived name. 

     // Returns a *relatively* unique representation of a given string
    int deriveNumericName(std::string name) {
        int numericName = 0;
        int temp = 0;
        double iTemp;
        std::stringstream oTemp;

        for (unsigned int i = 0; i < name.length(); ++i) {
            temp = int(name.c_str()[i] - 31); // The subtraction of 31 just 
                                              // makes the starting numbers as
                                              // small as possible. Since
                                              // names might have numbers or
                                              // spaces, we can't subtract
                                              // more than 31 (space is ascii
                                              // 32)
            
            iTemp = double(name.c_str()[i] - 41);
            oTemp << dubToStr(iTemp);


            temp = pow(temp, 4); // Square temp
            numericName = numericName + temp;
        }
        numericName = numericName * name.length();
        // std::cout << oTemp.str() << std::endl;
        return numericName;
    }


public:

    animals_c(){
        dupNum = 1;
    }
    
    void setWeight(double d){
        weight = d;
    };
    void setName(std::string str){
        name = str;
        baseName = str;
        numName = deriveNumericName(str);
    };

    // Changes the name whithout changing the  "base name"
    void changeName(std::string str){
        name = str;
        numName = deriveNumericName(str);
    }

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

    void setDupNum(int i){
        dupNum = i;
    };

    void feed(double amnt) {
        hunger = hunger - 1;
        weight = weight + (0.1 * weight * amnt); 
        // The 0.1 means %10. As in, increase the amount they weigh by 
        // (10% of weight * number of food items)
    };

    void print(){
        // Prints out the attributes of the instance of this animal.
        // uses "std::cout.width" to set the appropriate width.

        // std::cout.width(10);

        std::cout << getGreeting() << ",";
        // std::cout.width(6);
        std::cout << getType() << ",";
        // std::cout.width(14);
        std::cout << getName() << ",";
        // std::cout.width(6);
        std::cout << getAge() << ",";
        // std::cout.width(6);
        std::cout << getFriendly() << ",";
        // std::cout.width(6);
        std::cout << getWeight() << ",";
        // std::cout.width(6);
        std::cout << getHunger() << std::endl;

    }

   
    void refreshNumName() {
        numName = deriveNumericName(name);
    }


    double getHunger(){   return hunger; };
    double getFriendly(){ return friendliness; };
    double getWeight(){   return weight; };
    double getAge(){      return age; };

    int getNumName() const { return numName; }; // Const is only there because it's required for the operator overloading
    int getDupNum() {return dupNum; };

    std::string getBaseName(){ return baseName; };
    std::string getName(){ return name; };

    virtual std::string getType(){ return std::string("I AM AN ANIMAL B)"); };
    virtual std::string getGreeting(){ return std::string("WAZZUUUUUP!?");};

        
    // Well, here I REALLY don't know what I'm doing. This train wreck's gonna
    // be pretty bad :(

    // Checking equality of two animals checks if their numericNames are equal
    friend bool operator == (const animals_c &animal1, const animals_c &animal2) {
        // std::cout << "  Calling equal on two animals." << std::endl;
        return (animal1.getNumName() == animal2.getNumName());
    }

    // Check if first (left hand) is smaller than second (right hand)
    friend bool operator < (const animals_c &animal1, const animals_c &animal2) {
        return (animal1.getNumName() < animal2.getNumName());
    }

    // Check if first (left hand) is *larger* than second (right hand)
    friend bool operator > (const animals_c &animal1, const animals_c &animal2) {
        return (animal1.getNumName() > animal2.getNumName() );
    }

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




// These two functions are used fo the below sort functions. They exist so
// that the "std::sort()" function can make sense of the animals class and do
// an accurate comparison of them.

bool weightComp(animals_c* const& animal1, animals_c* const& animal2 ) {
    return animal1->getWeight() < animal2->getWeight();
}

bool friendComp(animals_c* const& animal1, animals_c* const& animal2 ) {
    return animal1->getFriendly() < animal2->getFriendly();
}


// The below two functions pretty much do what it says on the tin: they sort a
// given "zoo" by the animals weight and by the animals friendliness,
// respectively.

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


// Two short convenience methods to "pet" and "feed" all the animals in a
// given "zoo".

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
        zoo[i]->refreshNumName();
        
        // zoo[i]->print();
    }


    return zoo;
};


// Function given to the binary search tree to be run on an animal when it
// finds that their names are equal. It mutates the name of the animal that's
// trying to be inserted (animal2) by taking it's "base name" and adding the
// appropriate roman-numeral suffix to the end.

// A bug that happens is if you have a "fido" in the spreadsheet and a "fido
// II" in the spreadsheet, the "fido II" might be renamed "fido II" if he's
// inserted late into the game and previous fido's have come before him. This
// is because his "base name", or his original name, was "fido II" already. I
// don't take the names and break them up try to find their "true" base name,
// it's just entered naively. However, if it's inserted into the BST before
// other fido's, then since their base names are just "fido" they can be
// renamed appropriately.
//
// So, if this is what our CSV looks like and it's read in from top to bottom:
//
//     dog,fido,10,4,14,2
//     dog,fido,10,4,14,2
//     dog,fido ii,13,4,2,1
//
// Then the dog named "fido ii" would be renamed to "fido II II" since his
// base name is "fido II" already. However, this is what the CSV looks like:
//
//     dog,fido ii,13,4,2,1
//     dog,fido,10,4,14,2
//     dog,fido,10,4,14,2
//
// Then the dog "fido II" would not be renamed, since he would be inserted
// before the others, preventing him colliding, which prevents the odd
// renaming conventions.
//
//   It's a Feature, not a bug!
//                             -- Management
//
// I chose to not fix this bug (aside from time constraints) because I assume
// that we're not supposed to "take away" from the data read from the CSV,
// only add to it. If we were to try to decipher roman numerals out of the
// data, we could very easily damage the data we've read in, so instead I've
// chosen to take a "safer", but naive, approach.


// Takes two animals, modifying the seconds name if they're initially the same
void fixSameName(animals_c* animal1, animals_c* animal2){
    // Compare the names of animal1 and animal2
    if (*animal1 == *animal2) {
        // They're equal, so we increment the duplicate name of our animal
        animal2->setDupNum(animal2->getDupNum()+1);
        // Change the name of animal2, adding the roman numeral representation of our animal
        animal2->changeName( animal2->getBaseName() + iToRoman(animal2->getDupNum()) );

    }
}

// The function given to the binary search tree to see if an animal has the
// same name as string being searched for.
int compareStrToAnimal(animals_c* animal, std::string str) {

    if (DEBUG){
        std::cout << "Animal Name : '"<< animal->getName() << "'" << std::endl;
        std::cout << "Input String: '"<< str << "'" << std::endl;
    }

    if (str == animal->getName()){
        animal->print();
        return 1;
    }
    // Implicit else: (if the names aren't the same)
    return 0;
}




