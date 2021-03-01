#include "prototaype.h"
#include "SR.h"




int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA3.0-3                |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";
	



	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	int poku = 1;
	
	setlocale(LC_CTYPE, "ukr");
	SetConsoleOutputCP(866);

	/*std::string s = "opop";
	std::regex regex_integer("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}([\\.,]?[-_  ]?[А-Яа-яA-za-z]{1,20}){0,5}$");
	bool a = regex_match(s, regex_integer)*/;


	while (poku != 0)
		poku=vstup_info(poku);






	

	int ram = _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\nРоботу завершено\nТривалiсть роботи:" << kon << " хв " << kon2 << " сек" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}