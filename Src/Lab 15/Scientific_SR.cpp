#include "prototaype.h"
#include "SR.h"



Scientific_SR& Scientific_SR::operator = (const Scientific_SR& SR)
{
	//cout << "���������� ��������� '='" << endl;
	if (this == &SR)
		return *this;

	surname         = SR.surname;
	cientific_topic = SR.cientific_topic;
	predmet = SR.predmet;
	zavdanj = SR.zavdanj;
	termin =SR.termin;



	return *this;
}
Scientific_SR& Scientific_SR::operator = (const Scientific_SR* SR)
{
	//cout << "���������� ��������� '='" << endl;
	if (this == SR)
		return *this;
	if (typeid(*this).name() != typeid(*SR).name()) throw std::invalid_argument("������� ���������");;
	surname         = SR->surname;
	cientific_topic = SR->cientific_topic;
	predmet = SR->predmet;
	zavdanj = SR->zavdanj;
	termin = SR->termin;

	return  *this;
}
//bool operator < (Scientific_SR& p, Scientific_SR& p2) {
//	int i = 0;
//	if (p.Get_surname() < p2.Get_surname())i++;
//	if (p.Get_predmet() < p2.Get_predmet())i++;
//	if (p.Get_cientific_topic() < p2.Get_cientific_topic())i++;
//	if (p.Get_zavdanj() < p2.Get_zavdanj())i++;
//	if (p.Get_termin()  < p2.Get_termin())i++;
//	if (i < 3)return 0;
//	else return 1;
//
//}
//bool operator > (Scientific_SR& p, Scientific_SR& p2)
//{
//	int i = 0;
//	if (p.Get_surname() > p2.Get_surname())i++;
//	if (p.Get_predmet() > p2.Get_predmet())i++;
//	if (p.Get_cientific_topic() > p2.Get_cientific_topic())i++;
//	if (p.Get_zavdanj() > p2.Get_zavdanj())i++;
//	if (p.Get_termin()  > p2.Get_termin())i++;
//	if (i < 3)return 0;
//	else return 1;
//}
//
//bool operator== (Scientific_SR& p, Scientific_SR& p2) { return !(p < p2) && !(p > p2); }
bool operator!= (Scientific_SR& p, Scientific_SR& p2) { return !(p == p2); }

bool operator <= (Scientific_SR& p, Scientific_SR& p2) { return (p == p2) || !(p2 < p); }
bool operator >= (Scientific_SR& p, Scientific_SR& p2) { return (p == p2) || !(p2 > p); }



//����� �� �����
ostream& operator<< (ostream& out, Scientific_SR& pr)
{
	out << "    |" << std::setw(14) << pr.Get_surname() << "|" << std::setw(14) << pr.Get_predmet()
		<< "|" << std::setw(18) << pr.Get_cientific_topic()
		<< "|" << std::setw(11) << pr.Get_termin() << "|" << std::setw(11) << pr.Get_zavdanj() << "|"
		<< "\n------------------------------------------------------------------------------------\n";
	return out;
}


//������� � �����
ifstream& operator >> (ifstream& stream, Scientific_SR& add)
{
	std::regex regex_integer(("^[�-�A-Z][�-��-�a-zA-Z0-9 -_\\.,]*$"));//�������� �� ������� ������
	std::regex regex_integer2(("^[A-za-z�-��-�][A-za-z�-��-�0-9]{1,20}[\\.,]?[-_ ]?[�-��-�A-za-z]{1,20}?$"));//�������� �� ���������� ����

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream fOpen;
	int value;
	std::string text;



	stream >> text;
	if ((regex_match(text, regex_integer2)) == 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		std::cout << "�������� ������� � ����������" << std::endl;
		text = "Eror(No name)";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

	}
	else if ((regex_match(text, regex_integer)) == 0)
	{
		text[0] -= 32;
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << "�������� ������� ������� � ���������� �� ������ �������� ��" << std::endl;
		SetConsoleTextAttribute(hConsole, (WORD)(10));
	}	add.Set_surname(text);////����
	stream >> text;

	if ((regex_match(text, regex_integer2)) == 0)
	{
		text = "Eror(No name)";
	}
	else if ((regex_match(text, regex_integer)) == 0)
	{
		text[0] -= 32;
		std::cout << "�������� ������� ������� � ���������� �� ������ �������� ��" << std::endl;

	}add.Set_predmet(text);
	stream >> text;

	if ((regex_match(text, regex_integer2)) == 0)
	{

		text = "Eror(No name)";

	}
	else if ((regex_match(text, regex_integer)) == 0)
	{
		text[0] -= 32;
		std::cout << "�������� ������� ������� � ���������� �� ������ �������� ��" << std::endl;

	}add.Set_cientific_topic(text);

	
	 stream >> value;
	 add.Set_termin(value);
	 stream >> value;
     add.Set_zavdanj(value);
	

	return stream;

}

