#include "Shapes.h"

//  2D SHAPES
void Shape2D::ShowArea() const {
    cout << "Area: " << this->Area();
}

void Shape2D::Display() const {
    cout << this->GetName2D() << " (";
    this->ShowArea();
    cout << ")";
}

bool Shape2D::operator>(const Shape2D& rhs) const {
    if (this->Area() > rhs.Area()) return true;
    return false;
}

bool Shape2D::operator<(const Shape2D& rhs) const {
    if (this->Area() < rhs.Area()) return true;
    return false;
}

bool Shape2D::operator==(const Shape2D& rhs) const {
    if (this->Area() == rhs.Area()) return true;
    return false;
}

//  3D SHAPES
void Shape3D::ShowVolume() const {
    cout << "Volume: " << this->Volume();
}

void Shape3D::Display() const {
    cout << this->GetName3D() << " (";
    this->ShowVolume();
    cout << ")";
}

bool Shape3D::operator>(const Shape3D& rhs) const {
    if (this->Volume() > rhs.Volume()) return true;
    return false;
}

bool Shape3D::operator<(const Shape3D& rhs) const {
    if (this->Volume() < rhs.Volume()) return true;
    return false;
}

bool Shape3D::operator==(const Shape3D& rhs) const {
    if (this->Volume() == rhs.Volume()) return true;
    return false;
}

//  SQUARE
float Square::Area() const {
    return this->side_ * this->side_;
}

void Square::Scale(float scaleFactor) {
    this->side_ *= scaleFactor;
}

string Square::GetName2D() const {
    return "Square";
}

//  RECTANGLE
float Rectangle::Area() const {
    return this->width_ * this->height_;
}

void Rectangle::Scale(float scaleFactor) {
    this->width_ *= scaleFactor;
    this->height_ *= scaleFactor;
}

string Rectangle::GetName2D() const {
    return "Rectangle";
}

//  TRIANGLE
float Triangle::Area() const {
    return 0.5f * this->base_ * this->height_; 
}

void Triangle::Scale(float scaleFactor) {
    this->base_ *= scaleFactor;
    this->height_ *= scaleFactor;
}

string Triangle::GetName2D() const {
    return "Triangle";
}

//  CIRCLE
float Circle::Area() const {
    return PI * this->radius_ * this->radius_;
}

void Circle::Scale(float scaleFactor) {
    this->radius_ *= scaleFactor;
}

string Circle::GetName2D() const {
    return "Circle";
}

//  ELLIPSE
float Ellipse::Area() const {
    // Semi-major and semi-minor axes are half the length of the axes
    return PI * (this->major_ / 2) * (this->minor_ / 2);
}

void Ellipse::Scale(float scaleFactor) {
    this->major_ *= scaleFactor;
    this->minor_ *= scaleFactor;
}

string Ellipse::GetName2D() const {
    return "Ellipse";
}

//  TRAPEZOID
float Trapezoid::Area() const {
    return ((this->aside_ + this->bside_) * this->height_) / 2;
}

void Trapezoid::Scale(float scaleFactor) {
    this->aside_ *= scaleFactor;
    this->bside_ *= scaleFactor;
    this->height_ *= scaleFactor;
}

string Trapezoid::GetName2D() const {
    return "Trapezoid";
}

//  SECTOR
float Sector::Area() const {
    return 0.5f * this->radius_ * this->radius_ * this->degreesToRadians(this->angle_);
}

void Sector::Scale(float scaleFactor) {
    this->radius_ *= scaleFactor;
}

float Sector::degreesToRadians(float degrees) const {
    return degrees * PI / 180;
}

string Sector::GetName2D() const {
    return "Sector";
}

//  TRIANGULAR PYRAMID
float TriangularPyramid::Volume() const {
    return this->Triangle::Area() * this->height_ / 3;
}

void TriangularPyramid::Scale(float scaleFactor) {
    this->height_ *= scaleFactor;
    this->Triangle::Scale(scaleFactor);
}

string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid";
}

void TriangularPyramid::Display() const {
    Shape3D::Display();
}

//  RECTANGULAR PYRAMID
float RectangularPyramid::Volume() const {
    return this->Rectangle::Area() * this->height_ / 3;
}

void RectangularPyramid::Scale(float scaleFactor) {
    this->height_ *= scaleFactor;
    this->Rectangle::Scale(scaleFactor);
}

string RectangularPyramid::GetName3D() const {
    return "Rectangular Pyramid";
}

void RectangularPyramid::Display() const {
    Shape3D::Display();
}

//  CYLINDER
float Cylinder::Volume() const {
    return this->Circle::Area() * this->height_;
}

void Cylinder::Scale(float scaleFactor) {
    this->height_ *= scaleFactor;
    this->Circle::Scale(scaleFactor);
}

string Cylinder::GetName3D() const {
    return "Cylinder";
}

void Cylinder::Display() const {
    Shape3D::Display();
}

//  SPHERE
float Sphere::Volume() const {
    return 4 * this->radius_ * this->Circle::Area() / 3;
}

void Sphere::Scale(float scaleFactor) {
    this->radius_ *= scaleFactor;
    this->Circle::Scale(scaleFactor);
}

string Sphere::GetName3D() const {
    return "Sphere";
}

void Sphere::Display() const {
    Shape3D::Display();
}