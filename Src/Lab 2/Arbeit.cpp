#include "prototaype.h"
#include "SR.h"



int vstup_info(int nov)
{
	
	RGZ* h=NULL ;
	int  a = 1, u = 0;
	Init(h);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("������� ��� ����������\n ");
	printf("\n�����: ");
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	printf(__DATE__);
	printf("\n��� ������� ������ ��������: ", SetConsoleTextAttribute(hConsole, (WORD)(10)));
	printf(__TIME__, SetConsoleTextAttribute(hConsole, (WORD)(11)));
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	printf("\n\n ������� ������\n\n ������ ���i\n ");
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		printf("\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ");
		scanf("%i", &a);
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			printf("��i���� �������i� �� ������ ������? :");
			scanf("%i", &a);
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
		case 5: {h->rgz.delete_List(h);
			printf("������");
			Init(h);
			break; }
		case 6:h->rgz.curriculum(h);
			break;
		case 7:nov = 0;
			h->rgz.delete_List(h);
			SR();
			return 0;
		case 8:
			h->rgz.delete_List(h);
			{system("cls");
			nov = 1;
			return 1;
			}
		case 9:
			h->rgz.checking_the_constructor();
			break;

		}
		char pit[] = "������ �� ���� �������?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = main_menu(a);
		else a = 7;

	}
}




void Init(RGZ*& p) {
	p = new RGZ;
	p->next = NULL;
}


void SR::Print_run(RGZ* p)
{
	RGZ* pr = p->next;
	int i = 1;
	while (pr != NULL)
	{
		printf("|RGZ %-3d  |", i);
		
			cout << pr->rgz.Get_predmet()<<"\t|"<< pr->rgz.Get_teme()<<"\t";
		
		printf("|%-18i|%-11i|%-11i|\n", pr->rgz.Get_bal(), pr->rgz.Get_termin(), pr->rgz.Get_zavdanj());
		
		printf("-----------------------------------------------------------------------------------\n");
		i++;
		pr = pr->next;
	}
}

void SR::Print_el(RGZ* p)
{
	RGZ* pr = p;

	int d;
	printf("���� ������� ������ �i���������: ");
	scanf("%i", &d);
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
	cout << pr->rgz.Get_predmet() << "\t|" << pr->rgz.Get_teme() << "\t";

	printf("|%-18i|%-11i|%-11i|\n", pr->rgz.Get_bal(), pr->rgz.Get_termin(), pr->rgz.Get_zavdanj());
	printf("-----------------------------------------------------------------------------------\n");

}

void SR::add_el(int cathedra,string predmet, string tema, int bal, int zavdanj, int termin, RGZ* p)
{
	
	RGZ* add = new RGZ;
	RGZ* head = p;
	add->next = NULL;
	add->rgz.Set_cathedra(cathedra);
	add->rgz.Set_predmet(predmet);
	add->rgz.Set_teme(tema);
	add->rgz.Set_bal(bal);
	add->rgz.Set_termi(termin);
	add->rgz.Set_zavdanj(zavdanj);
	add->next = head->next;
	head->next = add;
}



void SR::add_el(RGZ* p)
{
	string predmet, tema;
	int bal, termin, zadanj, cathedra;
	cout << "������� :";
	cin >> predmet;
	cout << "����:";
	cin >> tema;
	cout << "�i���i��� ���i� �� �������� : ";
	scanf("%i", &bal);
	cout << "���i�� (� ����) : ";
	scanf("%i", &termin);
	cout << "�i���i��� ������� : ";
	scanf("%i", &zadanj);

	cout << "���������/�������(���� �����): ";
	scanf("%i", &cathedra);
	p->rgz.add_el(cathedra,predmet, tema, bal, termin, zadanj, p);
	cout << "\n������ ������\n\n" << endl;
	/////������� ����� ������� �� 2
}


void SR::delet_el(RGZ* p)
{
	RGZ* pr = p->next;
	RGZ* temp = p;
	int d;
	printf("���� ������� ������ ��������");
	scanf("%i", &d);
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
					printf("\n������ ��������� �������� ��i������� �������\n");
					printf("����i�� i��� �������� ");
					scanf("%d", &d);
					a = 1;
				}
		}else{
			temp = p;
			pr = p->next;
			printf("\n������ ��������� �������� ��i������� �������\n");
			printf("����i�� i��� �������� ");
			scanf("%d", &d);
			a = 1;
		}
	}
	{

		temp->next = pr->next;

		delete(pr);
	}
}

void SR::delete_List(RGZ* p)//
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

void Riad_FL(RGZ* h)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h;
	string text, adresa;
	int value, temp = 0;
	ifstream fOpen; 
	printf("\n���� ���� �������?\n\n 1. RGZ.txt\n 2. add_RGZ.txt\n ��� �i�i�:");
	scanf("%i", &temp);
	switch (temp)
	{
	case 1:adresa = "RGZ.txt";
		break;
	case 2:adresa = "add_RGZ.txt";
		break;
	}
	fOpen.open(adresa, ios_base::in);
	if (!fOpen)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(5));
		cout << "File is not open\n\n";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		return;

	}SetConsoleTextAttribute(hConsole, (WORD)(10));
	while (!fOpen.eof()) {
		RGZ* add=new RGZ;
		add->next = p->next;
		p->next = add;
		fOpen >> text;
	
		add->rgz.Set_predmet(text);
		fOpen >> text;
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

void dop_INFO(RGZ* h)
{
	int a;
	printf("\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ");
	scanf("%i", &a);
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



void SR::curriculum(RGZ*p)
{
	RGZ* pr=p->next;
	int cu = 0, i = 0;
	cout << "\n\n������ ����i����i���/�������(�����) :";
	
		cin >> cu;
		while (pr->next != 0)
		{
			
			if (cu == pr->rgz.Get_cathedra())
				i++;
			pr = pr->next;
		}
		if (i > 0)
		{
			cout << "������ �������� � ����� ����������� ���� ����� �������: " << i << " ���"<<endl;
			
			cout << "��� �i���� � ���� �������i� ��� ����i��� ������ \n 1:��\n 2:��� \n ��� ���i�:";
			int king;
			cin >> king;
			if (king == 1)
			{
				cout << "\n � ����� �������i� :";
				pr = p;
				while (pr->next != 0)
				{
					if (cu == pr->rgz.Get_cathedra())
						if ((i++) % 4 != 0)
							cout << " | " << pr->rgz.Get_predmet();
						else cout << "\n | " << pr->rgz.Get_predmet();
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
			cout << "\n\n�i��� � ����� ���i ��� ������i��� ������ ��� � ������ �������i�!!!\n\n ";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}

}

void SR::checking_the_constructor()
{
	SR konst("�������", "����", 3, 4, 4, 134);//��� ������������ � �����������
	cout <<"������� �����: "<< konst.Get_teme() << endl;
	SR konst2;//��� ������������
	cout <<"������� �����: "<< konst2.Get_teme()<<endl;
	SR konst3(konst2);//��� ������������ ���������
	cout <<"������� ����� : " <<konst3.Get_teme()<<endl;
}

