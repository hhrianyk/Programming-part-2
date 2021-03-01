
#include "prototaype.h"
#include "SR.h"


int Scientific_SR::vstup_info(number nov)
{

	Scientific_SR h = Scientific_SR();
	List_SR List;
	system("cls");
	number  a = 1, u = 0;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Доброго дня користувач\n ";

	std::cout << "\nЗараз: ";
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << __DATE__;
	std::cout << "\nЧас початку роботи програми: ", SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << __TIME__ << SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "\n\nВи знаходитесь у класi наслiднику 'наукові ргз' ";
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
				h.add_el(List);

			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			h.Riad_FL(List), a = 0;
			break;
		}
	}
	a = h.main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			system("cls");
			h.printTableHead();
			h.Print_run(List);
			break;
		case 2:	system("cls"),	h.dop_INFO(List);
			break;
		case 3:	system("cls") ,h.delet_el(List);
			break;
		case 4:	system("cls"),	h.Print_el(List);
			break;
		case 5: 
			system("cls"); 
			List.delete_list(List);
			std::cout << "Успішно";
		
			break; 
		case 6:nov = 0;
			List.delete_list(List);
			Scientific_SR();
			return 0;
		case 7:
			List.delete_list(List);
			{system("cls");
			nov = 1;
			return 1;
			}
		case 8:
			do
			{
				system("cls");
				RGZ p;
				p.vstup_info(nov);
				system("cls");
			} while (nov == 1);
			if (nov == 0) {
				List.delete_list(List);
				return 0;
			}
			else break;
		case 9:
			h.sortSTR(List);
			break;
			
		}
			char pit[] = "Бажаєте ще щось зробити?";
			a = yes_and_no(a, pit);
			if (a == 1)
				a = h.main_menu(a);
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
	std::cout << "  9. Сортувати... \n";

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

int Scientific_SR::kriter(number n)
{
	cout << "\nЗа яким крiтерiєм хочете сортувати список \n\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "  1.Викладач\n";
	cout << "  2.Предмет\n";
	cout << "  3.Наукова тема \n";
	cout << "  4.Строк здачі\n";
	cout << "  5.Кількість завдань\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << " \nваш вибiр: ";
	cin >> n;
	return n;
}
