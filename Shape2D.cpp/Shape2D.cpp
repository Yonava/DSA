#include "Shape2D.h"

// square
float Shape2D::Area(float s) {
  return s * s;
}

// triangle
float Shape2D::Area(float b, float h) {
  return 0.5f * b * h;
}

// trapezoid
float Shape2D::Area(float a, float b, float h) {
  return ((a + b) / 2) * h;
}