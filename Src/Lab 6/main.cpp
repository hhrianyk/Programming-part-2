#include "prototaype.h"
#include "SR.h"





int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA6.0-32               |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";
	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	int poku = 1;
	
	setlocale(LC_CTYPE, "ru");
	
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);

	while (poku != 0)
		poku=Start_Menu(poku);


	auto ram =0*_CrtDumpMemoryLeaks();

	std::cout << "\n������ �����i:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\n������ ���������\n������i��� ������:" << kon << " �� " << kon2 << " ���" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}