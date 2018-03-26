#include "rational_number.h"
#include "vector.h"
#include "matrix.h"
#include "vector_ex.h"
#include "matrix_ex.h"
#include "rational_number_ex.h"
#include "matrix_coord.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    try
    {
        if(argc < 4)
        {
            cout << "Not enough arguments" << endl;
            return 0;
        }
        bool flag = atoi(argv[1]);
        if(flag == 0)
        {
            Matrix mat(argv[2]);
            double dub[mat.get_length_x()][mat.get_length_y()];
            for(unsigned int i = 0; i < mat.get_length_x(); i++)
                for(unsigned int j = 0; j < mat.get_length_y(); j++)
                    dub[i][j] = mat[Matrix_coord(i, j)].get_double();
            ofstream OutFile;
            OutFile.open(argv[3], ios::out | ios::binary);
            unsigned int x = mat.get_length_x();
            unsigned int y = mat.get_length_y();
            OutFile.write( (char*)(&x), sizeof(unsigned int));
            OutFile.write( (char*)(&y), sizeof(unsigned int));
            OutFile.write( (char*)dub, sizeof(double) * mat.get_length_y() * mat.get_length_x());
            OutFile.close();
            cout << "Done" << endl;
            return 0;
        }
        else
        {
            unsigned int x;
            unsigned int y;
            unsigned int power;
            Rational_number rat;
            if(argc < 5)
            {
                cout << "Not enough arguments" << endl;
                return 0;
            }
            power = 10^atoi(argv[4]);
            ifstream InFile;
            InFile.open(argv[2], ios::binary);
            InFile.read(reinterpret_cast<char*>(&x), sizeof(unsigned int));
            InFile.read(reinterpret_cast<char*>(&y), sizeof(unsigned int));
            double dub[x][y];
            InFile.read(reinterpret_cast<char*>(&dub), sizeof(double) * x* y);
            Matrix mat(x,y);
            for(unsigned int i = 0; i < mat.get_length_x(); i++)
                for(unsigned int j = 0; j < mat.get_length_y(); j++)
                {
                    if(dub[i][j] != 0)
                    {
                        rat = (long int)(dub[i][j] * power);
                        rat /= power;
                        rat.make_canonical();
                        mat(i ,j) = rat;
                    }
                }
            mat.write(argv[3]);
            cout << "Done" << endl;
        }

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
    catch(...)
    {
        cout << "File ex" << endl;
    }
    return 0;
}

