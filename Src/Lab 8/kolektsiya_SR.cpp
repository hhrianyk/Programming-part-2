#include "prototaype.h"
#include "SR.h"




kolektsiya_SR& kolektsiya_SR::operator = (const kolektsiya_SR& SR)
{
	//cout << "Перегрузка оператора '='" << endl;
	if (this == &SR)
		return *this;
	predmet      = SR.predmet;
	collection   = SR.collection;
	author       = SR.author;
	Vydavnytstvo = SR.Vydavnytstvo;
	data         = SR.data;


	return *this;
}
kolektsiya_SR& kolektsiya_SR::operator = (const kolektsiya_SR* SR)
{
	//cout << "Перегрузка оператора '='" << endl;
	if (this == SR)
		return *this;
	if (typeid(*this).name() != typeid(*SR).name()) throw std::invalid_argument("помилка зберігання");;
	
	predmet      = SR->predmet;
	collection   = SR->collection;
	author       = SR->author;
	Vydavnytstvo = SR->Vydavnytstvo;
	data         = SR->data;

	return  *this;
}
bool operator < (kolektsiya_SR& p, kolektsiya_SR& p2) {
	int i = 0;
	if (p.Get_collection()   < p2.Get_collection())i++;
	if (p.Get_predmet()      < p2.Get_predmet())i++;
	if (p.Get_author()       < p2.Get_author())i++;
	if (p.Get_Vydavnytstvo() < p2.Get_Vydavnytstvo())i++;
	if (p.Get_data()         < p2.Get_data())i++;
	if (i < 3)return 0;
	else return 1;

}
bool operator > (kolektsiya_SR& p, kolektsiya_SR& p2)
{
	int i = 0;
	if (p.Get_collection()     > p2.Get_collection())i++;
	if (p.Get_predmet()        > p2.Get_predmet())i++;
	if (p.Get_author()         > p2.Get_author())i++;
	if (p.Get_Vydavnytstvo()   > p2.Get_Vydavnytstvo())i++;
	if (p.Get_data()           > p2.Get_data())i++;
	if (i < 3)return 0;
	else return 1;
}

bool operator== (kolektsiya_SR& p, kolektsiya_SR& p2) { return !(p < p2) && !(p > p2); }
bool operator!= (kolektsiya_SR& p, kolektsiya_SR& p2) { return !(p == p2); }

bool operator <= (kolektsiya_SR& p, kolektsiya_SR& p2) { return (p == p2) || !(p2 < p); }
bool operator >= (kolektsiya_SR& p, kolektsiya_SR& p2) { return (p == p2) || !(p2 > p); }



//вивод на екран
ostream& operator<< (ostream& out, kolektsiya_SR& pr)
{
	out << "    |" << std::setw(14) << pr.Get_predmet() << "|" << std::setw(14) << pr.Get_collection() << "|" << std::setw(18) << pr.Get_author()
		<< "|" << std::setw(11) << pr.Get_Vydavnytstvo() << "|" << std::setw(11) << pr.Get_data() << "|"
		<< "\n------------------------------------------------------------------------------------\n" ;
	return out;
}

ostream& operator<< (ostream& out, kolektsiya_SR*& pr)
{
	out << "    |" << std::setw(14) << pr->Get_predmet() << "|" << std::setw(14) << pr->Get_collection() << "|" << std::setw(18) << pr->Get_author()
		<< "|" << std::setw(11) << pr->Get_Vydavnytstvo() << "|" << std::setw(11) << pr->Get_data() << "|"
		<< "\n------------------------------------------------------------------------------------\n";
	return out;
}
//читання з файлу
ifstream& operator >> (ifstream& stream, kolektsiya_SR& add)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}?$"));//перевірка на правильний ввод

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream fOpen;
	
	std::string text;



	stream >> text;
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
	stream >> text;
	add.Set_collection(text);////туту
	stream >> text;
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
	stream >> text;

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

	
	stream>>add.data;


	return stream;

}

/////////////////////////////


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
	int  temp = 0;
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
	
		fOpen >> add;
		

		A.add(&add);
	}

	fOpen.close();

}

