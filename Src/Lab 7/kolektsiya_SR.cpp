#include "prototaype.h"
#include "SR.h"


void kolektsiya_SR::add_el(List_SR& A)
{
	kolektsiya_SR add;


	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	int  value5;
	std::string value1, value2, value3 , value4;
	bool condition = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введiть назву предмета : ";
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
		std::cout << "Введiть назву збирника завдань : ";
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
			value1[0] -= 32;
			std::cout << "Програма виявила помилку в написанні та успішно випрвила її" << std::endl;
		}
		condition = false;
	}std::cout << "додано" << std::endl;
	condition = true;
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введiть призвище автора : ";
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
	condition = true; condition = true;
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		std::cout << "Введiть назву видаництва : ";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

		std::cin >> value4;

		if ((regex_match(value4, regex_integer2)) == 0)
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
	while (condition) {///////регулярка дати
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		cout << "Введiть рік видання : ";
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

	}SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << " додано" << std::endl;
	add.Set_predmet(value1);
	add.Set_collection(value2);
	add.Set_author(value3);	
	add.Set_Vydavnytstvo(value4);
	add.Set_data(value5);

	A.add(&add);
	
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cout << "\nВашi данi успiшно записанi\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));

}


void kolektsiya_SR::Riad_FL(List_SR& A)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	kolektsiya_SR add;
	std::ifstream fOpen;
	int value, temp = 0;
	std::string text;

	fOpen.open("zbyrnk_zavdan.txt", std::ios_base::in);
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
			std::cout << "1Критична помилка в написаному" << std::endl;
			text = "Eror(No name)";
			SetConsoleTextAttribute(hConsole, (WORD)(10));

		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			std::cout << "Програма виявила помилку в написаному та успішно випрвила її" << std::endl;
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}	add.Set_predmet(text);////туту
		fOpen >> text;
		add.Set_collection(text);////туту
		fOpen >> text;
		if ((regex_match(text, regex_integer2)) == 0)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(12));
			std::cout << "3Критична помилка в написаному" << std::endl;
			text = "Eror(No name)";
			SetConsoleTextAttribute(hConsole, (WORD)(10));

		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			SetConsoleTextAttribute(hConsole, (WORD)(11));
			std::cout << "Програма виявила помилку в написаному та успішно випрвила її" << std::endl;
			SetConsoleTextAttribute(hConsole, (WORD)(10));
		}	add.Set_author(text);////туту
		fOpen >> text;

		if ((regex_match(text, regex_integer2)) == 0)
		{
			text = "Eror(No name)";
		}
		else if ((regex_match(text, regex_integer)) == 0)
		{
			text[0] -= 32;
			std::cout << "4Програма виявила помилку в написаному та успішно випрвила її" << std::endl;

		}add.Set_Vydavnytstvo(text);
		/*fOpen >> text;*/

		fOpen >> value;
		add.Set_data(value);

		A.add(&add);
	}

	fOpen.close();

}

void kolektsiya_SR::Print_el(List_SR& A)
{
	kolektsiya_SR* pr = NULL;

	number d, a = 1;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;
	while (a)
	{
		a = 0;
		if (d > 0 && d < A.Get_kol_Index())
		{
			pr = (kolektsiya_SR*)A.Get_Elem(d - 1);
		}
		else { error(a, d); }
	}
	pr->printTableHead();

	std::cout << "|RGZ-" << d << "    |" << std::setw(14) << pr->Get_predmet() << "|" << std::setw(14) << pr->Get_collection() << "|" << std::setw(18) << pr->Get_author()
		<< "|" << std::setw(11) << pr->Get_Vydavnytstvo() << "|" << std::setw(11) << pr->Get_data() << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------\n";
}

