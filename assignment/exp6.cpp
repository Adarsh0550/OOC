#include <iostream>
using namespace std;

// Function prototypes for overloading area function
int area(int);
int area(int, int);
float area(float);
float area(float, float);

int main() {
    int s, l, b;
    float r, bs, ht;

    // Taking user inputs
    cout << "Enter side of a square: ";
    cin >> s;

    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;

    cout << "Enter radius of circle: ";
    cin >> r;

    cout << "Enter base and height of triangle: ";
    cin >> bs >> ht;

    // Displaying calculated areas
    cout << "\nArea of square is: " << area(s) << endl;
    cout << "Area of rectangle is: " << area(l, b) << endl;
    cout << "Area of circle is: " << area(r) << endl;
    cout << "Area of triangle is: " << area(bs, ht) << endl;

    return 0;
}

// Function definitions
int area(int s) { 
    return (s * s); 
}

int area(int l, int b) { 
    return (l * b); 
}

float area(float r) { 
    return (3.14f * r * r); 
}

float area(float bs, float ht) { 
    return ((bs * ht) / 2.0f); 
}
