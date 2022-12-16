#include <stdio.h>
#include <iostream>
#include <vector>
#include "Shapes.h"

using std::getline;
using std::vector;

// function prototypes
void print2DShapes(vector<Shape2D *> &shapes2D);
void print3DShapes(vector<Shape3D *> &shapes3D);

void insertionSort2D(vector<Shape2D *> &shapes);
void insertionSort3D(vector<Shape3D *> &shapes);

void scaleShapes2D(vector<Shape2D *> &shapes);
void scaleShapes3D(vector<Shape3D *> &shapes);
void scaleShapesMixed(vector<Shape *> &shapes);

void scaleShapesMixed(vector<Shape *> &shapes) {
  std::string buffer;
  double scalar;

  std::printf("Enter scale factor: \n");
  getline(std::cin, buffer);

  scalar = std::stod(buffer);

  for (int i = 0; i < shapes.size(); i++) {
    shapes[i]->Scale(scalar);
    shapes[i]->Display();
    std::printf("\n");
  }
}

// prints the volume of each shape in the 3d shapes vector
void print3DShapes(vector<Shape3D *> &shapes3D)
{
  for (int i = 0; i < shapes3D.size(); i++)
  {
    shapes3D[i]->Display();
    std::printf("\n");
  }
  std::printf("\n");
}

// scales each shape in the shapes vector by the given scale factor
void scaleShapes2D(vector<Shape2D *> &shapes)
{
  std::string buffer;
  double scalar;

  std::printf("Enter scale factor: \n");
  getline(std::cin, buffer);

  scalar = std::stod(buffer);

  for (int i = 0; i < shapes.size(); i++)
  {
    shapes[i]->Scale(scalar);
    shapes[i]->Display();
    std::printf("\n");
  }
}

// scales each shape in the shapes vector by the given scale factor
void scaleShapes3D(vector<Shape3D *> &shapes)
{
  std::string buffer;
  double scalar;

  std::printf("Enter scale factor: \n");
  getline(std::cin, buffer);

  scalar = std::stod(buffer);

  for (int i = 0; i < shapes.size(); i++)
  {
    shapes[i]->Scale(scalar);
    shapes[i]->Display();
    std::printf("\n");
  }
}

// sorts the shapes vector by area
void insertionSort2D(vector<Shape2D *> &shapes)
{
  int secPos = 0;
  Shape2D* tempShape = nullptr;

  for (int posInShapes = 1; posInShapes < shapes.size(); posInShapes++)
  {
    tempShape = shapes[posInShapes];
    secPos = posInShapes - 1;

    while (secPos >= 0 && *shapes[secPos] > *tempShape)
    {
      shapes[secPos + 1] = shapes[secPos];
      secPos--;
    }
    shapes[secPos + 1] = tempShape;
  }

  tempShape = nullptr;
  delete tempShape;
}

// sorts the shapes vector by volume
void insertionSort3D(vector<Shape3D *> &shapes)
{
  int secPos = 0;
  Shape3D* tempShape = nullptr;

  for (int posInShapes = 1; posInShapes < shapes.size(); posInShapes++)
  {
    tempShape = shapes[posInShapes];
    secPos = posInShapes - 1;

    while (secPos >= 0 && *shapes[secPos] > *tempShape)
    {
      shapes[secPos + 1] = shapes[secPos];
      secPos--;
    }
    shapes[secPos + 1] = tempShape;
  }

  tempShape = nullptr;
  delete tempShape;
}

// https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
// Borrowed from here since I didn't know how to do the math!
float roundToTwoDecimals(const float area)
{
  float ret = static_cast<int>((area * 100) + 0.5);
  return static_cast<float>(ret / 100);
}

