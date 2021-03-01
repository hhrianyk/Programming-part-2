#include "prototaype.h"
#include "SR.h"





int main()
{
	std::cout << "\t\t\t-----------------------------------------\n";
	std::cout << "\t\t\t|  |         LABA7.5.1                |   |\n";
	std::cout << "\t\t\t-----------------------------------------\n";


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	number poku = 1;

	setlocale(LC_CTYPE, "ru");

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	int n = 1;
	
	RGZ A;
	A.Set_bal(10);
	A.Set_predmet("11");
	A.Set_teme("12");
	A.Set_termi(19);
	A.Set_zavdanj(15);

	Scientific_SR B;
	B.Set_bal(21);
	B.Set_cientific_topic("22");
	B.Set_predmet("23");
	B.Set_surname("25");
	B.Set_termi(27);

	List_SR C;
	C.add(&A);
	C.add(&B);
	
	






	while (poku != 0)
		poku = Start_Menu(poku);


	auto ram = 0* _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	std::cout << "\nРоботу завершено\nТривалiсть роботи:" << kon << " хв " << kon2 << " сек" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}