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

//Funciones
double H(double x, double y, double z, double px, double py, double pz);
double dx(double x, double y, double z, double px, double py, double pz);
double dy(double x, double y, double z, double px, double py, double pz);
double dz(double x, double y, double z, double px, double py, double pz);
double dpx(double x, double y, double z, double px, double py, double pz);
double dpy(double x, double y, double z, double px, double py, double pz);
double dpzx(double x, double y, double z, double px, double py, double pz);
void RK(double x, double y, double z, double px, double py, double pz, double h, double ti, double tf);

int main()
{
    double x = 2.5, y = 0.0, z = 0.0, px = 0.0, py = 1.7, pz = 0.2;
    double h = 0.1, ti = 0.0, tf = 1000.0;
    RK(x, y, z, px, py, pz, h, ti, tf); 
    return 0;
} 

double H(double x, double y, double z, double px, double py, double pz)
{
    double n, m, k;
    n = (x*x)/(a*a); m = (y*y)/(b*b); k = (z*z)/(c*c);
    double Ham = 1/2*(px*px + py*py + pz*pz) + omega*(px*y - py*x) + A*std::log(C + n + m + k); 
    return 0;
}

double dx(double x, double y, double z, double px, double py, double pz)
{
    return px + omega*y;
}
double dy(double x, double y, double z, double px, double py, double pz)
{
    return py - omega*x;
}
double dz(double x, double y, double z, double px, double py, double pz)
{
    return pz;
}
double dpx(double x, double y, double z, double px, double py, double pz)
{
    double n, m, k;
    n = (x*x)/(a*a); m = (y*y)/(b*b); k = (z*z)/(c*c);
    return omega*py - (2*A*x)/(a*a*(C + n + m + k));
}
double dpy(double x, double y, double z, double px, double py, double pz)
{
    double n, m, k;
    n = (x*x)/(a*a); m = (y*y)/(b*b); k = (z*z)/(c*c);
    return -omega*px - (2*A*y)/(b*b*(C + n + m + k));
}
double dpz(double x, double y, double z, double px, double py, double pz)
{
    double n, m, k;
    n = (x*x)/(a*a); m = (y*y)/(b*b); k = (z*z)/(c*c);
    return -(2*A*z)/(c*c*(C + n + m + k));
}
void RK(double x, double y, double z, double px, double py, double pz, double h, double ti, double tf)
{
    std::vector<double> sol(6), k1(6, 0), k2(6, 0), k3(6, 0), k4(6, 0);
    //sol[0] = x; sol[1] = y; sol[2] = z; sol[3] = px; sol[4] = py; sol[5] = pz; 
    double temp = 0.0;

    while(ti <= tf)
    {
        sol = {x, y, z, px, py, pz};

        k1[0] = dx(x, y, z, px, py, pz);
        k1[1] = dy(x, y, z, px, py, pz);
        k1[2] = dz(x, y, z, px, py, pz);
        k1[3] = dpx(x, y, z, px, py, pz);
        k1[4] = dpy(x, y, z, px, py, pz);
        k1[5] = dpz(x, y, z, px, py, pz);
        k2[0] = dx(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k2[1] = dy(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k2[2] = dz(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k2[3] = dpx(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k2[4] = dpy(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k2[5] = dpz(x + k1[0]*h*0.5, y + k1[1]*h*0.5, z + k1[2]*h*0.5, px + k1[3]*h*0.5, py + k1[4]*h*0.5, pz + k1[5]*h*0.5);
        k3[0] = dx(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k3[1] = dy(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k3[2] = dz(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k3[3] = dpx(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k3[4] = dpy(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k3[5] = dpz(x + k2[0]*h*0.5, y + k2[1]*h*0.5, z + k2[2]*h*0.5, px + k2[3]*h*0.5, py + k2[4]*h*0.5, pz + k2[5]*h*0.5);
        k4[0] = dx(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        k4[1] = dy(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        k4[2] = dz(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        k4[3] = dpx(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        k4[4] = dpy(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        k4[5] = dpz(x + k2[0]*h, y + k2[1]*h, z + k2[2]*h, px + k2[3]*h, py + k2[4]*h, pz + k2[5]*h);
        ti += h;
        temp = x;
        x = temp + (h/6)*(k1[0] + 2*k2[0] +2*k3[0] + k4[0]);
        temp = y;
        y = temp + (h/6)*(k1[1] + 2*k2[1] +2*k3[1] + k4[1]);
        temp = z;
        z = temp + (h/6)*(k1[2] + 2*k2[2] +2*k3[2] + k4[2]);
        temp = px;
        px = temp + (h/6)*(k1[3] + 2*k2[3] +2*k3[3] + k4[3]);
        temp = py;
        py = temp + (h/6)*(k1[4] + 2*k2[4] +2*k3[4] + k4[4]);
        temp = pz;
        pz = temp + (h/6)*(k1[5] + 2*k2[5] +2*k3[5] + k4[5]);

        for(int i = 0; i < 6; i++)
        {
            std::cout << sol[i] << "\t";
        }
        std::cout << "\n";
    }


}