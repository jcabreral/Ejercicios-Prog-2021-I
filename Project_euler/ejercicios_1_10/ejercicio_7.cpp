#include <iostream>
#include <cstdlib>
#include <cmath>

int isprime(int m);
int nthprime(int n);

int main(int argc, char *argv[])
{
  const int n = std::atoi(argv[1]);
  std::cout << nthprime(n) << "\n";

  return 0;
}

int isprime(int m)
{
    int count = 0;
    for(int i = 2; i <= m; i++){
        if(m%i == 0){
            count +=1;
        }
    }
    if(count == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int nthprime(int n)
{
  int count = 0, i = 0;
  while(count < n){
    
    i++;
    if(isprime(i) == 1){
      count++;
    }
  }
  return i;
}