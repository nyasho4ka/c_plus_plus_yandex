#include <vector>
#include <iostream>
using namespace std;


class Matrix {
public:
    Matrix() {
        _matrix = {{}};
    }
    Matrix(int num_rows, int num_cols) {
        BuildMatrix(num_rows, num_cols);
    }

    void BuildMatrix(int num_rows, int num_cols) {
        _matrix = {};
        for (int i = 0; i < num_rows; i++) {
            _matrix.push_back(vector<int>());
            for (int j = 0; j < num_cols; j++) {
                _matrix[i].push_back(0);
            }
        }
    }

    void Reset(int num_rows, int num_cols) {
        BuildMatrix(num_rows, num_cols);
    }

    int GetNumRows() const{
        return _matrix.size();
    }

    int GetNumCols() const{
        return _matrix[0].size();
    }

    void CheckIndices(int row, int col) const {
        if (row >= GetNumRows() || col >= GetNumCols()) {
            throw out_of_range("There is no element with such index: [" + to_string(row) + "," + to_string(col) + "]");
        }
    }

    int At(int row, int col) const{
        CheckIndices(row, col);
        return _matrix[row][col];
    }

    int& At(int row, int col) {
        CheckIndices(row, col);
        return _matrix[row][col];
    }

    void SetAt(int row, int col, int value) {
        CheckIndices(row, col);
        _matrix[row][col] = value;
    }

private:
    vector<vector<int>> _matrix;
};

istream& operator>>(istream& stream, Matrix& matrix) {
    int num_rows, num_cols;
    int current_value;
    stream >> num_rows >> num_cols;
    matrix = Matrix(num_rows, num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            stream >> current_value;
            matrix.SetAt(i, j, current_value);
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, Matrix& matrix) {
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumRows() << endl;
    for (int i = 0; i < matrix.GetNumRows(); i++) {
        for (int j = 0; j < matrix.GetNumCols(); j++) {
            stream << matrix.At(i, j);
            if (j != matrix.GetNumCols() - 1) {
                stream << ' ';
            }
        }
        if (i != matrix.GetNumRows() - 1) {
            stream << endl;
        }
    }
    return stream;
}

bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix) {
    if (
        leftMatrix.GetNumRows() != rightMatrix.GetNumRows()
        || leftMatrix.GetNumCols() != rightMatrix.GetNumCols()
    ) {
        return false;
    }
    for (int i = 0; i < leftMatrix.GetNumRows(); i++) {
        for (int j = 0; j < leftMatrix.GetNumCols(); j++) {
            if (leftMatrix.At(i, j) != rightMatrix.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(const Matrix& leftMatrix, const Matrix& rightMatrix) {
    if (
        leftMatrix.GetNumRows() != rightMatrix.GetNumRows()
        || leftMatrix.GetNumCols() != rightMatrix.GetNumCols()
    ) {
        throw invalid_argument("Matrices' sizes are not equal! ["
                               + to_string(leftMatrix.GetNumRows()) + "," + to_string(leftMatrix.GetNumCols()) + "] ,["
                               + to_string(rightMatrix.GetNumRows()) + "," + to_string(rightMatrix.GetNumCols()) + "]");
    }
    Matrix matrix;
    matrix.Reset(leftMatrix.GetNumRows(), leftMatrix.GetNumCols());
    for (int i = 0; i < leftMatrix.GetNumRows(); i++) {
        for (int j = 0; j < leftMatrix.GetNumCols(); j++) {
            matrix.SetAt(i, j, leftMatrix.At(i,j) + rightMatrix.At(i, j));
        }
    }
    return matrix;
}

int main(){
    Matrix matrix1;
    Matrix matrix2;
    cin >> matrix1;
    cin >> matrix2;
    cout << "---------------" << endl;
    cout << matrix1 << endl;
    cout << "---------------" << endl;
    cout << matrix2 << endl;
    cout << "---------------" << endl;
    cout << "Are matrix equal? " << to_string(matrix1 == matrix2) << endl;
    cout << "---------------" << endl;
    Matrix matrix3 = matrix1 + matrix2;
    cout << matrix3 << endl;
    return 0;
}