#include "prototaype.h"
#include "SR.h"




void kolektsiya_SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |    �������   |   ������    |     �����        |�����������|   ��      |" << std::endl;
	std::cout << "|         |              |     �������  |     ������      |    RGZ    |����������� |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
}

int kolektsiya_SR::main_menu(number e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));

	std::cout << " \n  1. ������� �� ����� ������ ������� ���\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. ������ ������ � ������\n";
	std::cout << "  3. �������� ������ � ������ �� ��������\n";
	std::cout << "  4. ³��������� ������ ������ �� �������\n";
	std::cout << "  5. �������� ������ \n";

  
	std::cout << "  8. ������� �� ����������� ���� \n";
	std::cout << "  9. ������� �� ������������ ���� \n";

	std::cout << "  11. ��������� ������ \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \n��� ���i�: ";
	std::cin >> e;
	return e;
}


int kolektsiya_SR::vstup_info(number nov, List_SR& List)
{
	kolektsiya_SR h = kolektsiya_SR();

	system("cls");
	number  a = 1, u = 0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n�� ����������� � ����i ����i����� '������� �������' ";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n ������� ������\n\n ������ ���i\n ";
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ";
		cin >> a;
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cout << "��i���� �������i� �� ������ ������? :";
			std::cin >> a;
			for (int i = 0; i < a; i++)
				h.add_el(List);

			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			h.Riad_FL(List), a = 0;
			break;
		}
	}
	a = h.main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			system("cls");
			h.printTableHead();
			h.Print_run(List);;
			break;
		case 2:	system("cls"), h.dop_INFO(List);
			break;
		case 3:	system("cls"), h.delet_el(List);
			break;
		case 4:	system("cls"), h.Print_el(List);
			break;
		case 5:
			system("cls");
			List.delete_list_one_Class(h);
			std::cout << "������";
			break;
	
		case 8:system("cls"), List.vstup_info(nov, List);
			break;
		case 9: system("cls"); 
			return 123;
			break;
		case 10:
			List.delete_list_one_Class(h);
			system("cls");
			return nov;

		case 11:List.delete_list(List);
			system("cls");
			nov = 0;
			return 0;
			break;
		}
		string pit = "������ �� ���� �������?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = h.main_menu(a);
		else a = 11;


	}
	return 0;
}



void kolektsiya_SR::error(number& a, number& d)
{

	std::cout << "\n������ ��������� �i��������� ��i������� �������\n";
	std::cout << "����i�� i��� �������� ";
	std::cin >> d;
	a = 1;

}