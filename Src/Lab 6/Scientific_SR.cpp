#include "prototaype.h"
#include "SR.h"

void Scientific_SR::add_el(RGZ* p)
{
	RGZ* add = new RGZ;
	RGZ* head = p;
	add->next = NULL;


	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	int  value4, value5, value6;
	std::string value1, value2, value3;
	bool condition = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введiть ПРIЗВИЩЕ ВИКЛАДАЧА предмету : ";
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
	}std::cout << "додано" << std::endl;
	condition = true;
		while (condition)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			std::cout << "Введiть назву предмету : ";
			SetConsoleTextAttribute(hConsole, (WORD)(10));

			std::cin >> value3;

			if ((regex_match(value3, regex_integer2)) == 0)
			{
				std::cout << "pomylka";
				SetConsoleTextAttribute(hConsole, (WORD)(15));
				cout << "\nСпробуй ще раз\n";

				std::cin.clear();

				std::cin.ignore(std::cin.rdbuf()->in_avail());
				continue;
			}

			if ((regex_match(value3, regex_integer)) == 0)
			{
				value1[0] -= 32;
				std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
			}
			condition = false;
		}std::cout << "додано" << std::endl;
		condition = true;

		while (condition) {
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			if ((std::cin.rdbuf()->in_avail()) != 1);
			SetConsoleTextAttribute(hConsole, (WORD)(14));
			std::cout << "Введіть Наукову теме\n(Примiтка: при введенi слiв бiльше одного в якостi пробiлу використовайте ''_''):";
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
			
		}
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
			add->rBgz.Set_zavdanj(value5);
		add->rBgz.Set_surname(value1);
		add->rBgz.Set_cientific_topic(value2);
		add->rBgz.Set_predmet(value3);
		add->rBgz.Set_termi(value4);
	

		add->next = head->next;
		head->next = add;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cout << "\nВашi данi успiшно записанi\n";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

}


void Scientific_SR::Riad_FL(RGZ* h)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RGZ* p = h;
	std::ifstream fOpen;
	int value, temp = 0;
	std::string text, adresa;

	std::cout << "\nЯкий файл відкрити?\n\n 1. follower.txt\n 2. follower.txt\n Ваш вiбiр:";
	std::cin >> temp;
	switch (temp)
	{
	case 1:adresa = "follower.txt";///
		break;
	case 2:adresa = "follower.txt";//
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
	while (!fOpen.eof())
	{
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
		}	add->rBgz.Set_surname(text);////туту
		fOpen >> text;

		if ((regex_match(text, regex_integer2)) == 0)
		{
			text = "Eror(No name)";
		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;

		}add->rBgz.Set_predmet(text);
		fOpen >> text;

		if ((regex_match(text, regex_integer2)) == 0)
		{

			text = "Eror(No name)";

		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;

		}add->rBgz.Set_cientific_topic(text);
		fOpen >> value;
		add->rBgz.Set_termi(value);
		fOpen >> value;
		add->rBgz.Set_zavdanj(value);
	
		p = p->next;
	}

	fOpen.close();
	
}
void Scientific_SR::Print_run(RGZ* p)///спадок вивести     
{
	RGZ* pr = p->next;
	int i = 1;
	std::stringstream f;
	do
	{
		f << "|RGZ-" << i++ << "    |" << std::setw(14) << pr->rBgz.Get_surname() << "|" << std::setw(14) << pr->rBgz.Get_predmet() << "|" << std::setw(18) << pr->rBgz.Get_cientific_topic()
			<< "|" << std::setw(11) << pr->rBgz.Get_termin() << "|" << std::setw(11) << pr->rBgz.Get_zavdanj() << "|" 
			<< "\n------------------------------------------------------------------------------------\n" << std::endl;

		pr = pr->next;
	}while (pr != NULL);
	cout << f.str()<<endl;
	
}

void Scientific_SR::dop_INFO(RGZ* h)
{
	number a;
	std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
	std::cin >> a;
	switch (a)
	{
	case 1:
		h->rBgz.add_el(h);
		break;
	case 2:
		h->rBgz.Riad_FL(h), a = 0;
		break;
	}
}
void Scientific_SR::Print_el(RGZ* p)
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
	p->rBgz.printTableHead();

	std::cout << "|RGZ-" <<d<< "    |" <<std::setw(14) << pr->rBgz.Get_surname() << "|" << std::setw(14) << pr->rBgz.Get_predmet() << "|" << std::setw(18) << pr->rBgz.Get_cientific_topic()
		<< "|" << std::setw(11) << pr->rBgz.Get_termin() << "|" << std::setw(11) << pr->rgz.Get_zavdanj() << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------\n";
}