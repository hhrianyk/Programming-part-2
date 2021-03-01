////проверка стрінгстрвім на пустоту Print_two_words_in_line
#include "prototaype.h"
#include "SR.h"
#define ARRAY_SIZE 255

int RGZ::vstup_info(number nov)
{
	RGZ h=RGZ();
	List_SR List;
	
	system("cls");
	number  a = 1, u = 0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Доброго дня користувач\n ";

	std::cout << "\nЗараз: ";
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	std::cout << __DATE__;
	std::cout << "\nЧас початку роботи програми: ", SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << __TIME__ << SetConsoleTextAttribute(hConsole, (WORD)(11));
	cout << "\n\nВи знаходитесь у базовому класі";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n Почнемо роботу\n\n Ввести данi\n ";
	while (a != 0)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
		cin >> a;
		
		switch (a)
		{
		case 1:SetConsoleTextAttribute(hConsole, (WORD)(10));
			std::cout << "Скiльки елементiв ви хочете додати? :";
			std::cin >> a;
			for (int i = 0; i < a; i++)
				h.add_el(List);
			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
				h.Riad_FL(List), a = 0;
			break;
		}
	}
	//List.show();
	a = h.main_menu(a);
	while (a)
	{
		switch (a)
		{
				case 1:
					h.printTableHead();
					h.Print_run(List);
					break;
				case 2:	h.dop_INFO(List);
					break;
				case 3:h.delet_el(List);
					break;
				case 4:	h.Print_el(List);
					break;
				case 5: {List.delete_list(List);
					std::cout << "Успішно";
					
					break; }
				case 6:h.curriculum(List);
					break;
				case 7:nov = 0;
					List.delete_list(List);
					RGZ();
					return 0;
				case 8:
					List.delete_list(List);
					{system("cls");
					nov = 1;
					return 1;
					}
				case 9:
					h.printTableHead();
					h.Print_two_words_in_line(List);
					break;
				case 10:
					h.save_for_Fl(List);
					break;
				case 11: h.print_saved_for_Fl();
					break;
				case 12: h.sortSTR(List);
					break;
				/*case 13: h->AG.kəvər();
					break;*/
				}
			string pit = "Бажаєте ще щось зробити?";
			a = yes_and_no(a, pit);
			if (a == 1)
				a = h.main_menu(a);
			else a = 0;

		}
		return 0;
}

void RGZ::dop_INFO(List_SR& A)
{
	RGZ h;
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

void RGZ::Riad_FL(List_SR& A)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    RGZ add;
	
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
		add.Set_predmet(text);
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
	
		add.Set_teme(text);
		fOpen >> value;
		add.Set_bal(value);
		fOpen >> value;
		add.Set_termi(value);
		fOpen >> value;
		add.Set_zavdanj(value);
		fOpen >> value;
		add.cathedr.Set_cathedra(value);
		A.add(&add);
		
	}
	
	fOpen.close();
	
}

void RGZ::Print_run(List_SR& A)
{	std::stringstream f;
int kol = A.Get_kol_Index();
	for(int i=0;i<kol;i++)
	{
		RGZ* pr = (RGZ*)A.Get_Elem(i);

		f << "|RGZ-" << i+1 << "    |" << std::setw(14) << pr->Get_predmet() << "|" 
			<< std::setw(14) << pr->Get_teme() << "|" << std::setw(18) << pr->Get_bal()
			<< "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj() 
			<< "|" << "\n------------------------------------------------------------------------------------\n" << std::endl;

	}
	std::cout << f.str();

}

void RGZ::Print_el(List_SR& A)
{
	RGZ* pr=NULL;
	number d, a = 1;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;

	if (A.Get_kol_Index() < 1)return;
	while (a)
	{
		a = 0;
		if (d > 0 && d<A.Get_kol_Index())
		{
			 pr = (RGZ*)A.Get_Elem(d-1);
		}
		else {error(a, d);}
	}
	pr->printTableHead();
	cout << "|RGZ-" << d  << "    |" << std::setw(14) << pr->Get_predmet() << "|" << std::setw(14) << pr->Get_teme() << "|" << std::setw(18) << pr->Get_bal() << "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj() << "|" << "\n------------------------------------------------------------------------------------\n" << std::endl;

	
}

void RGZ::delet_el(List_SR& A)
{
	RGZ* pr = NULL;
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	number d ,a = 1;
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



void RGZ::save_for_Fl(List_SR& A)//зберегти все у файл
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	RGZ* p=NULL;

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
	for (int i = 0; i < A.Get_kol_Index(); i++) {
		p = (RGZ*)A.Get_Elem(i);
		fOpen << p->Get_predmet() << " " << p->Get_teme() << " " << p->Get_bal() << " " << p->Get_zavdanj()
			<< " " << p->Get_termin() << " " << p->cathedr.Get_cathedra() << std::endl;
	}
		
	
	fOpen.close();
	std::cout << "\nЗбереження успішно завершено" << std::endl;


}

void RGZ::print_saved_for_Fl()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
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

