#ifndef rational_H
#define rational_H

using namespace std;

int NOD(int a, int b);

class Rational {
private:
	int num, denum;
public:
	Rational();
	Rational(int a);
	Rational(int a, int b);
	Rational operator +(Rational);
	Rational operator -(Rational);
	Rational operator *(Rational);
	Rational operator /(Rational);
	Rational& operator +=(Rational& t);
	Rational& operator -=(Rational& t);
	Rational& operator *=(Rational& t);
	Rational& operator /=(Rational& t);
	Rational& operator =(Rational& t);
	Rational operator -();
	bool operator >(Rational);
	bool operator <(Rational);
	bool operator >=(Rational);
	bool operator <=(Rational);
	bool operator ==(Rational);
	bool operator !=(Rational);

	friend ostream& operator<< (ostream& out, Rational temp);
	friend Rational operator+(int value, Rational& t);
};

#endif