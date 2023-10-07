#include <iostream>
// подключаем библиотеку malloc.h для возможности выделения памяти массиву на n ячеек
#include <malloc.h>
#include <cmath>
using namespace std;
// функция нахождения суммы n значений массива
int sumarr(int* a, int n) {
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
// функция для нахождения 1/2 значения типа int с округлением в меньшую сторону
int del2(int n) {
	if (n % 2 == 0) {
		return n / 2;
	}
	else {
		return (n - 1) / 2;
	}
}
int main() {
	int n;
	int pr1 = 0;
	cin >> n;
	int* cki = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> cki[i];
	}
	for (int i = 0; i < del2(sumarr(cki, n)); i++) {
		if (result(cki, n, (del2(sumarr(cki, n)) - i)) == 1) {
			pr1 = del2(sumarr(cki, n)) - i;
			break;
		}
	}
	int pr2 = sumarr(cki, n) - pr1;
	cout << "Минимальная разница между порциями = " << abs(pr2 - pr1);
}