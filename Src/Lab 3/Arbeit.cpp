#include "prototaype.h"
#include "SR.h"


void Init(RGZ*& p) {
	p = new RGZ;
	p->next = NULL;
}

int vstup_info(int nov)
{
	
	RGZ* h=NULL ;
	int  a = 1, u = 0;
	Init(h);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "������� ��� ����������\n ";
	std::cout << "\n�����: ";
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << __DATE__;
	std::cout << "\n��� ������� ������ ��������: ", SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << __TIME__<< SetConsoleTextAttribute(hConsole, (WORD)(11));
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n ������� ������\n\n ������ ���i\n ";
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		std::cout << "\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ";
		std::cin >> a;
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cout << "��i���� �������i� �� ������ ������? :";
			std::cin>> a;
			for (int i = 0; i < a; i++)
				h->rgz.add_el(h);

			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			Riad_FL(h), a = 0;
			break;
		}	
	}
	a = main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			h->rgz.printTableHead();
			h->rgz.Print_run(h);
			break;
		case 2:	dop_INFO(h);
			break;
		case 3:h->rgz.delet_el(h);
			break;
		case 4:	h->rgz.Print_el(h);
			break;
		case 5: {h->rgz.delete_list(h);
			std::cout << "������";
			Init(h);
			break; }
		case 6:h->rgz.curriculum(h);
			break;
		case 7:nov = 0;
			h->rgz.delete_list(h);
			SR();
			return 0;
		case 8:
			h->rgz.delete_list(h);
			{system("cls");
			nov = 1;
			return 1;
			}
		case 9:
			h->rgz.checking_the_constructor();
			break;

		case 10:
			h->rgz.save_for_Fl(h);
			break;
		case 11: h->rgz.print_saved_for_Fl();
			break;
		}
		char pit[] = "������ �� ���� �������?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = main_menu(a);
		else a = 7;

	}
}


void dop_INFO(RGZ* h)
{
	int a;
	std::cout << "\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ";
	std::cin>> a;
	switch (a)
	{
	case 1:
		h->rgz.add_el(h);
		break;
	case 2:
		Riad_FL(h), a = 0;
		break;
	}
}


void Riad_FL(RGZ* h)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h;
	std::ifstream fOpen;
int value, temp = 0;
    std::string text, adresa;
	
	std::cout << "\n���� ���� �������?\n\n 1. RGZ.txt\n 2. add_RGZ.txt\n ��� �i�i�:";
	std::cin>> temp;
	switch (temp)
	{
	case 1:adresa = "RGZ.txt";
		break;
	case 2:adresa = "add_RGZ.txt";
		break;
	}
	fOpen.open(adresa, std::ios_base::in);
	if (!fOpen)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(5));
		std::cout << "File is not open\n\n";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		return;

	}SetConsoleTextAttribute(hConsole, (WORD)(10));
	while (!fOpen.eof()) {
		RGZ* add=new RGZ;
		add->next = p->next;
		p->next = add;
		fOpen >> text;
		if ( text[0] >= 'a' && text[0] <= 'z' || text[0] >= '�' && text[0] <= '�' || text[0] == '�')
			text[0] -= 32;
		add->rgz.Set_predmet(text);
		fOpen >> text;
		if (text[0] >= 'a' && text[0] <= 'z' || text[0] >= '�' && text[0] <= '�' || text[0] == '�')
			text[0] -= 32;
		add->rgz.Set_teme(text);
		fOpen >> value;
		add->rgz.Set_bal(value);
		fOpen >> value;
		add->rgz.Set_termi(value);
		fOpen >> value;
		add->rgz.Set_zavdanj(value);
		fOpen >> value;
		add->rgz.Set_cathedra(value);
		p = p->next;
	}

	fOpen.close();
}




void SR::Print_run(RGZ* p)
{
	RGZ* pr = p->next;
	int i = 1;
	
	std::stringstream f;	
	while (pr != NULL)
	{
		f <<"|RGZ-"<<i++<<"    |"<< std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) << pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) << pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|" <<"\n------------------------------------------------------------------------------------\n"<<std::endl;
		/*printf("|RGZ %-3d  |", i);
		std::cout << std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) << pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) << pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|" << std::endl;
		std::cout <<"-----------------------------------------------------------------------------------\n";*/

		pr = pr->next;
	}
		std::cout << f.str();
}

