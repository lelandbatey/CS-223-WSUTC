class name_c
{

private:

    std::string value;
    long long numericName;
    

public:
    name_c() {
        value = std::string();
        numericName = 0;

    };

    void setName(std::string inName){
        value = inName;
        numericName = simpleNumOfString(inName);
    };

    std::string getVal(){
        return value;
    }

    long long getNumName(){
        return numericName;
    }

    // ~name_c();

    friend bool operator == (const name_c &nm1, const name_c &nm2){
        return (nm1.numericName == nm2.numericName);
    }

    friend bool operator > (const name_c &nm1, const name_c &nm2){
        return (nm1.numericName > nm2.numericName);
    }

    friend bool operator < (const name_c &nm1, const name_c &nm2){
        return (nm1.numericName < nm2.numericName);
    }


};