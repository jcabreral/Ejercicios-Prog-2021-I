#include<iostream>

/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.*/

void mult_tres_cinco(int numa, int numb);


int main(void){

  int val1, val2;
  std::cout<<"Ingrese el límite inferior: ";
  std::cin>>val1;
  std::cout<<"Ingrese el límite superior: ";
  std::cin>>val2;

  mult_tres_cinco(val1, val2);

  return 0;
}

void mult_tres_cinco(int numa, int numb){

  int suma = 0;
  for(int ii = numa; ii< numb; ii++ ){
      
      if(ii%3 == 0 || ii%5 == 0){
        suma += ii;
      }
  }
  std::cout<<"La suma de los multiplos de 3 y 5 entre "<<numa<<" y "<<numb<<" es: "<<suma<<"\n";
}
