#include <iostream>

/*Los factores primos de 13195 son 5, 7, 13 y 29.

¿Cuál es el factor primo más grande del número 600851475143?*/
/*Soprepasa la capacidad de computo de Repl.it y no lo corre, en Dev lo corre y da el resultado correcto pero también se queda colgado y no termina la ejecución del problema*/
void primos(long long int numa);

int main(void){

  long long int val1;
  std::cout<<"Ingrese el número que desea descomponer en factores primos: ";
  std::cin>>val1;
  std::cout<<"Los factores primos de "<<val1<<" son:\n ";
  primos(val1);
  std::cout<<"\n";

  return 0;
}

void primos(long long int numa){

  long long int i = 2, mayor = 0; 
  long long int n = numa;
  while(i <= numa){
    
    if(n % i == 0){
      std::cout<<i<<" ";
      n /= i;
      if(i>mayor){
        mayor = i;
      }
    }
    else{
      i +=1;
    }
  }
  std::cout<<"\nEl factor primo más grande es: "<<mayor<<"\n"; 
}