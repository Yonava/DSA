#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Shape
{
public:
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