#include "rational_number.h"
#include "vector.h"
#include "matrix.h"
#include "vector_ex.h"
#include "matrix_ex.h"
#include "rational_number_ex.h"
#include <iostream>
#include <stdlib.h>
#define SQUARE_ZERO 0
#define SQUARE_DIAOGONAL 1
#define SQUARE_NON_DIAG 2
#define MATRIX_ZERO 3
#define MATRIX 4
#define MATRIX_CIN 5
#define VECTOR_ZERO 6
#define VECTOR 7
#define VECTOR_CIN 8
using namespace std;

int main(int argc, char** argv)
{
    unsigned int flag = 0;
    if(argc < 2)
    {
        cout << "Not enough arguments" << endl;
        return 0;
    }
    flag = atoi(argv[1]);
    try
    {
        if(flag ==  SQUARE_ZERO)
        {
            if(argc < 4)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Matrix(atoi(argv[2])).write(argv[3]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == SQUARE_DIAOGONAL)
        {
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Matrix(atoi(argv[2]), Rational_number(argv[3])).write(argv[4]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == SQUARE_NON_DIAG)
        {
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Matrix(atoi(argv[2]), Rational_number(argv[3]), 1).write(argv[4]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == MATRIX_ZERO)
        {
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Matrix(atoi(argv[2]), atoi(argv[3])).write(argv[4]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == MATRIX)
        {
            if(argc < 6)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Matrix(atoi(argv[2]), atoi(argv[3]), Rational_number(argv[4])).write(argv[5]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == MATRIX_CIN)
        {
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            char buf[1000];
            Matrix mat(atoi(argv[2]), atoi(argv[3]));
            Rational_number rat;
            for(unsigned int i = 0; i < mat.get_length_x(); i++)
                for(unsigned int j = 0; j < mat.get_length_y(); j++)
                {
                    cout << '[' << i + 1 << ']' << '[' << j + 1 << "] = ";
                    cin >> buf;
                    rat = buf;
                    if(rat != 0)
                        mat(i, j) = rat;
                }
            mat.write(argv[4]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == VECTOR_ZERO)
        {
            if(argc < 4)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Vector(atoi(argv[2])).write(argv[3]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == VECTOR)
        {
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            Vector(atoi(argv[2]), Rational_number(argv[3])).write(argv[4]);
            cout << "Done" << endl;
            return 0;
        }
        if(flag == VECTOR_CIN)
        {
            if(argc < 4)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            char buf[1000];
            Vector vec(atoi(argv[2]));
            Rational_number rat;
            for(unsigned int i = 0; i < vec.get_number_of_elements(); i++)
            {
                cout << '[' << i + 1 << "] = ";
                cin >> buf;
                rat = buf;
                if(rat != 0)
                    vec(i) = rat;
            }
            vec.write(argv[3]);
            cout << "Done" << endl;
            return 0;
        }
    }
    catch(const Rational_number_ex ex)
    {
        cout << ex.what() << endl;
        return 1;
    }
    catch(const Matrix_ex ex)
    {
        cout << ex.what() << endl;
        return 1;
    }
    catch(const Vector_ex ex)
    {
        cout << ex.what() << endl;
        return 1;
    }
    return 0;

}
