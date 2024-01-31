//virtual
//abstract
#include<iostream>
using namespace std;

class Mammal {
public:
    virtual void breed() = 0;
};

class Cat : public Mammal {
    void breed() {
        cout << "고양이 새기 낳는중" << endl;
    }
};

class Dog : public Mammal {
    void breed() {
        cout << "강아지 새기 낳는중" << endl;
    }
};

class Shape {
public:
    virtual double getArea() = 0;
    virtual double getRound() = 0;
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r) : radius(r) {}
    double getArea() {
        return this->radius * this->radius * 3.14;
    }
    double getRound() {
        return this->radius * 2 * 3.14;
    }
};


class Triangle : public Shape {
private:
    int base;
    int height;
public:
    Triangle(int b, int h) : base(b), height(h) {}
    double getArea() {
        return this->base * this->height * 0.5;
    }
    double getRound() {
        return this->base * 3;
    }
};


class Square : public Shape {
private:
    int side;
public:
    Square(int s) : side(s) {}
    double getArea() {
        return this->side * this->side;
    }
    double getRound() {
        return this->side * 4;
    }
};

int main() {
    Circle a(5);
    Triangle b(3, 5);
    Square c(5);

    cout << a.getArea() << endl;
    cout << a.getRound() << endl;
    cout << b.getArea() << endl;
    cout << b.getRound() << endl;
    cout << c.getArea() << endl;
    cout << c.getRound() << endl;


}
