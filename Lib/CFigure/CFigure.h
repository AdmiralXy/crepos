#ifndef CFigure_H
#define CFigure_H


class Hairbrush // ����������� ������ ���������, ��� ����� � �����������
{
private:
	double width; // ����� ���������
	double height; // ������ ���������
	int teethsHeight; // ������ ������
	int teethsNumber; // ���������� ������
	double space; // ���������� ����� �������
	int heightOfHandle; // ������ �����
	void calculate(); // ������ ����������
public:
	Hairbrush(); // ����������� �� ���������
	Hairbrush(const Hairbrush &); // ����������� �����������
	~Hairbrush(); // ����������
	int initialize(int, int, int, int); // ������������� ���������� ������ ���������
	void resize(int w); // ��������� ������
	void setTeethsHeight(int n); // ��������� ������ ������
	void setTeethsNumber(int n); // ��������� ���������� ������
	void setHeightHandle(int n); // ��������� ������ �����
	void print();
};

#endif