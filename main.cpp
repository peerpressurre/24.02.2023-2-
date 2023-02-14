#include <iostream>
#include <ctime>
using namespace std;;
int main()
{
    int col = 5, row = 5;
    srand(time(0));
    int** arr_2d = new int* [col];
    int* rows = new int[col];
    for (size_t i = 0; i < col; i++)
    {
        arr_2d[i] = new int[row];
        rows[i] = row;
        for (size_t j = 0; j < row; j++)
        {
            arr_2d[i][j] = rand() % 10;
        }
    }
    //--------------PRINT----------------
    cout << "<---------1ST ARRAY--------------------->" << endl;
    for (size_t i = 0; i < col; i++)
    {
        cout << "Row [" << i << "]:  ";
        for (size_t j = 0; j < rows[i]; j++)
        {
            cout << arr_2d[i][j] << '\t';
        }
        cout << endl;
    }

    //--------------ADDING-----------------
    int** arr_2d_2 = new int* [col - 1];
    int* rows_2 = new int[col - 1];
    int index;
    cout << "Enter number of row to delete: ";
    cin >> index;
    for (size_t i = 0; i < col-1; i++)
    {
        arr_2d_2[i] = new int[row];
        rows_2[i] = row;
        for (size_t j = 0; j < row; j++)
        {
            if (i < index)
            {
                arr_2d_2[i][j] = arr_2d[i][j];
            }
            else
            {
                arr_2d_2[i][j] = arr_2d[i+1][j];
            }
        }
    }

    cout << endl << "\n";
    //--------------PRINT2----------------
    cout << "<---------2ND ARRAY--------------------->" << endl;
    for (size_t i = 0; i < col - 1; i++)
    {
        cout << "Row [" << i << "]:  ";
        for (size_t j = 0; j < row; j++)
        {
            cout << arr_2d_2[i][j] << '\t';
        }
        cout << endl;
    }
    //--------------DELETE----------------
    for (size_t i = 0; i < col; i++)
    {
        delete[] arr_2d[i];
    }
    delete[] arr_2d;

    for (size_t i = 0; i < col; i++)
    {
        delete[] arr_2d_2[i];
    }
    delete[] arr_2d_2;
    return 0;
}