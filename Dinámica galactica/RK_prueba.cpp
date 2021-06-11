#include<iostream>
#include<cmath>
#include<vector>

//Resolución de una EDO lineal por RK-4

using fptr = double (double, double);

double f1(double t, double y);
void Rk(fptr fun, double h, double tini, double tfinal, double yini);

int main()
{
    Rk(f1, 0.1, 0.0, 100.0, 1.0);
        
    return 0;
} 

double f1(double t, double y)
{
    return y;
}
void Rk(fptr fun, double h, double tini, double tfinal, double yini)
{
    double k1, k2, k3, k4, temp;
    std::vector<double> t, y;

    while(tini <= tfinal)
    {
        t.push_back(tini);
        y.push_back(yini);
        k1 = fun(tini, yini);
        k2 = fun(tini + h*0.5, yini + k1*h*0.5);
        k3 = fun(tini + h*0.5, yini + k2*h*0.5);
        k4 = fun(tini + h, yini + k3*h);
        tini += h;
        temp = yini;
        yini = temp + (h/6)*(k1 + 2*k2 +2*k3 + k4);
    }

    int N = h*tfinal;
    for(int i = 0; i <= N; i++){
        std::cout << t[i] << "\t" << y[i] << "\n";
    }
    std::cout << std::endl;

}

/*
En este caso se hace el programa para un sistema de 2 EDO sencillas para probar la funcionalidad
del código

using fptr = double (double, double, double);

double f1(double t, double x, double y);
double f2(double t, double x, double y);
void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini);

int main()
{
    Rk(f1, f2, 1.0, 0.0, 46.0, 1.0, 0.0);
        
    return 0;
} 

double f1(double t, double x, double y)
{
    return -0.1*x;
}
double f2(double t, double x, double y)
{
    return 0.1*x - 0.09*y;
}
void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini)
{
    double k1, k2, k3, k4, l1, l2, l3, l4, tempx, tempy;
    std::vector<double> t, x, y;

    while(tini <= tfinal)
    {
        t.push_back(tini);
        x.push_back(xini);
        y.push_back(yini);
        k1 = f1(tini, xini, yini);
        l1 = f2(tini, xini, yini);
        k2 = f1(tini + h*0.5, xini + k1*h*0.5, yini + l1*h*0.5);
        l2 = f2(tini + h*0.5, xini + k1*h*0.5, yini + l1*h*0.5);
        k3 = f1(tini + h*0.5, xini + k2*h*0.5, yini + l2*h*0.5);
        l3 = f2(tini + h*0.5, xini + k2*h*0.5, yini + l2*h*0.5);
        k4 = f1(tini + h*0.5, xini + k3*h, yini + l3*h);
        l4 = f2(tini + h*0.5, xini + k3*h, yini + l3*h);
        tini += h;
        tempx = xini;
        xini = tempx + (h/6)*(k1 + 2*k2 +2*k3 + k4);
        tempy = yini;
        yini = tempy + (h/6)*(l1 + 2*l2 +2*l3 + l4);
    }

    int N = h*tfinal;
    for(int i = 0; i <= N; i++){
        std::cout << t[i] << "\t" << x[i] << "\t" << y[i] << "\n";
    }
    std::cout << std::endl;

}
*/

/* Es el mismo caso de un sistema de 2 EDO pero ahora use vectores para k y l en RK
using fptr = double (double, double, double);

double f1(double t, double x, double y);
double f2(double t, double x, double y);
void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini);

int main()
{
    Rk(f1, f2, 1.0, 0.0, 46.0, 1.0, 0.0);
    return 0;
} 

double f1(double t, double x, double y)
{
    return -0.1*x;
}
double f2(double t, double x, double y)
{
    return 0.1*x - 0.09*y;
}
void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini)
{
    double tempx, tempy;
    std::vector<double> t, x, y, k(4), l(4);

    while(tini <= tfinal)
    {
        t.push_back(tini);
        x.push_back(xini);
        y.push_back(yini);
        k[0] = f1(tini, xini, yini);
        l[0] = f2(tini, xini, yini);
        k[1] = f1(tini + h*0.5, xini + k[0]*h*0.5, yini + l[0]*h*0.5);
        l[1] = f2(tini + h*0.5, xini + k[0]*h*0.5, yini + l[0]*h*0.5);
        k[2] = f1(tini + h*0.5, xini + k[1]*h*0.5, yini + l[1]*h*0.5);
        l[2] = f2(tini + h*0.5, xini + k[1]*h*0.5, yini + l[1]*h*0.5);
        k[3] = f1(tini + h*0.5, xini + k[2]*h, yini + l[2]*h);
        l[3] = f2(tini + h*0.5, xini + k[2]*h, yini + l[2]*h);
        tini += h;
        tempx = xini;
        xini = tempx + (h/6)*(k[0] + 2*k[1] +2*k[2] + k[3]);
        tempy = yini;
        yini = tempy + (h/6)*(l[0] + 2*l[1] +2*l[2] + l[3]);
    }

    int N = h*tfinal;
    for(int i = 0; i <= N; i++){
        std::cout << t[i] << "\t" << x[i] << "\t" << y[i] << "\n";
    }
    std::cout << std::endl;

}
*/