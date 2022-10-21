#include "Shape2D.h"

// square
float Square::Area() {
  return side_ * side_;
}

// rect
float Rect::Area() {
  return 0.5f * length_ * width_;
}