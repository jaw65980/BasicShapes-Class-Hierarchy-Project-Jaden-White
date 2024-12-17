

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
bool shaperectangle;

class BasicShape
{
public:

    virtual void SetName(float x, float y, float r, string n)
    {

    }

    virtual void CalcArea(double a, string n)
    {
        cout << "Name:" << n << endl;
        cout << "Area:" << a << setprecision(3) << endl;
    }

private:
    double area;
    string name;

};

class Circles : public BasicShape 
{
public:
    void SetName(float x, float y, float r, string n) override
    {
        double area = (3.14 * r) * (3.14 * r);
        BasicShape::CalcArea(area, n);
    }
private:

    float xCenter;
    float yCenter;
    float radius;

};

class Rectangle : private BasicShape
{
public:
    void SetName(float x, float y, float r, string n) override
    {
        float area = (x * y);
        BasicShape::CalcArea(area, n);
    }
private:
    float length;
    float width;
};

class Square : private Rectangle
{
public:
    void SetName(float x, float y, float r, string n) override
    {
        Rectangle::SetName(x, y, r, n);
    }
private:
    float side;
};

int main()
{
    float x;
    float y;
    float r;
    string n;

    float Objectx[5] = { 3, 6, 0, 0, 1 };
    float Objecty[5] = { 9, 3, 0, 0, 4 };
    float Objectr[5] = { 0, 0, 1, 2, 0 };
    string Objectn[5] = { "Rectangle", "Rectangle", "Circle", "Circle", "Square" };

    for (int i = 0; i <= 4; i++)
    {
        x = Objectx[i];
        y = Objecty[i];
        r = Objectr[i];
        n = Objectn[i];

        if (n == "Circle")
        {
            Circles circle;
            circle.SetName(x, y, r, n);
        }

        if (n == "Rectangle")
        {
            if (x == y)
            {
                Square square;
                square.SetName(x, y, r, n);
            }
            else
            {
                Rectangle rectangle;
                rectangle.SetName(x, y, r, n);
            }
        }

        if (n == "Square")
        {
            Square square;
            square.SetName(x, y, r, n);
        }

        cout << endl;
    }

}

