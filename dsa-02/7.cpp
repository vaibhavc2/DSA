#include <iostream>
using namespace std;

// Arithmetic Progression

class AP
{
private:
    int a, n, d, terms;

public:
    void inputFunction();
    int nth_Term();
    int sumOf_AllTerms();
    int sumOf_nTerms();
    void outputFunction();
};

void AP::inputFunction()
{
    cout << endl
         << "First term(a): ";
    cin >> this->a;
    cout << endl
         << "Common Difference(d): ";
    cin >> this->d;
    cout << endl
         << "Total Number of Terms: ";
    cin >> this->terms;
    cout << endl
         << endl
         << "Enter the number of term you want to calculate: ";
    cin >> this->n;
}

int AP::nth_Term()
{
    int result = this->a + ((this->n - 1) * this->d);
    return result;
}

int AP::sumOf_AllTerms()
{
    int sum = 0;
    sum = (this->terms * ((2 * this->a) + ((this->terms - 1) * this->d))) / 2;
    return sum;
}

int AP::sumOf_nTerms()
{
    int sum = 0;
    sum = (this->n * ((2 * this->a) + ((this->n - 1) * this->d))) / 2;
    return sum;
}

void AP::outputFunction()
{
    cout << "nth Term of this AP is: " << nth_Term() << endl;
    cout << "Sum of " << this->n << " terms of this AP is: " << sumOf_nTerms() << endl;
    cout << "Sum of All terms of this AP is: " << sumOf_AllTerms() << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Given an Arithmetic Progression: 'AP = a * n + d', Try this AP calculator: " << endl;
    AP ap1;
    ap1.inputFunction();
    ap1.outputFunction();
    return 0;
}