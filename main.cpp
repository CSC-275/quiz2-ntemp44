#include <iostream>
#include <cmath>
#include <iomanip>

class Circle {
// complete declaration for Circle class here
    private:
    double m_radius;
    protected:
    double m_area;
    double calcArea(double radius) {
        return M_PI * radius * radius;
    }
    public:
    Circle() {
        m_radius = 1;
        m_area = 3.14;
    }
    Circle(double radius) {
        m_radius = radius;
        m_area = calcArea(radius);
    }

    virtual void display() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::endl;
        std::cout << "The area of a circle with ..." << std::endl;
        std::cout << "a radius of " << m_radius << " inches" << std::endl;
        std::cout << "has an area of " << m_area << " square inches." << std::endl;
    }
};

class Cylinder : public Circle {
// complete declaration for Cylinder class here
    private:
    double m_height;
    double m_volume;
    double calcVolume(double radius, double height) {
        return M_PI * radius * radius * height;
    }
    public:
    Cylinder(double radius, double height): Circle(radius) {
        m_height = height;
        m_volume = calcVolume(radius, height);
    }

    void display() override {
       Circle::display();
        std::cout << "And the volume of a Cylinder with..." << std::endl;
        std::cout << "a circular end area of " << m_area << " square inches" << std::endl;
        std::cout << "and a height of " << m_height << " inches" << std::endl;
        std::cout << "has a volume of " << m_volume << " cubic inches." << std::endl;
    }
};

int main() {
    Circle c1, c2(5.25);
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5,8.65);
    cl1->display();
    return 0;
}
