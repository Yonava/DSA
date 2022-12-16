#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

// Global Constants
const float PI = 3.14159f;

// Base Class
class Shape
{
public:
  virtual void Scale(float scaleFactor) = 0;
  virtual void Display() const = 0;
};

// Virtual Base Classes
class Shape2D : virtual public Shape
{
public:
  virtual float Area() const = 0;
  void ShowArea() const;
  virtual string GetName2D() const = 0;
  void Display() const;
  bool operator>(const Shape2D &rhs) const;
  bool operator<(const Shape2D &rhs) const;
  bool operator==(const Shape2D &rhs) const;
};

// Virtual Base Classes
class Shape3D : virtual public Shape
{
public:
  virtual float Volume() const = 0;
  void ShowVolume() const;
  virtual string GetName3D() const = 0;
  void Display() const;
  bool operator>(const Shape3D &rhs) const;
  bool operator<(const Shape3D &rhs) const;
  bool operator==(const Shape3D &rhs) const;
};

// 2D Shapes Classes
class Square : virtual public Shape2D
{
private:
  float side;

public:
  Square(float side = 0) : side(side) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

// 2D Shapes Classes
class Rectangle : virtual public Shape2D
{
private:
  float width, height;

public:
  Rectangle(float width = 0, float height = 0) : width(width), height(height) {}
  // outputs the area of the rectangle
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

// 2D Shapes Classes
class Triangle : virtual public Shape2D
{
private:
  float base, height;

public:
  // use 0 as the default values for base and height
  Triangle(float base = 0, float height = 0) : base(base), height(height) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Circle : virtual public Shape2D
{
private:
  float radius;

public:
  Circle(float radius = 0) : radius(radius) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Ellipse : virtual public Shape2D
{
private:
  float major, minor;

public:
  Ellipse(float major = 0, float minor = 0) : major(major), minor(minor) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Trapezoid : virtual public Shape2D
{
private:
  float aside, bside, height;

public:
  Trapezoid(float aside = 0, float bside = 0, float height = 0) : aside(aside), bside(bside), height(height) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Sector : virtual public Shape2D
{
private:
  // angle in degrees
  float radius, angle;

public:
  Sector(float radius = 0, float angle = 0) : radius(radius), angle(angle) {}
  float Area() const;
  void Scale(float scaleFactor);
  float degreesToRadians(float degrees) const;
  string GetName2D() const;
};

//  3D Shapes Classes

class TriangularPyramid : public Shape3D, private Triangle
{
private:
  float height;

public:
  TriangularPyramid(float height = 0, float baselen = 0, float baseheight = 0) : height(height), Triangle(baselen, baseheight) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class RectangularPyramid : public Shape3D, private Rectangle
{
private:
  float height;

public:
  RectangularPyramid(float height = 0, float basewidth = 0, float baseheight = 0) : height(height), Rectangle(basewidth, baseheight) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class Cylinder : public Shape3D, private Circle
{
private:
  float height;

public:
  // borrows the radius from Circle
  Cylinder(float height = 0, float radius = 0) : height(height), Circle(radius) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class Sphere : public Shape3D, private Circle
{
private:
  // radius is inherited from Circle
  float radius;

public:
  Sphere(float radius = 0) : radius(radius), Circle(radius) {}
  // Volume() is inherited from Shape3D
  float Volume() const;
  // Scale() is inherited from Shape
  void Scale(float scaleFactor);
  // GetName3D() is inherited from Shape3D
  string GetName3D() const;
  // Display() is inherited from Shape
  void Display() const;
};