#include "prototaype.h"
#include "SR.h"


void SR::Init(RGZ*& p) {
	p = new RGZ;
	p->next = NULL;
}

int vstup_info(number nov)
{

	RGZ* h = NULL;
	number  a = 1, u = 0;
	h->rgz.Init(h);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Доброго дня користувач\n ";
	std::cout << "\nЗараз: ";
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << __DATE__;
	std::cout << "\nЧас початку роботи програми: ", SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << __TIME__ << SetConsoleTextAttribute(hConsole, (WORD)(11));
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n Почнемо роботу\n\n Ввести данi\n ";
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
		std::cin >> a;
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cout << "Скiльки елементiв ви хочете додати? :";
			std::cin >> a;
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
			std::cout << "Успішно";
			h->rgz.Init(h);
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
			h->rgz.printTableHead();
			h->rgz.Print_two_words_in_line(h);
			break;

		case 10:
			h->rgz.save_for_Fl(h);
			break;
		case 11: h->rgz.print_saved_for_Fl();
			break;
		case 12: h->rgz.sortSTR(h);
			break;
		case 13: h->rgz.AG.kəvər();
			break;
}
		char pit[] = "Бажаєте ще щось зробити?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = main_menu(a);
		else a = 7;

	}
}

void dop_INFO(RGZ* h)
{
	number a;
	std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
	std::cin >> a;
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
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h;
	std::ifstream fOpen;
	int value, temp = 0;
	std::string text, adresa;

	std::cout << "\nЯкий файл відкрити?\n\n 1. RGZ.txt\n 2. add_RGZ.txt\n Ваш вiбiр:";
	std::cin >> temp;
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
		RGZ* add = new RGZ;
		add->next = p->next;
		p->next = add;
		fOpen >> text;
		if ((regex_match(text, regex_integer2)) == 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(12));
			std::cout << "Критична помилка в напиcаннi" << std::endl;
			text = "Eror(No name)";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			
		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}
		add->rgz.Set_predmet(text);
		fOpen >> text;
		if ((regex_match(text, regex_integer2)) == 0)
		{

			text = "Eror(No name)";
			
		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
		}
		add->rgz.Set_teme(text);
		fOpen >> value;
		add->rgz.Set_bal(value);
		fOpen >> value;
		add->rgz.Set_termi(value);
		fOpen >> value;
		add->rgz.Set_zavdanj(value);
		fOpen >> value;
		add->rgz.cathedr.Set_cathedra(value);
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
		f << "|RGZ-" << i++ << "    |" << std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) << pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) << pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|" << "\n------------------------------------------------------------------------------------\n" << std::endl;
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

	number d;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;
	number a = 1;
	while (a)
	{
		a = 0;
		if (d > 0)
		{
			for (int i = 0; i < d; i++)
				if (pr->next != NULL)
					pr = pr->next;
				else
				{
					pr = p->next;
					error(a, d);
				}
		}
		else
		{
			pr = p->next;
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
	number d;
	std::cout << "Який елемент хочете видалити";
	std::cin >> d;
	number a = 1;
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
					std::cout << "\nНажаль неможливо видалити неiснуючий елемент\n";
					std::cout << "Введiть iнше значення ";
					std::cin >> d;
					a = 1;
				}
		}
		else {
			temp = p;
			pr = p->next;
			std::cout << "\nНажаль неможливо видалити неiснуючий елемент\n";
			std::cout << "Введiть iнше значення ";
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
void SR::curriculum(RGZ* p)
{
	RGZ* pr = p->next;
	int cu = 0, i = 0;
	std::cout << "\n\nВведіть спецiальнiсть/кафедру(номер) :";

	std::cin >> cu;
	while (pr->next != 0)
	{

		if (cu == pr->rgz.cathedr.Get_cathedra())
			i++;
		pr = pr->next;
	}
	if (i > 0)
	{
		std::cout << "Вашому студенту у цьому навчальному році треба зробити: " << i << " РГЗ" << std::endl;

		std::cout << "Вам цiкаво з яких предметiв вам потрiбно робити \n 1:да\n 2:нет \n Ваш вибiр:";
		int king;
		std::cin >> king;
		if (king == 1)
		{
			std::cout << "\n З таких предметiв :";
			pr = p;
			while (pr->next != 0)
			{
				if (cu == pr->rgz.cathedr.Get_cathedra())
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
		std::cout << "\n\nВiтаю у цьому роцi ваи непотрiбно робити РГЗ з жодних предметiв!!!\n\n ";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
	}

}

void SR::save_for_Fl(RGZ* h)//зберегти все у файл
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h->next;

	std::string adresa;
	int  temp = 0;
	std::fstream fOpen;
	std::cout << "\nЯкий файл відкрити?\n\n 1. txt.txt(текстовий файл)\n 2. bib.bin(бінарний файл)\n Ваш вiбiр:";
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
		fOpen << p->rgz.Get_predmet() << " " << p->rgz.Get_teme() << " " << p->rgz.Get_bal() << " " << p->rgz.Get_zavdanj() << " " << p->rgz.Get_termin() << " " << p->rgz.cathedr.Get_cathedra() << std::endl;
		p = p->next;
	}
	fOpen.close();
	std::cout << "\nЗбереження успішно завершено" << std::endl;


}

void SR::print_saved_for_Fl()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*	RGZ* p = h;*/
	std::ifstream fOpen;
	int value, temp = 0;
	std::string text, adresa;

	std::cout << "\nЯкий файл відкрити?\n\n 1. txt.txt(текстовий файл)\n 2. bib.bin(бінарний файл)\n Ваш вiбiр:";
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
	while (!fOpen.eof()) {

		fOpen >> text;
		std::cout << text << " ";
		fOpen >> text;
		std::cout << text << " ";
		fOpen >> value;
		std::cout << value << " ";
		fOpen >> value;
		std::cout << value << " ";
		fOpen >> value;
		std::cout << value << " ";
		fOpen >> value;
		std::cout << value << std::endl;

	}

}

