#include <iostream>
#include <vector>

// Базовий клас, який визначає інтерфейс для операції виведення інформації.
class Shape {
public:
    virtual void draw() const = 0;
};

// Конкретні класи, які реалізують операцію виведення для різних фігур.
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

// Клас, який використовує фігури для виведення інформації.
class Drawing {
private:
    std::vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void drawShapes() const {
        for (const auto& shape : shapes) {
            shape->draw();
        }
    }
};

int main() {
    Drawing drawing;

    // Додаємо фігури до малюнка.
    drawing.addShape(new Circle());
    drawing.addShape(new Square());

    // Виводимо інформацію про всі фігури.
    drawing.drawShapes();

    return 0;
}
