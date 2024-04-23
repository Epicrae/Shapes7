// iShapes.cpp
#include "pch.h"
#include "pShapes.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
using namespace comsc;

// class function implementations
// SQUARE and CUBE
SQUARE::SQUARE(const vector<string> &tokens)
    : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

void SQUARE::output(ostream &out) const {
  const double area = side * side; // Calculate the area of a square
  const double perimeter = 4 * side;
  out << "SQUARE side=" << side << " area=" << area
      << " Perimeter=" << perimeter << endl;
}

CUBE::CUBE(const vector<string> &tokens) : SQUARE(tokens) {}

void CUBE::output(ostream &out) const {
  double volume = pow(side, 3);          // Calculate the volume of a cube
  double surfaceArea = 6 * pow(side, 2); // Calculate the surface area
  out << "CUBE side=" << side << " volume=" << fixed << setprecision(2)
      << volume << " surface area=" << surfaceArea << endl;
}

// RECTANGLE and BOX
RECTANGLE::RECTANGLE(const vector<string> &tokens)
    : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
      width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}

void RECTANGLE::output(ostream &out) const {
  double area =
      length * width; // Calculate the area of a rectangle (length * width)
  out << "RECTANGLE length=" << length << " width=" << width
      << " area=" << fixed << setprecision(2) << area << endl;
}

BOX::BOX(const vector<string> &tokens)
    : RECTANGLE(tokens),
      height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) {}

void BOX::output(ostream &out) const {
  double volume = length * width * height;
  double surfaceArea = 2 * (length * width + length * height + width * height);
  out << "BOX length=" << length << " width=" << width << " height=" << height
      << " surface area=" << fixed << setprecision(2) << surfaceArea
      << " volume=" << volume << endl;
}

// CIRCLE and CYLINDER
CIRCLE::CIRCLE(const vector<string> &tokens)
    : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

void CIRCLE::output(ostream &out) const {
  const double pi = 3.14159;
  double area = pi * radius * radius;
  double circumference = 2 * pi * radius;
  out << "CIRCLE radius=" << radius << " area=" << fixed << setprecision(2)
      << area << " circumference=" << circumference << endl;
}

CYLINDER::CYLINDER(const vector<string> &tokens)
    : CIRCLE(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}

void CYLINDER::output(ostream &out) const {
  const double pi = 3.14159;
  double volume = pi * radius * radius * height;
  double surfaceArea = 2 * pi * radius * (radius + height);
  out << "CYLINDER radius=" << radius << " height=" << height
      << " surface area=" << fixed << setprecision(2) << surfaceArea
      << " volume=" << volume << endl;
}

// TRIANGLE and PRISM
TRIANGLE::TRIANGLE(const vector<string> &tokens)
    : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

void TRIANGLE::output(ostream &out) const {
  const double area = (sqrt(3) / 4) * side * side;
  out << "Triangle side: " << side << " area: " << fixed << setprecision(2)
      << area << endl;
}

PRISM::PRISM(const vector<string> &tokens)
    : TRIANGLE(tokens),
      height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}

void PRISM::output(ostream &out) const {
  double baseArea = (sqrt(3) / 4) * side * side;
  double volume = baseArea * height;
  double surfaceArea = 2 * baseArea + 3 * side * height;
  out << "PRISM side=" << side << " height=" << height << " base area=" << fixed
      << setprecision(2) << baseArea << " volume=" << volume
      << " surface area=" << surfaceArea << endl;
}