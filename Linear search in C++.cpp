#include <iostream>
#include <iomanip>
#include <ctime>

// Прототипы функций
int linSearch(int arr[], int requiredKey, int size); // Линейный поиск
void showArr(int arr[], int size); // Показ массива

int main()
{
	setlocale(LC_ALL, "rus");
	const int arrSize = 50;
	int arr[arrSize];
	int requiredKey = 0; // Искомое значение (ключ)
	int nElement = 0; // Номер элемента массива
	srand(time(NULL));

	// Запись случ.чисел в массив от 1 до 50
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 1 + rand() % 50;
	}

	showArr(arr, arrSize);

	std::cout << "Какое число необходимо искать? ";
	std::cin >> requiredKey; // Вывод искомого числа

	// Поиск искомого числа и запись номера элемента
	nElement = linSearch(arr, requiredKey, arrSize);

	if (nElement != -1)
	{
		// Если в массиве найдено искомое число - выводим индекс элемента на экран
		std::cout << "Значение " << " находиться в ячейке с индексом: " << nElement << std::endl;
	}
	else
	{
		// Если в массиве не найдено искомое число
		std::cout << "В массиве нет такого значения" << std::endl;
	}

	system("Pause");
	return 0;
}

// Вывод массива на экран
void showArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << std::setw(4) << arr[i];
		if ((i + 1) % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

// Линейный поиск
int linSearch(int arr[], int requiredKey, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == requiredKey)
		{
			return i;
		}
	}
	return -1;
}
