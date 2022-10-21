#include "Shape2D.h"

// square
Square::Square(float s) {
  side_ = s;
}

float Square::Area() {
  return side_ * side_;
}

// rect
Rect::Rect(float l, float w) {
  length_ = l;
  width_ = w;
}

float Rect::Area() {
  return 0.5f * length_ * width_;
}