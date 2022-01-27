#include <iostream>

class Animal {

public:

    void virtual voiceDefault() = 0;

    void virtual voiceAggressive() = 0;

};

class Dog : public Animal {

public:

    void voiceDefault() {
        std::cout << "Bark";
    }

    void voiceAggressive() {
        std::cout << "Woof";
    }
};

class Cat : public Animal {

public:

    void  voiceDefault() {
        std::cout << "Meow";
    }

    void  voiceAggressive() {
        std::cout << "Purr";
    }
};

void meeting(Animal *a, Animal *b) {

    if (a == b) {
        a->voiceAggressive();
        std::cout << " ";
        b->voiceAggressive();
    } else {
        a->voiceDefault();
        std::cout << " ";
        b->voiceDefault();
    }
    std::cout << std::endl;
}

int main() {
    Animal *d = new Dog;
    Animal *c = new Cat;

    meeting(d, d);
    meeting(d, c);
    meeting(c, d);
    meeting(c, c);

    delete d;
    d = nullptr;
    delete c;
    c = nullptr;

    return 0;
}
