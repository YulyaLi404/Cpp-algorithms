#include <iostream>

// Прототип функции, которая выполнит сортировку "пузырьком"
void bubbleSort(int arrForSort[], const int SIZE);

void main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 5;
	int arr[SIZE];

	std::cout << "Исходный массив:\n";
	for (int i = 0; i < SIZE; i++) {
		arr[i] = SIZE - i; // Заполняем значениями по убыванию
		std::cout << arr[i] << "\n_\n";
	}
	std::cout << "\n\n";

	bubbleSort(arr, SIZE); // передаем в функцию для сортировки

	std::cout << "Массив после сортировки:\n";
	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i] << "\n\n";
	}
	std::cout << "\n\n";

	system("Pause");
}

void bubbleSort(int arrForSort[], const int SIZE)
{
	int buff = 0;  // Для временного хранения значения, при перезаписи

	for (int i = 0; i < SIZE - 1; i++) {
		// Вложенный цикл проходит от четвертого элемента
		// До первого, находит с помощью if самое "легкое" значение,
		// Сравнивая соседние пары элементов,
		// И поднимает его в нулевую ячейку массива
		for (int j = SIZE - 1; j > i; j--) {
			if (arrForSort[j] < arrForSort[j - 1]) {
				buff = arrForSort[j - 1];
				arrForSort[j - 1] = arrForSort[j];
				arrForSort[j] = buff;
			}
		}
		// Далее значение i увеличивается на 1
		// И внутри цикл будет перебирать элементы
		// От четвертого до второго. Таким образом поднимет самое
		// "Легкое" значение из оставшихся в первую ячейку и т.д.
	}
}
