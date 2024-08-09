#include <iostream>
#include <cmath>
using namespace std;

float* crosP(float v1[3], float v2[3])
{
    float* ans=new float[3];
    ans[0] = (v1[1] * v2[2] - v2[1] * v1[2]);
    ans[1] = (v2[0] * v1[2] - v1[0] * v2[2]);
    ans[2] = (v1[0] * v2[1] - v2[0] * v1[1]);
    return ans;
}

float magnitude(float arr[3])
{
    return sqrt(arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2]);
}

int main()
{
    float x1, y1, z1, x2, y2, z2;
    cout << "Enter the two points: ";
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    float x3, y3, z3;
    cout << "Enter the 3rd points to find perpendiculars distance: ";
    cin >> x3 >> y3 >> z3;
    float arr1[3], arr2[3];
    arr1[0] = x2 - x1;
    arr1[1] = y2 - y1;
    arr1[2] = z2 - z1;

    arr2[0] = x3 - x1;
    arr2[1] = y3 - y1;
    arr2[2] = z3 - z1;

    float *pt = crosP(arr1, arr2);

    float mag1=magnitude(pt);
    float mag2=magnitude(arr1);
    cout<<"Perpendicular distance is: "<<mag1/mag2;
    return 0;
}