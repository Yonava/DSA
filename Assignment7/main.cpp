#include <iostream>
#include <vector>
#include "Shapes.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Create with test data
void make2D(vector<Shape2D*>& shapes2D);
void make3D(vector<Shape3D*>& shapes3D);
// Test the shapes' display function
void test2D(vector<Shape2D*>& shapes2D);
void test3D(vector<Shape3D*>& shapes3D);
// Test scaling on the shapes
void scaleShapes2D(vector<Shape2D*>& shapes);
void scaleShapes3D(vector<Shape3D*>& shapes);
// Insertion sort
void insertionSort2D(vector<Shape2D*>& shapes);
void insertionSort3D(vector<Shape3D*>& shapes);
// Binary search
int binarySearch2D(vector<Shape2D*>& shapes, float area, int low, int high);
int binarySearch3D(vector<Shape3D*>& shapes, float volume, int low, int high);

int main() {
    vector<Shape2D*> shapes2D;
    vector<Shape3D*> shapes3D;
    float searchVal;
    int select, result;
    bool quit = false;

    make2D(shapes2D);
    make3D(shapes3D);

    while (!quit) {
        cout << "Shape Tester: " << endl;
        cout << "1. Test 2D Shapes" << endl;
        cout << "2. Test 3D Shapes" << endl;
        cout << "3. Scale 2D Shapes" << endl;
        cout << "4. Scale 3D Shapes" << endl;
        cout << "5. Sort 2D Shapes" << endl;
        cout << "6. Sort 3D Shapes" << endl;
        cout << "7. Search 2D Shapes for an area" << endl;
        cout << "8. Search 3D Shapes for a volume" << endl;
        cout << "9. Display smallest/largest 2D shapes" << endl;
        cout << "10. Display smallest/largest 3D shapes" << endl;
        cout << "11. Exit" << endl << endl;
        cout << "Select: ";
        cin >> select;

        switch(select) {
            case 1:
                test2D(shapes2D);
                break;
            case 2:
                test3D(shapes3D);
                break;
            case 3:
                cout << endl;
                scaleShapes2D(shapes2D);
                cout << endl;
                break;
            case 4:
                cout << endl;
                scaleShapes3D(shapes3D);
                cout << endl;
                break;
            case 5:
                cout << "Sorting 2D Shapes..." << endl;
                insertionSort2D(shapes2D);
                for (unsigned int i = 0; i < shapes2D.size(); i++) {
                    shapes2D[i]->Display();
                    cout << endl;
                }
                cout << endl;
                break;
            case 6:
                cout << "Sorting 3D Shapes..." << endl;
                insertionSort3D(shapes3D);
                for (unsigned int i = 0; i < shapes3D.size(); i++) {
                    shapes3D[i]->Display();
                    cout << endl;
                }
                cout << endl;
                break;
            case 7:
                cout << "Enter an Area to search for: ";
                cin >> searchVal;
                // Ensure list is sorted first
                insertionSort2D(shapes2D);
                result = binarySearch2D(shapes2D, searchVal, 0, shapes2D.size());
                if (result == -1)
                    cout << "No 2D Shape found with Area " << searchVal;
                else {
                    cout << "2D Shape with Area " << searchVal << " found at index " << result << endl;
                    cout << "\t";
                    shapes2D[result]->Display();
                }
                cout << endl << endl;
                break;
            case 8:
                cout << "Enter a Volume to search for: ";
                cin >> searchVal;
                // Ensure list is sorted first
                insertionSort3D(shapes3D);
                result = binarySearch3D(shapes3D, searchVal, 0, shapes3D.size());
                if (result == -1)
                    cout << "No 3D Shape found with Volume " << searchVal;
                else {
                    cout << "3D Shape with Area " << searchVal << " found at index " << result << endl;
                    cout << "\t";
                    shapes3D[result]->Display();
                }
                cout << endl << endl;
                break;
            case 9:
                // Make sure list is sorted
                insertionSort2D(shapes2D);
                cout << "Smallest 2D Shape: ";
                shapes2D[0]->Display();
                cout << endl << "Largest 2D Shape: ";
                shapes2D[shapes2D.size() - 1]->Display();
                cout << endl << endl;
                break;
            case 10:
                // Make sure list is sorted
                insertionSort3D(shapes3D);
                cout << "Smallest 3D Shape: ";
                shapes3D[0]->Display();
                cout << endl << "Largest 3D Shape: ";
                shapes3D[shapes3D.size() - 1]->Display();
                cout << endl << endl;
                break;
            case 11:
                quit = true;
                break;
            default:
                cout << "Error: Invalid input";
                break;
        }
    }

    for (unsigned int i = 0; i < shapes2D.size(); i++)
        delete shapes2D[i];
    for (unsigned int i = 0; i < shapes3D.size(); i++)
        delete shapes3D[i];

    return 0;
}

