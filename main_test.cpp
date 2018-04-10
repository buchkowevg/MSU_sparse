#include "rational_number.h"
#include "vector.h"
#include "matrix.h"
#include "vector_ex.h"
#include "matrix_ex.h"
#include "rational_number_ex.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    try
    {
        Vector vec(3);

        Rational_number rat = "3/27";
        Rational_number rat1 = "1/3";
        vec(0) = "1/2";
        vec(1) = "1/4";
        vec(2) = "1/16";
        Vector vec1(2);
        vec1(0) = "1";
        vec1(1) = "2";
        Matrix mat1(2);
        Matrix mat2(3);
        mat1(0,0) = "3";
        mat1(0,1) = "1";
        mat1(1,0) = "4";
        mat1(1,1) ="2";
        mat1 = mat1 * vec1;
        //Rational_number
        cout <<to_string(mat1) <<endl;
        //rat = rat / 0;
        //free(s);
    }
    catch(const Rational_number_ex ex)
    {
        cout << ex.what() << endl;
    }
    catch(const Matrix_ex ex)
    {
        cout << ex.what() << endl;
    }
    catch(const Vector_ex ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}
