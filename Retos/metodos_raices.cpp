#include <iostream>
#include <cmath>

using fptr = double (double); 

const double M = 68.1;
const double G = 9.81;
const double VT = 40;
const double T = 10;

double f(double x);
double fderiv(double x);
double g(double x);

double bisection(double xl, double xu, double eps, fptr func, int nmax, int & nsteps);
double regulafalsi(double xl, double xu, double eps, fptr func, int nmax, int & nsteps);
double fixedpoint(double x0, double eps, fptr func, int nmax, int & nsteps);
double newton(double x0, double eps, fptr func, fptr deriv, int nmax, int & nsteps);
double secante(double x0, double x1, double eps, fptr func, int nmax, int & nsteps);

int main (int argc, char *argv[])
{
    double XL = std::atof(argv[1]);
    double XU = std::atof(argv[2]);;
    double eps = std::atof(argv[3]);
    int NMAX = 1000;
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    int steps = 0;
    double root;
    /*root = bisection(XL, XU, eps, f, NMAX, steps);
    std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";
    root = regulafalsi(XL, XU, eps, f, NMAX, steps);
    std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";
    root = fixedpoint(XL, eps, g , NMAX, steps);
    std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";
    root = newton(XL, eps, f, fderiv, NMAX, steps);
    std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";
    root = secante(XL, XU, eps, f, NMAX, steps);
    std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";*/

    while(eps >= 1.0e-9){
        root = secante(XL, XU, eps, f, NMAX, steps);
        std::cout << eps << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";
        eps /=10;
    }
}

double f(double x)
{
    return M*G*(1 - std::exp(-x*T/M))/x - VT;
}

double fderiv(double x)
{
    double h = 0.001;
    return (f(x+h/2) - f(x-h/2))/h;
}

double g(double x)
{
    return M*G*(1 - std::exp(-x*T/M))/VT;
}


double bisection(double xl, double xu, double eps, fptr func, int nmax, int & nsteps)
{
    nsteps = 0;
    double xr = xl;
    do {
        xr = 0.5*(xl + xu);
        nsteps++;
        //std::cout << xr << "\n";
        if (std::fabs(func(xr)) < eps) {
            break;
        } else if (func(xl)*func(xr) < 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        //std::cout << xl << "\t" << xu << "\n";
    } while (nsteps <= nmax);
    return xr;
}


double regulafalsi(double xl, double xu, double eps, fptr func, int nmax, int & nsteps)
{
    nsteps = 0;
    double xr = xl;
    do {
        double fxu = func(xu);
        double fxl = func(xl);
        xr = xu - (fxu*(xl -xu))/(fxl - fxu);
        nsteps++;
        //std::cout << xr << "\n";
        if (std::fabs(func(xr)) < eps) {
            break;
        } else if (fxl*func(xr) < 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        //std::cout << xl << "\t" << xu << "\n";
    } while (nsteps <= nmax);
    return xr;
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

double secante(double x0, double x1, double eps, fptr func, int nmax, int & nsteps){
    nsteps = 0;
    double xr = x0;
    while(nsteps <= nmax) {
        if (std::fabs(func(xr)) < eps) {
            break;
        } else {
            xr = x1 - (f(x1)*(x0- x1))/(f(x0)- f(x1));
        }
        nsteps++;
        x0 = x1;
        x1 = xr;
    }
    return xr;
}
