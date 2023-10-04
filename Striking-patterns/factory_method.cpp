#include <iostream>

class Shape
{
  public:
    virtual void draw() = 0;
    virtual ~Shape() { }
};

class Circle : public Shape
{
  public:
    void draw() override {
        std::cout << "Circle\n";
    }
};

class Square : public Shape
{
  public:
    void draw() override {
        std::cout << "Square\n";
    }
};

class Triangle : public Shape
{
  public:
    void draw() override {
        std::cout << "Triangle\n";
    }
};

class ShapeFactory
{
  public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() { }
};

class CircleFactory : public ShapeFactory
{
  public:
    Shape* createShape() {
        return new Circle;
    }
};

class SquareFactory : public ShapeFactory
{
  public:
    Shape* createShape() {
        return new Square;
    }
};

class TriangleFactory : public ShapeFactory
{
  public:
    Shape* createShape() {
        return new Triangle;
    }
};

int main() {
    CircleFactory*   obj1     = new CircleFactory;
    SquareFactory*   obj2     = new SquareFactory;
    TriangleFactory* obj3     = new TriangleFactory;
    std::vector<Shape*> arr;
    arr.push_back(obj1->createShape());
    arr.push_back(obj2->createShape());
    arr.push_back(obj3->createShape());

    for (auto element : arr) {
        element->draw();
    }

    for (auto element : arr) {
        delete element;
    }
}