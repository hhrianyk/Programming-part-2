#include "prototaype.h"
#include "SR.h"




////���� � ����� �������� �������� ���� ��� ������ ����� ���



int Start_Menu(number n)
{
	List_SR List;
	RGZ A;
	Scientific_SR B;
	kolektsiya_SR C;
	
	while (n != 0)
	{
		
			cout << "\n������� ������, ���� �� ������ ��������: \n\n";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << "   ������ RGZ ------> 1\n   ������ �������� ������ ����� ---- > 2\n   ������ �������� �������� ������� ---- > 3\n  ";

			SetConsoleTextAttribute(hConsole, (WORD)(10));
			cout << " \n��� ���i�: ";
			cin >> n;


	    
			switch (n)
			{
			case 1: n = A.vstup_info(n, List);
				break;
			case 2: n = B.vstup_info(n, List);
				break;
			case 3: n = C.vstup_info(n, List);
				break;

		
	     	}
	}

	List.delete_list(List);
	return n;
}

int RGZ::main_menu(number e)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));

	std::cout << " \n  1. ������� �� ����� ������\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. ������ ������� � ������\n";
	std::cout << "  3. �������� ������� � ������ �� ��������\n";
	std::cout << "  4. ³��������� ������� ������ �� �������\n";
	std::cout << "  5. �������� ������ \n";
	std::cout << "  6. ��������� �i���i��� ���, �� ������ ������� �� ����\n  ���i�� �������� � i�������i � �i����i�����i ��\n  ����������� �����\n";
	std::cout << "  7. ³��������� ������� ������ �� ����� ��� ����� � ���� \n";
	std::cout << "  8. �������� ���i y ���� \n";
	std::cout << "  9. ������� ���i ����� �� ����� \n"; 
	std::cout << "  10. ?��������� \n";
	

	std::cout << "  11. ������� �� ����������� ���� \n";
	std::cout << "  12. ������� �� ������������ ���� \n";
	std::cout << "  13. ?(�� ���������)��������������� �������� �������� \n";
	std::cout << "  14. ��������� ������ \n";

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \n��� ���i�: ";
	std::cin >> e;

	return e;
}


int yes_and_no(number& t, string p)
{
	std::cout << "\n\n" << p << "\n ";
	std::cout << "���- 1\n ";
	std::cout << "�i- 2\n ";
	std::cout << "������� ������ :";
	std::cin >> t;

	return t;

}

void RGZ::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  �������     |   ���a       | �i���i��� ���i�  |����� ����i| �i���i��� |" << std::endl;
	std::cout << "|         |              |              |�� �������� RGZ   |    RGZ    |   ������� |" << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
}

void RGZ::error(number& a, number& d)
{

	std::cout << "\n������ ��������� �i��������� ��i������� �������\n";
	std::cout << "����i�� i��� �������� ";
	std::cin >> d;
	a = 1;

}

int RGZ::kriter(number n)
{
	cout << "\n�� ���� ��i���i�� ������ ��������� ������ \n\n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "  1.�������\n";
	cout << "  2.����\n";
	cout << "  3.����� \n";
	cout << "  4.��������\n";
	cout << "  5.���\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << " \n��� ���i�: ";
	cin >> n;
	return n;
}