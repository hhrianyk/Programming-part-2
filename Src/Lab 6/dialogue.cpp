#include "SR.h"
#include "prototaype.h"

int SR::main_menu(number e)
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
		std::cout << "  7. ��������� ������ \n";
		std::cout << "  8. ��������������� �������� �������� \n";
		std::cout << "  9. ³��������� ������� ������ �� ����� ��� ����� � ���� \n";
		std::cout << "  10.�������� ���i y ���� \n";
		std::cout << "  11.������� ���i ����� �� ����� \n";
		std::cout << "  12.��������� \n";
		std::cout << "  13.����� ������ \n";
	
	 SetConsoleTextAttribute(hConsole, (WORD)(10));
	 std::cout << " \n��� ���i�: ";
	 std::cin>>e;

	return e;
}


int yes_and_no(number& t, char p[])
{
	std::cout << "\n\n"<<p<<"\n ";
	std::cout << "���- 1\n ";
	std::cout << "�i- 2\n ";
	std::cout << "������� ������ :";
	std::cin>> t;
	if (t == 2)
	{
		int oo = 12;

	}
	return t;
	
}
void SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  �������     |   ���a       | �i���i��� ���i�  |����� ����i| �i���i��� |"<<std::endl;
	std::cout << "|         |              |              |�� �������� RGZ   |    RGZ    |   ������� |"<< std::endl;
	std::cout << "------------------------------------------------------------------------------------"<< std::endl;
}


void SR::error(number& a, number& d )
{

	std::cout << "\n������ ��������� �i��������� ��i������� �������\n";
	std::cout << "����i�� i��� �������� ";
	std::cin >> d;
	a = 1;
	
}

int SR::kriter(number n)
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
