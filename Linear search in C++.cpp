#include <iostream>
#include <iomanip>
#include <ctime>

// ��������� �������
int linSearch(int arr[], int requiredKey, int size); // �������� �����
void showArr(int arr[], int size); // ����� �������

int main()
{
	setlocale(LC_ALL, "Rus");
	const int arrSize = 50;
	int arr[arrSize];
	int requiredKey = 0; // ������� �������� (����)
	int nElement = 0; // ����� �������� �������
	srand(time(NULL));

	// ������ ����.����� � ������ �� 1 �� 50
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 1 + rand() % 50;
	}

	showArr(arr, arrSize);

	std::cout << "����� ����� ���������� ������? ";
	std::cin >> requiredKey; // ����� �������� �����

	// ����� �������� ����� � ������ ������ ��������
	nElement = linSearch(arr, requiredKey, arrSize);

	if (nElement != -1)
	{
		// ���� � ������� ������� ������� ����� - ������� ������ �������� �� �����
		std::cout << "�������� " << " ���������� � ������ � ��������: " << nElement << std::endl;
	}
	else
	{
		// ���� � ������� �� ������� ������� �����
		std::cout << "� ������� ��� ������ ��������" << std::endl;
	}

	system("Pause");
	return 0;
}

// ����� ������� �� �����
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

// �������� �����
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