#include "prototaype.h"
#include "SR.h"


int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA15.0.1                |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	number poku = 1;



	setlocale(LC_CTYPE, "ru");

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);

	
     Start_Menu(poku);
	 
	auto ram =  _CrtDumpMemoryLeaks();

	std::cout << "\n������ �����i:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\n������ ���������\n������i��� ������:" << kon << " �� " << kon2 << " ���" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}