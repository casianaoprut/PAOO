#include<iostream>
using namespace std;

class Pet {
    private: 
        Pet(const Pet&); //prevent copy
    public:
        std::string nume;
        int varsta;
        std::string cod_identificare;
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
                cout<<"Copy pet"<<endl;
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
        Persoana& operator=(const Persoana& persoana){
            cout<<"Persoana Copy assigment operator called"<<endl;
            if(this!=&persoana){
                cout<<"Persoana Copy assigment operator called"<<endl;
                nume=persoana.nume;
                prenume=persoana.prenume;
                varsta=persoana.varsta;
                cnp=persoana.cnp;
            }
            return *this;
        };
};

class Owner: public Persoana {
    private: 
        Owner(const Owner&);
    public:
        Pet pet;
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
        Owner& operator=(const Owner& owner){
            cout<<"Owner Copy assigment operator called"<<endl;
            if(this!=&owner){
                cout<<"Copy Owner"<<endl;
                Persoana::operator=(owner);
                pet=owner.pet;
            }
            return *this;
        };

};

int main(){
    Owner owner1("Popescu", "Ion", 34, "SAAMMZZNNNNNN", "Tara", 3,"112321");
    Owner owner2("Ionescu", "Georgel",42,"SAAMMZZNNNNNN", "Rex", 10, "12a12");
    Owner owner3 ("Ionescu", "Costel", 34, "SAAMMZZNNNNNN", "Cleo", 5,"e12a34");
    owner1 = owner1;
    owner1 = owner2 = owner3;
    owner1.print_owner_details();
}