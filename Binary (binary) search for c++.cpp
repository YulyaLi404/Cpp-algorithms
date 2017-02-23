#include <iostream>

// Прототип функции
int Search_Binary(int arr[], int left, int right, int key); // Алгоритм бинарного поиска

int main()
{
	setlocale(LC_ALL, "Rus");

	const int SIZE = 12;
	int array[SIZE] = {};
	int key = 0;
	int index = 0; // Индекс ячейки с искомым значением

	for (int i = 0; i < SIZE; i++) {     // Заполняем и показывем массив
		array[i] = i + 1;
		std::cout << array[i] << " | ";
	}

	std::cout << "\n\nВведите любое число: ";
	std::cin >> key;

	index = Search_Binary(array, 0, SIZE, key);

	if (index >= 0) {
		std::cout << "Указанное число находиться в ячейке с индексом: " << index << "\n\n";
	}
	else {
		std::cout << "В массиве нет такого числа!\n\n";
	}

	system("Pause");
	return 0;
}

int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1) {
		midd = (left + right) / 2;

		if (key < arr[midd]) {       // Если искомое меньше значения в ячейке
			right = midd - 1;        // Смещаем правуб границу поиска
		}
		else if (key > arr[midd]) {  // Если искомое больше значения в ячейке
			left = midd + 1;         // Смещаем левую границу поиска
		}
		else {						 // Иначе (значения равны)
			return midd;             // Функция возвращает индекс ячейки
		}

		if (left > right) {			 // Если границы сомкнулись
			return -1;
		}
	}
}
