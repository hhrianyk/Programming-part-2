////проверка стрінгстрвім на пустоту Print_two_words_in_line
#include "prototaype.h"
#include "SR.h"



#define ARRAY_SIZE 255
/////перегрузки операторів

RGZ& RGZ::operator = (const RGZ& SR)
{
//	cout << "Перегрузка оператора '='" << endl;
	if (this == &SR)
		return *this;

	predmet = SR.predmet;
	tema = SR.tema;
	termin = SR.termin;
	bal = SR.bal;
	zavdanj = SR.zavdanj;


	return *this;
}
RGZ& RGZ::operator = (const RGZ* SR)
{
	//cout << "Перегрузка оператора '='" << endl;
	if (this == SR)
		return *this;
	if (typeid(*this).name() != typeid(*SR).name()) throw std::invalid_argument("помилка зберігання");;
	predmet = SR->predmet;
	tema = SR->tema;
	termin = SR->termin;
	bal = SR->bal;
	zavdanj = SR->zavdanj;

	return  *this;
}

/*
bool operator < (RGZ& p, RGZ& p2) {
	int i=0;
	if (p.Get_bal()     < p2.Get_bal())i++;
	if (p.Get_predmet() < p2.Get_predmet())i++;
	if (p.Get_teme()    < p2.Get_teme())i++;
	if (p.Get_zavdanj() < p2.Get_zavdanj())i++;
	if (p.Get_termin()  < p2.Get_termin())i++;
	if (i < 3)return 0;
	else return 1;

}

bool operator > (RGZ& p, RGZ& p2)
{
	int i=0;
	if (p.Get_bal()    > p2.Get_bal())i++;
	if (p.Get_predmet()>p2.Get_predmet())i++;
	if (p.Get_teme()   > p2.Get_teme())i++;
	if (p.Get_zavdanj()> p2.Get_zavdanj())i++;
	if (p.Get_termin() > p2.Get_termin())i++;
	if (i < 3)return 0;
	else return 1;
}
*/

bool operator== (RGZ& p, RGZ& p2) { return !(p < p2) && !(p > p2); }
bool operator!= (RGZ& p, RGZ& p2) { return !(p == p2) ; }

bool operator <= (RGZ& p, RGZ& p2) { return (p == p2) || !(p2 < p); }
bool operator >= (RGZ& p, RGZ& p2) { return (p == p2) || !(p2 > p); }



//вивод на екран
ostream& operator<< (ostream& out, const RGZ& pr)
{
	out << "    |" << std::setw(14) << pr.Get_predmet() << "|" << std::setw(14) << pr.Get_teme()
		<< "|" << std::setw(18) << pr.Get_bal() << "|" << std::setw(11) << pr.Get_termin() << "|" << std::setw(11)
		<< pr.Get_zavdanj() << "|"
		<< "\n------------------------------------------------------------------------------------\n";
	return out;
}

//читання з файлу
ifstream& operator >> (ifstream& stream, RGZ& add)
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
		stream >> text;
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

 
		stream >> add.bal;
		stream >> add.termin;
		stream >> add.zavdanj;


		return stream;
	
}

/////////////////////////////
template <typename T> bool bal_termin(T a)
{
	return a.Get_termin() < a.Get_bal();

}



////////////////////////////

template<typename T> void RGZ::dop_INFO(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)
{
	T h;
	number a;
	std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
	std::cin >> a;
	switch (a)
	{
	case 1:
		h.add_el( N,  A, B,  C,  D,E);
		break;
	case 2:
		h.Riad_FL( N, A, B, C, D,E), a = 0;
		break;
	}
}

template<typename T> void RGZ::Riad_FL(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)
{
	
	    T add;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::ifstream fOpen;
		int temp = 0;
		std::string text, adresa;
		if (typeid(A).name() == typeid(vector<RGZ>).name())
		{
			std::cout << "\nЯкий файл відкрити?\n\n 1. RGZ.txt\n 2. add_RGZ.txt\n Ваш вiбiр:";
			std::cin >> temp;
			switch (temp)
			{
			case 1:adresa = "RGZ.txt";
				break;
			case 2:adresa = "add_RGZ.txt";
				break;
			}
		}
		else adresa = "follower.txt";
		fOpen.open(adresa, std::ios_base::in);
		if (!fOpen)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(5));
			std::cout << "File is not open\n\n";
			SetConsoleTextAttribute(hConsole, (WORD)(10));
			return;

		}SetConsoleTextAttribute(hConsole, (WORD)(10));
		//RGZ* add2 = RGZ;
		while (!fOpen.eof()) {
			fOpen >> add;
			if (N == 1)	A.push_back(add);
			else if (N == 2) B.insert(add);
			else if (N == 3) C.push_back(add);
			else if (N == 4) D.insert(pair<int, T>(D.size() + 1, add));
		 	else if (N == 5) E.push_back(new T(add));
		}
		
	
	
	fOpen.close();
	
}


