#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits> // for numeric_limits
using namespace std;

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

    void allocateMemory() {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocateMemory();
    }

    ~Matrix() {
        deallocateMemory();
    }

    void fillFromKeyboard() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void fillWithRandomValues(T minVal, T maxVal) {
        srand(time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = minVal + (rand() % static_cast<int>(maxVal - minVal + 1));
            }
        }
    }

    void display() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << setw(5) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    T getMaxElement() const {
        T maxElem = numeric_limits<T>::min();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > maxElem) {
                    maxElem = data[i][j];
                }
            }
        }
        return maxElem;
    }

    T getMinElement() const {
        T minElem = numeric_limits<T>::max();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < minElem) {
                    minElem = data[i][j];
                }
            }
        }
        return minElem;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices dimensions do not match for addition.");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices dimensions do not match for subtraction.");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrices dimensions do not match for multiplication.");
        }
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> operator/(const T divisor) const {
        if (divisor == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] / divisor;
            }
        }
        return result;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    Matrix<int> matrix1(rows, cols);
    Matrix<int> matrix2(rows, cols);

    matrix1.fillWithRandomValues(1, 10);
    matrix2.fillWithRandomValues(1, 10);

    cout << "Matrix 1:" << endl;
    matrix1.display();
	cout << "--------------------------------" << endl;
    cout << "Matrix 2:" << endl;
    matrix2.display();

    try {
        Matrix<int> sum = matrix1 + matrix2;
        cout << "Sum:" << endl;
        sum.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        Matrix<int> product = matrix1 * matrix2;
        cout << "Product:" << endl;
        product.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Max element in Matrix 1: " << matrix1.getMaxElement() << endl;
    cout << "--------------------------------" << endl;
    cout << "Min element in Matrix 1: " << matrix1.getMinElement() << endl;
    cout << "--------------------------------" << endl;
}
