#include<iostream>
#include<random>
#include<cstdlib>

template <class T>
void gen_rand_num(int seed, int nsamples, T dis);

int main(int argc, char *argv[])
{
    int SEED = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int A = std::atoi(argv[3]);
    int B = std::atoi(argv[4]);

    std::uniform_real_distribution<double> dis(A, B);
    //std::normal_distribution<double> dis(A, B);
    //std::gamma_distribution<double> dis(A, B);
    gen_rand_num(SEED, N, dis);

    return 0;
}

template <class T>
void gen_rand_num(int seed, int nsamples, T dis)
{
    // declarar el random engine
    std::mt19937 gen32(seed);
    // generar nsamples numbers e imprimirlos
    for(int n = 0; n < nsamples; n++)
    {
        std::cout << dis(gen32) << "\n";
    }
}
