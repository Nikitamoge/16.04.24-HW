#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speak() = 0; 
};

class Frog : public Animal {
public:
    void speak() override {
        cout << "Quaaaaaaaaa." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof Woof Woof." << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow Meow Meow." << endl;
    }

    void scratch(bool HomeworkDone) {
        if (HomeworkDone) {
            cout << "Owner is safe." << endl;
        }
        else {
            cout << "Owner is scratched." << endl;
        }
    }

    void purr() {
        cout << "Purr Purr Purr." << endl;
    }
};

int main() {
    unique_ptr<Animal> animals[3];
    animals[0] = make_unique<Frog>();
    animals[1] = make_unique<Dog>();
    unique_ptr<Cat> cat = make_unique<Cat>();
    animals[2] = move(cat);

    for (int i = 0; i < 3; i++) {
        animals[i]->speak();
    }

    cat->scratch(false);
    cat->purr();
}