#include "prototaype.h"//�������� �� ���������
#include "Student.h"

class SR
{
private:
	string predmet;
	string tema;
	int bal;
	int zavdanj;
	int termin;
	

public:
	void printTableHead();
	void run_Print(RGZ* p );//1 ���������� ��������
	void el_Print(RGZ* p);
	/*int vstup_info(int);*/
	void add_el(string  , string ,int ,int ,int ,RGZ* p);//������ �������
	void Init(RGZ*&);
	int  sche(int&, char[]);
	int VSTUProzmova(int);
	void Riad_FL(RGZ*);
	void dop_INFO(RGZ*);

	void add_one_el(RGZ* p);
	void delet_el(RGZ* p);//������� �������
	void dead_el(RGZ* p);//������� ������

	string Get_predmet() { return predmet; }
	string Get_teme() { return tema; }
	int Get_bal() { return bal; }
	int Get_zavdanj() { return zavdanj; }
	int Get_termin() { return termin; }

	void Set_predmet(string value1) { this->predmet = value1; }
	void Set_teme(string value1) { this->tema = value1; }
	void Set_bal(int value) { this->bal = value; }
	void Set_zavdanj(int value) { this->zavdanj = value; }
	void Set_termi(int value) { this->termin = value; }
};
struct RGZ {
	SR rgz;
	RGZ* next;
};
int main()
{
	/*Student s = Student();
	cout << s.getId() << endl;*/

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	int poku = 1;
	setlocale(LC_ALL ,"rus");
	while (poku!=0)
	poku=vstup_info(poku);
	int ram = _CrtDumpMemoryLeaks();
	cout <<"\n������ �����i:"<< ram << endl;
	SetConsoleTextAttribute(hConsole, (WORD)(13));

	cout << "\n������ ���������\n������i��� ������:" << kon << " �� " << kon2 << " ���" << endl;
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	return 0;
}

int vstup_info(int nov)
{
	RGZ* h = 0;
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
		scanf("%i", & a);
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			printf("��i���� �������i� �� ������ ������? :");
			scanf("%i", &a);
			for (int i = 0; i < a; i++)
				h->rgz.add_one_el(h);
			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			Riad_FL(h), a = 0;
			break;
		}	/*if (a != 1 || a != 2)
			{
				printf("\n������� ���� �����i� �� i���\n\n ����i�� ���i� �� ���");
				a = 1;
			}*/
		
	}
		a = VSTUProzmova(a);
		while (a)
		{
			switch (a)
			{
			case 1:
				h->rgz.printTableHead();
				h->rgz.run_Print(h);
				break;
			case 2:	dop_INFO(h);
				break;
			case 3:h->rgz.delet_el(h);
				break;
			case 4:	h->rgz.el_Print(h);
				break;
			case 5: {h->rgz.dead_el(h);
				printf("������");
				Init(h);
				break; }
			case 6:nov = 0;
				h->rgz.dead_el(h);
				return 0;
			case 7:
				h->rgz.dead_el(h);
			{system("cls");
			nov = 1;
			return 1;
			}
			}
			char pit[] = "������ �� ���� �������?";
			a = sche(a, pit);
			if (a == 1)
				a = VSTUProzmova(a);
			else a = 6;

		}
	}




void Init(RGZ*& p) {
	p = new RGZ;
	p->next = NULL;
}


void SR::run_Print(RGZ* p)
{
	RGZ* pr = p->next;
	int i=1;
	while (pr!=NULL)
	{
		printf("|RGZ %-3d  |", i);
	/*	printf("%-14s|", pr->rgz.Get_predmet());
		printf("%-14s", pr->rgz.Get_teme());*/
	//cout << pr->rgz.Get_predmet()<<"  |"<< pr->rgz.Get_teme();
		cout << pr->rgz.Get_predmet() << "\t" ;
		printf("|%-18i|%-11i|%-11i|\n", pr->rgz.Get_bal(), pr->rgz.Get_termin(), pr->rgz.Get_zavdanj());
		/*printf("%-14s|%-14s|%-18i|%-11i|%-11i|\n",pr->rgz.Get_predmet(),pr->rgz.Get_teme(), pr->rgz.Get_bal(), pr->rgz.Get_termin(),pr->rgz.Get_zavdanj());
	*/
		printf("-----------------------------------------------------------------------------------\n");
		i++;
		pr = pr->next;
	}
}

