#include<iostream>
#include<cmath>
#include<vector>

using fptr = double (double, double);

double funtion(double x, double y);
void Rk(fptr fun, double h, double xini, double xfinal, double yini);

int main()
{

    Rk(funtion, 0.25, 0.0, 1.25, 1.0);


    return 0;
} 

double funtion(double x, double y)
{
    return y*y;
}
void Rk(fptr fun, double h, double xini, double xfinal, double yini)
{
    double k1, k2, k3, k4, temp;

    while(xini <= xfinal)
    {
        std::cout << xini << "\t" << yini << std::endl;
        k1 = fun(xini, yini);
        k2 = fun(xini + h*0.5, yini + k1*h*0.5);
        k3 = fun(xini + h*0.5, yini + k2*h*0.5);
        k4 = fun(xini + h, yini + k3*h);
        xini += h;
        temp = yini;
        yini = temp + (h/6)*(k1 + 2*k2 +2*k3 + k4);
    }

}