void RGZ::add_el(List_SR& A)
{
	
	RGZ add ;
	
	/*List_SR A;*/

	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}?$"));//перевірка на правильний ввод

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
		if (value2[0] >= 'a' && value2[0] <= 'z' || value2[0] >= 'а' && value2[0] <= 'я' || value2[0] == 'ё')
			value2[0] -= 32;
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

	add.Set_predmet(value1);
	add.Set_teme(value2);
	add.Set_bal(value3);
	add.Set_termi(value4);
	add.Set_zavdanj(value5);
	add.cathedr.Set_cathedra(value6);

	A.add(&add);
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cout << "\nВашi данi успiшно записанi\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	
}

void RGZ::curriculum(List_SR& A)
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	RGZ* pr;
	int cu = 0, i = 0;
	std::cout << "\n\nВведіть спецiальнiсть/кафедру(номер) :";

	std::cin >> cu;
	for (int j = 0; j < A.Get_kol_Index(); j++)
	{
		pr = (RGZ*)A.Get_Elem(j);

		if (cu == pr->cathedr.Get_cathedra())
			i++;

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
			for (int j = 0; j < A.Get_kol_Index(); j++)
			{
				pr = (RGZ*)A.Get_Elem(j);

				if (cu == pr->cathedr.Get_cathedra())
					if ((i++) % 4 != 0)
						std::cout << " | " << pr->Get_predmet();
					else std::cout << "\n | " << pr->Get_predmet();

			}
		}else return;
     }
	
	else
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(11));
		std::cout << "\n\nВiтаю у цьому роцi ваи непотрiбно робити РГЗ з жодних предметiв!!!\n\n ";
		SetConsoleTextAttribute(hConsole, (WORD)(10));
	}

}

void RGZ::Print_two_words_in_line(List_SR& A)
{
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	std::regex regex_integer("^[А-Яа-яA-za-z0-9]{1,10}[\\.,]?[-_\ ][А-Яа-яA-za-z]{1,10}$");

	std::stringstream f;

	for (int i = 0; i < A.Get_kol_Index(); i++)
	{
		RGZ* pr = (RGZ*)A.Get_Elem(i);
		if (regex_match(pr->Get_predmet(), regex_integer) == 1)
		{
			

			f << "|RGZ-" << i + 1 << "    |" << std::setw(14) << pr->Get_predmet() << "|" 
				<< std::setw(14) << pr->Get_teme() << "|" << std::setw(18) << pr->Get_bal()
				<< "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj()
				<< "|" << "\n------------------------------------------------------------------------------------\n" << std::endl;

		}
		else if ((regex_match((pr->Get_teme()), regex_integer)) == 1)
		{
			

			f << "|RGZ-" << i + 1 << "    |" << std::setw(14) << pr->Get_predmet() << "|"
				<< std::setw(14) << pr->Get_teme() << "|" << std::setw(18) << pr->Get_bal()
				<< "|" << std::setw(11) << pr->Get_termin() << "|" << std::setw(11) << pr->Get_zavdanj()
				<< "|" << "\n------------------------------------------------------------------------------------\n" << std::endl;

		}
		
	}
	//if(f==nullptr)
	std::cout << f.str();
}

void RGZ::sortSTR(List_SR& A)//сортувати елементи
{
	number b = 0;
	if (A.Get_kol_Index() < 1)
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	b = kriter(b);
	bool a = true;
	cout << "Як сортувати\n 1: Вiд меншого до бiльшого \n 2: Вiд бiльшого до меншого \n\n Вибiр: ";
	int k = 0, m;
	cin >> m;
	if (m == 1) k = 1;
	else k = -1;
	RGZ* p1 = (RGZ*)A.Get_Elem(0);
	RGZ* p2 = (RGZ*)A.Get_Elem(0);
	
	while (a)
	{
		
		a = false;
		switch (b)

		{
		case 1:
			for (int i = 0; i < A.Get_kol_Index()-1; i++)
			{
                    p1 = (RGZ*)A.Get_Elem(i);
					p2 = (RGZ*)A.Get_Elem(i + 1);
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
				p1 = (RGZ*)A.Get_Elem(i);
				p2 = (RGZ*)A.Get_Elem(i + 1);
				if (m == 1)
				{
					if (p1->Get_teme()  > p2->Get_teme())
					{
						A.sort(i);
						a = true;
					}
				}
				else
				{
					if (p1->Get_teme() < p2->Get_teme())
					{
						A.sort(i);
						a = true;
					}

				}

			}break;
		case 3:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (RGZ*)A.Get_Elem(i);
				p2 = (RGZ*)A.Get_Elem(i + 1);
				if (p1->Get_termin()*k > p2->Get_termin()*k)
				{
					A.sort(i);
					a = true;
				}
			
			}break;
		case 4:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (RGZ*)A.Get_Elem(i);
				p2 = (RGZ*)A.Get_Elem(i + 1);
				if (p1->Get_zavdanj()*k> p2->Get_zavdanj()*k)
				{
					A.sort(i);
					a = true;
				}
			}break;
		case 5:
			for (int i = 0; i < A.Get_kol_Index() - 1; i++)
			{
				p1 = (RGZ*)A.Get_Elem(i);
				p2 = (RGZ*)A.Get_Elem(i + 1);
				if (p1->Get_bal()*k > p2->Get_bal()*k)
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
		RGZ pr = RGZ();
		pr.printTableHead(), pr.Print_run(A);
	}
		
}