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
        if(argc != 3)
        {
            cout << "number of arguments != 2" << endl;
            return 0;
        }
        Matrix mat1(argv[2]);
        Matrix mat2(argv[3]);
        char* s = to_string(mat1 * mat2);
        cout << s << endl;
        free(s);
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
