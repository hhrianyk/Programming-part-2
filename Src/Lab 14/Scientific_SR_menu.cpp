#include "prototaype.h"
#include "SR.h"


////Файл у якому міститься споміжний текс для роботи класу Scientific_SR

//int Scientific_SR::vstup_info(number nov, int N, vector<Scientific_SR>& A, set<Scientific_SR>& B, list<Scientific_SR>& C, map<int, Scientific_SR>& D)
//{
//
//	Scientific_SR h ;
//	
//
//
//	system("cls");
//	number  a = 1;
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//
//
//	cout << "\n\nВи знаходитесь у класі RGZ";
//	SetConsoleTextAttribute(hConsole, (WORD)(10));
//	std::cout << "\n\n Почнемо роботу\n\n Ввести данi\n ";
//	while (a != 0)
//	{
//		SetConsoleTextAttribute(hConsole, (WORD)(12));
//		cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
//		cin >> a;
//
//		switch (a)
//		{
//		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
//			std::cout << "Скiльки елементiв ви хочете додати? :";
//			std::cin >> a;
//			for (int i = 0; i < a; i++)
//				h.add_el(N, A, B, C, D);
//			a = 0;
//			break;
//		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
//			//h.Riad_FL(N, A, B, C, D), a = 0;
//			break;
//		}
//	}
//
//	a = h.main_menu(a);
//	/*while (a)
//	{
//		switch (a)
//		{
//		case 1:
//			h.printTableHead();
//			h.Print_run(N, A, B, C, D);
//			break;
//		case 2:	h.dop_INFO(N, A, B, C, D);
//			break;
//		case 3:h.delet_el(N, A, B, C, D);
//			break;
//		case 4:	h.Print_el(N, A, B, C, D);
//			break;
//		case 5: if (N == 1)	A.clear();
//			  else if (N == 2) B.clear();
//			  else if (N == 3) C.clear();
//			  else if (N == 4) D.clear();
//			system("cls");
//			std::cout << "Успішно";
//			break;
//		case 11:
//			system("cls");
//			//List.vstup_info(nov,List);
//			break;
//		case 12: system("cls");
//			return 123;
//
//			break;
//		case 14://List.delete_list(List);
//			system("cls");
//			nov = 0;
//			return 0;
//			break;
//
//		}
//		string pit = "Бажаєте ще щось зробити?";
//		a = yes_and_no(a, pit);
//		if (a == 1)
//			a = h.main_menu(a);
//		else a = 14;
//
//	}*/
//	return 0;
//}
//

void Scientific_SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  Прізвище    |   Предмет    |      Наукова     |Строк здачi| Кiлькiсть |" << std::endl;
	std::cout << "|         |    викладача |              |     темаматика   |    RGZ    |   завдань |" << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
}
