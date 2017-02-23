#include <iostream>
#include <string>

// Функция для поиска подстроки в строке
// + поиск позиции, с которой начинается подстрока
int pos(char *s, char *c, int n);

int main()
{
	char *s = "parapapa";
	char *c = "pa";

	int i, n = 0;

	for (i = 1; n != -1; i++) {
		n = pos(s, c, i);

		if (n >= 0) {
			std::cout << n << std::endl;
		}
	}

	std::string z = "parapapa";

	for (i = z.find("pa", i++); i != std::string::npos; i = z.find("pa", i + 1)) {
		std::cout << i << std::endl;
	}

	setlocale(LC_ALL, "rus");
	std::string r = "Hello world";
	std::cout << "Найдено в позиции " << r.find("lo") << std::endl;

	system("Pause");
	return 0;
}

int pos(char *s, char *c, int n)
{
	int i, j;        // Счетчики для циклов
	int lenC, lenS;  // Длины строк

	// Находим размеры строки исходника и искомого
	for (lenC = 0; c[lenC]; lenC++);
	for (lenS = 0; s[lenS]; lenS++);

	for (i = 0; i <= lenS - lenC; i++) {   // Пока есть возможность поиска
		for (j = 0; s[i + j] == c[j]; j++);  // Проверяем совпадение посимвольно
										                     // Если посимвольно совпадает по длине искомого
											                   // Вернем из функции номер ячейки, откуда начинается совпадение
											                   // учитывать 0-терминатор ( '\0' )
		if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) {
			return i;
		}
		if (j == lenC) {
			if (n - 1) {
				n--;
			}
			else {
				return i;
			}
		}
	}
	// Иначе вернем -1 как результат отсутствия подстроки
	return -1;
}
