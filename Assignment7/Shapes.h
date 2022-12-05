#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

const float PI = 3.14159f;

class Shape
{
public:
  virtual void Scale(float scaleFactor) = 0;
  virtual void Display() const = 0;
};

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

//  2D SHAPES
class Square : virtual public Shape2D
{
private:
  float side_;

public:
  Square(float side = 0) : side_(side) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Rectangle : virtual public Shape2D
{
private:
  float width_, height_;

public:
  Rectangle(float width = 0, float height = 0) : width_(width), height_(height) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Triangle : virtual public Shape2D
{
private:
  float base_, height_;

public:
  Triangle(float base = 0, float height = 0) : base_(base), height_(height) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Circle : virtual public Shape2D
{
private:
  float radius_;

public:
  Circle(float radius = 0) : radius_(radius) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Ellipse : virtual public Shape2D
{
private:
  float major_, minor_;

public:
  Ellipse(float major = 0, float minor = 0) : major_(major), minor_(minor) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Trapezoid : virtual public Shape2D
{
private:
  float aside_, bside_, height_;

public:
  Trapezoid(float aside = 0, float bside = 0, float height = 0) : aside_(aside), bside_(bside), height_(height) {}
  float Area() const;
  void Scale(float scaleFactor);
  string GetName2D() const;
};

class Sector : virtual public Shape2D
{
private:
  // The angle is in degrees
  float radius_, angle_;

public:
  Sector(float radius = 0, float angle = 0) : radius_(radius), angle_(angle) {}
  float Area() const;
  void Scale(float scaleFactor);
  float degreesToRadians(float degrees) const;
  string GetName2D() const;
};

//  3D SHAPES
class TriangularPyramid : public Shape3D, private Triangle
{
private:
  float height_;

public:
  TriangularPyramid(float height = 0, float baselen = 0, float baseheight = 0) : height_(height), Triangle(baselen, baseheight) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class RectangularPyramid : public Shape3D, private Rectangle
{
private:
  float height_;

public:
  RectangularPyramid(float height = 0, float basewidth = 0, float baseheight = 0) : height_(height), Rectangle(basewidth, baseheight) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class Cylinder : public Shape3D, private Circle
{
private:
  float height_;

public:
  Cylinder(float height = 0, float radius = 0) : height_(height), Circle(radius) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};

class Sphere : public Shape3D, private Circle
{
private:
  float radius_;

public:
  Sphere(float radius = 0) : radius_(radius), Circle(radius) {}
  float Volume() const;
  void Scale(float scaleFactor);
  string GetName3D() const;
  void Display() const;
};