template<typename T>  void RGZ::Print_run(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)//?????
{
	int i = 0;
	if (N == 1) for_each(A.begin(), A.end(), [&](T a) {cout << "|RGZ-"<<++i; a.show(); });
	else if (N == 2)for_each(B.begin(), B.end(), [&](T a) {cout << "|RGZ-"; a.show(); });
	else if (N == 3)for_each(C.begin(), C.end(), [&](T a) {cout << "|RGZ-"<<++i; a.show(); });
	else if (N == 4)for_each(D.begin(), D.end(), [](pair<int, T> keys) {cout << "|RGZ-"<< keys.first; keys.second.show(); });
	else if (N == 5)for_each(E.begin(), E.end(), [&](RGZ* a) {cout << "|RGZ-"<<++i; a->show(); });
	
}


 template<typename T> void RGZ::Print_container(T A)
 {
	 int i = 0;
	 for (auto x : A)
		 try {
		 cout << "|RGZ-" << ++i;
		 x.show();

	      }   
	 catch (std::invalid_argument e) { ; }
 }

 template<typename T>  void RGZ::Print_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)////шаблон
{
	 if (N == 1)if (A.empty())
	 {
		 cout << "!!!!Пустий масив!!!" << endl;
		 system("pause&cls");
		 return;
	 }
	 else if (N == 2)if (B.empty())
	 {
		 cout << "!!!!Пустий масив!!!" << endl;
		 system("pause&cls");
		 return;
	 }
	 else if (N == 3)if (C.empty())
	 {
		 cout << "!!!!Пустий масив!!!" << endl;
		 system("pause&cls");
		 return;
	 }
	 else if (N == 4)if (D.empty())
	 {
		 cout << "!!!!Пустий масив!!!" << endl;
		 system("pause&cls");
		 return;
	 }
	 else if (N == 5)if (E.empty())
	 {
		 cout << "!!!!Пустий масив!!!" << endl;
		 system("pause&cls");
		 return;
	 }


	number d, a = 1;
	std::cout << "Який елемент хочете вiдобразити: ";
	std::cin >> d;

	if (N == 1)
	while (a)
	try {
		a = 0;
		if (d > 0 && d <= (A.size()))
		{			
			T x=A.at(--d);
			x.printTableHead();
			x.show();
			cout << endl;


		}
		else { error(a, d); }
	    }catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;
	}

	else if (N == 2)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= (B.size()))
			{
				auto iter = B.cbegin();
				for (int i = 1; i < d; i++) iter++;
				T x = x;
				x.printTableHead();
				cout << "|RGZ  " << *iter;
				cout << endl;

			}
			else { error(a, d); }
		}catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;
	}

	else if (N == 3)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= (C.size()))
			{

				auto iter = C.cbegin();
				for (int i = 1; i < d; i++) iter++;
				T x = x;
				x.printTableHead();
				cout << "|RGZ  " << *iter;
			}

			else { error(a, d); }
		}catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;
	}


	else if (N == 4)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= (D.size()))
			{

				T x = D.at(d);
				x.printTableHead();
				x.show();
				cout << endl;


			}
			else { error(a, d); }
		}catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;
	}

	else if (N == 5)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= E.size())
			{

				RGZ* x = E.at(--d);
				cout <<endl<<endl<<"------------------------------------------------------------------------------------"<<endl<<" "<< d++;
				x->show();
				cout << endl;

			}
			else { error(a, d); }
		}catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;}


}

