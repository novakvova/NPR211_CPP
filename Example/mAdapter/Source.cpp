// Java implementation of Adapter pattern
#include <iostream>

class Bird
{
public:
    virtual void fly() = 0;
    virtual void makeSound() = 0;
};

class Sparrow : public Bird
{
public:
    void fly() override
    {
        std::cout << "Flying" << std::endl;
    }
    void makeSound() override
    {
        std::cout << "Chirp Chirp" << std::endl;
    }
};

class ToyDuck
{
public:
    virtual void squeak() = 0;
};

class PlasticToyDuck : public ToyDuck
{
public:
    void squeak() override
    {
        std::cout << "Squeak" << std::endl;
    }
};

class BirdAdapter : public ToyDuck
{
public:
    BirdAdapter(Bird& bird) : bird_(bird) {}
    void squeak() override
    {
        bird_.makeSound();
    }

private:
    Bird& bird_;
};

int main()
{
    Sparrow sparrow;
    PlasticToyDuck toyDuck;

    ToyDuck& birdAdapter = *(new BirdAdapter(sparrow));

    std::cout << "Sparrow..." << std::endl;
    sparrow.fly();
    sparrow.makeSound();

    std::cout << "ToyDuck..." << std::endl;
    toyDuck.squeak();

    std::cout << "BirdAdapter..." << std::endl;
    birdAdapter.squeak();

    return 0;
}
// This code is contributed by Ahmed Izz Murtaja