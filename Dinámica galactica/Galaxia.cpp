#include <iostream>
#include<cmath>
#include<vector>
#include <boost/numeric/odeint.hpp>


using namespace boost::numeric::odeint;

const double W = 0.25;
const double A = 1.0;
const double C = A;
const double a = 1.25;
const double b = 1.0;
const double c = 0.75;

typedef std::vector< double > state_type;

void galactic ( state_type &x , state_type &dxdt , double t )
{
    // q1 = 0 q2 = 1 q3 = 2 p1 = 3 p2 = 4 p3 = 5
    double n, m, k;
    n = ((x[0]*x[0])/(a*a)); m = ((x[1]*x[1])/(b*b)); k = ((x[2]*x[2])/(c*c));
    //q1 prima
    dxdt[0] = x[3] + W*x[1];
    //q2 prima
    dxdt[1] = x[4] - W*x[0];
    //q3 prima
    dxdt[2] = x[5] ;
    //p1 prima
    dxdt[3] = W*x[4] - ((2*A*x[0])/((a*a)*(C + n + m + k)));
    //p2 prima
    dxdt[4] = -W*x[3] - ((2*A*x[1])/((b*b)*(C + n + m + k)));
    //p3 prima
    dxdt[5] = -((2*A*x[2])/((c*c)*(C + n + m + k)));
}

void write_galaxy( const state_type &x , const double t )
{
    std::cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << x[3] << '\t' << x[4] << '\t' << x[5] << "\n";
}



int main(int argc, char **argv)
{
    state_type x ( 6 );
    x = {{ 2.5 , 0.0 , 0.0 , 0.0 , 1.68884 , 0.2}};
    const double dt = 0.1;
    integrate_const( runge_kutta4< state_type >() , galactic , x , 0.0 , 10000.0 , dt , write_galaxy );

}


