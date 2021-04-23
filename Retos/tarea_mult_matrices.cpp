#include <iostream>

int main(void)
{
  const int M = 3; // rows
  const int N = 2; // columns

	double A[M][N] = {{0.0}};
	double B[N][M] = {{0.0}};
    double C[M][M] = {{0.0}};
    //A
	for(int ii = 0; ii < M; ++ii) {
        for(int jj = 0; jj < N; ++jj) {
            A[ii][jj] = ii*N + jj;
        }
	}
    //B
	for(int ii = 0; ii < N; ++ii) {
        for(int jj = 0; jj < M; ++jj) {
            B[ii][jj] = ii*N + jj;
        }
	}
    //C
    for(int ii = 0; ii < M; ++ii) {
        for(int jj = 0; jj < M; ++jj) {
            for(int k = 0; k < N; k++){
                C[ii][jj] += A[ii][k]*B[k][jj];
            }
        }
	}

	std::cout << "Matriz A: \n";
	for(int ii = 0; ii < M; ++ii) {
        for(int jj = 0; jj < N; ++jj) {
            std::cout << A[ii][jj] << "\t";
        }
        std::cout << "\n";
	}

	std::cout << "Matriz B: \n";
	for(int ii = 0; ii < N; ++ii) {
        for(int jj = 0; jj < M; ++jj) {
            std::cout << B[ii][jj] << "\t";
        }
        std::cout << "\n";
	}

    std::cout << "Matriz C: \n";
	for(int ii = 0; ii < M; ++ii) {
        for(int jj = 0; jj < M; ++jj) {
            std::cout << C[ii][jj] << "\t";
        }
        std::cout << "\n";
	}

	return 0;
}
