#include <iostream>
using namespace std;

class Polynomial
{
private:
    /* data */
public:
    int *degCoeff;
    int capacity;

    // Default Constructor
    Polynomial(/* args */)
    {
        this->capacity = 10;
        this->degCoeff = (int *)calloc(capacity, sizeof(int));
    }
    // Copy Constructor
    Polynomial(Polynomial const &P)
    {
        this->capacity = P.capacity;

        // Deep Copy
        // this->degCoeff = new int[capacity];
        this->degCoeff = (int *)calloc(capacity, sizeof(int));
        for (int i = 0; i < capacity; i++)
        {
            this->degCoeff[i] = P.degCoeff[i];
        }
    }
    // Copy Assignment operator
    Polynomial operator=(Polynomial const &P)
    {
        this->capacity = P.capacity;

        // Deep Copy
        // this->degCoeff = new int[capacity];
        this->degCoeff = (int *)calloc(capacity, sizeof(int));
        for (int i = 0; i < capacity; i++)
        {
            this->degCoeff[i] = P.degCoeff[i];
        }

        return *this;
    }

    // setCoefficient
    Polynomial setCoefficient(int degree, int coefficient)
    {
        int *newDegCoeff;
        while (this->capacity < degree)
        {
            newDegCoeff = (int *)calloc(2 * capacity, sizeof(int));
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            delete[] degCoeff;
            newDegCoeff = degCoeff;
            capacity *= 2;
        }
        this->degCoeff[degree] = coefficient;
        return *this;
    }

    // +
    Polynomial operator+(Polynomial const &P)
    {
        Polynomial pNew;
        pNew.capacity = max(this->capacity, P.capacity);
        for (int i = 0; i < pNew.capacity; i++)
        {
            pNew.degCoeff[i] = this->degCoeff[i] + P.degCoeff[i];
        }
        return pNew;
    }
    // -
    Polynomial operator-(Polynomial const &P)
    {
        Polynomial pNew;
        pNew.capacity = max(this->capacity, P.capacity);
        for (int i = 0; i < pNew.capacity; i++)
        {
            pNew.degCoeff[i] = this->degCoeff[i] - P.degCoeff[i];
        }
        return pNew;
    }

    // *
    Polynomial operator*(Polynomial const &P)
    {
        Polynomial pNew;
        pNew.capacity = this->capacity + P.capacity;

        int *newDegCoeff = (int *)calloc(pNew.capacity, sizeof(int));
        for (int i = 0; i < this->capacity; i++)
        {
            for (int j = 0; j < P.capacity; j++)
            {
                if (this->degCoeff[i] != 0 && P.degCoeff[j] != 0)
                {
                    newDegCoeff[i + j] = this->degCoeff[i] * P.degCoeff[i];
                }
            }
        }
        return pNew;
    }

    // print
    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (this->degCoeff[i] != 0)
            {
                cout << this->degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};
