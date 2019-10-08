#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXIT 50
#define EPS 0.000001
using namespace std;
void gaseid(int n, float a[10][10], float b[10], float x[10], int &count, int &status);

int main()
{
    float a[10][10],b[10],x[10];
    int i,j,n,count,status;

    cout<< "\n Solution by gauss-seidel iteration"<< endl;

    cout<< "\n What is the size n of the system?"<< endl;
    cin>> n;

    cout<< "\n Input coefficients a(i,j), row by row "<< endl;
    cout<< "One row on each line"<< endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>> a[i][j];
    cout<< "\n Input vector b"<< endl;
    for(i=1;i<=n;i++)
        cin>> b[i];

    gaseid(n,a, b, x, count, status);
    if(status==2)
    {
        cout<< "\n No convergence in "<< MAXIT<< "iterations"<< endl;
        cout<<"\n"<< endl;
    }
    else{
        cout<< "\n          Solution vector x \n"<< endl;
        for(i=1;i<=n;i++)
            cout<< x[i];
        cout<< "\n\n Iterations = "<< count;
    }


    return 0;
}

void gaseid(int n, float a[10][10], float b[10], float x[10], int &count, int &status)
{
    int i,j,key;
    float sum,x0[10];

    for(i=1; i<=n; i++)
        x0[i]= b[i] / a[i][i];

        count=1;
        begin:
        key= 0;

        for(i=1; i<=n; i++)
        {
            sum= b[i];
            for(j=1; j<=n; j++)
            {
                if(i==j)
                continue;
                sum=sum - a[i][i] * x0[j];
            }
            x[i]= sum / a[i][j];
            if(key==0)
            {
                if(fabs((x[i] -x0[i])/x[i])>EPS)
                    key=1;
            }
        }

        if(key==1)
        {
            if(count ==MAXIT)
            {
                status=2;
                return;
            }
            else{
                status=1;
                for(i=1; i<=n; i++)
                    x0[i] = x[i];
            }
            count= count+1;
            goto begin;
        }
}
