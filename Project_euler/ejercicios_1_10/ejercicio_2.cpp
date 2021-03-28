#include<iostream>

/*Cada nuevo término de la secuencia de Fibonacci se genera sumando los dos términos anteriores. Al comenzar con 1 y 2, los primeros 10 términos serán:
    1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
Al considerar los términos en la secuencia de Fibonacci cuyos valores no exceden los cuatro millones, encuentre la suma de los términos pares. */

void num_fibo(int numa);

int main(void){

int val1;
  std::cout<<"Este programa calcula la suma de los números pares de la serie de Fibonacci\n";
  std::cout<<"Ingrese hasta que número desea calcular la suma: ";
  std::cin>>val1;
  
  num_fibo(val1);

  return 0;
}

void num_fibo(int numa){

  int a = 1, b = 2, suma = 0, c;
  for (int i = b; i<=numa; i++){
    if (a<=numa){
      std::cout<<a<<" ";
      c = b;
		  b += a;
		  a = c;
    }
    if(a%2 == 0){
      suma += c;
    }
  }
  std::cout<<"\nLa suma de los términos pares es: "<<suma<<"\n";
}