void make2D(vector<Shape2D*>& shapes2D) {
    shapes2D.push_back(new Square);
    shapes2D.push_back(new Square(3.4));
    shapes2D.push_back(new Square(8.7));
    shapes2D.push_back(new Square(9));
    shapes2D.push_back(new Rectangle);
    shapes2D.push_back(new Rectangle(2.3, 1.4));
    shapes2D.push_back(new Triangle);
    shapes2D.push_back(new Triangle(1.3, 4.5));
    shapes2D.push_back(new Triangle(1.1, 1.1));
    shapes2D.push_back(new Circle);
    shapes2D.push_back(new Circle(1.3));
    shapes2D.push_back(new Circle(0.2));
    shapes2D.push_back(new Trapezoid);
    shapes2D.push_back(new Trapezoid(0.01, 3.9, 1.0));
    shapes2D.push_back(new Trapezoid(1.2, 1.3, 1.54));
    shapes2D.push_back(new Ellipse);
    shapes2D.push_back(new Ellipse(1.2, 4.5));
    shapes2D.push_back(new Sector);
    shapes2D.push_back(new Sector(1.3, 60));
}

void make3D(vector<Shape3D*>& shapes3D) {
    shapes3D.push_back(new TriangularPyramid);
    shapes3D.push_back(new TriangularPyramid(1.3, 2.3, 4.5));
    shapes3D.push_back(new TriangularPyramid(3.1, 1.1, 2.00));
    shapes3D.push_back(new TriangularPyramid(44.2, 32.1, 5.8));    
    shapes3D.push_back(new RectangularPyramid);
    shapes3D.push_back(new RectangularPyramid(1.3, 2.4, 5.6));
    shapes3D.push_back(new Cylinder);
    shapes3D.push_back(new Cylinder(1.3, 4.5));
    shapes3D.push_back(new Cylinder(9.8, 1.2));
    shapes3D.push_back(new Sphere);
    shapes3D.push_back(new Sphere(4.5));
    shapes3D.push_back(new Sphere(0.05));
}

void test2D(vector<Shape2D*>& shapes2D) {
    for (unsigned int i = 0; i < shapes2D.size(); i++) {
        shapes2D[i]->Display();
        cout << endl;
    }
    cout << endl;
}

void test3D(vector<Shape3D*>& shapes3D) {
    for (unsigned int i = 0; i < shapes3D.size(); i++) {
        shapes3D[i]->Display();
        cout << endl;
    }
    cout << endl;
}

void scaleShapes2D(vector<Shape2D*>& shapes) {
    float scaleFactor;
    cout << "Enter scale factor: ";
    cin >> scaleFactor;

    cout << "Scaling..." << endl << endl;
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->Scale(scaleFactor);
        shapes[i]->Display();
        cout << endl;
    }
}

void scaleShapes3D(vector<Shape3D*>& shapes) {
    float scaleFactor;
    cout << "Enter scale factor: ";
    cin >> scaleFactor;

    cout << "Scaling..." << endl << endl;
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->Scale(scaleFactor);
        shapes[i]->Display();
        cout << endl;
    }
}

void insertionSort2D(vector<Shape2D*>& shapes) {
    int i, j;
    Shape2D* hold;
    for(i = 1; i < shapes.size(); i++) {
        hold = shapes[i];
        j = i - 1;

        while (j >= 0 && shapes[j]->Area() > hold->Area()) {
            shapes[j + 1] = shapes[j];
            j--;
        }
        shapes[j + 1] = hold;
    }
}

void insertionSort3D(vector<Shape3D*>& shapes) {
    int i, j;
    Shape3D* hold;
    for(i = 1; i < shapes.size(); i++) {
        hold = shapes[i];
        j = i - 1;

        while (j >= 0 && shapes[j]->Volume() > hold->Volume()) {
            shapes[j + 1] = shapes[j];
            j--;
        }
        shapes[j + 1] = hold;
    }
}

int binarySearch2D(vector<Shape2D*>& shapes, float area, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (shapes[mid]->Area() == area)
            return mid;
        if (shapes[mid]->Area() < area)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch3D(vector<Shape3D*>& shapes, float volume, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (shapes[mid]->Volume() == volume)
            return mid;
        if (shapes[mid]->Volume() < volume)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}