void kolektsiya_SR::Print_run(List_SR& A)///спадок вивести     
{
	std::stringstream f;
	int kol = A.Get_kol_Index();
	for (int i = 0; i < kol; i++)
	{
		kolektsiya_SR* pr = (kolektsiya_SR*)A.Get_Elem(i);
		f << "|RGZ-" << i++ << "    |" << std::setw(14) << pr->Get_predmet() << "|" << std::setw(14) << pr->Get_collection() << "|" << std::setw(18) << pr->Get_author()
			<< "|" << std::setw(11) << pr->Get_Vydavnytstvo() << "|" << std::setw(11) << pr-Get_data() << "|"
			<< "\n------------------------------------------------------------------------------------\n" << std::endl;

	}
	cout << f.str() << endl;

}

void kolektsiya_SR::dop_INFO(List_SR& A)
{
	kolektsiya_SR h;
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


void kolektsiya_SR::poshuk(List_SR& A)
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	kolektsiya_SR* p =NULL;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод
	string autor;
	int  perevirka=0;
	bool condition = true;
	while (condition)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(14));
		cout << "Введіть прізвище автора :";
		SetConsoleTextAttribute(hConsole, (WORD)(10));

		std::cin >> autor;

		if ((regex_match(autor, regex_integer2)) == 0)
		{
			std::cout << "pomylka";
			SetConsoleTextAttribute(hConsole, (WORD)(15));
			cout << "\nСпробуй ще раз\n";

			std::cin.clear();

			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}

		if ((regex_match(autor, regex_integer)) == 0)
		{
			autor[0] -= 32;
		}
		condition = false;
	}
	cout << endl << endl;
	int kol = A.Get_kol_Index();
	for (int i = 0; i < kol; i++)
	{
		kolektsiya_SR* pr = (kolektsiya_SR*)A.Get_Elem(i);

		if (autor == p->Get_author())
		{
			perevirka++;
			cout << "|RGZ-" <<i+1 << "    |" << std::setw(14) << p->Get_predmet() << "|" << std::setw(14) << p->Get_collection() << "|" << std::setw(18) << p->Get_author()
				<< "|" << std::setw(11) << p->Get_Vydavnytstvo() << "|" << std::setw(11) << p->Get_data() << "|" << std::endl;
			std::cout << "-----------------------------------------------------------------------------------\n";
		
		}

	}
	if (perevirka == 0)
		cout << "\nТакого автора незнайдено\n";
	system("pause");
}


void kolektsiya_SR::sortSTR(List_SR& A)//сортувати елементи
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
	kolektsiya_SR* p1 = (kolektsiya_SR*)A.Get_Elem(0);
	kolektsiya_SR* p2 = (kolektsiya_SR*)A.Get_Elem(0);

	while (a)
	{

		a = false;
		switch (b)

		{
		case 1:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A.Get_Elem(i);
				p2 = (kolektsiya_SR*)A.Get_Elem(i + 1);
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

			}
			break;
		case 2:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A.Get_Elem(i);
				p2 = (kolektsiya_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_collection() > p2->Get_collection())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_collection() < p2->Get_collection())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 3:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A.Get_Elem(i);
				p2 = (kolektsiya_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_author() > p2->Get_author())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_author() < p2->Get_author())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 4:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A.Get_Elem(i);
				p2 = (kolektsiya_SR*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_Vydavnytstvo() > p2->Get_Vydavnytstvo())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_Vydavnytstvo() < p2->Get_Vydavnytstvo())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 5:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A.Get_Elem(i);
				p2 = (kolektsiya_SR*)A.Get_Elem(i + 1);
				if (p1->Get_data() * k > p2->Get_data()* k)
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

void kolektsiya_SR::delet_el(List_SR& A)
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	kolektsiya_SR* pr = NULL;

	number d, a = 1;
	std::cout << "Який елемент хочете видалити: ";
	std::cin >> d;

	while (a)
	{
		a = 0;
		if (d > 0 && d < A.Get_kol_Index())
		{
			A.del_el(d);
		}
		else
		{
			std::cout << "\nНажаль неможливо видалити неiснуючий елемент\n";
			std::cout << "Введiть iнше значення ";
			std::cin >> d;
			a = 1;
		}
	}


}

//
//void kolektsiya_SR::delete_list(List_SR& A)//
//{
//	while (A.Get_kol_Index() > 0)
//		A.del();
//}
