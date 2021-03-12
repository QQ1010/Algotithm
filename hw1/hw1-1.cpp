#include <cstdio>
#include <stdint.h>
#include <iostream>

using namespace std;

class matrix{
    public:
    long long **data;
    matrix() {}
    matrix(int32_t input_row , int32_t input_col) {
        row = input_row;
        col = input_col;
        data = new long long  *[row];
        for(int32_t i = 0 ; i < row ; i++){
            data[i] = new long long [col];
        }
    }
    void matrix_delete();
    void matrix_print();
    matrix& operator = (const matrix& rhs);
    matrix operator * (const matrix& rhs);
    private:
    int32_t row;
    int32_t col;
    
};
void matrix::matrix_delete() {
    for(int32_t i = 0 ; i < row ; i++)
    {
        delete data[i];
    }
    delete data;
}

void matrix::matrix_print() {
    cout << "============= matrix =============" << endl;
    for(int32_t i = 0 ; i < row ; i++)
    {
        for(int32_t j = 0 ; j < col ; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

matrix& matrix::operator = (const matrix& rhs) {
    this->matrix_delete();
    row = rhs.row;
    col = rhs.col;
    data = new long long*[row];
    for(int32_t i = 0 ; i < row ; i++)
    {
        data[i] = new long long[col];
    }
    for(int32_t i = 0 ; i < rhs.row ; i++)
    {
        for(int32_t j = 0 ; j < rhs.col ; j++)
        {
            data[i][j] = rhs.data[i][j];
        }
    }
    return *this;
}

matrix matrix::operator * (const matrix& rhs) {
    if(col != rhs.row) {
        cout << "This two matrix cannot mult." << endl;
    }
    else {
        matrix tmp(row,rhs.col);
        for(int32_t i = 0 ; i < row ; i++)
        {
            for(int32_t j = 0 ; j < rhs.col ; j++)
            {
                long long sum = 0;
                for(int32_t k = 0 ; k < rhs.row ; k++)
                {
                    sum = sum%1000000007 + (data[i][k]*rhs.data[k][j])%1000000007;
                }
                tmp.data[i][j] = sum;
            } 
        }
        return tmp;
    }
}

matrix pown(matrix A,int32_t n)  {
    matrix goal(2,2);
    goal.data[0][0] = 1;
    goal.data[0][1] = 0;
    goal.data[1][0] = 0;
    goal.data[1][1] = 1;
    matrix base1_A(2,2);
    base1_A = A;
    while(n > 1) {
        if(n%2 == 1) {
            goal = goal * base1_A;
        }
        A = A * A;
        n /= 2;
    }
    goal = goal * A;
    return goal;
}

int main()
{
    int64_t a1,a2,x,y,n,num;
    cin >> num;
    while(num --){
        cin >> a1 >> a2 >> x >> y >> n;
        matrix A(2,2);
        A.data[0][0] = x;
        A.data[0][1] = y;
        A.data[1][0] = 1;
        A.data[1][1] = 0;
        matrix B(2,1);
        B.data[0][0] = a2;
        B.data[1][0] = a1;
        matrix ans(2,1);
        ans = pown(A,n-2) * B;
        cout << ans.data[0][0]%1000000007 << endl;
    }
    return 0;
}