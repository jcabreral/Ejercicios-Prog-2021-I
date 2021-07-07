#include<iostream>
#include<cmath>

int sum_cuad(int x);
int cuad_sum(int x);
void total(int x);

int main()
{
    int x = 100;
    total(x);
    
    return 0;
}

int sum_cuad(int x)
{
    int suma = 0;
    for(int i = 1; i <= x; i++)
    {
        suma += i*i;
    }
    return suma;
}
int cuad_sum(int x)
{
    int suma = 0;
    for(int i = 1; i <= x; i++)
    {
        suma += i;
    }
    return std::pow(suma, 2);
}
void total(int x)
{
    int total;
    total = cuad_sum(x) - sum_cuad(x);
    std::cout << total << "\n";
}