void SR::add_el(RGZ* h) 
{

	RGZ* add = new RGZ;
	RGZ* head = h;
	add->next = NULL;
	
    std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	int  value3, value4, value5, value6;
	std::string value1, value2;
	bool condition = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введiть назву предмету : ";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

		std::cin >> value1;

		if ((regex_match(value1, regex_integer2)) == 0)
		{
			std::cout << "pomylka";
			SetConsoleTextAttribute(hConsole, (WORD)(15));
			cout << "\nСпробуй ще раз\n";

			std::cin.clear();

			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
	
		if ((regex_match(value1, regex_integer)) == 0)
		{
			value1[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
		}
		condition = false;
	
	}

	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " додано" << std::endl;
	condition = true;
	while (condition) {
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		if ((std::cin.rdbuf()->in_avail()) != 1);
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введіть тему :";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		std::cin >> value2;
		if ((regex_match(value2, regex_integer2)) == 0)
		{
			std::cout << "pomylka";
			SetConsoleTextAttribute(hConsole, (WORD)(15));
			cout << "\nСпробуй ще раз\n";

			std::cin.clear();

			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}

		if ((regex_match(value2, regex_integer)) == 0)
		{
			value2[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
		}
		condition = false;
		/*if (value2[0] >= 'a' && value2[0] <= 'z' || value2[0] >= 'а' && value2[0] <= 'я' || value2[0] == 'ё')
			value2[0] -= 32;*/
		}
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << "додано" << std::endl;
	condition = true;
	while (condition) 
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		if ((std::cin.rdbuf()->in_avail()) != 1);
		std::cout << "Введiть Кiлькiсть балiв за завдання : ";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		std::cin >> value3;

		if (std::cin.fail()) {//Если есть ошибка, выводим сообщение
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			cout << "Спробуйте ще раз\n";
			std::cin.clear();//Почистили поток
			std::cin.ignore(std::cin.rdbuf()->in_avail());//Восстановили поток
			continue;
		}
		if (value3 > 0)
			condition = false;

		else
			cout << "\nВи сильно недооцiнюєте складнiсть цього RGZ\n";
	}
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << "додано" << std::endl;
	condition = true;
	while (condition) {
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		if ((std::cin.rdbuf()->in_avail()) != 1);
		cout << "Введiть Перiод (у днях) : ";

		std::cin >> value4;
		if (std::cin.fail()) {
			SetConsoleTextAttribute(hConsole, (WORD)(15));
			cout << "\nСпробуй ще раз\n";

			std::cin.clear();

			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		if (value4 > 0)
			condition = false;

		else
			cout << "Навiть професiоналу на це потребується бiльше часу";
	}SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << "додано" << std::endl;
	condition = true;
	while (condition) {
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		cout << "Введiть кiлькiсть завдань : ";
		std::cin >> value5;
		if (std::cin.fail()) {
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << "Спробуй ще раз\n";

			std::cin.clear();

			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		if (value5 > 0)
			condition = false;

		else
			cout << " Навiщо взагалi його робити?\n";

	}SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " додано" << std::endl;
	condition = true;
	while (condition) {
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		cout << "Введіть факультет/кафедру : ";
		std::cin >> value6;
		if (std::cin.fail()) {
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			cout << " Спробуй ще раз\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		condition = false;
		if (value6 > 0)
			condition = false;
		else
			cout << " Ви впевненi, що таке iснує?  " << std::endl;
	}SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " додано" << std::endl;
	SetConsoleTextAttribute(hConsole, (WORD)(5));

	add->rgz.Set_predmet(value1);
	add->rgz.Set_teme(value2);
	add->rgz.Set_bal(value3);
	add->rgz.Set_termi(value4);
	add->rgz.Set_zavdanj(value5);
	add->rgz.cathedr.Set_cathedra(value6);
	add->next = head->next;
	head->next = add;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cout << "\nВашi данi успiшно записанi\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
}

void SR::Print_two_words_in_line(RGZ* p)
{
	std::regex regex_integer("^[А-Яа-яA-za-z0-9]{1,10}[\\.,]?[-_\ ][А-Яа-яA-za-z]{1,10}$");
	
RGZ* pr = p->next;
int i = 1;

std::stringstream f;
while (pr != NULL)
{
	if (regex_match(pr->rgz.Get_predmet(), regex_integer) == 1)
	{
		f << "|RGZ-" << i++ << "    |" << std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) 
			<< pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) 
			<< pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|"
			<< "\n------------------------------------------------------------------------------------\n" << std::endl;
		pr = pr->next;
	}
	else if ((regex_match((pr->rgz.Get_teme()), regex_integer)) == 1)
	{
	f << "|RGZ-" << i++ << "    |" << std::setw(14) << pr->rgz.Get_predmet() << "|" << std::setw(14) 
		<< pr->rgz.Get_teme() << "|" << std::setw(18) << pr->rgz.Get_bal() << "|" << std::setw(11) 
		<< pr->rgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|"
		<< "\n------------------------------------------------------------------------------------\n" << std::endl;
	pr = pr->next;
	}
	else{pr = pr->next;}
}
std::cout << f.str();
}

void SR::sortSTR(RGZ* pr)//сортувати елементи
{
	number b = 0;
	b = kriter(b);
	bool a = true;
	cout << "Як сортувати\n 1: Вiд меншого до бiльшого \n 2: Вiд бiльшого до меншого \n\n Вибiр: ";
	int k = 0,m;
		cin >> m ;
		if (m == 1) k = 1;
		else k = -1;
		
	while (a)
	{
		RGZ* p = pr;
		RGZ* p1 = pr->next;
		RGZ* p2 = p1->next;
	a = false;
		switch (b)
		{
		case 1:
			while (p2)
			{
				if (m == 1)
				{
					if (p1->rgz.Get_predmet() > p2->rgz.Get_predmet())
					{
						sortN(p, p1, p2);
						a = true;
					}
					else
						sortK(p, p1, p2);
				}
			else
				if (p1->rgz.Get_predmet() < p2->rgz.Get_predmet())
				{
					sortN(p, p1, p2);
					a = true;
				}
				else
					sortK(p, p1, p2);
			}
			break;
		case 2:
			while (p2)
			{
				if (m == 1)
				{
					if (p1->rgz.Get_teme() > p2->rgz.Get_teme())
					{
						sortN(p, p1, p2);
						a = true;
					}
					else
						sortK(p, p1, p2);
				}
				else
						if (p1->rgz.Get_teme() < p2->rgz.Get_teme())
						{
							sortN(p, p1, p2);
							a = true;
						}
						else
							sortK(p, p1, p2);
			}break;
		case 3:
			while (p2)
			{
				{if (p1->rgz.Get_termin()*k > p2->rgz.Get_termin()*k)
					{
						sortN(p, p1, p2);
						a = true;
					}
					else
						sortK(p, p1, p2);
			}
			
			}break;
		case 4:
			while (p2)
			{			
					if (p1->rgz.Get_zavdanj()*k > p2->rgz.Get_zavdanj()*k)
					{
						sortN(p, p1, p2);
						a = true;
					}
					else
						sortK(p, p1, p2);						
			}break;
		case 5:
			while (p2)
			{				
				if (p1->rgz.Get_bal()*k > p2->rgz.Get_bal()*k)
					{
						sortN(p, p1, p2);
						a = true;
					}
					else
						sortK(p, p1, p2);		
			}break;
		
		}
	}

	number d = 0;
	char p[] = "Бажаєте вивести на екран список";
	d = yes_and_no(d, p);
	if (d == 1)
		pr->rgz.printTableHead(),Print_run(pr);
}

void SR::sortN(RGZ*& p, RGZ*& p1, RGZ*& p2)
{
	p1->next = p2->next;
	p2->next = p1;
	p->next = p2;
	p = p2;
	p2 = p1->next;

}
void SR::sortK(RGZ*& p, RGZ*& p1, RGZ*& p2)
{
	p = p1;
	p1 = p2;
	p2 = p2->next;
}

