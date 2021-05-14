#include <iostream>
#include <vector>
#include <cmath>

bool is_orthogonal(const std::vector<double> & M, const double eps);

int main(void){

    std::vector<double> A = {1, 0, 0, 0,
                             0, 0.8, 0.3, -0.52,
                             0, -0.6, 0.4, -0.69,
                             0, 0, 0.86, 0.5};

    std::cout << is_orthogonal(A, 0.001) << std::endl;
    std::cout << is_orthogonal(A, 0.012) << std::endl;
    std::cout << is_orthogonal(A, 0.1) << std::endl;

    return 0;
}

bool is_orthogonal(const std::vector<double> & M, const double eps)
{
    const int N = 4;
    std::vector<double> MT, C, I;
    MT.resize(N*N);
    C.resize(N*N);
    I.resize(N*N);
    double error = 0.0;
    bool comparacion;
    
    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            MT[ii*N + jj] = M[jj*N + ii];
        }
    }

    for(int ii = 0; ii < N; ++ii) {
        for(int jj = 0; jj < N; ++jj) {
            for(int k = 0; k < N; k++){
                C[ii*N + jj] += M[ii*N + k]*MT[k*N + jj];
            }
        }
	}

    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            if(ii == jj){
                I[ii*N + jj] = 1;
            }
            else{
                I[ii*N + jj] = 0;
            }
        }
    }

    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            error = std::fabs((C[ii*N + jj] - I[ii*N + jj]));
            if(error <= eps){
                comparacion = true;
            }
            else{
                comparacion = false;
                break;
            }
        }
    }
    
    return (comparacion);
    /*std::cout << "I matrix:\n";
    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            std::cout << I[ii*N + jj] <<  "\t"; 
        }
        std::cout << "\n";
    }*/
    

}
