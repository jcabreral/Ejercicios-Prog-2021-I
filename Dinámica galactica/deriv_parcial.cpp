#include<iostream>
#include<vector>
#include<cmath>

double f(double x, double y);
double derv_parx(double x, double y, double h);
double derv_pary(double x, double y, double h);

int main()
{
    double h = 0.1, N = 10.0, x = 0.0, y = 0.0;
    for(int i = 0; i <= N; i++)
    {
        std::cout << x << "\t" << y << "\t" << derv_parx(x, y, h) << "\t" << derv_pary(x, y, h) << "\n";
        x += h;
        y += h;
    }
    return 0;
}

double f(double x, double y)
{
    return x*x - 2*y*y;
}
double derv_parx(double x, double y, double h)
{
    return (f(x + h, y) - f(x - h, y))/(2*h);
}
double derv_pary(double x, double y, double h)
{
    return (f(x, y + h) - f(x, y - h))/(2*h);
}