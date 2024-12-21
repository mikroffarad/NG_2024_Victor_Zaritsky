#include <iostream>
#include <vector>
#include <iomanip> // for std::setw

using namespace std;

struct Matrix {
    vector<vector<int>> data;

    void input(const string& name) {
        int rows, cols;
        cout << "You're creating a " << name << endl;
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> cols;

        data.resize(rows, vector<int>(cols));

        cout << "Enter the matrix elements:\n";
        for (int counterRows = 0; counterRows < rows; counterRows++) {
            for (int counterCols = 0; counterCols < cols; counterCols++) {
                cout << "Element [" << counterRows << "][" << counterCols << "]: ";
                cin >> data[counterRows][counterCols];
            }
        }
    }

    void display() const {
        // Determine the maximum length of any element in the matrix
        int maxWidth = 0;
        for (const auto& row : data) {
            for (int value : row) {
                int width = to_string(value).length(); // Determine the length of number
                if (width > maxWidth) {
                    maxWidth = width;
                }
            }
        }

        // Print the matrix with proper alignment
        for (const auto& row : data) {
            for (int value : row) {
                cout << std::setw(maxWidth + 1) << value; // Align elements by setting a fixed column width
            }
            cout << endl;
        }
    }

    int getRowsNumber() const {
        return data.size();
    }

    int getColsNumber() const {
        return data.empty() ? 0 : data[0].size();
    }

    bool isEqualSize(const Matrix& anotherMatrix) const {
        return getRowsNumber() == anotherMatrix.getRowsNumber() && getColsNumber() == anotherMatrix.getColsNumber();
    }

    Matrix performOperation(const Matrix& anotherMatrix) {
        if (!isEqualSize(anotherMatrix)) {
            throw invalid_argument("Matrices must be of the same size.");
        }

        Matrix result;
        result.data.resize(getRowsNumber(), vector<int>(getColsNumber()));

        char operation;
        cout << "Enter an operation (+ or -): ";
        cin >> operation;

        for (int counterRows = 0; counterRows < getRowsNumber(); counterRows++) {
            for (int counterCols = 0; counterCols < getColsNumber(); counterCols++) {
                if (operation == '+') {
                    result.data[counterRows][counterCols] = data[counterRows][counterCols] + anotherMatrix.data[counterRows][counterCols];
                } else if (operation == '-') {
                    result.data[counterRows][counterCols] = data[counterRows][counterCols] - anotherMatrix.data[counterRows][counterCols];
                } else {
                    throw invalid_argument("Invalid operation.");
                }
            }
        }
        return result;
    }
};

int main()
{
    Matrix matrix1;
    Matrix matrix2;

    matrix1.input("Martix 1");
    matrix2.input("Martix 2");

    Matrix result;
    result = matrix1.performOperation(matrix2);
    result.display();
}
