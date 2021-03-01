
#include "prototaype.h"
#include "SR.h"


int vstup_info2(number nov)
{

	RGZ* h = NULL;
	system("cls");
	number  a = 1, u = 0;
	h->rBgz.Init(h);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Доброго дня користувач\n ";
	std::cout << "\nЗараз: ";
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << __DATE__;
	std::cout << "\nЧас початку роботи програми: ", SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << __TIME__ << SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "\n\nВи знаходитесь у класi наслiднику ";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n Почнемо роботу\n\n Ввести данi\n ";
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
		cin >> a;
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cout << "Скiльки елементiв ви хочете додати? :";
			std::cin >> a;
			for (int i = 0; i < a; i++)
				h->rBgz.add_el(h);

			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			h->rBgz.Riad_FL(h), a = 0;
			break;
		}
	}
	a = h->rBgz.main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			system("cls");
			h->rBgz.printTableHead();
			h->rBgz.Print_run(h);
			break;
		case 2:	system("cls"),	h->rBgz.dop_INFO(h);
			break;
		case 3:	system("cls") ,h->rBgz.delet_el(h);
			break;
		case 4:	system("cls"),	h->rBgz.Print_el(h);
			break;
		case 5: 
			system("cls"); 
			h->rBgz.delete_list(h);
			std::cout << "Успішно";
			h->rBgz.Init(h);
			break; 
		case 6:nov = 0;
			h->rBgz.delete_list(h);
			SR();
			return 0;
		case 7:
			h->rBgz.delete_list(h);
			{system("cls");
			nov = 1;
			return 1;
			}
		case 8:
			do
			{
				system("cls");
				vstup_info(nov);
				system("cls");
			} while (nov == 1);
			if (nov == 0) {
				h->rBgz.delete_list(h);
				return 0;
			}
			else break;
			
		}
			char pit[] = "Бажаєте ще щось зробити?";
			a = yes_and_no(a, pit);
			if (a == 1)
				a = h->rBgz.main_menu(a);
			else a = 6;

		
	}
}
int Scientific_SR::main_menu(number e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));

	std::cout << " \n  1. Вивести на екран список\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. Додати елемент в список\n";
	std::cout << "  3. Видалити елемент з списку за номереом\n";
	std::cout << "  4. Відобразити елемент списку за номером\n";
	std::cout << "  5. Очистити список \n";
	std::cout << "  6. Завершити роботу \n";
	std::cout << "  7. Перезавантажити програму програму \n";
	std::cout << "  8. Перейти до базового класу \n";

	/*std::cout << "  12.Сортувати \n";*/

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \nваш вибiр: ";
	std::cin >> e;
	return e;
}


void Scientific_SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  Прізвище    |   Предмет    |      Наукова     |Строк здачi| Кiлькiсть |" << std::endl;
	std::cout << "|         |    викладача |              |     темаматика   |    RGZ    |   завдань |" << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
}


int Start_Menu(number n)
{

	cout << "\nВиберіть список, яким ви хочете керувати: \n\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "   список Базовий клас -> 1\n   список Наслідник ---- > 2\n";

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << " \nваш вибiр: ";
	cin >> n;

	switch (n)
	{
	case 1:n = vstup_info(n);///

		break;
	case 2:n = vstup_info2(n);//
		break;
	}


	return n;
}