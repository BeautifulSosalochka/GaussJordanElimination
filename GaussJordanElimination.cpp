#include <iostream>
#include <vector>

template<typename T>
class GaussJordan {
public:
    GaussJordan(std::vector<std::vector<T>>& matrix) : matrix(matrix) {}

    void Solve() {
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            int max_row = i;
            for (int k = i + 1; k < rows; ++k) {
                if (std::abs(matrix[k][i]) > std::abs(matrix[max_row][i])) {
                    max_row = k;
                }
            }
            if (max_row != i) {
                std::swap(matrix[i], matrix[max_row]);
            }
            T divisor = matrix[i][i];
            if (divisor != 0) {
                for (int k = 0; k < rows; ++k) {
                    if (k != i) {
                        T multiplier = matrix[k][i];
                        for (int j = i; j < cols; ++j) {
                            matrix[k][j] -= multiplier * matrix[i][j];
                        }
                    }
                }
            }
        }
    }
    void PrintSolution() {
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        std::cout << "Solution: " << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    std::vector<std::vector<T>>& matrix;
};

int main() {
    std::vector<std::vector<double>> exampleMatrix = {
            {1, 2, 3, 2},
            {1, -1, 1, 0},
            {1, 3, -1, -2}
    };
    GaussJordan<double> GJSolver(exampleMatrix);
    GJSolver.Solve();
    GJSolver.PrintSolution();

    return 0;
}