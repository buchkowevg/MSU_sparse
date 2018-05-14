#include <cstdlib>
#include <iostream>

#include "rational_number.h"
#include "vector.h"
#include "matrix.h"
#include "sparse_ex.h"
#include "matrix_coord_row_column.h"

using namespace std;

int main(int argc, char** argv)
{
    try
    {
        cout << Vector(3,Rational_number("1/2")) << endl;
    }
    catch(const Sparse_ex &ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}

