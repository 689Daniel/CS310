/*
   Author:         Lane Dorscher
   Date:           05/13/2026
   Assignment:     M9: Discussion

   Program Assignment: 
   Create a simple C++ program using inheritance with a base class and at least two child classes and at least two errors. 
   The program should not execute and there should be at least two errors in the code.

   Program Description:
   This program showcases inheritance and polymorphism. Using inheritance, child shape classes implement their own interpretation of DrawShape
   to output to draw themselves to the console. It uses the default fonts so to make the shapes less distorted, the characters are doubled up.
*/
/*
 * Modified by Daniel Preller
 * 5/14/2026
*/

#include <iostream>
#include <string>

using namespace std;


// classes
class Shape
{
    // Daniel Preller: Added colons after access modifiers to comply with syntax
    protected: int length;
    protected: int width;


    public: Shape(int l, int w) : length(l), width(w) { }
    public: virtual ~Shape() = default;
    public: virtual void DrawShape() const = 0;
    public: virtual std::string GetDimensions() const
    {
        // Daniel Preller: added std::to_string() function around ints to properly cast them to strings for concatenation
        return "Length: " + std::to_string(length)  +
            ", Width: " + std::to_string(width);
    }
};

class Rectangle : public Shape
{

    // Daniel Preller: Added colons after access modifiers to comply with syntax
    public: Rectangle(int l, int w) : Shape(l, w)
    {
        
    }

    public: void DrawShape() const override
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
        return "Radius: " + std::to_string(radius);// Daniel Preller: Added to_string function call to display radius
    }
};


int main()
{
    Rectangle rectangle(5, 10);
    Rectangle square(10, 10);
    Circle circle(10);

    cout << "The rectangle's dimensions: " << rectangle.GetDimensions() << endl;
    rectangle.DrawShape();
    cout << endl << endl;
    cout << "The squares's dimensions: " << square.GetDimensions() << endl;
    square.DrawShape();
    cout << endl << endl;
    cout << "The circle's dimensions: " << circle.GetDimensions() << endl;
    circle.DrawShape();

    cin.get();

    return 0;
}