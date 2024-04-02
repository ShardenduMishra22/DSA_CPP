#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void displayBase() {
        cout << "Base Class\n";
    }
};

// Single Inheritance: Public mode
class DerivedSinglePublic : public Base {
public:
    void displayDerivedSinglePublic() {
        cout << "DerivedSinglePublic Class\n";
    }
};

// Single Inheritance: Protected mode
class DerivedSingleProtected : protected Base {
public:
    void displayDerivedSingleProtected() {
        cout << "DerivedSingleProtected Class\n";
    }
};

// Single Inheritance: Private mode
class DerivedSinglePrivate : private Base {
public:
    void displayDerivedSinglePrivate() {
        cout << "DerivedSinglePrivate Class\n";
    }
};

// Multiple Inheritance: Public mode
class DerivedMultiplePublic : public Base, public DerivedSinglePublic {
public:
    void displayDerivedMultiplePublic() {
        cout << "DerivedMultiplePublic Class\n";
    }
};

// Multiple Inheritance: Protected mode
class DerivedMultipleProtected : protected Base, protected DerivedSingleProtected {
public:
    void displayDerivedMultipleProtected() {
        cout << "DerivedMultipleProtected Class\n";
    }
};

// Multiple Inheritance: Private mode
class DerivedMultiplePrivate : private Base, private DerivedSinglePrivate {
public:
    void displayDerivedMultiplePrivate() {
        cout << "DerivedMultiplePrivate Class\n";
    }
};

// Multilevel Inheritance: Public mode
class DerivedMultilevelPublic : public DerivedSinglePublic {
public:
    void displayDerivedMultilevelPublic() {
        cout << "DerivedMultilevelPublic Class\n";
    }
};

// Multilevel Inheritance: Protected mode
class DerivedMultilevelProtected : protected DerivedSingleProtected {
public:
    void displayDerivedMultilevelProtected() {
        cout << "DerivedMultilevelProtected Class\n";
    }
};

// Multilevel Inheritance: Private mode
class DerivedMultilevelPrivate : private DerivedSinglePrivate {
public:
    void displayDerivedMultilevelPrivate() {
        cout << "DerivedMultilevelPrivate Class\n";
    }
};

// Hierarchical Inheritance: Public mode
class DerivedHierarchicalPublic1 : public Base {
public:
    void displayDerivedHierarchicalPublic1() {
        cout << "DerivedHierarchicalPublic1 Class\n";
    }
};

class DerivedHierarchicalPublic2 : public Base {
public:
    void displayDerivedHierarchicalPublic2() {
        cout << "DerivedHierarchicalPublic2 Class\n";
    }
};

// Hierarchical Inheritance: Protected mode
class DerivedHierarchicalProtected : protected Base {
public:
    void displayDerivedHierarchicalProtected() {
        cout << "DerivedHierarchicalProtected Class\n";
    }
};

// Hierarchical Inheritance: Private mode
class DerivedHierarchicalPrivate : private Base {
public:
    void displayDerivedHierarchicalPrivate() {
        cout << "DerivedHierarchicalPrivate Class\n";
    }
};

// Hybrid Inheritance: Public mode
class DerivedHybridPublic : public Base, public DerivedSinglePublic {
public:
    void displayDerivedHybridPublic() {
        cout << "DerivedHybridPublic Class\n";
    }
};

// Hybrid Inheritance: Protected mode
class DerivedHybridProtected : protected Base, protected DerivedSingleProtected {
public:
    void displayDerivedHybridProtected() {
        cout << "DerivedHybridProtected Class\n";
    }
};

// Hybrid Inheritance: Private mode
class DerivedHybridPrivate : private Base, private DerivedSinglePrivate {
public:
    void displayDerivedHybridPrivate() {
        cout << "DerivedHybridPrivate Class\n";
    }
};

int main() {
    // Single Inheritance
    DerivedSinglePublic obj1;
    obj1.displayBase();
    obj1.displayDerivedSinglePublic();

    // Multiple Inheritance
    DerivedMultiplePublic obj2;
    // obj2.displayBase();
    obj2.displayDerivedSinglePublic();
    obj2.displayDerivedMultiplePublic();

    // Multilevel Inheritance
    DerivedMultilevelPublic obj3;
    obj3.displayBase();
    obj3.displayDerivedSinglePublic();
    obj3.displayDerivedMultilevelPublic();

    // Hierarchical Inheritance
    DerivedHierarchicalPublic1 obj4;
    DerivedHierarchicalPublic2 obj5;
    obj4.displayBase();
    obj4.displayDerivedHierarchicalPublic1();
    obj5.displayDerivedHierarchicalPublic2();

    // Hybrid Inheritance
    DerivedHybridPublic obj6;
    // obj6.displayBase();
    obj6.displayDerivedSinglePublic();
    obj6.displayDerivedHybridPublic();

    return 0;
}