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

	while (poku != 0)
		poku=vstup_info(poku);

	int ram = _CrtDumpMemoryLeaks();


	std::cout << "\n������ �����i:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\n������ ���������\n������i��� ������:" << kon << " �� " << kon2 << " ���" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}