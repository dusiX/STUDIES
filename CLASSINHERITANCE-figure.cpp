// Programme including Figure class which has coordinates of the figure's anchor point on the plane. There are also classes inheriting from Figure class:
// Rectangle class, which includes width and height of a rectangle, and Circle class, which includes radius of a circle. Both of them have a function including 
// area of a figure

#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

class Figure {
public:
    int x, y;

    Figure() {
        x = 0;
        y = 0;
    }

    Figure(int a, int b) {
        this->x = a;
        this->y = b;
    }

    void print() {
        cout << "P = [" << x << ", " << y << "]" << endl;
    }

    friend ostream& operator<<(ostream&, const Figure&);
    friend ostream& operator<<(ostream&, Figure);

};

ostream& operator<<(ostream& str, const Figure& n) {
    return str << n.x;
}

ostream& operator<<(ostream& str, Figure n) {
    return str << n.y;
}

class Rectangle
    :public Figure {
    int x, y;
public:
    double width, height;
    float pole;

    Rectangle(int a, int b, double c, double d) {
        this->x = a;
        this->y = b;
        this->width = c;
        this->height = d;
    }

    double area() {
        pole = width * height;
        return pole;
    }

    void print() {
        cout << "Coordinates of the point: [" << x << ", " << y << "]" << endl;
        cout << "Rectangle dimensions: " << width << "x" << height << endl;
        cout << "Area of the rectangle: " << area() << endl;
    }

};

class Circle
    :public Figure {
    int x, y;
public:
    double radius;
    float pole;

    Circle(int a, int b, double c) {
        this->x = a;
        this->y = b;
        this->radius = c;
    }

    double area() {
        pole = (M_PI * radius) * (M_PI * radius);
        return pole;
    }

    void print() {
        cout << "Coordinates of the point: [" << x << ", " << y << "]" << endl;
        cout << "Circle's radius: " << radius << endl;
        cout << "Area of the circle: " << area() << endl;
    }

};

int main()
{
    int a, b;
    double c, d, e;

    srand(time(NULL));
    a = rand() % 11 + 1;
    b = rand() % 11 + 1;

    Figure* f1 = new Figure(a, b);
    f1->print();

    a = rand() % 11 + 1;
    b = rand() % 11 + 1;
    c = rand() % 11 + 1;
    d = rand() % 11 + 1;

    Rectangle* f2 = new Rectangle(a, b, c, d);
    f2->print();

    a = rand() % 11 + 1;
    b = rand() % 11 + 1;
    e = rand() % 11 + 1;

    Circle* f3 = new Circle(a, b, e);
    f3->print();

    return 0;
}
