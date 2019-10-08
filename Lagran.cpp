#include <iostream>
#define MAX 10
using namespace std;

int main()
{
    int n,j;
    float x[MAX],f[MAX],fp,lf,sum,xp;

    cout<< "Input number of data points, n"<< endl;
    cin>> n;

    cout<< "Input data points x(i) and values f(i) "<< endl;
    cout<< "(One set in each line)"<< endl;

    for(int i=1;i<=n;i++)
        cin>> x[i]>> f[i];

    cout<< "Input x at which interpolation is required."<< endl;
    cin>> xp;

    sum=0.0;
    for(int i=1;i<=n;i++)
    {
        lf=1.0;
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                lf=lf*(xp-x[j])/(x[i]-x[j]);
        }
        sum= sum+lf*f[i];
    }

    fp=sum;

    cout<< "Lagrangian interpolaion"<< endl;

    cout<<"Interpolated function value"<< endl;
    cout<< "at x="<< xp<< " is "<< fp<< endl;
    return 0;
}
