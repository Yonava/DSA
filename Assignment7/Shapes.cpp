#include "Shapes.h"

void Shape2D::ShowArea() {
  cout << "Area of " << GetName2D() << " is: " << Area();
}

Square::Square(float sideLength) {
  s = sideLength;
}

float Square::Area() {
  return s * s;
}

string Square::GetName2D() {
  return "Square";
}

Rectangle::Rectangle(float width, float length) {
  w = width;
  l = length;
}

float Rectangle::Area() {
  return w * l;
}

string Rectangle::GetName2D() {
  return "Rectangle";
}

Triangle::Triangle(float base, float height) {
  b = base;
  h = height;
}

float Triangle::Area() {
  return (b * h) / 2;
}

string Triangle::GetName2D() {
  return "Triangle";
}

Circle::Circle(float radius) {
  r = radius;
}

float Circle::Area() {
  return r * r * PI;
}

string Circle::GetName2D() {
  return "Circle";
}

Ellipse::Ellipse(float majorAxis, float minorAxis) {
  maj = majorAxis;
  min = minorAxis;
}

float Ellipse::Area() {
  return maj * min * PI;
}

string Ellipse::GetName2D() {
  return "Ellipse";
}

Trapezoid::Trapezoid(float sideA, float sideB, float height) {
  a = sideA;
  b = sideB;
  h = height;
}

float Trapezoid::Area() {
  return .5 * (a + b) * h;
}

string Trapezoid::GetName2D() {
  return "Trapezoid";
}

Sector::Sector(float radius, float angleInDegrees) {
  r = radius;
  a = angleInDegrees;
}

float Sector::Area() {
  return  .5 * r * r * a;
}

string Sector::GetName2D() {
  return "Sector";
}