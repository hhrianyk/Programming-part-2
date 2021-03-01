#include "prototaype.h"
#include "SR.h"



void Scientific_SR::add_el(List_SR& A)
{
	Scientific_SR add;

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
			add.Set_zavdanj(value5);
		add.Set_surname(value1);
		add.Set_cientific_topic(value2);
		add.Set_predmet(value3);
		add.Set_termi(value4);
	

		A.add(&add);

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cout << "\nВашi данi успiшно записанi\n";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

}

void Scientific_SR::Riad_FL(List_SR& A)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Scientific_SR add;
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
		fOpen >> text;
		if ((regex_match(text, regex_integer2)) == 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(12));
			std::cout << "Критична помилка в написаному" << std::endl;
			text = "Eror(No name)";
			SetConsoleTextAttribute(hConsole, (WORD)(10));

		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			std::cout << "Програма виявила помилку в написаному та успішно випрвила її" << std::endl;
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}	add.Set_surname(text);////туту
		fOpen >> text;

		if ((regex_match(text, regex_integer2)) == 0)
		{
			text = "Eror(No name)";
		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "Програма виявила помилку в написаному та успішно випрвила її" << std::endl;

		}add.Set_predmet(text);
		fOpen >> text;

		if ((regex_match(text, regex_integer2)) == 0)
		{

			text = "Eror(No name)";

		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "Програма виявила помилку в написаному та успішно випрвила її" << std::endl;

		}add.Set_cientific_topic(text);
		fOpen >> value;
		add.Set_termi(value);
		fOpen >> value;
		add.Set_zavdanj(value);
	
		A.add(&add);
	}

	fOpen.close();
	
}

void Scientific_SR::Print_run(List_SR& A)///спадок вивести     
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	std::stringstream f;
	int kol = A.Get_kol_Index();
	for (int i = 0; i < kol; i++)
	{
		Scientific_SR* pr = (Scientific_SR*)A.Get_Elem(i);
		f << "|RGZ-" << i+1 << "    |" << std::setw(14) << pr->Get_surname() << "|" << std::setw(14) << pr->Get_predmet() 
			<< "|" << std::setw(18) << pr->Get_cientific_topic()
			<< "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj() << "|"
			<< "\n------------------------------------------------------------------------------------\n" << std::endl;

	}
	cout << f.str()<<endl;
	
}

void Scientific_SR::dop_INFO(List_SR& A)
{
	Scientific_SR h;
	number a;
	std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
	std::cin >> a;
	switch (a)
	{
	case 1:
		h.add_el(A);
		break;
	case 2:
		h.Riad_FL(A), a = 0;
		break;
	}
}

void Scientific_SR::Print_el(List_SR& A)
{
	Scientific_SR* pr = NULL;

	number d, a = 1;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;
	while (a)
	{
		a = 0;
		if (d > 0 && d < A.Get_kol_Index())
		{
			pr = (Scientific_SR*)A.Get_Elem(d - 1);
		}
		else { error(a, d); }
	}
	pr->printTableHead();
	
	std::cout << "|RGZ-" <<d<< "    |" <<std::setw(14) << pr->Get_surname() << "|" << std::setw(14) 
		<< pr->Get_predmet() << "|" << std::setw(18) << pr->Get_cientific_topic()
		<< "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj() << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------\n";
}


void Scientific_SR::sortSTR(List_SR& A)//сортувати елементи
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	number b = 0;
	b = kriter(b);
	bool a = true;
	cout << "Як сортувати\n 1: Вiд меншого до бiльшого \n 2: Вiд бiльшого до меншого \n\n Вибiр: ";
	int k = 0, m;
	cin >> m;
	if (m == 1) k = 1;
	else k = -1;
	Scientific_SR* p1 = (Scientific_SR*)A.Get_Elem(0);
	Scientific_SR* p2 = (Scientific_SR*)A.Get_Elem(0);

	while (a)
	{

		a = false;
		switch (b)

		{
		case 1:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (Scientific_SR*)A.Get_Elem(i);
				p2 = (Scientific_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_surname() > p2->Get_surname())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_surname() < p2->Get_surname())
					{
						A.sort(i);
						a = true;
					}
				}

			}
			break;
		case 2:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (Scientific_SR*)A.Get_Elem(i);
				p2 = (Scientific_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_predmet() > p2->Get_predmet())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_predmet() < p2->Get_predmet())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 3:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (Scientific_SR*)A.Get_Elem(i);
				p2 = (Scientific_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_cientific_topic()  > p2->Get_cientific_topic())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_cientific_topic() < p2->Get_cientific_topic())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 4:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (Scientific_SR*)A.Get_Elem(i);
				p2 = (Scientific_SR*)A.Get_Elem(i + 1);
				if (p1->Get_termin() * k > p2->Get_termin()* k)
				{
					A.sort(i);
					a = true;
				}
			}break;
		case 5:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (Scientific_SR*)A.Get_Elem(i);
				p2 = (Scientific_SR*)A.Get_Elem(i + 1);
				if (p1->Get_zavdanj() * k > p2->Get_zavdanj()* k)
				{
					A.sort(i);
					a = true;
				}

			}break;

		}
	}
	number d = 0;
	string p = "Бажаєте вивести на екран список";
	d = yes_and_no(d, p);
	if (d == 1)
	{
		Scientific_SR  pr = Scientific_SR();
		pr.printTableHead(), pr.Print_run(A);
	}

}