template<typename T>   void RGZ::delet_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)///шаблон
{
	if (N==1)if (A.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	else if (N == 2)if (B.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	else if (N == 3)if (C.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	else if (N == 4)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}
	else if (N == 5)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}

	number d, a = 1;
	std::cout << "Який елемент хочете видалити: ";
	std::cin >> d;
	if(N==1)
	while (a)
		try {
		a = 0;
		if (d > 0 && d <= A.size())
		{	 A.erase(A.begin()+d-1);}
		else { error(a, d); }
	}
	catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
	}

	else if(N==2)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= B.size())
			{
			auto iter = B.cbegin();
			for (int i = 1; i < d; i++) iter++;
				B.erase(iter);
			}
			else { error(a, d); }
		}
	catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
	}
	else if (N == 3)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= C.size())
			{
				auto iter = C.cbegin();
				for (int i = 1; i < d; i++) iter++;

			 	C.erase(iter);
			}
			else { error(a, d); }
		}
	catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
	}

	else if (N == 4)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= D.size())
			{
				D.erase(d);
			}
			else { error(a, d); }
		}
	catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
	}
	if (N == 5)
		while (a)
			try {
			a = 0;
			if (d > 0 && d <= E.size())
			{
				E.erase(E.begin() + d - 1);
			}
			else { error(a, d); }
		}
	catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
	}
	
}

 void RGZ::el(RGZ& add)
{
	std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}?$"));//перевірка на правильний ввод

	int  value3, value4, value5;
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
		/*if ((std::cin.rdbuf()->in_avail()) != 1);*/
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
		/*if ((std::cin.rdbuf()->in_avail()) != 1);*/
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
		/*if ((std::cin.rdbuf()->in_avail()) != 1);*/
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
	SetConsoleTextAttribute(hConsole, (WORD)(5));

	add.Set_predmet(value1);
	add.Set_teme(value2);
	add.Set_bal(value3);
	add.Set_termin(value4);
	add.Set_zavdanj(value5);


}

template<typename T>  void RGZ::add_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)
{

	T add;
	el(add);
	if (N == 1)	A.push_back(add);
	else if (N == 2) B.insert(add);
	else if (N == 3) C.push_back(add);
	else if (N == 4) D.insert(pair<int, T>(D.size() + 1, add));
	else if (N == 5) E.push_back(new T(add));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "\nВашi данi успiшно записанi\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));

}

template<typename T>  void RGZ::number_items(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)
{
	T h;
	     if (N == 1)if (A.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
	    int a = 0;
		a=h.Count_menu(a);
		h.count_hopper(a, A,h);
	}
	else if (N == 2)if (B.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a= h.Count_menu(a);
		h.count_hopper(a, B,h);
	}
	else if (N == 3)if (C.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Count_menu(a);
		h.count_hopper(a, C,h);
	}
	else if (N == 4)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Count_menu(a);
		h.count_hopper_map(a, D,h);
	}
    else if (N == 5)if (E.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Count_menu(a);
		h.count_hopper_star(a, E,h);
	}
	
	
}

template<typename T, typename T2> void RGZ::count_hopper(int N, T A,T2 h)
{
	int a ;
	
	if (N == 1) cout << "  Кількість: " <<A.size()<<endl<<endl;
	else if (N == 2)
	{
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), bal_termin<T2>)<< endl << endl;
	}
	else if (N == 3) {
		 
		cout << "Введіть граничне число: ";
		cin >> a;
	 	cout << "  Кількість: "<<std::count_if(A.begin(), A.end(), [&](T2 p) -> bool { return p.Get_termin() < a; }) << endl << endl;
		
	}
	else if (N == 4)
	{
	cout << "Введіть граничне число: ";
	cin >> a;
	cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](T2 pr) -> bool { return pr.Get_termin() > a; }) << endl << endl;

      }
}
template<typename T, typename T2> void RGZ::count_hopper_map(int N, T A, T2 h)
{
	int a;

	if (N == 1) cout << "  Кількість: " << A.size() << endl << endl;
	else if (N == 2)
	{
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](std::pair<int, T2>  p) { return p.second.Get_termin() < p.second.Get_bal(); }) << endl << endl;
	}
	else if (N == 3) {
		int n = 0;
		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](std::pair<int, T2>  p) { return p.second.Get_termin() < a; });

	}
	else if (N == 4)
	{
		cout << "Зачинено на ремонт ";
		return;
		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](std::pair<int, T2>  p) { return p.second.Get_termin() > a; }) << endl << endl;

	}
	
}

