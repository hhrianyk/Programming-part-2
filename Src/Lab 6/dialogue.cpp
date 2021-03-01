#include "SR.h"
#include "prototaype.h"

int SR::main_menu(number e)
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
		SetConsoleTextAttribute(hConsole, (WORD)(11));

		std::cout << " \n  1. Вивести на екран список\n";
		system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
		std::cout << "  2. Додати елемент в список\n";
		std::cout << "  3. Видалити елемент з списку за номереом\n";
		std::cout << "  4. Відобразити елемент списку за номером\n";
		std::cout << "  5. Очистити список \n";
		std::cout << "  6. Визначити кiлькiсть РГЗ, що виконує студент за весь\n  перiод навчання в iнститутi у вiдповiдностi до\n  навчального плану\n";
		std::cout << "  7. Завершити роботу \n";
		std::cout << "  8. Перезавантажити програму програму \n";
		std::cout << "  9. Відобразити елемент списку які мають два слова у назві \n";
		std::cout << "  10.Записати данi y файл \n";
		std::cout << "  11.Вивести данi файлу на екран \n";
		std::cout << "  12.Сортувати \n";
		std::cout << "  13.Добра порада \n";
	
	 SetConsoleTextAttribute(hConsole, (WORD)(10));
	 std::cout << " \nваш вибiр: ";
	 std::cin>>e;

	return e;
}


int yes_and_no(number& t, char p[])
{
	std::cout << "\n\n"<<p<<"\n ";
	std::cout << "так- 1\n ";
	std::cout << "нi- 2\n ";
	std::cout << "вибрана робота :";
	std::cin>> t;
	if (t == 2)
	{
		int oo = 12;

	}
	return t;
	
}
void SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  Предмет     |   Темa       | Кiлькiсть балiв  |Строк здачi| Кiлькiсть |"<<std::endl;
	std::cout << "|         |              |              |за виконане RGZ   |    RGZ    |   завдань |"<< std::endl;
	std::cout << "------------------------------------------------------------------------------------"<< std::endl;
}


void SR::error(number& a, number& d )
{

	std::cout << "\nНажаль неможливо вiдобразити неiснуючий елемент\n";
	std::cout << "Введiть iнше значення ";
	std::cin >> d;
	a = 1;
	
}

int SR::kriter(number n)
{
	cout << "\nЗа яким крiтерiєм хочете сортувати список \n\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "  1.Предмет\n";
	cout << "  2.Тема\n";
	cout << "  3.Термін \n";
	cout << "  4.завдання\n";
	cout << "  5.бал\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << " \nваш вибiр: ";
	cin >> n;
	return n;
}
