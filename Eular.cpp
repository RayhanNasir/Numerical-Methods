#include <iostream>

using namespace std;

int main()
{
    int n;
    float x,y,xp,h,dy;
    float func(float, float);

    cout<< "\n Solution by euler's method "<< endl;

    cout<< "Input initial values of x and y \n"<< endl;
    cin>> x >> y;

    cout<< "Input x at which y is required"<< endl;
    cin>> xp;

    cout<< "Input step-size, h"<< endl;
    cin>> h;

    n= (int)((xp-x)/h+0.5);

    for(int i=1;i<=n;i++)
    {
        dy=h*func(x,y);
        x=x+h;
        y=y+dy;
        cout<< i<<"  "<< x<<"  "<< y<< endl;
    }

    return 0;
}

    float func(float x, float y)
    {
        float f;
        f=1-y;
        return (f);
    }
