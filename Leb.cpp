#include <iostream>

using namespace std;
void gauss1(int n, float a[10][10], float b[10], float x[10], int &status);

int main()
{
    int status,n;
    float a[10][10],b[10],x[10];

    cout<< "Solution by simple gauss metod"<< endl;

    cout<< "What is the size of the system (n)?"<< endl;
    cin>> n;

    cout<< "Input coefficients a(i,j), row-wise"<< endl;
    cout<< "One row on each line"<< endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>> a[i][j];

    cout<< "Input vector b"<< endl;
    for(int i=1;i<=n;i++)
        cin>> b[i];

    gauss1(n,a,b,x,status);

    if(status!=0)
    {
        cout<< "Solution vector"<< endl;

        for(int i=1;i<=n;i++)
            cout<< x[i];

        cout<< endl;
    }
    else
    {
        cout<< "Singular matrix, reorder equations."<<endl;
    }
    return 0;
}

void gauss1(int n, float a[10][10], float b[10], float x[10], int &status)
{
    int i,j,k;
    float pivot,factor,sum;

    for(k=1;k<=n-1;k++)
    {
        pivot=a[k][k];
        if(pivot< 0.000001)
        {
            status=0;
            return;
        }
        status=1;
        for(i=k+1;i<=n;i++)
        {
            factor= a[i][k]/pivot;
            for(j=k+1;j<=n;j++)
            {
                a[i][j]=a[i][j] - factor * a[k][j];
            }
            b[i]=b[i] - factor * b[k];
        }
    }

    x[n] =b[n] / a[n][n];
    for(k=n-1;k>=1;k--)
    {
        sum=0.0;
        for(j=k+1;j<=n;j++)
            sum= sum + a[k][j] * x[j];
        x[k]= (b[k] - sum) / a[k][k];
    }
}