/////////////////////////////




//
//void Scientific_SR::add_el(List_SR& A)
//{
//	Scientific_SR add;
//
//	std::regex regex_integer(("^[�-�A-Z][�-��-�a-zA-Z0-9 -_\\.,]*$"));//�������� �� ������� ������
//	std::regex regex_integer2(("^[A-za-z�-��-�][A-za-z�-��-�0-9]{1,20}[\\.,]?[-_ ]?[�-��-�A-za-z]{1,20}$"));//�������� �� ���������� ����
//
//	int  value4, value5;
//	std::string value1, value2, value3;
//	bool condition = true;
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	while (condition)
//	{
//		SetConsoleTextAttribute(hConsole, (WORD)(14));
//		std::cout << "����i�� ��I����� ��������� �������� : ";
//		SetConsoleTextAttribute(hConsole, (WORD)(10));
//
//		std::cin >> value1;
//
//		if ((regex_match(value1, regex_integer2)) == 0)
//		{
//			std::cout << "pomylka";
//			SetConsoleTextAttribute(hConsole, (WORD)(15));
//			cout << "\n������� �� ���\n";
//
//			std::cin.clear();
//
//			std::cin.ignore(std::cin.rdbuf()->in_avail());
//			continue;
//		}
//
//		if ((regex_match(value1, regex_integer)) == 0)
//		{
//			value1[0] -= 32;
//			std::cout << "�������� ������� ������� � �������� �� ������ �������� ��" << std::endl;
//		}
//		condition = false;
//	}std::cout << "������" << std::endl;
//	condition = true;
//		while (condition)
//		{
//			SetConsoleTextAttribute(hConsole, (WORD)(14));
//			std::cout << "����i�� ����� �������� : ";
//			SetConsoleTextAttribute(hConsole, (WORD)(10));
//
//			std::cin >> value3;
//
//			if ((regex_match(value3, regex_integer2)) == 0)
//			{
//				std::cout << "pomylka";
//				SetConsoleTextAttribute(hConsole, (WORD)(15));
//				cout << "\n������� �� ���\n";
//
//				std::cin.clear();
//
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				continue;
//			}
//
//			if ((regex_match(value3, regex_integer)) == 0)
//			{
//				value1[0] -= 32;
//				std::cout << "�������� ������� ������� � �������� �� ������ �������� ��" << std::endl;
//			}
//			condition = false;
//		}std::cout << "������" << std::endl;
//		condition = true;
//
//		while (condition) {
//			SetConsoleTextAttribute(hConsole, (WORD)(10));
//			SetConsoleTextAttribute(hConsole, (WORD)(14));
//			std::cout << "������ ������� ����\n(����i���: ��� ������i ��i� �i���� ������ � �����i ����i�� �������������� ''_''):";
//			SetConsoleTextAttribute(hConsole, (WORD)(10));
//			std::cin >> value2;
//			if ((regex_match(value2, regex_integer2)) == 0)
//			{
//				std::cout << "pomylka";
//				SetConsoleTextAttribute(hConsole, (WORD)(15));
//				cout << "\n������� �� ���\n";
//
//				std::cin.clear();
//
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				continue;
//			}
//
//			if ((regex_match(value2, regex_integer)) == 0)
//			{
//				value2[0] -= 32;
//				std::cout << "�������� ������� ������� � �������� �� ������ �������� ��" << std::endl;
//			}
//
//
//			condition = false;
//			
//		}
//		std::cout << "������" << std::endl;
//		condition = true;
//		while (condition) {
//			SetConsoleTextAttribute(hConsole, (WORD)(14));
//			cout << "����i�� ���i�� (� ����) : ";
//
//			std::cin >> value4;
//			if (std::cin.fail()) {
//				SetConsoleTextAttribute(hConsole, (WORD)(15));
//				cout << "\n������� �� ���\n";
//
//				std::cin.clear();
//
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				continue;
//			}
//			if (value4 > 0)
//				condition = false;
//
//			else
//				cout << "���i�� ������i����� �� �� ����������� �i���� ����";
//		}SetConsoleTextAttribute(hConsole, (WORD)(11));
//		std::cout << "������" << std::endl;
//		condition = true;
//		while (condition) {
//			SetConsoleTextAttribute(hConsole, (WORD)(14));
//			cout << "����i�� �i���i��� ������� : ";
//			std::cin >> value5;
//			if (std::cin.fail()) {
//				SetConsoleTextAttribute(hConsole, (WORD)(11));
//				cout << "������� �� ���\n";
//
//				std::cin.clear();
//
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				continue;
//			}
//			if (value5 > 0)
//				condition = false;
//
//			else
//				cout << " ���i�� ������i ���� ������?\n";
//
//		}SetConsoleTextAttribute(hConsole, (WORD)(11));
//		std::cout << " ������" << std::endl;
//			add.Set_zavdanj(value5);
//		add.Set_surname(value1);
//		add.Set_cientific_topic(value2);
//		add.Set_predmet(value3);
//		add.Set_termin(value4);
//	
//
//		A.add(&add);
//
//		std::cin.clear();
//		std::cin.ignore(std::cin.rdbuf()->in_avail());
//
//		std::cout << "\n���i ���i ���i��� �������i\n";
//		SetConsoleTextAttribute(hConsole, (WORD)(10));
//
//}
//
//void Scientific_SR::Riad_FL(List_SR& A)
//{
//	std::regex regex_integer(("^[�-�A-Z][�-��-�a-zA-Z0-9 -_\\.,]*$"));//�������� �� ������� ������
//	std::regex regex_integer2(("^[A-za-z�-��-�][A-za-z�-��-�0-9]{1,20}[\\.,]?[-_ ]?[�-��-�A-za-z]{1,20}$"));//�������� �� ���������� ����
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	Scientific_SR add;
//	std::ifstream fOpen;
//	int  temp = 0;
//	std::string text, adresa;
//
//	std::cout << "\n���� ���� �������?\n\n 1. follower.txt\n 2. follower.txt\n ��� �i�i�:";
//	std::cin >> temp;
//	switch (temp)
//	{
//	case 1:adresa = "follower.txt";///
//		break;
//	case 2:adresa = "follower.txt";//
//		break;
//	}
//	fOpen.open(adresa, std::ios_base::in);
//	if (!fOpen)
//    {
//		SetConsoleTextAttribute(hConsole, (WORD)(5));
//		std::cout << "File is not open\n\n";
//		SetConsoleTextAttribute(hConsole, (WORD)(10));
//		return;
//
//	}SetConsoleTextAttribute(hConsole, (WORD)(10));
//	while (!fOpen.eof())
//	{
//	
//		fOpen >> add;
//		A.add(&add);
//	}
//
//	fOpen.close();
//	
//}
//
//void Scientific_SR::Print_run(List_SR& A)///������ �������     
//{
//
//	Scientific_SR pr;
//
//	int kol = A.Get_kol_Index();
//	for (int i = 0; i < kol; i++)
//	{
//		try {
//			
//				pr = (Scientific_SR*)A[i];
//
//
//				cout << "|RGZ-" << i + 1 << pr << std::endl;
//			}
//	
//		catch (std::invalid_argument e) {
//			//cout << e.what() << endl;
//		}
//		
//
//	}
//
//	
//}
//
//void Scientific_SR::dop_INFO(List_SR& A)
//{
//	Scientific_SR h;
//	number a;
//	std::cout << "\n 1: � ����i�����\n 2: 3 �����\n ��� �i�i�:   ";
//	std::cin >> a;
//	switch (a)
//	{
//	case 1:
//		h.add_el(A);
//		break;
//	case 2:
//		h.Riad_FL(A), a = 0;
//		break;
//	}
//}
//
//void Scientific_SR::Print_el(List_SR& A)
//{
//	if (A.Get_kol_Index() < 1)
//	{
//		cout << "!!!!������ �����!!!" << endl;
//		system("pause&cls");
//		return;
//	}
//	Scientific_SR pr;
//	number d, a = 1;
//	std::cout << "���� ������� ������ �i���������: ";
//	std::cin >> d;
//	while (a)
//	try {
//	  	a = 0;
//		if (d > 0 && d < A.Get_kol_Index())
//		{
//
//			pr = (Scientific_SR*)A[d-1];
//			pr.printTableHead();
//			cout << "|RGZ-" << d << pr << std::endl;
//		}
//		
//		else { error(a, d); }
//	}
//
//	catch (std::invalid_argument e) {
//		cout << "������� ������ ��������";
//	}
//}

