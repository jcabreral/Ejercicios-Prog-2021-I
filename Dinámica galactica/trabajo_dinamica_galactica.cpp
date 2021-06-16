#include<iostream>
#include<cmath>
#include<vector>

//Constantes del problema
const double A = 1.0;
const double C = 1.0;
const double omega = 0.25;
const double a = 1.25;
const double b = 1.0;
const double c = 0.75;

using fptr = double (double, double, double);

//Estructuras
struct K
{
    double k1 = 0;
    double k2 = 0;
    double k3 = 0;
    double k4 = 0;
};

struct q
{
    double q1 = 0;
    double q2 = 0;
    double q3 = 0;
};

struct p
{
    double p1 = 0;
    double p2 = 0;
    double p3 = 0;
};

//Funciones
double H(std::vector<q> & coordenadas, std::vector<p> & momentos);
void coor(std::vector<q> & coordenadas);
void mom(std::vector<p> & momentos);
void RK(std::vector<K> & k, std::vector<q> & coordenadas, std::vector<p> & momentos, double t, double h);


int main()
{
    //std::cout << H(2.5, 0.0, 0.0, 0.0, 1.75, 0.0) << std::endl;
    return 0;
} 

double H(std::vector<q> & coordenadas, std::vector<p> & momentos)
{
    // double n, m, k;
    // n = (q1*q1)/(a*a);
    // m = (q2*q2)/(b*b);
    // k = (q3*q3)/(c*c);
    // double Ham = 1/2*(p1*p1 + p2*p2 + p3*p3) + omega*(p1*q2 - p2*q1) + A*std::log(C + n + m + k); 
    return 0;
}

void RK(std::vector<K> & k, std::vector<q> & coordenadas, std::vector<p> & momentos, double t, double h)
{
    for(auto & body: k) 
    {
        body.k1 = body.k2; 
    }
}