#include "matrix_coord_row_column.h"
Matrix_column_coord::Matrix_column_coord(Matrix* m, unsigned int c)
{
    mat = m;
    coord_index = c;
    column = m->get_column(c);
}
void Matrix_column_coord::sync_to()
{
    mat->insert_column(column, coord_index);
}
void Matrix_column_coord::sync_from()
{
    column = mat->get_column(coord_index);
}

Matrix_row_coord::Matrix_row_coord(Matrix* m, unsigned int c)
{
    mat = m;
    coord_index = c;
    row = m->get_row(c);
}
void Matrix_row_coord::sync_to()
{
    mat->insert_row(row, coord_index);
}
void Matrix_row_coord::sync_from()
{
    row = mat->get_row(coord_index);
}

