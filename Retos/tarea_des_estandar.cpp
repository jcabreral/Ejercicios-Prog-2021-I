#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

void initialize(std::vector<double> & a);
void print(const std::vector<double> & a);
void print_desviacion(const std::vector<double> & a);

int main(void)
{
  const int N = 10;
  std::vector<double>  data(N);

  initialize(data);
  print(data);
  print_desviacion(data);

  return 0;
}

void print_desviacion(const std::vector<double> & a)
{
  double des_estandar, suma = 0.0;
  double sum = std::accumulate(a.begin(), a.end(), 0.0);
  double average = sum/a.size();
  for(auto val : a){
    suma += (std::pow(val - average, 2));
  }
  
  des_estandar = std::sqrt(suma/a.size());
  std::cout << "La desviación estandar es: " << des_estandar << std::endl;
  
}

void initialize(std::vector<double> & a)
{
  for(int ii = 0; ii < a.size(); ++ii){
    a[ii] = 2*ii + 1;
  }
}

void print(const std::vector<double> & a)
{
  for(auto val : a){
    std::cout << val << "  ";
  }
  std::cout << std::endl;
}