void kolektsiya_SR::Print_el(List_SR& A)
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	kolektsiya_SR pr;
	number d, a = 1;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;
	while (a)
	{
		a = 0;
		if (d > 0 && d < A.Get_kol_Index())
		{
			try {
				pr = (kolektsiya_SR*)A[d-1];
			}
			catch (std::invalid_argument e) {
				cout << "помилка виводу елементу";
				error(a, d);
			}
		}
		else { error(a, d); }
	}
	pr.printTableHead();
	cout << "|RGZ-" << d << pr << std::endl;

}

void kolektsiya_SR::Print_run(List_SR& A)///спадок вивести ////зробити шаблонной    
{
	
	kolektsiya_SR pr;
	int kol = A.Get_kol_Index();
	for (int i = 0; i < kol; i++)
	try{
		 pr= (kolektsiya_SR*)A[i];
		cout << "|RGZ-" << i+1 << pr <<std::endl;

	}
	catch (std::invalid_argument e) {	/*cout << e.what() << endl;*/}


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
	system("cls");
	kolektsiya_SR p ;
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
	try{
		p = (kolektsiya_SR*)A[i];

		if (autor == p.Get_author())
		{
			perevirka++;
			cout << "|RGZ-" <<i+1 << p<< std::endl;
		
		}

	}
	catch (std::invalid_argument e) { ; }
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
	kolektsiya_SR p1, p2;

	while (a)
	{

		a = false;
		switch (b)

		{
		case 1:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i+1];
				if (m == 1)
				{
					if (p1.Get_predmet() > p2.Get_predmet())
					{
						A.swap(i);
						a = true;
					}
				}
				else
				{
					if (p1.Get_predmet() < p2.Get_predmet())
					{
						A.swap(i);
						a = true;
					}
				}

			}
			break;
		case 2:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i + 1];
				if (m == 1)
				{
					if (p1.Get_collection() > p2.Get_collection())
					{
						A.swap(i);
						a = true;
					}
				}
				else
				{
					if (p1.Get_collection() < p2.Get_collection())
					{
						A.swap(i);
						a = true;
					}

				}

			}break;
		case 3:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i + 1];
				if (m == 1)
				{
					if (p1.Get_author() > p2.Get_author())
					{
						A.swap(i);
						a = true;
					}
				}
				else
				{
					if (p1.Get_author() < p2.Get_author())
					{
						A.swap(i);
						a = true;
					}

				}

			}break;
		case 4:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i + 1];
				if (m == 1)
				{
					if (p1.Get_Vydavnytstvo() > p2.Get_Vydavnytstvo())
					{
						A.swap(i);
						a = true;
					}
				}
				else
				{
					if (p1.Get_Vydavnytstvo() < p2.Get_Vydavnytstvo())
					{
						A.swap(i);
						a = true;
					}

				}

			}break;
		case 5:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i + 1];
				if (p1.Get_data() * k > p2.Get_data()* k)
				{
					A.swap(i);
					a = true;
				}

			}break;
		case 6:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (kolektsiya_SR*)A[i];
				p2 = (kolektsiya_SR*)A[i + 1];

				if (m == 1)
				{

					p1 > p2;
					p1 >= p2;
					p1 <= p2;
					p1 == p2;
					p1 != p2;

					A.swap(i);
					a = true;

				}
				else
				{
					if (p1 < p2)
					{
						A.swap(i);
						a = true;
					}

				}
			}
			break;

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
	number d, a = 1;
	std::cout << "Який елемент хочете видалити: ";
	std::cin >> d;
	kolektsiya_SR pr;
	while (a)
    try {	
		a = 0;
		if (d > 0 && d <= A.Get_kol_Index())
		{			
				pr = (kolektsiya_SR*)A[d-1];
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
	catch (std::invalid_argument e) {std::cout << "\nНажаль неможливо видалити неiснуючий елемент\n";}

}

//
//void kolektsiya_SR::delete_list(List_SR& A)//
//{
//	while (A.Get_kol_Index() > 0)
//		A.del();
//}
