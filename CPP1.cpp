#include <iostream>

using namespace std;

class Animal {
public:
    string name;
    int age;

    Animal() {
        name = "0";
        age = 0;
    }

    Animal(string a, int b) {
        this->name = a;
        this->age = b;
    }

    void print() {
        cout << "Imie zwierzecia: " << name << endl;
        cout << "Wiek zwierzecia: " << age << endl;
        cout << endl;
    }

    friend ostream& operator<<(ostream&, const Animal&);
    friend ostream& operator<<(ostream&, Animal);
};

ostream& operator<<(ostream& str, const Animal& n) {
    return str << n.name;
}

ostream& operator<<(ostream& str, Animal n) {
    return str << n.age;
}

class Horse 
    : public Animal{
            string name;
            int age;
public:
    string breed;
    int height;

    Horse(string a, int b, string c, int d) {
        this->name = a;
        this->age = b;
        this->breed = c;
        this->height = d;
    };

    void print() {
        cout << "Imie konia: " << name << endl;
        cout << "Wiek konia: " << age << endl;
        cout << "Rasa konia: " << breed << endl;
        cout << "Wzrost konia: " << height << endl;
        cout << endl;
    }

};

class Dog 
    : public Animal{
        string name;
        int age;
public:
    float weight;

    Dog(string a, int b, float c) {
        this->name = a;
        this->age = b;
        this->weight = c;
    };

    void print() {
        cout << "Imie psa: " << name << endl;
        cout << "Wiek psa: " << age << endl;
        cout << "Waga psa: " << weight << endl;
        cout << endl;
    }

};

int main()
{
    Animal* a1 = new Animal("Jack", 16);
    a1->print();

    Horse* h1 = new Horse("Jack", 16, "Appaloosa", 2);
    h1->print();

    Dog* d1 = new Dog("Lasle", 4, 14);
    d1->print();

    return 0;
}
