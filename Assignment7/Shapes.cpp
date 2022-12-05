#include "Shapes.h"

//  2D SHAPES
void Shape2D::ShowArea() const
{
  printf("Area: %f", this->Area());
}

void Shape2D::Display() const
{
  printf("%s (", this->GetName2D().c_str());
  this->ShowArea();
  printf(")\n");
}

bool Shape2D::operator>(const Shape2D &rhs) const
{
  return (this->Area() > rhs.Area());
}

bool Shape2D::operator<(const Shape2D &rhs) const
{
  return (this->Area() < rhs.Area());
}

bool Shape2D::operator==(const Shape2D &rhs) const
{
  return (this->Area() == rhs.Area());
}

//  3D SHAPES
void Shape3D::ShowVolume() const
{
  printf("Volume: %f", this->Volume());
}

void Shape3D::Display() const
{
  printf("%s (", this->GetName3D().c_str());
  this->ShowVolume();
  printf(")\n");
}

bool Shape3D::operator>(const Shape3D &rhs) const
{
  return (this->Volume() > rhs.Volume());
}

bool Shape3D::operator<(const Shape3D &rhs) const
{
  return (this->Volume() < rhs.Volume());
}

bool Shape3D::operator==(const Shape3D &rhs) const
{
  return (this->Volume() == rhs.Volume());
}

//  SQUARE
float Square::Area() const
{
  return this->side * this->side;
}

void Square::Scale(float scaleFactor)
{
  this->side *= scaleFactor;
}

string Square::GetName2D() const
{
  return "Square";
}

//  RECTANGLE
float Rectangle::Area() const
{
  return this->width * this->height;
}

void Rectangle::Scale(float scaleFactor)
{
  this->width *= scaleFactor;
  this->height *= scaleFactor;
}

string Rectangle::GetName2D() const
{
  return "Rectangle";
}

//  TRIANGLE
float Triangle::Area() const
{
  return 0.5f * this->base * this->height;
}

void Triangle::Scale(float scaleFactor)
{
  this->base *= scaleFactor;
  this->height *= scaleFactor;
}

string Triangle::GetName2D() const
{
  return "Triangle";
}

//  CIRCLE
float Circle::Area() const
{
  return PI * this->radius * this->radius;
}

void Circle::Scale(float scaleFactor)
{
  this->radius *= scaleFactor;
}

string Circle::GetName2D() const
{
  return "Circle";
}

//  ELLIPSE
float Ellipse::Area() const
{
  // Semi-major and semi-minor axes are half the length of the axes
  return PI * (this->major / 2) * (this->minor / 2);
}

void Ellipse::Scale(float scaleFactor)
{
  this->major *= scaleFactor;
  this->minor *= scaleFactor;
}

string Ellipse::GetName2D() const
{
  return "Ellipse";
}

//  TRAPEZOID
float Trapezoid::Area() const
{
  return ((this->aside + this->bside) * this->height) / 2;
}

void Trapezoid::Scale(float scaleFactor)
{
  this->aside *= scaleFactor;
  this->bside *= scaleFactor;
  this->height *= scaleFactor;
}

string Trapezoid::GetName2D() const
{
  return "Trapezoid";
}

//  SECTOR
float Sector::Area() const
{
  return 0.5f * this->radius * this->radius * this->degreesToRadians(this->angle);
}

void Sector::Scale(float scaleFactor)
{
  this->radius *= scaleFactor;
}

float Sector::degreesToRadians(float degrees) const
{
  return degrees * PI / 180;
}

string Sector::GetName2D() const
{
  return "Sector";
}

//  TRIANGULAR PYRAMID
float TriangularPyramid::Volume() const
{
  return this->Triangle::Area() * this->height / 3;
}

void TriangularPyramid::Scale(float scaleFactor)
{
  this->height *= scaleFactor;
  this->Triangle::Scale(scaleFactor);
}

string TriangularPyramid::GetName3D() const
{
  return "Triangular Pyramid";
}

void TriangularPyramid::Display() const
{
  Shape3D::Display();
}

//  RECTANGULAR PYRAMID
float RectangularPyramid::Volume() const
{
  return this->Rectangle::Area() * this->height / 3;
}

void RectangularPyramid::Scale(float scaleFactor)
{
  this->height *= scaleFactor;
  this->Rectangle::Scale(scaleFactor);
}

string RectangularPyramid::GetName3D() const
{
  return "Rectangular Pyramid";
}

void RectangularPyramid::Display() const
{
  Shape3D::Display();
}

//  CYLINDER
float Cylinder::Volume() const
{
  return this->Circle::Area() * this->height;
}

void Cylinder::Scale(float scaleFactor)
{
  this->height *= scaleFactor;
  this->Circle::Scale(scaleFactor);
}

string Cylinder::GetName3D() const
{
  return "Cylinder";
}

void Cylinder::Display() const
{
  Shape3D::Display();
}

//  SPHERE
float Sphere::Volume() const
{
  return 4 * this->radius * this->Circle::Area() / 3;
}

void Sphere::Scale(float scaleFactor)
{
  this->radius *= scaleFactor;
  this->Circle::Scale(scaleFactor);
}

string Sphere::GetName3D() const
{
  return "Sphere";
}

void Sphere::Display() const
{
  Shape3D::Display();
}