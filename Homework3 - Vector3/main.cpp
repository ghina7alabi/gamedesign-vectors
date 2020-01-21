#include <iostream>
#include <cmath>

using namespace std;

class Vector3
{
public:
    Vector3();

    float x, y, z;
    Vector3(float x, float y, float z);

    float Length() const;

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(float s) const;
    Vector3 operator/(float s) const;

    Vector3 Normalized() const;

    friend float Dot(const Vector3& a, const Vector3& b);

    Vector3 CrossProduct(const Vector3& a, const Vector3& b);

};

Vector3:: Vector3()
{

}


Vector3::Vector3(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}


float Vector3::Length() const
{
    float length;
    length = sqrt( (x * x) + (y * y) + (z * z) );
    return length;
}


Vector3 Vector3::operator+(const Vector3& v) const
{
    Vector3 r;

    r.x = x + v.x;
    r.y = y + v.y;
    r.z = z + v.z;

    return r;
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    Vector3 r;

    r.x = x - v.x;
    r.y = y - v.y;
    r.z = z - v.z;

    return r;
}

Vector3 Vector3::operator*(float s) const
{
    Vector3 scaled;

    scaled.x = x*s;
    scaled.y = y*s;
    scaled.z = z*s;

    return scaled;
}

Vector3 Vector3::operator/(float s) const
{
    Vector3 scaled;

    scaled.x = x / s;
    scaled.y = y / s;
    scaled.z = z / s;

    return scaled;
}

Vector3 Vector3::Normalized() const
{
    Vector3 normalized;
    normalized = (*this) / Length();
    return normalized;
}

float Dot(const Vector3& a, const Vector3& b)
{
    float value;

    value = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);

    return value;
}

Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b)
{
    Vector3 value;

    float aCP;
    float bCP;
    float cCP;

    aCP = (a.y * b.z - a.z * b.y);
    bCP = (a.z * b.x - a.x * b.z);
    cCP = (a.x * b.y - a.y * b.x);

    value.x = aCP;
    value.y = bCP;
    value.z = cCP;

   return value;
}



int main(int argc, const char * argv[])
{

    cout << "Hey! This is Homework 3 of GAME205" << endl;


    Vector3 a = Vector3(2, 0, 4);
    Vector3 b = Vector3(-1, 3, 2);

    cout << "Va = " << "(" << a.x << ", " << a.y << ", " << a.z << ")" << endl;
    cout << "Vb = " << "(" << b.x << ", " << b.y << ", " << b.z << ")" << endl;


    Vector3 sumOfVectors = a + b;
    cout << "Va + Vb = " << "(" << sumOfVectors.x << ", " << sumOfVectors.y << ", " << sumOfVectors.z << ")" << endl;

    Vector3 subtractionOfVectors = a - b;
    cout << "Va - Vb = " << "(" << subtractionOfVectors.x << ", " << subtractionOfVectors.y << ", " << subtractionOfVectors.z << ")" << endl;

    Vector3 scaledVector = a*2;
    cout << "2V = " << "(" << scaledVector.x << ", " << scaledVector.y << ", " << scaledVector.z << ")" << endl;

    Vector3 scaledDivVector = a/2;
    cout << "1/2V = (" << scaledDivVector.x << ", " << scaledDivVector.y << ", " << scaledDivVector.z << ")" << endl;

    Vector3 lengthOfVector = a;
    cout << "|Va| = " << lengthOfVector.Length();
    cout << endl;

    Vector3 normalizedVector = a.Normalized();
    cout << "Va normalized = " << "(" << normalizedVector.x << ", " << normalizedVector.y << ", " << normalizedVector.z << ")" << endl;

    cout << "Va . Vb = " << Dot(a, b);
    cout << endl;

    Vector3 crossProduct = a.CrossProduct(a, b);
    cout << "Va * Vb = " << "(" << crossProduct.x << ", " << crossProduct.y << ", " << crossProduct.z << ")" << endl;

    return 0;
}
