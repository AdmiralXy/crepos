#include <iostream>
#include "rational.h"

using namespace std;

int NOD(int a, int b) {
	if (a < 0)
		a *= -1;
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

Rational::Rational()
{
	num = 0;
	denum = 1;
}
Rational::Rational(int a)
{
	num = a;
	denum = 1;
}
Rational::Rational(int a, int b)
{
	int var = NOD(a, b);
	num = a / var;
	denum = b / var;
}

ostream& operator<<(ostream& out, Rational t) {
	out << t.num;
	if (t.denum != 1)
		out << "/" << t.denum;
	return out;
}

Rational Rational::operator +(Rational t) {
	return Rational(num * t.denum + denum * t.num, denum * t.denum);
}

Rational operator+(int a, Rational& t) {
	return t + a;
}

Rational Rational::operator -(Rational t) {
	return Rational(num * t.denum - denum * t.num, denum * t.denum);
}

Rational Rational::operator *(Rational t) {
	return Rational(num * t.num, denum * t.denum);
}

Rational Rational::operator /(Rational t) {
	return Rational(num * t.denum, denum * t.num);
}

Rational& Rational::operator +=(Rational &t) {
	num = num * t.denum + denum * t.num;
	denum = denum * t.denum;
	int var = NOD(num, denum);
	num /= var;
	denum /= var;
	return *this;
}

Rational& Rational::operator -=(Rational &t) {
	num *= t.denum - denum * t.num;
	denum *= t.denum;
	int var = NOD(num, denum);
	num /= var;
	denum /= var;
	return *this;
}

Rational& Rational::operator *=(Rational &t) {
	num *= t.num;
	denum *= t.denum;
	int var = NOD(num, denum);
	num /= var;
	denum /= var;
	return *this;
}

Rational& Rational::operator /=(Rational &t) {
	num *= t.denum;
	denum *= t.num;
	int var = NOD(num, denum);
	num /= var;
	denum /= var;
	return *this;
}

Rational& Rational::operator =(Rational &t) {
	num = t.num;
	denum = t.denum;
	return *this;
}

Rational Rational::operator -() {
	return Rational(num * -1, denum);
}

bool Rational::operator <(Rational t) {
	return num * t.denum < t.num*denum;
}

bool Rational::operator >(Rational t) {
	return num * t.denum > t.num*denum;
}

bool Rational::operator >=(Rational t) {
	return num * t.denum >= t.num*denum;
}

bool Rational::operator <=(Rational t) {
	return num * t.denum <= t.num*denum;
}

bool Rational::operator ==(Rational t) {
	return num * t.denum == t.num*denum;
}

bool Rational::operator !=(Rational t) {
	return num * t.denum != t.num*denum;
}