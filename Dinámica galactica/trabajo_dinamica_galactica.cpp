#include<iostream>
#include<cmath>
#include<vector>

const double A = 1.0;
const double C = 1.0;
const double omega = 0.25;
const double a = 1.25;
const double b = 1.0;
const double c = 0.75;

using fptr = double (double, double, double);

double H(double q1, double q2, double q3, double p1, double p2, double p3);
double dev_parcial(double t, double x, double y);
void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini);

int main()
{
    std::cout << H(2.5, 0.0, 0.0, 0.0, 1.75, 0.0) << std::endl;
    return 0;
} 

double H(double q1, double q2, double q3, double p1, double p2, double p3)
{
    double n, m, k;
    n = (q1*q1)/(a*a);
    m = (q2*q2)/(b*b);
    k = (q3*q3)/(c*c);
    double Ham = 1/2*(p1*p1 + p2*p2 + p3*p3) + omega*(p1*q2 - p2*q1) + A*std::log(C + n + m + k); 
    return Ham;
}
/*void Rk(fptr f1, fptr f2, double h, double tini, double tfinal, double xini, double yini)
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

}*/