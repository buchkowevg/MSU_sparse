#include "matrix_coord_row_column.h"
Matrix_column_coord::Matrix_column_coord(Matrix* m, unsigned int c)
{
    if(c >= m->get_length_y()) throw "out of range";
    coord_index = c;
    try
    {
        column = m->get_column(c);
    }
    catch(...)
    {

    }
}
void Matrix_column_coord::sync_to()
{
    try
    {
        mat->insert_column(column, coord_index);
    }
    catch(...)
    {

    }
}
void Matrix_column_coord::sync_from()
{
    try
    {
        column = mat->get_column(coord_index);
    }
    catch(...)
    {

    }
}

Matrix_row_coord::Matrix_row_coord(Matrix* m, unsigned int c)
{
    if(c >= m->get_length_y()) throw "out of range";
    coord_index = c;
    try
    {
        row = m->get_row(c);
    }
    catch(...)
    {

    }
}
void Matrix_row_coord::sync_to()
{
    try
    {
        mat->insert_row(row, coord_index);
    }
    catch(...)
    {

    }
}
void Matrix_row_coord::sync_from()
{
    try
    {
        row = mat->get_row(coord_index);
    }
    catch(...)
    {

    }
}

