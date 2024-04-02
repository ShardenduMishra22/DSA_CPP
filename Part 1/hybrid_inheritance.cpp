#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating\n";
    }

    void sleep() {
        cout << "Animal is sleeping\n";
    }
};

// Intermediate base class
class Pet {
public:
    void play() {
        cout << "Pet is playing\n";
    }
};

// Derived class 1
class Dog : public Animal, public Pet {
public:
    void bark() {
        cout << "Dog is barking\n";
    }
};

// Derived class 2
class Cat : public Animal, public Pet {
public:
    void meow() {
        cout << "Cat is meowing\n";
    }
};

int main() {
    Dog dog;
    dog.eat();    // Accessing base class function
    dog.sleep();  // Accessing base class function
    dog.play();   // Accessing intermediate base class function
    dog.bark();   // Accessing derived class function

    cout << endl;

    Cat cat;
    cat.eat();    // Accessing base class function
    cat.sleep();  // Accessing base class function
    cat.play();   // Accessing intermediate base class function
    cat.meow();   // Accessing derived class function

    return 0;
}
