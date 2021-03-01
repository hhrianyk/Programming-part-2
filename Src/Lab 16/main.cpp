#include "prototaype.h"





int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA8.10.5                |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	number poku = 1;

	setlocale(LC_CTYPE, "ru");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	
    poku = Start_Menu(poku);
	 
		


	auto ram = 0* _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\nРоботу завершено\nТривалiсть роботи:" << kon << " хв " << kon2 << " сек" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}