// performs a binary search on the shapes vector for the given area
int binarySearch2D(vector<Shape2D *> &shapes, float area, int low, int high)
{
  while (low <= high)
  {
    int mid = low + ((high - low) / 2);

    float midShapeArea = roundToTwoDecimals(shapes[mid]->Area());
    float searchArea = roundToTwoDecimals(area);

    if (midShapeArea == searchArea)
    {
      return mid;
    }
    if (midShapeArea < searchArea)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

// performs a binary search on the shapes vector for the given volume
int binarySearch3D(vector<Shape3D *> &shapes, float volume, int low, int high)
{
  while (low <= high)
  {
    int mid = low + ((high - low) / 2);

    float midShapeArea = roundToTwoDecimals(shapes[mid]->Volume());
    float searchArea = roundToTwoDecimals(volume);

    if (midShapeArea == searchArea)
    {
      return mid;
    }
    if (midShapeArea < searchArea)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

// creates 2d shape objects and adds them to the 2d shapes vector
void create2D(vector<Shape2D *> &shapes2D)
{
  shapes2D.push_back(new Square);
  shapes2D.push_back(new Square(2.5));

  shapes2D.push_back(new Rectangle);
  shapes2D.push_back(new Rectangle(2.5, 3.5));

  shapes2D.push_back(new Triangle);
  shapes2D.push_back(new Triangle(2.1, 3.0));

  shapes2D.push_back(new Circle);
  shapes2D.push_back(new Circle(2.3));

  shapes2D.push_back(new Trapezoid);
  shapes2D.push_back(new Trapezoid(2.2, 3.2, 4.1));

  shapes2D.push_back(new Ellipse);
  shapes2D.push_back(new Ellipse(2.0, 3.4));

  shapes2D.push_back(new Sector);
  shapes2D.push_back(new Sector(2.9, 3.0));
}

// creates 3d shape objects and adds them to the 3d shapes vector
void create3D(vector<Shape3D *> &shapes3D)
{
  shapes3D.push_back(new TriangularPyramid);
  shapes3D.push_back(new TriangularPyramid(4.1, 7.0, 6.8));

  shapes3D.push_back(new RectangularPyramid);
  shapes3D.push_back(new RectangularPyramid(0.5, 0.5, 0.5));

  shapes3D.push_back(new Cylinder);
  shapes3D.push_back(new Cylinder(9.9, 9.8));

  shapes3D.push_back(new Sphere);
  shapes3D.push_back(new Sphere(4.5));
}

// creates both 2d and 3d shape objects and adds them to the shapes vector
void createMixed(vector<Shape *> &shapes)
{
  shapes.push_back(new Square);
  shapes.push_back(new Square(2.5));

  shapes.push_back(new Rectangle);
  shapes.push_back(new Rectangle(2.5, 3.5));

  shapes.push_back(new Triangle);
  shapes.push_back(new Triangle(2.1, 3.0));

  shapes.push_back(new Circle);
  shapes.push_back(new Circle(2.3));

  shapes.push_back(new Trapezoid);
  shapes.push_back(new Trapezoid(2.2, 3.2, 4.1));

  shapes.push_back(new Ellipse);
  shapes.push_back(new Ellipse(2.0, 3.4));

  shapes.push_back(new Sector);
  shapes.push_back(new Sector(2.9, 3.0));

  shapes.push_back(new TriangularPyramid);
  shapes.push_back(new TriangularPyramid(4.1, 7.0, 6.8));

  shapes.push_back(new RectangularPyramid);
  shapes.push_back(new RectangularPyramid(0.5, 0.5, 0.5));

  shapes.push_back(new Cylinder);
  shapes.push_back(new Cylinder(9.9, 9.8));

  shapes.push_back(new Sphere);
  shapes.push_back(new Sphere(4.5));
}

// starts the program
int main()
{
  // Create vectors of 2D and 3D shapes
  vector<Shape2D *> shapes2D;
  vector<Shape3D *> shapes3D;

  // mixed shapes vector
  vector<Shape *> shapes;

  // menu loop variables
  float searchVal;
  std::string buffer;
  int select, result;
  bool quit = false;

  // Create test data
  create2D(shapes2D);
  create3D(shapes3D);
  createMixed(shapes);

  // Main menu
  while (!quit)
  {
    printf("Select An Option: \n");
    printf("1 - Print All 2 Dimensional Shapes\n");
    printf("2 - Scale All 2 Dimensional Shapes\n");
    printf("3 - Sort 2 Dimensional Shapes By Area\n");
    printf("4 - Find Index of 2 Dimensional Shape via Area\n");
    printf("5 - Print The Smallest and The Largest 2D Shape\n");
    printf("\n\n");
    printf("6 - Print All 3 Dimensional Shapes\n");
    printf("7 - Shrink/Enlarge All 3 Dimensional Shapes\n");
    printf("8 - Sort 3 Dimensional Shapes By Volume\n");
    printf("9 - Find Index of 3 Dimensional Shape via Volume\n");
    printf("10 - Print The Smallest and The Largest 3D Shape\n");    
    printf("\n\n");
    printf("11 - Scale Mixed Shapes\n");
    printf("12 - Sort Mixed Shapes By Area\n");
    printf("14 - Print The Smallest and The Largest Mixed Shape\n");
    printf("\n\n");
    printf("15 - Leave\n");

    getline(std::cin, buffer);
    select = std::stoi(buffer);

    switch (select)
    {
    case 1:
      print2DShapes(shapes2D);
      break;
    case 2:
      // scale all 2D shapes
      std::printf("\n");
      scaleShapes2D(shapes2D);
      std::printf("\n");
      break;
    case 3:
      // sort shapes by area
      insertionSort2D(shapes2D);
      for (int i = 0; i < shapes2D.size(); i++)
      {
        shapes2D[i]->Display();
        std::printf("\n");
      }
      std::printf("\n");
      break;
    case 4:
      // search shapes by area
      std::printf("Enter an Area to search for: ");
      getline(std::cin, buffer);
      searchVal = stod(buffer);

      // Ensure list is sorted first
      insertionSort2D(shapes2D);
      result = binarySearch2D(shapes2D, searchVal, 0, shapes2D.size());
      if (result == -1)
        printf("No 2D shape found with an area of %f\n", searchVal);
      else
      {
        printf("2D shape with area of %f found in position %d\t", searchVal, result);
        shapes2D[result]->Display();
      }
      printf("\n\n");
      break;
    case 5:
      // print smallest and largest 2D shapes
      insertionSort2D(shapes2D);
      printf("Smallest 2D Shape: \n");
      shapes2D[0]->Display();
      printf("Largest 2D Shape: \n");
      shapes2D[shapes2D.size() - 1]->Display();
      printf("\n\n");
      break;
    case 6:
      // print all 3D shapes
      print3DShapes(shapes3D);
      break;
    case 7:
      // scale all 3D shapes
      std::printf("\n");
      scaleShapes3D(shapes3D);
      std::printf("\n");
      break;
    case 8:
      // sort shapes by volume
      insertionSort3D(shapes3D);
      for (int i = 0; i < shapes3D.size(); i++)
      {
        shapes3D[i]->Display();
        std::printf("\n");
      }
      std::printf("\n");
      break;
    case 9:
      // search shapes by volume
      printf("Enter a volume to search for: \n");
      getline(std::cin, buffer);
      searchVal = stod(buffer);
      // Ensure list is sorted first
      insertionSort3D(shapes3D);
      result = binarySearch3D(shapes3D, searchVal, 0, shapes3D.size());
      if (result == -1)
        printf("No 3D shape found with an area of %f\n", searchVal);
      else
      {
        printf("3D shape with area of %f found in position %d\t", searchVal, result);
        shapes3D[result]->Display();
      }
      printf("\n\n");
      break;
    case 10:
      // print smallest and largest 3D shapes
      insertionSort3D(shapes3D);
      printf("Smallest 3D Shape: \n");
      shapes3D[0]->Display();
      printf("Largest 3D Shape: \n");
      shapes3D[shapes3D.size() - 1]->Display();
      printf("\n\n");
      break;
    case 11:
      // scale all mixed shapes
      std::printf("\n");
      scaleShapesMixed(shapes);
      std::printf("\n");
      break;
    case 15:
      // leave
      printf("Goodbye!\n");
      quit = true;
      break;
    default:
      printf("Invalid selection\n\n");
      break;
    }
  }

  // Free memory
  for (int i = 0; i < shapes2D.size(); i++)
  {
    delete shapes2D[i];
  }

  for (int i = 0; i < shapes3D.size(); i++)
  {
    delete shapes3D[i];
  }

  return 0;
}
