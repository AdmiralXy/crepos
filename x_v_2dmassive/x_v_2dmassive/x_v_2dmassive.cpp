#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	const int n = 5;
	const int m = 5;
	int x = 0;
	int o = 0;
	bool b = true;
	int M[n][m]
	  { 3, 3, 12, 17, 20,
		1, 4, 12, 16, 18,
		4, 4, 12, 17, 19,
		5, 6, 12, 8, 17,
		4, 5, 12, 14, 17 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
		for (int i = 0; i < m && b == true; i++) {
			x = M[0][i];
			cout << "SEARCH X: " << x << endl;
			for (int j = 1; j < m; j++) {
				int l = 0, r = m - 1;
				while (l < r) {
					int k = (l + r) / 2;
					if (M[j][k] < x)
						l = k + 1;
					else
						r = k;
				}
				if (x == M[j][r])
					o++;
				else
					o = 0;
			}
			if (o == 4) {
				b = false;
				cout << "X est!" << endl;
			}
		}
    return 0;
}

