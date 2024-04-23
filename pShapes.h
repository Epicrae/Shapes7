#ifndef ISHAPES_H
#define ISHAPES_H
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace comsc {

    struct Shape {
        virtual ~Shape() {} //Virtual deconstrutor makes sure that the destructor of the derived class is called correctly.
        virtual void output(ostream& out) const = 0;//pure virtual function to output shape
        // steam insersion operator
        friend ostream& operator<<(ostream& out, const Shape& shape) {//opeartor overloading
            shape.output(out);
            return out;
        }
    };

    // class definitions
    class SQUARE : public Shape { // SQUARE
    protected:
        const double side;

    public:
        SQUARE(const vector<string>& tokens);
        void output(ostream&) const;
    };
    class CUBE : public SQUARE { // CUBE
    public:
        CUBE(const vector<string>& tokens);
        void output(ostream&) const;
    };

    class RECTANGLE : public Shape { // RECTANGLE
    protected:
        const double length;
        const double width;

    public:
        RECTANGLE(const vector<string>& tokens);
        void output(ostream&) const;
    };

    class BOX : public RECTANGLE { // BOX
    private:
        const double height;

    public:
        BOX(const vector<string>& tokens);
        void output(ostream&) const;
    };

    // Circle and CYLINDER
    class CIRCLE : public Shape {
    protected:
        const double radius;

    public:
        CIRCLE(const vector<string>& tokens); // CIRCLE
        void output(ostream&) const;
    };

    class CYLINDER : public CIRCLE { // CYLINDER
    private:
        const double height;

    public:
        CYLINDER(const std::vector<std::string>& tokens);
        void output(std::ostream& os) const;
    };

    class TRIANGLE : public Shape { // TRIANGLE
    protected:
        const double side;

    public:
        TRIANGLE(const vector<string>& tokens);
        void output(ostream&) const;
    };
    class PRISM : public TRIANGLE { // PRISM
        const double height;

    public:
        PRISM(const vector<string>& tokens);
        void output(ostream&) const;
    };
}
#endif
