#include <iostream>
#include <cmath>
#include <vector>

const double T0 = 0.0;
const double TF = 10000;
const double H = 0.025;
const int DIM = 6;
const double W = 0.25;
const double A = 1.0;
const double C = A;
const double a = 1.25;
const double b = 1.0;
const double c = 0.75;

typedef std::vector<double> state_t;
template<typename system_t, typename state_t>
  void rk4(system_t deriv, state_t & data, double ta, double tb, double h);

void fderiv(const state_t & y, state_t & dydt, double t)
{
    double n, m, k;
    n = ((y[0]*y[0])/(a*a)); m = ((y[1]*y[1])/(b*b)); k = ((y[2]*y[2])/(c*c));
    
    dydt[0] = y[3] + W*y[1];
    dydt[1] = y[4] - W*y[0];
    dydt[2] = y[5];
    dydt[3] = W*y[4] - ((2*A*y[0])/((a*a)*(C + n + m + k)));
    dydt[4] = -W*y[3] - ((2*A*y[1])/((b*b)*(C + n + m + k)));
    dydt[5] = -((2*A*y[2])/((c*c)*(C + n + m + k)));
}

int main(void)
{
    state_t y(DIM);
    y = {2.5 , 0.0 , 0.0 , 0.0 , 1.68884 , 0.2};  // initial conditions

    rk4(fderiv, y, T0, TF, H);

    return 0;
}

template<typename system_t, typename state_t>
void rk4(system_t deriv, state_t & data, double ta, double tb, double h)
{
    std::cout.precision(10);
    state_t dydt(data.size());
    state_t k1(data.size()), k2(data.size()),
        k3(data.size()), k4(data.size()), aux(data.size());

    const int nsteps = (tb - ta)/h;
    for (int ii = 0; ii <= nsteps; ++ii) {
        double t = ta + ii*h;
    // k1
    deriv(data, dydt, t);
    for(int ii = 0; ii < data.size(); ++ii) {
        k1[ii] = h*dydt[ii];
    }
    // k2 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k1[ii]/2;
    }
    // k2
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k2[ii] = h*dydt[ii];
    }
    // k3 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k2[ii]/2;
    }
    // k3
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k3[ii] = h*dydt[ii];
    }
    // k4 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k3[ii];
    }
    // k4
    deriv(aux, dydt, t + h);
    for(int ii = 0; ii < data.size(); ++ii) {
        k4[ii] = h*dydt[ii];
    }

    // write new data
    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }

    /*if(data[0] > 0. && std::abs(data[1]) < 0.01 && dydt[1] > 0){
        std::cout << data[0] << "   " << data[1] << "   " << data[2] << "\n";
    }*/

    std::cout << t << "  " << data[0] << "   " << data[1] << "   " << data[2] << "   " << data[3]
        <<  "   " << data[4] <<  "   " << data[5] << "\n";

    }

}
