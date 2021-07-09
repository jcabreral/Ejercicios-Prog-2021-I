#include<iostream>
#include<cmath>

bool prime_check(int m);
double sum_prime(int m);

int main(int argc, char *argv[])
{
  std::cout.precision(12); std::cout.setf(std::ios::scientific);
  const int n = 2000000;
  std::cout << sum_prime(n) << "\n";

  return 0;
}

bool prime_check(int m)
{
  bool is_prime = true;
  if(m == 2)
  {
    return true;
  }
  else
  {
    for(int i = 2; i <= std::sqrt(m); i++)
    {
      if(m%i == 0)
      {
        is_prime = false;
        break;
      }
    }
    return is_prime;
  }
}

double sum_prime(int m)
{
  double suma = 0.0;
  int n = 2;
  while(true)
  {
    if(prime_check(n))
    {
      suma += n;
    }
    if(n == m)
    {
      break;
    }
    n++;
  }
  return suma;
}
