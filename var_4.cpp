#include<iostream>

void suma(float numa, float numb);
void multip(float numa, float numb);

int main(void){

    float  val1, val2;
    std::cout<<"Ingrese el primer  valor: ";
    std::cin>>val1;
    std::cout<<"Ingrese el segundo  valor: ";
    std::cin>>val2;


    suma(val1, val2);
    multip(val1, val2);


    return 0;
}

void suma(float numa, float numb){

    float result;
    result = numa + numb;
    std::cout<<"El resultado de la suma es: "<<result<<"\n";
}

void multip(float numa, float numb){
    float result;
    result = numa * numb;
    std::cout<<"El resultado de la multiplicación es: "<<result<<"\n";
}
