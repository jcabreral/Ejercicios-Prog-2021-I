#include <iostream>
#include <string>

void imprimir(std::string text);
void separar(int numa);

int main(void){

  int val1;
  std::string texto;
  std::cout<<"Ingresa un número o una palabra: ";
  std::cin>>texto;
  imprimir(texto);

  std::cout<<"Ingresa un número: ";
  std::cin>>val1;
  separar(val1);

  return 0;
}

void imprimir(std::string text){

  int a = 0;
  a = text.length();
  for(int ii = 0; ii<a; ii++){
    std::cout<<text[ii];
    if(ii < a-1){
      std::cout<<" - ";
    }
  }
  std::cout<<"\n";
}

void separar(int numa){

  int div = 1, temp = numa, suma = 0;
  while(temp > 10){
    temp /= 10;
    div *= 10;
  }

  while(div != 0){

    int n;
    n = numa / div;
    std::cout<<n;
    if(div/10 != 0){
      std::cout<<" - ";
    }
    numa = numa % div;
    suma += n;
    div = div / 10;

  }
  std::cout<<"\n"<<suma;
  std::cout<<"\n";

}
