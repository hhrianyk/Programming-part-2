#include "prototaype.h"
#include "SR.h"
#include "my_ptr.h"



////���� � ����� �������� �������� ���� ��� ������ ����� ���



int Start_Menu(number n)
{
	vector< unique_ptr<RGZ>> a; 
	vector< shared_ptr <RGZ>> b;
	vector <  my::UNO<RGZ>> d;


	RGZ A;

	while (n != 0)
	{
		n = 1;
		int k;
		cout << "\n������� � �������, ���� ����������� ��������: \n\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		cout << "   unique_ptr -----> 1\n   shared_ptr -----> 2\n   my::UNO --------> 3\n ";

		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << " \n��� ���i�: ";
		cin >> k;
		system("cls");

		while (n != 3)
		{

			cout << "\n������� � �������, ��� �� ������ ���������: \n\n";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << "   ������ RGZ & Scientific_SR--------- >1\n\n   �������� ���� -------------------- >3  \n   ��������� ������------------------- >4  \n  ";
			
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			cout << " \n��� ���i�: ";
			cin >> n;
			do 
			{
				switch (n)
				{
				case 1: n = A.vstup_info(n, k, a, b, d);
					break;
				
				case 3: n = 3, system("cls");
					break;
				case 4: a.clear(), d.clear();
					return n;
					break;

				}
			} while (n>3);
		}
	}
	
}

int RGZ::main_menu(number e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));

	std::cout << " \n  1. ������� �� ����� ������\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. ������ ������� � ������\n";
	std::cout << "  3. �������� ������� � ������ �� ��������\n";
	std::cout << "  4. ³��������� ������� ������ �� �������\n";
	std::cout << "  5. �������� ������ \n";
	std::cout << "  6. ���������� ������� �������� �� ������� �������\n";
	std::cout << "  7. ����� �������� �� ������� �������.\n";
	std::cout << "  8. TEST(���� ��� ������ �������!!!)\n\n";


	
	std::cout << "  11. ������� �� ������������ ���� \n";
	std::cout << "  12. ��������� ������ \n";

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \n��� ���i�: ";
	std::cin >> e;
	system("cls");
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
	//std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	//std::cout << "|         |  �������     |   ���a       | �i���i��� ���i�  |����� ����i| �i���i��� |" << std::endl;
	//std::cout << "|         |              |              |�� �������� RGZ   |    RGZ    |   ������� |" << std::endl;
	//std::cout << "----------+--------------+--------------+------------------+-----------+------------" << std::endl;
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|���� ����|   ���� ����  |   ���� ���   |     ���� ���     |���� ������| ���� ���� |" << std::endl;
	std::cout << "----------+--------------+--------------+------------------+-----------+------------" << std::endl;
}

int  RGZ::Count_menu(int e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " \n     ������ ��\n\n\n";

	std::cout << " \n  1. ϳ��������� ������� �������� �� ������� �� ����\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. ϳ�������� ������� �� ���� ����� �� ��������\n";
	std::cout << "  3. ϳ��������� ������� �������� �� ����� �������� �� �������\n";
	std::cout << "  4. ϳ��������� ������� �������� �� ����� ����� �� �������\n";
	std::cout << "  ?. ���� ��??? \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \n��� ���i�: ";
	std::cin >> e;
	system("cls");
	return e;


}
int  RGZ::Poshuk_menu(int e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " \n     ������ ��\n";

	std::cout << " \n  1. ���� ������������ �������\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. ������ ��������� �������\n";
	std::cout << "  3. ������ ������� ���\n ";
	std::cout << "  4. ������ ������� �����\n";
	std::cout << "  ?. ���� ��??? \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \n��� ���i�: ";
	std::cin >> e;
	system("cls");
	return e;


}

void RGZ::error(number& a, number& d)
{

	std::cout << "\n������ ��������� �i��������� ��i������� �������\n";
	std::cout << "����i�� i��� �������� ";
	std::cin >> d;
	a = 1;

}