template<typename T, typename T2> void RGZ::count_hopper_star(int N, T A, T2 h)
{
	int a;

	if (N == 1) cout << "  Кількість: " << A.size() << endl << endl;
	else if (N == 2)
	{
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](RGZ* p) {return p->Get_termin() < p->Get_bal(); }) << endl << endl;
	}
	else if (N == 3) {

		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](RGZ* p) { return p->Get_termin() < a; }) << endl << endl;

	}
	else if (N == 4)
	{
		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](RGZ* pr)  { return pr->Get_termin() > a; }) << endl << endl;

	}
}

template<typename T>  void RGZ::Poshuk(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E)
{
	T h;
	if (N == 1)if (A.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}	else {
		int a = 0;
			a = h.Poshuk_menu(a);
		   h.Poshuk_hopper(a,A,h);
	}
	else if (N == 2)if (B.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
			a = h.Poshuk_menu(a);
		    h.Poshuk_hopper(a, B,h);
	}
	else if (N == 3)if (C.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Poshuk_menu(a);
		h.Poshuk_hopper(a, C,h);
	}
	else if (N == 4)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
			a = h.Poshuk_menu(a);
		h.Poshuk_hopper_map(a, D,h);
	}
    else if (N == 5)if (E.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a=0; 
		a = h.Poshuk_menu(a);
		h.Poshuk_hopper_star(a, E,h);
	}
	
}

