#include<iostream>
using namespace std;

class Pet {
    private: 
        std::string nume;
        int varsta;
        std::string cod_identificare;
        Pet(const Pet&); //prevent copy
    public:
        Pet(){};
        Pet(const std::string &nume, int varsta, const std::string &cod_identificare): //constructor
        nume(nume),
        varsta(varsta),
        cod_identificare(cod_identificare){
            cout << "Obiectul pet cu urmatoarele date a fost creat:" << endl;
            cout << "Name: " << nume << endl;
	        cout << "varsta  : " << varsta<< endl;
            cout << "Cod_identificare  : " << cod_identificare<< endl;
            cout << endl;
        };
        ~Pet(){ //destructor
            cout<<"Pet Destructor called"<<endl;
        };
        std::string toString(){
            return "Name: " +  nume + ", varsta: " + std::to_string(varsta) +  ", cod_identificare : " + cod_identificare;
        };
         Pet& operator=(const Pet& pet){
            cout<<"Pet Copy assigment operator called"<<endl;
            if(this!=&pet){
                nume=pet.nume;
                varsta=pet.varsta;
                cod_identificare=pet.cod_identificare;
            }
            return *this;
         };

};

class Persoana {
    public:
        std::string nume;
        std::string prenume;
        int varsta;
        std::string cnp;
    private:
        Persoana(const Persoana&);  //prevent copy
        Persoana& operator=(const Persoana);
    public: //constructor
        Persoana(){};
        Persoana(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp):
            nume(nume),
            prenume(prenume),
            varsta(varsta),
            cnp(cnp){};
    ~Persoana(){ //destructor
            cout<<"Persoana Destructor called"<<endl;
        };
};

class Owner: public Persoana {
    private: 
        Pet pet;
        Owner(const Owner&);
    public:
    Owner(){};
        Owner(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp, const std::string &pet_nume, int pet_varsta, const std::string &pet_cod_identificare): //constructor
        Persoana(nume,prenume,varsta,cnp),
        pet(pet_nume, pet_varsta, pet_cod_identificare){};
        ~Owner(){ //destructor
            cout<<"Owner Destructor called"<<endl;
        };
        void setNames(std::string nume, std::string prenume){
            this->nume = nume;
            this->prenume = prenume;
        };
        void setCNP(std::string cnp){
            this->cnp = cnp;
        };
        void setVarsta(const int &varsta){
            this->varsta = varsta;
        };
        void setPet(Pet& pet){
            this->pet = pet;
        };
        void print_pet_details(){
            cout << "print_pet_details" << endl;
            cout << pet.toString();
            cout << endl;
        }
        void print_owner_details(){
            cout << "print_owner_details" << endl;
            cout << "nume: " << nume << endl;
            cout << "prenume: " << prenume << endl;
	        cout << "varsta : " << varsta<< endl;
            cout << "CNP : " << cnp<< endl;
            cout << "Pet details:" << endl;
            cout<< pet.toString() << endl;
            cout << endl;
        }

};

int main(){
    Owner owner("Popescu", "Ion", 34, "SAAMMZZNNNNNN", "Tara", 3,"112321");
    owner.print_pet_details();
    owner.~Owner();
    Owner owner2;
    owner2.setNames("Ionescu", "Georgel");
    owner2.setVarsta(42);
    owner2.setCNP("SAAMMZZNNNNNN");
    Pet pet("Rex", 4, "12a12");
    owner2.setPet(pet);
    owner2.print_owner_details();
}