void SR::Print_el(RGZ* p)
{
	RGZ* pr = p;

	int d;
	std::cout << "���� ������� ������ �i���������: ";
	std::cin>> d;
	int a = 1;
	while (a)
	{
		a = 0;
		if (d > 0)
		{for (int i = 0; i < d; i++)
					if (pr->next != NULL)
						pr = pr->next;
					else
					{
						pr = p->next;
						error(a, d);
					}
	}
		else
		{               pr = p->next;
						error(a, d);
		}
	}
	p->rgz.printTableHead();
	printf("|RGZ %-3d  |", d);
	std::cout << std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) << pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) << pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------\n";

}

void SR::delet_el(RGZ* p)
{
	RGZ* pr = p->next;
	RGZ* temp = p;
	int d;
	std::cout << "���� ������� ������ ��������";
	std::cin>> d;
	int a = 1;
	while (a)
	{
		a = 0;
		if (d > 0)
		{
			for (int i = 1; i < d; i++)
				if (pr->next != NULL)
				{
					temp = temp->next;
					pr = pr->next;

				}
				else
				{
					temp = p;
					pr = p->next;
					std::cout << "\n������ ��������� �������� ��i������� �������\n";
					std::cout << "����i�� i��� �������� ";
					std::cin>>d;
					a = 1;
				}
		}else{
			temp = p;
			pr = p->next;
			std::cout << "\n������ ��������� �������� ��i������� �������\n";
			std::cout << "����i�� i��� �������� ";
			std::cin >> d;
			a = 1;
		}
	}
	{

		temp->next = pr->next;

		delete(pr);
	}
}

void SR::delete_list(RGZ* p)//
{
	RGZ* pr = p->next;
	if (p->next != 0)
	{

		while (p != 0)
		{

			p = pr->next;
			delete(pr);
			pr = p;
		}
	}
	delete(p, pr, this);

}




void SR::curriculum(RGZ*p)
{
	RGZ* pr=p->next;
	int cu = 0, i = 0;
	std::cout << "\n\n������ ����i����i���/�������(�����) :";
	
	std::cin >> cu;
		while (pr->next != 0)
		{
			
			if (cu == pr->rgz.Get_cathedra())
				i++;
			pr = pr->next;
		}
		if (i > 0)
		{
			std::cout << "������ �������� � ����� ����������� ���� ����� �������: " << i << " ���"<< std::endl;
			
			std::cout << "��� �i���� � ���� �������i� ��� ����i��� ������ \n 1:��\n 2:��� \n ��� ���i�:";
			int king;
			std::cin >> king;
			if (king == 1)
			{
				std::cout << "\n � ����� �������i� :";
				pr = p;
				while (pr->next != 0)
				{
					if (cu == pr->rgz.Get_cathedra())
						if ((i++) % 4 != 0)
							std::cout << " | " << pr->rgz.Get_predmet();
						else std::cout << "\n | " << pr->rgz.Get_predmet();
					pr = pr->next;
				}
			}
			else
				return;
		}
		else
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			std::cout << "\n\n�i��� � ����� ���i ��� ������i��� ������ ��� � ������ �������i�!!!\n\n ";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}

}

