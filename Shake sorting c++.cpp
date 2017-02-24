#include <iostream>

// Прототипы функций
void swapE1(int *arr, int i); // Ф-ция для обмена значений ячеек
void myShakerSort(int *arr, int size); //ф-ция "шейкер"-сортировки

int main()
{
	setlocale(LC_ALL, "rus");

	int size = 0;
	std::cout << "Размер массива: ";
	std::cin >> size;
	int *A = new int[size];

	for (int k = 0; k < size; k++) {
		A[k] = size - k; // запись значений по убыванию
		std::cout << A[k] << " | ";
	}

	myShakerSort(A, size); // сортировка

	std::cout << "\nМассив после сортировки:\n";
	for (int k = 0; k < size; k++) {
		std::cout << A[k] << " | ";
	}
	std::cout << std::endl;

	system("Pause");
	return 0;
}

void swapE1(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

void myShakerSort(int *arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;

	while (leftMark <= rightMark) {
		for (int i = rightMark; i >= leftMark; i--) {
			if (arr[i - 1] > arr[i]) {
				swapE1(arr, i);
			}
		}
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++) {
			if (arr[i - 1] > arr[i]) {
				swapE1(arr, i);
			}
		}
		rightMark--;

		std::cout << "\nИтерация: " << leftMark - 1; // просмотр количества итераций
	}
}
