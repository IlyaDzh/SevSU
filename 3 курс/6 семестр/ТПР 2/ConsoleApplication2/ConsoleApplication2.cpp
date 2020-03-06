#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 7;
	int A1[n][n] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 }
	};
	int A2[n][n] = {
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 1 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 1 }
	};
	int R[n][n];
	int K[n][n];
	int unique[n] = { 1, 1, 1, 1, 1, 1, 1 };
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			R[i][j] = A2[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			K[i][j] = 0;

	cout << "Матрица предпочтений:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << A1[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	cout << "Матрица эквивалентности:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << A2[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	cout << "Классы эквивалентности R:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "R(x" << (i + 1) << ") = {";
		for (int j = 0; j < n; j++)
			if (R[i][j] == 1) 
				cout << " x" << (j + 1) << ",";
		cout << "}" << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		if (unique[i] == 1) {
			for (int j = 0; j < n; j++) {
				K[count][j] = R[i][j];
				if ((j != i) && (R[i][j] == 1)) 
					unique[j] = 0;
			}
			count++;
		}
	}

	cout << "Множество X/~:" << endl;
	for (int i = 0, l = 1; i < n; i++) {
		if (unique[i] == 1) {
			cout << "k" << l << " -> {";
			l++;
			for (int j = 0; j < n; j++) 
				if (R[i][j] == 1) 
					cout << " x" << (j + 1) << ",";
			cout << "}" << endl;
		}
	}
	cout << endl;

	int rate_unique[n] = { 0, 0, 0, 0, 0, 0, 0 };
	int sum = 0;
	int cnt = count - 1;

	while (cnt >= 0) {
		for (int i = 0; i < count; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				if (K[i][j] == 1) 
					for (int t = 0; t < n; t++) 
						sum = sum + A1[j][t];
			}

			if (sum == 0) {
				rate_unique[cnt] = i + 1;
				cnt--;
				for (int j = 0; j < n; j++) {
					if (K[i][j] == 1) {
						for (int t = 0; t < n; t++) A1[j][t] = 1;
						for (int t = 0; t < n; t++) A1[t][j] = 0;
					}
				}
			}
		}
	}

	cout << "Упорядоченное множество X/~:" << endl;
	for (int k = 0; k < count; k++) {
		if (k) cout << " -> ";
		cout << "k" << rate_unique[k];
	}
	cout << endl << endl;

	int** preference = new int* [count];
	for (int co = 0; co < count; co++)
		preference[co] = new int[count];

	for (int i = 0; i < count; i++) 
		for (int l = 0; l < count; l++) 
			preference[i][l] = 0;

	cnt = count;
	for (int i = count - 1; i >= 0; i--) {
		for (int j = cnt; j < count; j++)
			preference[rate_unique[i] - 1][rate_unique[j] - 1] = 1;
		cnt--;
	}

	float u_ot_k[n] = { 0, 0, 0, 0, 0, 0, 0 };

	for (int k = count - 2; k >= 0; k--) {
		if (rate_unique[k] < rate_unique[k - 1]) 
			u_ot_k[rate_unique[k] - 1] = rate_unique[k];
		else 
			u_ot_k[rate_unique[k] - 1] = -rate_unique[k];

		if (k == 0) {
			u_ot_k[rate_unique[k] - 1] = rate_unique[k];
			break;
		}
		else if ((rate_unique[k] > rate_unique[k - 1] && rate_unique[k] > rate_unique[k + 1])) 
			u_ot_k[rate_unique[k] - 1] = float(rate_unique[k - 1]) + (float(rate_unique[k + 1]) - float(rate_unique[k - 1])) / 2;
	}

	cout << "Функции полезности U(k):" << endl;
	for (int k = 0; k < count; k++) 
		cout << "U(k" << (rate_unique[k]) << ")=" << u_ot_k[rate_unique[k] - 1] << endl;
	cout << endl;

	cout << "Функции полезности U(x):" << endl;
	for (int k = 0; k < count; k++) 
		for (int j = 0; j < n; j++) 
			if (K[rate_unique[k] - 1][j] == 1) 
				cout << "U(x" << j + 1 << ")=" << u_ot_k[rate_unique[k] - 1] << endl;
	cout << endl;

	for (int co = 0; co < count; co++)
		delete[] preference[co];
}