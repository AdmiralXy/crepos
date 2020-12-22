#include <omp.h>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "");

	int a = 0;
	int b = 0;

	printf("До входа в область 1: a=%d b=%d\n", a, b);
	#pragma omp parallel num_threads(2) private(a) firstprivate(b) // первая область, 2 нити, a и b защищённые
	{
		a = 0;
		a += omp_get_thread_num(); // увеличить значение на номер нити
		b += omp_get_thread_num(); // увеличить значение на номер нити
		printf("Область 1: Номер нити=%d a=%d b=%d\n", omp_get_thread_num(), a, b); // получить номер нити и значения a и b
	}
	printf("После выхода из области 1: a=%d b=%d\n", a, b);
	cout << endl;
	printf("До входа в область 2: a=%d b=%d\n", a, b);
	#pragma omp parallel num_threads(4) shared(a) private(b) // вторая область, 4 нити, a общая, b защищённая
	{
		b = 0;
		a -= omp_get_thread_num(); // уменьшить значение на номер нити
		b -= omp_get_thread_num(); // уменьшить значение на номер нити
		printf("Область 2: Номер нити=%d a=%d b=%d\n", omp_get_thread_num(), a, b);
	}
	printf("После выхода из области 2: a=%d b=%d\n", a, b);
}