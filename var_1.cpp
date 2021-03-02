#include <iostream>

int main(int argc, char **argv)
{
  int op;
  float km, millas;
  std::cout<<"¿Qué desea hacer? \n 1. km a millas \n 2. Millas a km.\n Ingrese la opción correspondiente: "; 
  std::cin>>op;
  if(op == 1){
    std::cout <<"Ingrese la cantidad de km a convertir en millas: ";
    std::cin>>km;
    millas = km*0.621371; 
    std::cout<<km<<" km equivalen a "<<millas<<" millas. \n";
  }
  else if(op==2){
    std::cout <<"Ingrese la cantidad de millas a convertir en km: ";
    std::cin>>millas;
    km = millas*1.60934;
    std::cout<<millas<<" millas equivalen a "<<km<<" km. \n";
  }
  else{
    std::cout<<"Ingreso un valor invalido. \n";
  }

  return 0;
}