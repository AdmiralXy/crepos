#ifndef pl_H
#define pl_H

#include <iostream>
using namespace std;

class Polynomial
{
private:
	int number;
	int *coefficients;
public:
	Polynomial();
	Polynomial(int, int);
	Polynomial(int, const int*);
	Polynomial(const Polynomial&);
	~Polynomial();
	int degree() const;
	int operator[](int) const;
	int operator()(int);
	Polynomial operator+(const Polynomial&);
	Polynomial operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator-=(const Polynomial&);
	Polynomial operator-();
	Polynomial operator*(const Polynomial&);
	Polynomial operator*=(const Polynomial&);
	Polynomial operator=(const Polynomial&);
	bool operator ==(const Polynomial&);
	bool operator !=(const Polynomial&);
	Polynomial operator *(int) const;
	Polynomial& operator *=(int);
	friend Polynomial operator *(int, const Polynomial&);
};

Polynomial operator *(int, const Polynomial&);
ostream& operator<<(ostream&, const Polynomial&);

#endif