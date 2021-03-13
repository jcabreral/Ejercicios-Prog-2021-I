#include<iostream>

void suma(float numa, float numb);
void resta(float numa, float numb);
void multip(float numa, float numb);
void mayor(float numa, float numb);

int main(void){

    float  val1, val2;
    std::cout<<"Ingrese el primer  valor: ";
    std::cin>>val1;
    std::cout<<"Ingrese el segundo  valor: ";
    std::cin>>val2;


    suma(val1, val2);
    resta(val1, val2);
    multip(val1, val2);
    mayor(val1, val2);

    return 0;
}

void suma(float numa, float numb){

    float result;
    result = numa + numb;
    std::cout<<"El resultado de la suma es: "<<result<<"\n";
}

void resta(float numa, float numb){
    float result;
    result = numa - numb;
    std::cout<<"El resultado de la resta de "<<numa<<"-"<<numb<<" es: "<<result<<"\n";
}

void multip(float numa, float numb){
    float result;
    result = numa * numb;
    std::cout<<"El resultado de la multiplicación es: "<<result<<"\n";
}

void mayor(float numa, float numb){
    if(numa > numb){
        std::cout<<numa<<" es mayor que "<<numb<<"\n";
    }
    else{
        std::cout<<numb<<" es mayor que "<<numa<<"\n";
    }
}
