#include <iostream>
// подключаем библиотеку malloc.h для возможности выделения памяти массиву на n ячеек
#include <malloc.h>
#include <cmath>
using namespace std;
// функция нахождения минимума
long long sum_arr = 0;
long long minrazn = LLONG_MAX;
long long minimum(long long a, long long b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
// функция для нахождения мин.разницы через сумму подмножества в множестве
int result(long long* a, int i, int n, long long sum) {
	if (i == n)
		return 0;
	minrazn = minimum(minrazn, abs(sum - (sum_arr - sum)));
	result(a, i + 1, n, sum);
	result(a, i + 1, n, sum + a[i]);
	return 0;
}
	int main() {
	int n;
	cin >> n;
	auto cki = (long long*)malloc(n * sizeof(long long));
	for (long long i = 0; i < n; i++) {
		cin >> cki[i];
		sum_arr += cki[i];
	}
	int i = 0;
	result(cki, i, n, 0);
	cout << "Минимальная разница между порциями Маши и Пети = " << minrazn;
	free(cki);
}