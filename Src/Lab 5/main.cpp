#include "prototaype.h"
#include "SR.h"




int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA5.1.2                |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";
	



	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	int poku = 1;
	
	setlocale(LC_CTYPE, "ru");
	SetConsoleOutputCP(866);

	while (poku != 0)
		poku=vstup_info(poku);

	auto ram = _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\nРоботу завершено\nТривалiсть роботи:" << kon << " хв " << kon2 << " сек" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}