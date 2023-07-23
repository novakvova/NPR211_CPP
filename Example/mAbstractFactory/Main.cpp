#include <iostream>

// AbstractProduct - Shape
class Shape {
public:
    virtual void draw() = 0;
};

// ConcreteProducts - Circle and Square
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle.\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Square.\n";
    }
};

// AbstractFactory - ShapeFactory
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
};

// ConcreteFactories - CircleFactory and SquareFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

int main() {
    ShapeFactory* factory;

    // Creating a Circle
    factory = new CircleFactory();
    Shape* circle = factory->createShape();
    circle->draw();
    delete circle;
    delete factory;

    // Creating a Square
    factory = new SquareFactory();
    Shape* square = factory->createShape();
    square->draw();
    delete square;
    delete factory;

    return 0;
}