/*
   Author:         Lane Dorscher
   Date:           05/22/2026
   Assignment:     M10: Discussion

   Program Assignment: 
   Create a simple C++ program using pointers and at least two errors. The program should 
   not execute and there should be at least two errors in the code.
.

   Program Description:
   This program is a continuation of M9: Discussion and demonstrates the use of pointers,
   inheritance, and polymorphism in C++. Shape objects are dynamically allocated using
   base class pointers and child classes override DrawShape() to display their own shapes
   in the console. The program uses pointer dereferencing and arrow operators to access
   object members and methods through Shape pointers.
*/
/*
 * Modified by Daniel Preller
 * 5/23/2026
*/

#include <iostream>
#include <string>

using namespace std;// Daniel Preller: Added namespace declaration

// classes
class Shape
{
protected:
    int length;
    int width;

public:
    Shape(int l, int w) : length(l), width(w) { }
    virtual ~Shape() = default;
    virtual void DrawShape() const = 0;
    virtual std::string GetDimensions() const
    {
        return "Length: " + to_string(length) +
            ", Width: " + to_string(width);
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int l, int w) : Shape(l, w)
    {
        
    }

    void DrawShape() const override
    {
        string shapeStr = "";
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                shapeStr += "##";
            }
            shapeStr += "\n";
        }
        cout << shapeStr;
    }

    
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int l) : Shape(l, l), radius(l/2) { }

    void DrawShape() const override
    {
        float cx = width / 2.0f;
        float cy = length / 2.0f;

        float rx = width / 2.0f;
        float ry = length / 2.0f;

        for (int y = 0; y < length; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float dx = (x + 0.5f - cx) / rx;
                float dy = (y + 0.5f - cy) / ry;

                if (dx * dx + dy * dy <= 1.0f)
                    std::cout << "##";
                else 
                    std::cout << "  ";
            }
            std::cout << "\n";
        }
    }

    std::string GetDimensions() const override
    {
        return "Radius: " + to_string(radius);
    }
};


int main()
{
    Shape *rectangle = new Rectangle(10, 20);
    Shape *square = new Rectangle(5, 5);
    Shape *circle = new Circle(5);

    // Daniel preller
    cout << "The rectangle's dimensions: " << rectangle->GetDimensions() << endl;
    rectangle->DrawShape();
    cout << endl << endl;
    cout << "The squares's dimensions: " << square->GetDimensions() << endl;
    square->DrawShape();
    cout << endl << endl;
    cout << "The circle's dimensions: " << circle->GetDimensions() << endl;
    circle->DrawShape();

    cin.get();

    return 0;
}