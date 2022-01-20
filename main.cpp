#include <iostream>

class Animal {
    std::string im;
public:
    Animal(std::string inIm) : im(inIm) {}

    virtual ~Animal() {}

    void virtual voiceDefault() = 0;

    void virtual voiceAggressive() = 0;

    std::string whoIm() {
        return im;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {}

    virtual ~Dog() {}

    void virtual voiceDefault() {
        std::cout << "Bark";
    }

    void virtual voiceAggressive() {
        std::cout << "Woof";
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("cat") {}

    virtual ~Cat() {}

    void virtual voiceDefault() {
        std::cout << "Meow";
    }

    void virtual voiceAggressive() {
        std::cout << "Purr";
    }
};

void meeting(Animal *a, Animal *b) {

    std::cout << a->whoIm() << " + " << b->whoIm() << " = ";

    if (a->whoIm() == b->whoIm()) {
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
