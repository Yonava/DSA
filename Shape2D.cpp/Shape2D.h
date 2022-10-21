class Shape2D {
  public:
    virtual float Area() {
      return 0.0f;
    }
};

class Square : public Shape2D {
  float side_;
  public:
    Square(float s);
    float Area();
};

class Rect : public Shape2D {
  float length_;
  float width_;
  public:
    Rect(float l, float w);
    float Area();
};