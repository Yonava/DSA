#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Shape
{
public:
  const float PI = 3.14159f; 
  virtual void Scale(float scaleFactor) = 0;
  virtual void Display() const = 0;
  virtual ~Shape() = 0;
};

class Shape2D : virtual public Shape
{
public:
  virtual float Area() const = 0;
  void ShowArea() const;
  virtual string GetName2D() const = 0;
  bool operator>(const Shape2D &rhs) const;
  bool operator<(const Shape2D &rhs) const;
  bool operator==(const Shape2D &rhs) const;
};

class Square : virtual public Shape2D
{
  float s;
  public:
    Square(float sideLength = 0);
    string GetName2D();
    float Area();
};

class Rectangle : virtual public Shape2D
{
  float l;
  float w;
  public:
    Rectangle(float width = 0, float length = 0);
    string GetName2D();
    float Area();
};

class Triangle : virtual public Shape2D
{
  float b;
  float h;
  public:
    Triangle(float base = 0, float height = 0);
    string GetName2D();
    float Area();
};

class Circle : virtual public Shape2D
{
  float r;
  public:
    Circle(float radius = 0);
    string GetName2D();
    float Area();
};

class Ellipse : virtual public Shape2D
{
  float maj;
  float min;
  public:
    Ellipse(float majorAxis = 0, float minorAxis = 0);
    string GetName2D();
    float Area();
};

class Trapezoid : virtual public Shape2D
{
  float a;
  float b;
  float h;
  public:
    Trapezoid(float sideA = 0, float sideB = 0, float height = 0);
    string GetName2D();
    float Area();
};

class Sector : virtual public Shape2D
{
  float r;
  float a;
  public:
    Sector(float radius = 0, float angleInDegrees = 0);
    string GetName2D();
    float Area();
};

class Shape3D : virtual public Shape
{
public:
  virtual float Volume() const = 0;
  void ShowVolume() const;
  virtual string GetName3D() const = 0;
  bool operator>(const Shape3D &rhs) const;
  bool operator<(const Shape3D &rhs) const;
  bool operator==(const Shape3D &rhs) const;
};