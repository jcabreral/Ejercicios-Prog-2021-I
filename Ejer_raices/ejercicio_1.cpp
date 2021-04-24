#include <iostream>
#include <cmath>

using fptr = double (double); 

double f(double x);
double fderiv(double x);
double g(double x);

double fixedpoint(double x0, double eps, fptr func, int nmax, int & nsteps);
double newton(double x0, double eps, fptr func, fptr deriv, int nmax, int & nsteps);

int main (int argc, char *argv[])
{
    double X0 = std::atof(argv[1]);
    double eps = std::atof(argv[2]);
    int NMAX = 10;
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    int steps = 0;
    double rootfp, rootn;
    rootfp = fixedpoint(X0, eps, g, NMAX, steps);
    rootn = newton(X0, eps, f, fderiv, NMAX, steps);

    std::cout <<"Método del punto fijo: " << rootfp << "\t" << steps << "\n";
    std::cout <<"Método de Newton: " << rootn << "\t" << steps << "\n";

    return 0;
    
}

double f(double x)
{
    return 2*std::pow(x, 3) - 11.7*x*x + 17.7*x - 5;
}

double fderiv(double x)
{
    double h = 0.001;
    return (f(x+h/2) - f(x-h/2))/h;
}

double g(double x)
{
    return -(2*std::pow(x, 3) - 11.7*x*x - 5)/17.7;
}


double fixedpoint(double x0, double eps, fptr func, int nmax, int & nsteps)
{
    nsteps = 0;
    double xr = x0;
    while(nsteps <= nmax) {
        if (std::fabs(func(xr) - xr) < eps) {
            break;
        } else {
            xr = func(xr);
        }
        nsteps++;
    }

    return xr;
}
double newton(double x0, double eps, fptr func, fptr deriv, int nmax, int & nsteps)
{
    nsteps = 0;
    double xr = x0;
    while(nsteps <= nmax) {
        if (std::fabs(func(xr)) < eps) {
            break;
        } else {
            xr = xr - func(xr)/deriv(xr);
        }
        nsteps++;
    }

    return xr;
}

