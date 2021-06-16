#include<iostream>
#include<random>
#include<cstdlib>

void gen_rand_num_gamma(int sedd, double a, double b, int nsamples);

int main(int argc, char *argv[])
{
    int SEED = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int A = std::atoi(argv[3]);
    int B = std::atoi(argv[4]);

    gen_rand_num_gamma(SEED, A, B, N);

    return 0;
}

void gen_rand_num_gamma(int sedd, double a, double b, int nsamples)
{
    // declarar el random engine
    std::mt19937 gen32(sedd);
    // declarar la distribución
    std::gamma_distribution<double> dis(a, b);
    // generar nsamples numbers e imprimirlos
    for(int n = 0; n < nsamples; n++)
    {
        std::cout << dis(gen32) << "\n";
    }
}
