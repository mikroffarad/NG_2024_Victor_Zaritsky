#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
    int cols;
    int rows;
    vector<vector<int>> data;
};

Matrix createMatrix(char name[]) {
    Matrix matrix;

    cout << "You're creating a " << name << endl;

    cout << "Enter the number of rows: ";
    cin >> matrix.rows;

    cout << "Enter the number of columns: ";
    cin >> matrix.cols;

    matrix.data.resize(matrix.rows, vector<int>(matrix.cols));

    cout << "Enter the matrix elements:\n";

    for (int row = 0; row < matrix.rows; row++) {
        for (int column = 0; column < matrix.cols; column++) {
            cout << "Element [" << row << "][" << column << "]: ";
            cin >> matrix.data[row][column];
        }
    }

    return matrix;
}

bool isEqual(Matrix matrix1, Matrix matrix2) {
    return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols ? true : false;
}

Matrix addOrSubtruct(Matrix matrix1, Matrix matrix2, char action) {
    Matrix result;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    result.data.resize(result.rows, vector<int>(result.cols));

    for (int row = 0; row < matrix1.rows; row++) {
        for (int col = 0; col < matrix1.cols; col++) {
            if (action == '+') {
                result.data[row][col] = matrix1.data[row][col] + matrix2.data[row][col];
            }
            if (action == '-') {
                result.data[row][col] = matrix1.data[row][col] - matrix2.data[row][col];
            }
        }
    }

    return result;
}

void displayMatrix(Matrix result) {
    for (int row = 0; row < result.rows; row++) {
        for (int colunm = 0; colunm < result.cols; colunm++) {
            cout << result.data[row][colunm] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix matrix1 = createMatrix("Martix 1");
    Matrix matrix2 = createMatrix("Matrix 2");

    if (isEqual(matrix1, matrix2)) {
        char action;
        cout << "Matrixes are equal!\nEnter an action: ";
        cin >> action;
        Matrix result = addOrSubtruct(matrix1, matrix2, action);
        displayMatrix(result);
    } else {
        cout << "It's sad( They're not equal";
    }
    cout << endl;
}
