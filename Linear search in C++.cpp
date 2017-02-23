#include <iostream>
#include <iomanip>
#include <ctime>

int linSearch(int arr[], int requiredKey, int size); // Ëèíåéíûé ïîèñê
void showArr(int arr[], int size); // Ïîêàç ìàññèâà

int main()
{
	setlocale(LC_ALL, "Rus");
	const int arrSize = 50;
	int arr[arrSize];
	int requiredKey = 0; // Èñêîìîå çíà÷åíèå (êëþ÷)
	int nElement = 0; // Íîìåð ýëåìåíòà ìàññèâà
	srand(time(NULL));

	// Çàïèñü ñëó÷.÷èñåë â ìàññèâ îò 1 äî 50
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 1 + rand() % 50;
	}

	showArr(arr, arrSize);

	std::cout << "Êàêîå ÷èñëî íåîáõîäèìî èñêàòü? ";
	std::cin >> requiredKey; // Âûâîä èñêîìîãî ÷èñëà

	// Ïîèñê èñêîìîãî ÷èñëà è çàïèñü íîìåðà ýëåìåíòà
	nElement = linSearch(arr, requiredKey, arrSize);

	if (nElement != -1)
	{
		// Åñëè â ìàññèâå íàéäåíî èñêîìîå ÷èñëî - âûâîäèì èíäåêñ ýëåìåíòà íà ýêðàí
		std::cout << "Çíà÷åíèå " << " íàõîäèòüñÿ â ÿ÷åéêå ñ èíäåêñîì: " << nElement << std::endl;
	}
	else
	{
		// Åñëè â ìàññèâå íå íàéäåíî èñêîìîå ÷èñëî
		std::cout << "Â ìàññèâå íåò òàêîãî çíà÷åíèÿ" << std::endl;
	}

	system("Pause");
	return 0;
}

// Âûâîä ìàññèâà íà ýêðàí
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

// Ëèíåéíûé ïîèñê
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
