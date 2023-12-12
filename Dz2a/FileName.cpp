#include <iostream>
using namespace std;
int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		cout << "Введите элемент" << i + 1 << ":";
		cin >> a[i];
	}
	cout << "элементы массива:";
	for (int k = 0; k < 10; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
	int s = 0;
	int b = 0;
	while (b < 10) {
		s = s + a[b];
		b = b + 1;
	}
	cout << "Сумма всех элементов массива: " << s << endl;
	int max = 0;
	for (int t = 0; t < 10; t++) {
		if (a[t] > max) {
			max = a[t];
		}
	}
	cout << "Максимальный элемент массива: " << max << endl;
	cout << "Отсортированный массив: ";
	for (int c = 1; c < 10; c++)
		for (int j = c; j > 0 && a[j - 1] < a[j]; j--)
			swap(a[j - 1], a[j]);
	for (int d = 0; d < 10; d++) {
		cout << a[d] << " ";
	}
	return 0;
}


}