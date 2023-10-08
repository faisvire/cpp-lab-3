#include <iostream>
// подключаем библиотеку malloc.h для возможности выделения памяти массиву на n ячеек
#include <malloc.h>
#include <cmath>
using namespace std;
// функция нахождения суммы n значений массива
int funcsumarr(int* a, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
// функция для нахождения суммы подмножества в множестве
bool result(int* a, int n, int sum) {
	if (sum == 0) {
		return 1;
	}
	else if (sum < 0 || n < 0) {
		return 0;
	}
	bool caseincl = result(a, (n - 1), sum - a[n]);
	bool caseexl = result(a, (n - 1), sum);
	return caseincl || caseexl;
}
int main() {
	int n;
	int pr1 = 0;
	cin >> n;
	int* cki = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> cki[i];
	}
	int sumarr = funcsumarr(cki, n);
	int sumarr2 = funcsumarr(cki, n) / 2;
	for (int i = 0; i < sumarr2; i++) {
		if (result(cki, n, sumarr2 - i) == 1) {
			pr1 = sumarr2 - i;
			break;
		}
	}
	int pr2 = sumarr - pr1;
	cout << "Минимальная разница между порциями = " << abs(pr2 - pr1);
}