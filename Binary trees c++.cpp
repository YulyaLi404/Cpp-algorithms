#include <iostream>

int tabs = 0; // Для создания отступов
	      // Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в функцию print

struct Branch
{
	char Data; // Поле данных
	Branch *LeftBranch; // Указатели на соседние ветви
	Branch *RightBranch; 
};

// Функция внесения данных
void Add(char aData, Branch *&aBranch)
{
	// Если ветки не существуют
	if (!aBranch) {
		// Создадим ее и зададим в нее данные
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else if (aBranch->Data>aData) { //Иначе сверим вносимое
		        //Если оно меньше того, что в этой ветке - добавим влево
			Add(aData, aBranch->LeftBranch);
		}
		else { //Иначе в ветку справа
			Add(aData, aBranch->RightBranch);
		};
}

// Функция вывода дерева
void print(Branch *aBranch)
{
	if (!aBranch) { // Есои ветки не существует - выходим. Выводить нечего
		return;
	}
	tabs++; // Иначе увеличим счетчик рекурсивно вызванных процедур
	        // Который будет считать нам отступы для красивого вывода

	print(aBranch->LeftBranch); // Выведем ветку и ее подветки слева

	for (int i = 0; i < tabs; i++) { // Потом отступы
		std::cout << " ";
	}

	std::cout << aBranch->Data << std::endl; // Данные этой ветки

	print(aBranch->RightBranch); // И ветки, что справа

	tabs--; // После уменьшим кол-во отступов
	return;
}


void FreeTree(Branch *aBranch)
{
	if (!aBranch) {
		return;
	}
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}

int main()
{
	Branch *Root = 0;
	char s[] = "18452789";

	for (int i = 0; s[i]; i++) {
		Add(s[i], Root);
	}

	print(Root);
	FreeTree(Root);

	std::cin.get();

	system("Pause");
	return 0;
}
