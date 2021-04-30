#include <iostream>
#include <cmath>

void norma(double A[], int M, int N);

int main(int argc, char *argv[])
{
    const int M = 10; // rows
    const int N = 20; // columns
    std::cout.precision(6); std::cout.setf(std::ios::scientific);

    double *A = nullptr;
    norma(A, M, N);
    
    return 0;
}
void norma(double A[], int M, int N){
    	
    double suma = 0.0; 
    A = new double [M*N];
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            A[i*N + j] = 1.0/(2*i + j + 1);
        }
	}
    std::cout << "Norma definida para esta matriz: \n";
	for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            suma += std::fabs(A[i*N + j]);
        }
	}
    std::cout << suma << "\n";
    delete [] A; 
    A = nullptr;
}