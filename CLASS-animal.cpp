// Programme including class which has name and age of the animal and prints data of these animals. There are also classes inheriting from Animal class: 
// Horse class, which includes breed and height of the horse, and Dog class, which includes weight of the dog.

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
        cout << "Name of an animal: " << name << endl;
        cout << "Age of an animal: " << age << endl;
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
        cout << "Name of the horse: " << name << endl;
        cout << "Age of the horse: " << age << endl;
        cout << "Breed of the horse: " << breed << endl;
        cout << "Height of the horse: " << height << endl;
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
        cout << "Name of the dog: " << name << endl;
        cout << "Age of the dog: " << age << endl;
        cout << "Weight of the dog: " << weight << endl;
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
