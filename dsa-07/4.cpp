#include <iostream>
using namespace std;

void input(int&, int&);

// Dynamic Memory Allocation of 2D Arrays
class Dynamic2DArray
{
private:
    int rows;
    int cols;
    int** arr;
public:
    Dynamic2DArray() // default constructor
    {
        // input custom number of rows and cols for this object
        input(this->rows, this->cols);

        // Dynamic2DArray::rows = rows;
        arr = new int*[this->rows];

        // allocate rows, each with 'y' number of elments (cols):
        for (int i = 0; i < this->rows; i++)
        {
            // *(arr + i) = new int[this->cols];
            arr[i] = new int[this->cols];
        }
    }
    Dynamic2DArray(int& rows, int& cols) // constructor overloading
    {
        this->rows = rows; // (*this).rows = rows
        this->cols = cols;
        // Dynamic2DArray::rows = rows;
        arr = new int*[this->rows];

        // allocate rows, each with 'y' number of elments (cols):
        for (int i = 0; i < this->rows; i++)
        {
            *(arr + i) = new int[this->cols];
        }
    }
    ~Dynamic2DArray(){
        //deallocate rows:
        for (int i = 0; i < this->rows; i++)
        {
            delete[] (*(arr + i));
        }
        // deallocate the memory block containing pointers to the rows
        delete[] arr;

    }
    void inputFunction();
    void outputFunction();
};

void Dynamic2DArray::inputFunction()
{
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter elements in Row " << i + 1 << " :" << endl;
        for (int j = 0; j < cols; j++)
        {
            int temp = 0;
            cin >> temp;
            // *(*(arr + i) + j) = temp;
            arr[i][j] = temp; // *(*(arr + i) + j) => arr[i][j]
        }
        cout << endl;
    }
}

void Dynamic2DArray::outputFunction()
{
    cout << endl << "Printing the 2D Array:" << endl;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            // cout << *(*(this->arr + i) + j) << " ";
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void input(int& a, int& b)
{
    cout << "Rows: ";
    cin >> a;
    cout << "Columns: ";
    cin >> b;
    cout << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // x: rows & y: columns
    int x, y;
    cout << "Rows: ";
    cin >> x;
    cout << "Columns: ";
    cin >> y;
    cout << endl;
    cout << endl;

    // int* arr = new int[x][y]; // This is not possible:

    // 2D array arr[x][y] is nothing but: "'x' number of arrays, each with 'y' number of elements"
    // Hence we need 'x' number of int* pointers pointing to those 'x' number of arrays allocated in the memory dynamically

    // int** arr_2d = new int*[x];

    Dynamic2DArray arr_2d(x, y);
    arr_2d.inputFunction();
    arr_2d.outputFunction();
    // Calling Destructor so that we can delete the object and its properties. (& deallocate memory)
    arr_2d.~Dynamic2DArray();

    cout << endl << "------ Dynamically Allocated Object ------" << endl << endl;
    // Dynamic Allocation of Objects of a Class:
    // Dynamic2DArray* arr = new Dynamic2DArray(x, y);
    Dynamic2DArray* arr = new Dynamic2DArray; // new operator calls constructor, Here we are using default constructor

    // arr->inputFunction();
    // OR
    (*arr).inputFunction();

    arr->outputFunction();

    // deallocate dynamically allocated array:
    delete arr; // calls Destructor automatically

    return 0;
}