void SR::el_Print(RGZ* p)
{
	RGZ* pr = p;
	
	int d;
	printf("���� ������� ������ �i���������: ");
	scanf("%i", &d);
	int a = 1;
	while (a)
	{
		a = 0;
		for (int i = 0; i < d; i++)
			if (pr->next != NULL)
				pr = pr->next;
			else
			{
		
				pr = p->next;
				printf("\n������ ��������� �i��������� ��i������� �������\n");
				printf("����i�� i��� �������� ");
				scanf("%d", &d);
				a = 1;
			}
	}
	p->rgz.printTableHead();
		printf("|RGZ %-3d  |", d);
		printf("%-14s|", pr->rgz.Get_predmet());
		printf("%-14s", pr->rgz.Get_teme());
		/*cout << pr->rgz.Get_predmet()<<"  |"<< pr->rgz.Get_teme()<<endl;*/
		printf("|%-18i|%-11i|%-11i|\n", pr->rgz.Get_bal(), pr->rgz.Get_termin(), pr->rgz.Get_zavdanj());
		printf("-----------------------------------------------------------------------------------\n");
	
}

void SR::add_el(string predmet ,string tema,int bal, int zavdanj, int termin,RGZ* p )
{
	RGZ* add = new RGZ;
	RGZ* head =p;
	add->next = NULL;
	add->rgz.Set_predmet(predmet);
	add->rgz.Set_teme(tema);
	add->rgz.Set_bal(bal);
	add->rgz.Set_termi(termin);
	add->rgz.Set_zavdanj(zavdanj);
	add->next = head->next;
	head->next = add;
	//size++;
}



void SR::add_one_el(RGZ* p)
{
	string predmet, tema; 
	int bal, termin, zadanj;
	cout << "������� :" ;
	cin >> predmet ;
	cout << "����:";
	cin >> tema;
	cout << "�i���i��� ���i� �� �������� : ";
	scanf("%i",& bal);
	cout << "���i�� : ";
	scanf("%i", &termin);
	cout << "�i���i��� ������� : ";
	scanf("%i", &zadanj);
	p->rgz.add_el(predmet, tema , bal, termin, zadanj, p);
	cout << "\n������ ������\n\n" << endl;
	/////������� ����� ������� �� 2
}

void SR::delet_el(RGZ* p)
{
	RGZ* pr = p->next;
	RGZ* temp=p;
	int d;
	printf("���� ������� ������ ��������");
	scanf("%i", &d);
	int a = 1;
	while (a)
	{
		a = 0;
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
	}
	{

		temp->next = pr->next;
	
		delete(pr);
	}
}

void SR::dead_el(RGZ* p)/////cerf aeyrbz yt hf,jnf'n
{RGZ* pr = p->next;
	if (p->next != 0)
	{
		
		while (p != 0)
		{

			p = pr->next;
			delete(pr);
			pr = p;
		}
	}
	delete(p,pr,this);
	
}

void Riad_FL(RGZ* h)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h;
	string text,adresa;
	int value,temp=0;
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
		RGZ* add = new RGZ;
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
		p = p->next;
	}
	
	fOpen.close();
}

void dop_INFO(RGZ*h)
{
	int a;
	printf("\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ");
	scanf("%i", &a);
	switch (a)
	{
	case 1:
		h->rgz.add_one_el(h);
		break;
	case 2:
		Riad_FL(h), a = 0;
		break;
	}
}

void SR::printTableHead()
{
	printf("\n\n-----------------------------------------------------------------------------------\n");
	printf("|         |  �������     |   ���a       | �i���i��� ���i�  |����� ����i| �i���i��� |\n");
	printf("|         |              |              |�� �������� RGZ   |    RGZ    |   ������� |\n  ");
	printf("-----------------------------------------------------------------------------------\n");
}