template<typename T, typename T2> void RGZ::Poshuk_hopper(int N, T A,T2 h)
{
	int a=0;

	if (N == 1) h.printTableHead(), cout << "|RGZ  " << *min_element(A.begin(), A.end());
	else if (N == 2)
	{
		h.printTableHead();
		cout << "|RGZ  "<< *max_element(A.begin(), A.end());
		
	}
	else if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;

		auto tr=std::find_if(A.begin(),A.end(), [&](const T2 a)-> bool { return a.Get_bal() ==n; });
		if(tr!=A.end())
		{
			h.printTableHead();
			cout << "|RGZ  ";
			cout << *tr;
		}
		else cout << "Незнайдено!!"<<endl;
	}
	else if (N == 4)
	{
		int n;
		cout << "Введіть термін який шукаєте: ";
		cin >> n;
		auto tr = std::find_if(A.begin(), A.end(), [&](const T2 a)-> bool { return a.Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout<<"|RGZ  " << *tr;
		}
		else cout << "Незнайдено!!" << endl;
	}
	
}
template<typename T, typename T2> void RGZ::Poshuk_hopper_star(int N, T A, T2 h)
{
	int a = 0;

	if (N == 1) h.printTableHead(), cout << "|RGZ  " << *min_element(A.begin(), A.end());
	else if (N == 2)
	{
		h.printTableHead();
		cout << "|RGZ  " << *max_element(A.begin(), A.end());

	}
	else if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;

		auto tr = std::find_if(A.begin(), A.end(), [&](const RGZ* a)-> bool { return a->Get_bal() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  ";
			cout << *tr;
		}
		else cout << "Незнайдено!!" << endl;
	}
	else if (N == 4)
	{
		int n;
		cout << "Введіть термін який шукаєте: ";
		cin >> n;
		auto tr = std::find_if(A.begin(), A.end(), [&](const RGZ* a)-> bool { return a->Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  " << *tr;
		}
		else cout << "Незнайдено!!" << endl;
	}

}
template<typename T, typename T2> void RGZ::Poshuk_hopper_map(int N, T A, T2 h)
{
	int a = 0;

	if (N == 1) h.printTableHead(), cout << "|RGZ  " << (min_element(A.begin(), A.end()))->second;
	else if (N == 2)
	{
		h.printTableHead();
		 cout << "|RGZ  "<<(max_element(A.begin(), A.end()))->second;
		
	}
	else if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;
		
		auto tr = find_if(A.begin(), A.end(), [&](std::pair<int, T2>  p){ return p.second.Get_bal()== n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  ";
			cout << tr->second;
		}
		else cout << "Незнайдено!!" << endl;
	}
	else if (N == 4)
	{

		int n;
		cout << "Введіть термін який шукаєте: ";
		cin >> n;
		auto tr = std::find_if(A.begin(), A.end(), [&](std::pair<int, T2>  p) { return p.second.Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  " << tr->second;
		}
		else cout << "Незнайдено!!" << endl;
		
	}
}



 int RGZ::vstup_info(number nov, int N, vector<RGZ>& A, set<RGZ>& B, list<RGZ>& C, map<int, RGZ>& D, vector<RGZ*>& E)
{
	RGZ h;


	system("cls");
	number  a = 1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	cout << "\n\nВи знаходитесь у класі RGZ";
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
				h.add_el(N, A, B, C, D,E);
			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			h.Riad_FL(N, A, B, C, D,E), a = 0;
			break;
		}
	}
	a = h.main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			h.printTableHead();
			h.Print_run(N, A, B, C, D,E);
			break;
		case 2:	h.dop_INFO(N, A, B, C, D,E);
			break;
		 case 3:h.delet_el(N, A, B, C, D,E);
			break; 
		case 4:	h.Print_el(N, A, B, C, D,E);
			break;
		case 5: if (N == 1)	A.clear();
			  else if (N == 2) B.clear();
			  else if (N == 3) C.clear();
			  else if (N == 4) D.clear();
			  else if (N == 5) E.clear();	
			system("cls");
			std::cout << "Успішно";
			break;
		case 6:h.number_items(N, A, B, C, D, E);
			break;
		case 7:h.Poshuk(N, A, B, C, D, E);
			break;
		case 11: system("cls");
			system("cls");
			nov = 3;
			return 3;
			break;
			
		case 12://List.delete_list(List);
			system("cls");
			nov = 4;
			return 4;
			break;

		}
		string pit = "Бажаєте ще щось зробити?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = h.main_menu(a);
		else a = 12;

	}
	return 0;
}





 int Scientific_SR::vstup_info(number nov, int N, vector<Scientific_SR>& A, set<Scientific_SR>& B, list<Scientific_SR>& C, map<int, Scientific_SR>& D, vector<RGZ*>& E)
 {

	 Scientific_SR h;



	 system("cls");
	 number  a = 1;

	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	 cout << "\n\nВи знаходитесь у класі RGZ";
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
				 h.add_el(N, A, B, C, D,E);
			 a = 0;
			 break;
		 case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			 h.Riad_FL(N, A, B, C, D,E), a = 0;
			 break;
		 }
	 }

	 a = h.main_menu(a);
	 while (a)
	 {
		 switch (a)
		 {
		 case 1:
			 h.printTableHead();
			 h.Print_run(N, A, B, C, D,E);
			 break;
		 case 2:	h.dop_INFO(N, A, B, C, D,E);
			 break;
		 case 3:h.delet_el(N, A, B, C, D,E);
			 break;
		 case 4:h.Print_el(N, A, B, C, D,E);
			 break;
		 case 5: if (N == 1)	A.clear();
			   else if (N == 2) B.clear();
			   else if (N == 3) C.clear();
			   else if (N == 4) D.clear();
			   else if (N == 5) E.clear();
			 system("cls");
			 std::cout << "Успішно";
			 break;
		 case 6:h.number_items(N, A, B, C, D, E);
			 break;
		 case 7:h.Poshuk(N, A, B, C, D, E);
			 break;
		 case 11:
			 system("cls");
			 nov = 3;
			 return 3;
			 break;
	
		 case 12://List.delete_list(List);
			 system("cls");
			 nov = 4;
			 return 4;
			 break;

		 }
		 string pit = "Бажаєте ще щось зробити?";
		 a = yes_and_no(a, pit);
		 if (a == 1)
			 a = h.main_menu(a);
		 else a = 12;

	 }
	 return 0;
 }
 
 void Scientific_SR::el(Scientific_SR&add)
 {

	 std::regex regex_integer(("^[А-ЯA-Z][А-Яа-яa-zA-Z0-9 -_\\.,]*$"));//проверка на великий символ
	 std::regex regex_integer2(("^[A-za-zА-Яа-я][A-za-zА-Яа-я0-9]{1,20}[\\.,]?[-_ ]?[А-Яа-яA-za-z]{1,20}$"));//перевірка на правильний ввод

	 int  value4, value5;
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
	 add.Set_termin(value4);

 }