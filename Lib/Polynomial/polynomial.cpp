#include <iostream>
#include "polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	coefficients = 0;
	number = 0;
}

Polynomial::Polynomial(int n, int C)
{
	number = n;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = C;
}

Polynomial::Polynomial(int n, const int* A)
{
	number = n;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = A[i];
}

Polynomial::Polynomial(const Polynomial& t)
{
	number = t.number;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = t[i];
}

Polynomial::~Polynomial()
{
	delete[] coefficients;
}

int Polynomial::degree() const
{
	return number - 1;
}

int Polynomial::operator[](int i) const
{
	return coefficients[i];
}

int Polynomial::operator()(int point)
{
	int res = 0;
	for (int i = degree(); i >= 0; i--)
		res = res * point + coefficients[i];
	return res;
}

Polynomial Polynomial::operator+(const Polynomial& t)
{
	int max = (number >= t.number) ? number : t.number;
	int min = (number >= t.number) ? t.number : number;
	
	// С конца пока сумма не равна нулю, либо индекс не отрицательный
	// если он 0 
	//Polynomial res(k,coefficients);
	int *temp = new int[max];

	for (int i = max - 1; i > min - 1; i--)
		temp[i] = coefficients[i];
	for (int i = min - 1; i >= 0; i--)
		temp[i] = coefficients[i] + t.coefficients[i];

	int normalize = 0;
	for (int i = max; temp[i - 1] == 0; i--)
		normalize++;

	Polynomial res(max - normalize, temp);
	delete[] temp;
	return res;
}

Polynomial Polynomial::operator+=(const Polynomial& t)
{
	// лишняя работа и если t = 0, то ничего не делать
	*this = *this + t;
	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& t)
{
	// лишняя работа
	return Polynomial(*this + -(Polynomial)(t));
}

Polynomial Polynomial::operator-=(const Polynomial& t)
{
	// лишняя работа
	*this = *this - t;
	return *this;
}

Polynomial Polynomial::operator-()
{
	for (int i = 0; i < number; i++)
		coefficients[i] = -coefficients[i];
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& t)
{
	// оператор *, если многочлен нулевой проверочка
	int i, j, max;
	max = number - 1 + t.number;
	int *temp = new int[max];
	for (int i = 0; i < max; i++)
		temp[i] = 0;

	for (i = number - 1; i >= 0; i--)
		for (j = t.number - 1; j >= 0; j--)
			temp[i + j] += (coefficients[i] * t.coefficients[j]);
	Polynomial res(max + 1, temp);
	delete[] temp;
	return res;
}

Polynomial Polynomial::operator*=(const Polynomial& t)
{
	// оператор *, если многочлен нулевой проверочка
	*this = *this * t;
	return *this;
}

Polynomial Polynomial::operator=(const Polynomial& t)
{
	delete[] coefficients;
	number = t.number;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = t.coefficients[i];
	return *this;
}

bool Polynomial::operator ==(const Polynomial& t)
{
	if (number != t.number)
		return false;
	else
		for (int i = 0; i < number; i++)
			if (coefficients[i] != t.coefficients[i])
				return false;
	return true;
}

bool Polynomial::operator !=(const Polynomial& t)
{
	return !(*this == t);
}

Polynomial Polynomial::operator *(int C) const
{
	//return Polynomial(*this * Polynomial(1, C));
}

Polynomial& Polynomial::operator *=(int C)
{
	// лишняя работа
	*this = *this * C;
	return *this;
}

Polynomial operator *(int C, const Polynomial& t) {
	//Polynomial res(t);
	//res *= C;
	return t*C;
}

ostream& operator<<(ostream& out, const Polynomial& t) {
	int i = t.degree();
	for (; i > 1; i--)
	{
		if (t[i])
			out << "(" << t[i] << ")" << "*x^" << i << " + ";
	}
	if (i - 1 != -1)
		if (t[i])
			out << "(" << t[i--] << ")*x + ";
	out << "(" << t[i] << ")";
	return out;
}