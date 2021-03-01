#include "prototaype.h"
#include "SR.h"




int main()
{
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t|  |         LABA2.0-2.4               |   |\n";
	cout << "\t\t\t-----------------------------------------\n";
	


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	int poku = 1;
	setlocale(LC_ALL, "rus");
	while (poku != 0)
		poku=vstup_info(poku);
	int ram = _CrtDumpMemoryLeaks();

	

	cout << "\nВитоку памятi:" << ram << endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	cout << "\nРоботу завершено\nТривалiсть роботи:" << kon << " хв " << kon2 << " сек" << endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}