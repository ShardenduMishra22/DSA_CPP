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

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking\n";
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing\n";
    }
};

int main() {
    Dog dog;
    dog.eat();    // Accessing base class function
    dog.sleep();  // Accessing base class function
    dog.bark();   // Accessing derived class function

    cout << endl;

    Cat cat;
    cat.eat();    // Accessing base class function
    cat.sleep();  // Accessing base class function
    cat.meow();   // Accessing derived class function

    return 0;
}
