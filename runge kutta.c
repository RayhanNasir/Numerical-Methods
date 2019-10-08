#include<stdio.h>

int main()
{
    int i,n;
    float x,y,xp,h,m1,m2,m3,m4;
    float func(float, float);

    printf("\n Solution by 4th order rk method\n\n");

    printf("Input initial values of x and y\n");
    scanf("%f %f",&x,&y);
    printf("Input x at which y is required\n");
    scanf("%f",&xp);
    printf("Input step-size, h\n");
    scanf("%f",&h);

    n=(int)((xp-x)/h+0.5);

    printf("\n");
    printf("--------------------------\n");
    printf(" Step x y \n");
    printf("--------------------------\n");

    for(i=1;i<=n;i++)
    {
        m1=func(x,y);
        m2=func(x+0.5*h, y+0.5*m1*h);
        m3=func(x+0.5*h, y+0.5*m2*h);
        m4=func(x+h, y+m3*h);
        x=x+h;
        y=y+(m1+2.0*m2 + 2.0*m3+m4) * h/6.0;
        printf("%5d %15.6f %15.6f \n",i,x,y);
    }
    printf("---------------------------\n");

    return 0;
}

float func(float x, float y)
{
    float f;
    //f=1.0-(2*x*y);
    //f=x+y;
    f=(x*x)-y;
    return (f);
}