void SR::checking_the_constructor()
{
	SR konst("�������", "����", 3, 4, 4, 134);//��� ������������ � �����������
	std::cout << "������� �����: "<< konst.Get_teme() << std::endl;
	SR konst2;//��� ������������
	std::cout << "������� �����: "<< konst2.Get_teme()<< std::endl;
	SR konst3(konst2);//��� ������������ ���������
	std::cout << "������� ����� : " <<konst3.Get_teme()<< std::endl;
}
void SR::save_for_Fl(RGZ* h)//�������� ��� � ����
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h->next;

	std::string adresa;
	int  temp = 0;
	std::fstream fOpen;
	std::cout << "\n���� ���� �������?\n\n 1. txt.txt(��������� ����)\n 2. bib.bin(������� ����)\n ��� �i�i�:";
	std::cin >> temp;
	switch (temp)
	{
	case 1:adresa = "txt.txt";
		break;
	case 2:adresa = "bin.bin";
		break;
	}
		fOpen.open(adresa, std::ios::out);
		if (!fOpen)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(5));
			std::cout << "File is not open\n\n";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			return;

		}SetConsoleTextAttribute(hConsole, (WORD)(10));
		while (p != 0) {
			fOpen << p->rgz.Get_predmet() << " " << p->rgz.Get_teme() << " " << p->rgz.Get_bal() << " " << p->rgz.Get_zavdanj() << " " << p->rgz.Get_termin() << " " << p->rgz.Get_cathedra() << std::endl;
			p = p->next;
		}
		fOpen.close();
		std::cout << "\n���������� ������ ���������" << std::endl;

	
}

	void SR::print_saved_for_Fl()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*	RGZ* p = h;*/
		std::ifstream fOpen;
		int value, temp = 0;
		std::string text, adresa;

		std::cout << "\n���� ���� �������?\n\n 1. txt.txt(��������� ����)\n 2. bib.bin(������� ����)\n ��� �i�i�:";
		std::cin >> temp;
		switch (temp)
		{
		case 1:adresa = "txt.txt";
			break;
		case 2:adresa = "bin.bin";
			break;
		}
		fOpen.open(adresa, std::ios_base::out);
		if (!fOpen)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(5));
			std::cout << "File is not open\n\n";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			return;

		}SetConsoleTextAttribute(hConsole, (WORD)(10));
		while (!fOpen.eof() ) {

			fOpen >> text;
			std::cout << text << " ";
			fOpen >> text;
			std::cout << text << " ";
			fOpen >> value;
			std::cout << value << " ";
			fOpen >> value;
			std::cout << value << " ";
			fOpen >> value;
			std::cout << value <<" ";
			fOpen >> value;
			std::cout << value<< std::endl;
		
		}
	
}

	void SR::add_el(RGZ* h) {
	
		RGZ* add = new RGZ;
		RGZ* head = h;
		add->next = NULL;

		int  value3, value4, value5, value6;
		std::string value1, value2;
		bool condition = true;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		while (condition)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			std::cout << "����i�� ����� �������� : ";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
	
			std::cin >> value1;
			
			condition = false;
			if  (value1[0] >= 'a' && value1[0] <= 'z' || value1[0] >= '�' && value1[0] <= '�' || value1[0] == '�')
				value1[0] -= 32;
			}
		
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << " ������" << std::endl;
		condition = true;
		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			if ((std::cin.rdbuf()->in_avail()) != 1);
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			std::cout << "������ ���� :";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cin >> value2;
			
			condition = false;
			if (value2[0] >= 'a' && value2[0] <= 'z' || value2[0] >= '�' && value2[0] <= '�' || value2[0] == '�')
				value2[0] -= 32;

		}
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << "������" << std::endl;
		condition = true;
		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			if ((std::cin.rdbuf()->in_avail()) != 1);
			std::cout << "����i�� �i���i��� ���i� �� �������� : ";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cin >> value3;
			 
			if (std::cin.fail()) {//���� ���� ������, ������� ���������
				SetConsoleTextAttribute(hConsole, (WORD)(10));
				cout << "��������� �� ���\n";
				std::cin.clear();//��������� �����
				std::cin.ignore(std::cin.rdbuf()->in_avail());//������������ �����
				continue;
			}
			if (value3 > 0)
				condition = false;

			else
				cout << "\n�� ������ ������i����� ������i��� ����� RGZ\n";
		}
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << "������" << std::endl;
		condition = true;
		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			if ((std::cin.rdbuf()->in_avail()) != 1);
			cout << "����i�� ���i�� (� ����) : ";
			
			std::cin >> value4;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(hConsole, (WORD)(15));
				cout << "\n������� �� ���\n";

				std::cin.clear();

				std::cin.ignore(std::cin.rdbuf()->in_avail());
				continue;
			}
			if(value4 > 0)
				condition = false;

			else
				cout << "���i�� ������i����� �� �� ����������� �i���� ����";
		}SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << "������" << std::endl;
		condition = true;
		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			cout << "����i�� �i���i��� ������� : ";
			std::cin >> value5;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(hConsole, (WORD)(11));
				cout << "������� �� ���\n";

				std::cin.clear();

				std::cin.ignore(std::cin.rdbuf()->in_avail());
				continue;
			}
			if (value5 > 0)
				condition = false;

			else
				cout << " ���i�� ������i ���� ������?\n" ;

		}SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << " ������" << std::endl;
		condition = true;
		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			cout << "������ ���������/������� : ";
			std::cin >> value6;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(hConsole, (WORD)(11));
				cout << " ������� �� ���\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				continue;
			}
			condition = false;
			if (value6 > 0)
				condition = false;
			else
				cout << " �� �������i, �� ���� i���?  "<<std::endl;
		}SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << " ������"<<std::endl;
		SetConsoleTextAttribute(hConsole, (WORD)(5));
		
		add->rgz.Set_predmet(value1);
		add->rgz.Set_teme(value2);
		add->rgz.Set_bal(value3);
		add->rgz.Set_termi(value4);
		add->rgz.Set_zavdanj(value5);
		add->rgz.Set_cathedra(value6);
		add->next = head->next;
		head->next = add;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cout << "\n���i ���i ���i��� �������i\n";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
	}