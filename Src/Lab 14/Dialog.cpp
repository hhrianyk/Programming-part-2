#include "prototaype.h"
#include "SR.h"




////���� � ����� �������� �������� ���� ��� ������ ����� ���



int Start_Menu(number n)
{
	vector<RGZ> a; //  at, push,pop,insert,[]
	set<RGZ> b; // insert, begin, end
	list<RGZ> c; // push,pop,insert
	map<int ,RGZ> d; // at,insert
	vector<RGZ*> e; // �� "�������"

	RGZ A;

	vector<Scientific_SR> q; //  at, push,pop,insert,[]
	set<Scientific_SR> w; // insert, begin, end
	list<Scientific_SR> r; // push,pop,insert
	map<int, Scientific_SR> t; // at,insert
	

    Scientific_SR B;
	while (n != 0)
	{
		n = 1;
		int k;
		cout << "\n������� ������, ���� ����������� ��������: \n\n";
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		cout << "   vektor ---> 1\n   set ------> 2\n   list -----> 3\n   map ------> 4\n   vektor* --> 5\n  ";

		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << " \n��� ���i�: ";
		cin >> k;
		system("cls");

		while (n != 3)
		{

			cout << "\n������� ������, ���� �� ������ ��������: \n\n";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << "   ������ RGZ ------------------------ >1\n   ������ �������� ������ ����� ---- >2\n   �������� ���� -------------------- >3  \n   ��������� ������------------------- >4  \n  ";
			cout << "   ��������� �������� (���������� � ��� �����)----5?" << endl;
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			cout << " \n��� ���i�: ";
			cin >> n;
			do 
			{
				switch (n)
				{
				case 1: n = A.vstup_info(n, k, a, b, c, d, e);
					break;
				case 2: n = B.vstup_info(n, k, q, w, r, t, e);
					break;
				case 3: n = 3, system("cls");
					break;
				case 4:a.clear(), b.clear(), c.clear(), d.clear(), q.clear(), w.clear(), r.clear(), t.clear();
					for (RGZ* key : e) {
						delete key;
						cout << endl;
					}
				case 5: A.additional_tasks();
					e.clear();
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
	std::cout << "  8. ���������.\n";
	std::cout << "  9. �ᒺ������ ���� STL ���������� ���� vector.\n\n";


	
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
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |  �������     |   ���a       | �i���i��� ���i�  |����� ����i| �i���i��� |" << std::endl;
	std::cout << "|         |              |              |�� �������� RGZ   |    RGZ    |   ������� |" << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
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

