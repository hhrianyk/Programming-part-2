#include "prototaype.h"
#include "SR.h"
#include "my_ptr.h"



////Файл у якому міститься споміжний текс для роботи класу РГЗ



int Start_Menu(number n)
{
	vector< unique_ptr<RGZ>> a; 
	vector< shared_ptr <RGZ>> b;
	vector <  my::UNO<RGZ>> d;


	RGZ A;

	while (n != 0)
	{
		n = 1;
		int k;
		cout << "\nВиберіть в списоку, яким контейнером керувати: \n\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		cout << "   unique_ptr -----> 1\n   shared_ptr -----> 2\n   my::UNO --------> 3\n ";

		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << " \nваш вибiр: ";
		cin >> k;
		system("cls");

		while (n != 3)
		{

			cout << "\nВиберіть в списоку, чим ви хочете оперувати: \n\n";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << "   список RGZ & Scientific_SR--------- >1\n\n   попереднє меню -------------------- >3  \n   Завершити роботу------------------- >4  \n  ";
			
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			cout << " \nваш вибiр: ";
			cin >> n;
			do 
			{
				switch (n)
				{
				case 1: n = A.vstup_info(n, k, a, b, d);
					break;
				
				case 3: n = 3, system("cls");
					break;
				case 4: a.clear(), d.clear();
					return n;
					break;

				}
			} while (n>3);
		}
	}
	
}

int RGZ::main_menu(number e)
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
	std::cout << "  6. визначення кількості елементів за заданим критерієм\n";
	std::cout << "  7. пошук елементу за заданим критерієм.\n";
	std::cout << "  8. TEST(ваші дані будуть знищенні!!!)\n\n";


	
	std::cout << "  11. Перейти до попереднього меню \n";
	std::cout << "  12. Завершити роботу \n";

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \nваш вибiр: ";
	std::cin >> e;
	system("cls");
	return e;
}


int yes_and_no(number& t, string p)
{
	std::cout << "\n\n" << p << "\n ";
	std::cout << "так- 1\n ";
	std::cout << "нi- 2\n ";
	std::cout << "вибрана робота :";
	std::cin >> t;

	return t;

}

void RGZ::printTableHead()
{
	//std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	//std::cout << "|         |  Предмет     |   Темa       | Кiлькiсть балiв  |Строк здачi| Кiлькiсть |" << std::endl;
	//std::cout << "|         |              |              |за виконане RGZ   |    RGZ    |   завдань |" << std::endl;
	//std::cout << "----------+--------------+--------------+------------------+-----------+------------" << std::endl;
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|Поле нуль|   Поле один  |   Поле два   |     Поле три     |Поле чотири| Поле пять |" << std::endl;
	std::cout << "----------+--------------+--------------+------------------+-----------+------------" << std::endl;
}

int  RGZ::Count_menu(int e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " \n     Оберіть дію\n\n\n";

	std::cout << " \n  1. Підрахувати кількість елементів від початку до кінця\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. Підрахувти кількість де балів менше за завдання\n";
	std::cout << "  3. Підрахувати кількість елементів де термін коротший за заданий\n";
	std::cout << "  4. Підрахувати кількість елементів де термін доший за заданий\n";
	std::cout << "  ?. Щось ще??? \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \nваш вибiр: ";
	std::cin >> e;
	system("cls");
	return e;


}
int  RGZ::Poshuk_menu(int e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " \n     Оберіть дію\n";

	std::cout << " \n  1. Знай максимальний елемент\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. Знайти мінімальний елемент\n";
	std::cout << "  3. Знайти заданий бал\n ";
	std::cout << "  4. Знайти заданий термін\n";
	std::cout << "  ?. Щось ще??? \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \nваш вибiр: ";
	std::cin >> e;
	system("cls");
	return e;


}

void RGZ::error(number& a, number& d)
{

	std::cout << "\nНажаль неможливо вiдобразити неiснуючий елемент\n";
	std::cout << "Введiть iнше значення ";
	std::cin >> d;
	a = 1;

}

