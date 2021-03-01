////проверка стрінгстрвім на пустоту Print_two_words_in_line
#include "prototaype.h"
#include "SR.h"
#include "my_ptr.h"
#include  "mysharedptr.h"

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
template <typename T> bool bal_termin(T a){return a.Get_termin() < a.Get_bal();}

template<typename T>bool Comparison(const T*& lhs, const T*& rhs) { return lhs > rhs;}


template<typename T, typename Pred, typename Func>
std::function<void(const T&)> predif(Pred p, Func f) {
	return [p, f](const T& value) {
		if (p(value))
			f(value);
	};
}



////////////////////////////

 void RGZ::dop_INFO(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B,  vector <  my::UNO<RGZ>>& D)
{
	
	 RGZ h;
	 Scientific_SR p;
	number a,b;
	 cout << "Яким способом хочете ввести данні?";
	std::cout << "\n 1: З клавiатири\n 2: 3 Файлу\n Ваш вiбiр:   ";
	std::cin >> a; 
	cout << "\n\n До якого класу належать ваші данні?\n 1: RGZ\n 2: Scientific_SR\n Ваш вiбiр:   ";
	cin >> b;

	switch (a)
	{
	case 1:
		if (b==1)h.add_el( N,  A, B,    D,h);
		else if (b == 2)h.add_el(N, A, B, D, p);
		break;
	case 2:
		if (b == 1)h.Riad_FL(N, A, B, D, h);
		else if (b == 2)h.Riad_FL(N, A, B, D, p);
		break;
	}

}

template<typename T> void RGZ::Riad_FL(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B,  vector <  my::UNO<RGZ>>& D, T  E)
{
	
	    T add;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::ifstream fOpen;
		int temp = 0;
		std::string text, adresa;
		if (typeid(E).name() == typeid(RGZ).name())
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
		int i = 0;

		while (!fOpen.eof()) {	

			fOpen >> add;

			if (N == 1)	A.push_back(unique_ptr<T>(new T(add)));
			else if (N == 2) B.push_back(make_shared<T>(add));

			else if (N == 3) D.push_back(my::UNO<RGZ>(new T(add)));;
					 	
		}
		
	
	
	fOpen.close();
	
}


template<typename T>  void RGZ::Print_run(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B, vector <  my::UNO<RGZ>>& D, T  E)//?????
{
	int i = 0;
	if (N == 1) for_each(A.begin(), A.end(), [&](unique_ptr <RGZ>& a) {cout << "|RGZ-"<<++i; a.get()->show(); });//////tut
	else if (N == 2)for_each(B.begin(), B.end(), [&](shared_ptr <RGZ> a) {cout << "|RGZ-"<<++i; a.get()->show(); });

	else if (N == 3)for_each(D.begin(), D.end(), [&](my::UNO <RGZ> a) {cout << "|RGZ-" << ++i; a.get()->show(); });

	
}


 template<typename T>  void RGZ::Print_el(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B, vector <  my::UNO<RGZ>>& D, T  E)////шаблон
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
	 else if (N == 3)if (D.empty())
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
			T x;
			x.printTableHead();
			A[--d]->show();
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

				T x ;
				x.printTableHead();
				B[--d]->show();
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
			if (d > 0 && d <= (D.size()))
			{
				D[--d].get()->show();
				cout << endl;
			}
			else { error(a, d); }
		}catch (std::invalid_argument e) {
		cout << "помилка виводу елементу";
		return;
	}

	


}

template<typename T>   void RGZ::delet_el(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B, vector <  my::UNO<RGZ>>& D, T  E)// редагувати/шаблон
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

	else if (N == 3)if (D.empty())
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
				B.erase(B.begin() + d - 1);
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
			if (d > 0 && d <=D.size())
			{
				D.erase(D.begin() + d - 1);
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

template<typename T> void RGZ::add_el(int N, vector<unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B,  vector <  my::UNO<RGZ>>& D, T  E)
{

	T add;
	el(add);
	if (N == 1)	A.push_back(unique_ptr<T>(new T(add)));
	else if (N == 2) B.push_back(make_shared<T>(add));

	else if (N == 3) D.push_back(my::UNO<RGZ>(new T(add)));
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "\nВашi данi успiшно записанi\n";
	SetConsoleTextAttribute(hConsole, (WORD)(10));

}

void RGZ::number_items(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B, vector <  my::UNO<RGZ>>& D)////tut
{
	RGZ h;
	     if (N == 1)if (A.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
	    int a = 0;
		cout << "Зачинено на ремонт" << endl;
		a=h.Count_menu(a);
	
	 	h.count_hopper(a, A);
	}
	else if (N == 2)if (B.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Count_menu(a);

		  h.count_hopper(a, B);
	}

	else if (N == 3)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
		a = h.Count_menu(a);
		h.count_hopper(a, D);
	}
  
	
	
}

 void RGZ::count_hopper(int N, vector< unique_ptr<RGZ>>& A)
{
	int a ;
	
	if (N == 1) cout << "  Кількість: " <<A.size()<<endl<<endl;
	else if (N == 2)
	{
		 cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](unique_ptr<RGZ>&  p) -> bool { return p.get()->Get_termin() < p.get()->Get_bal(); }) << endl << endl;
	}
	else if (N == 3) {
		 
		cout << "Введіть граничне число: ";
		cin >> a;
	 	 cout << "  Кількість: "<<std::count_if(A.begin(), A.end(), [&]( unique_ptr<RGZ>& p) -> bool { return p.get()->Get_termin() < a; }) << endl << endl;
		
	}
	else if (N == 4)
	{
	cout << "Введіть граничне число: ";
	cin >> a;
        cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&]( unique_ptr<RGZ>& pr) -> bool { return pr.get()->Get_termin() > a; }) << endl << endl;

      }
}
  void RGZ::count_hopper(int N, vector< shared_ptr <RGZ>> A)
{
	int a;

	if (N == 1) cout << "  Кількість: " << A.size() << endl << endl;
	else if (N == 2)
	{
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&]( shared_ptr <RGZ>& p) -> bool { return p.get()->Get_termin() < p.get()->Get_bal(); }) << endl << endl;
	}
	else if (N == 3) {

		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](shared_ptr <RGZ>& p) -> bool { return p.get()->Get_termin() < a; }) << endl << endl;

	}
	else if (N == 4)
	{
		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](shared_ptr <RGZ>& pr) -> bool { return pr.get()->Get_termin() > a; }) << endl << endl;

	}
}

void RGZ::count_hopper(int N, vector <  my::UNO<RGZ>> A)
{
	int a;

	if (N == 1) cout << "  Кількість: " << A.size() << endl << endl;
	else if (N == 2)
	{
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](my::UNO<RGZ>& p) -> bool { return p.get()->Get_termin() < p.get()->Get_bal(); }) << endl << endl;
	}
	else if (N == 3) {

		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](my::UNO<RGZ>& p) -> bool { return p.get()->Get_termin() < a; }) << endl << endl;

	}
	else if (N == 4)
	{
		cout << "Введіть граничне число: ";
		cin >> a;
		cout << "  Кількість: " << std::count_if(A.begin(), A.end(), [&](my::UNO<RGZ> pr) -> bool { return pr.get()->Get_termin() > a; }) << endl << endl;

	}
}

 void RGZ::Poshuk(int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B,  vector <  my::UNO<RGZ>>& D)
{
	RGZ h;
	if (N == 1)if (A.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}	else {
		int a = 0;
			a = h.Poshuk_menu(a);
			cout << "Зачинено на ремонт" << endl;
		    h.Poshuk_hopper(a,A );
	}
	else if (N == 2)if (B.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
			a = h.Poshuk_menu(a);
		    h.Poshuk_hopper (a, B );
	}

	else if (N == 3)if (D.empty())
	{
		cout << "!!!!Пустий масив!!!" << endl;
		system("pause&cls");
		return;
	}else {
		int a = 0;
			a = h.Poshuk_menu(a);
		h.Poshuk_hopper(a, D);
	}
 
	
}

 void RGZ::Poshuk_hopper(int N, vector< unique_ptr<RGZ>>& A)
{
	int a=0;
	RGZ h;
	if (N == 1) { h.printTableHead();  auto& a = *min_element(A.begin(), A.end()); a.get()->show(); }
	else if (N == 2) { h.printTableHead(); auto& a = *max_element(A.begin(), A.end()); a.get()->show(); }
	 if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;
       auto  tr = std::find_if(A.begin(),A.end(), [&]( unique_ptr<RGZ>& a) -> bool { return a.get()->Get_bal() == n; });
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
		auto tr = std::find_if(A.begin(), A.end(), [&](unique_ptr<RGZ>& a)-> bool { return a->Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout<<"|RGZ  " << *tr;
		}
		else cout << "Незнайдено!!" << endl;
	}
	
}

void RGZ::Poshuk_hopper(int N, vector< shared_ptr <RGZ>>& A)
{
	RGZ h;
	int a = 0;

	if (N == 1) {h.printTableHead();  auto& a = *min_element(A.begin(), A.end()); a.get()->show();}
	else if (N == 2) { h.printTableHead(); auto& a = *max_element(A.begin(), A.end()); a.get()->show();}
	if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;
		auto  tr = std::find_if(A.begin(), A.end(), [&](shared_ptr <RGZ>& a) -> bool { return a.get()->Get_bal() == n; });
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
		auto tr = std::find_if(A.begin(), A.end(), [&](shared_ptr <RGZ>& a)-> bool { return a->Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  " << *tr;
		}
		else cout << "Незнайдено!!" << endl;
	}

}
void RGZ::Poshuk_hopper(int N, vector< my::UNO <RGZ>> & A)
{
	RGZ h;
	int a = 0;

	if (N == 1) { h.printTableHead(); my::UNO <RGZ>& p = *min_element(A.begin(), A.end(), [&](my::UNO <RGZ>& a, my::UNO <RGZ>& b) -> bool { return a.get() > b.get(); }); p.get()->show(); }
	
	else if (N == 2) {  h.printTableHead(); my::UNO <RGZ>& p = *max_element(A.begin(), A.end(), [&](my::UNO <RGZ>& a, my::UNO <RGZ>& b) -> bool { return a.get() > b.get(); }); p.get()->show(); }
	else if (N == 3) {
		int n;
		cout << "Введіть бал який шукаєте: ";
		cin >> n;
		auto  tr = std::find_if(A.begin(), A.end(), [&](my::UNO <RGZ>& a) -> bool { return a.get()->Get_bal() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  ";
			tr->get()->show();
		}
		else cout << "Незнайдено!!" << endl;
	}
	else if (N == 4)
	{
		int n;
		cout << "Введіть термін який шукаєте: ";
		cin >> n;
		auto tr = std::find_if(A.begin(), A.end(), [&](my::UNO <RGZ>& a)-> bool { return a.get()->Get_termin() == n; });
		if (tr != A.end())
		{
			h.printTableHead();
			cout << "|RGZ  " ;
			tr->get()->show();
		}
		else cout << "Незнайдено!!" << endl;
	}

}




 int RGZ::vstup_info(number nov, int N, vector< unique_ptr<RGZ>>& A, vector< shared_ptr <RGZ>>& B,  vector <  my::UNO<RGZ>>& D)
{
	
	 RGZ h;

	system("cls");
	number  a = 1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (N==1)cout << "\t Ви користуєтесь покажчиком unique_ptr";
	else if (N == 2)cout << "\t Ви користуєтесь покажчиком shared_ptr";
	else if (N == 3)cout << "\t Ви користуєтесь покажчиком my::UNO";



	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << "\n\n Почнемо роботу\n\n  ";

	h.dop_INFO(N, A, B, D);


	a = h.main_menu(a);
	while (a)
	{

		switch (a)
		{
		case 1:
			h.printTableHead();
		  	h.Print_run(N, A, B,  D,h);
			break;
		case 2:	h.dop_INFO(N, A, B,  D);
			break;
		 case 3:h.delet_el(N, A, B, D,h);
			break; 
		case 4:	h.Print_el(N, A, B,  D,h);
			break;
		case 5: if (N == 1)	A.clear();
			  else if (N == 2) B.clear();
			  else if (N ==3) D.clear();
		
			system("cls");
			std::cout << "Успішно";
			break;
		case 6:h.number_items(N, A, B, D);
		 	break;
		case 7:h.Poshuk(N, A, B, D);
			break;
		case 8:h.testing(N, A, B,  D);
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


 void RGZ::testing(int N, vector< unique_ptr<RGZ>>&  A, vector< shared_ptr <RGZ>>&  B, vector <  my::UNO<RGZ>>& D)
 {

	 if (N == 1)
	 {
		 if (A.size() < 5) { cout << "У векторі недостатньо елеметів щоб виконати дію(повинно бути не менше 5 обєктів" << endl; system("pause&cls"); return; }
		  unique_ptr<RGZ>  b;
		  cout << "Адреса показчиків вашого масиву" << endl;
		 for (unique_ptr<RGZ>& uptr : A)

			cout << uptr.get() << endl;
		 // b.push_back(A[1]);
		 cout << "\n\nБуло створено вказівник unique_ptr<RGZ>> b який перейняв  права володіння у 4(-го) об'єкту вашого масиву" << endl;
		 b=std::move(A[3]);
		 cout << "Адреса показчиків вашого масиву" << endl;
		 for (unique_ptr<RGZ>& uptr : A)
			 cout << uptr.get() << endl;
		
		 cout << "Адрес 4(-го) об'єкту " <<A[3].get()<< endl;
		 cout << "\n\nвказівник unique_ptr<RGZ>> b" << endl;
		 cout << b.get();
		 A[3] = std::move(b);
		 //A[4].reset();
		 cout << "\n\nПрава на володіння вашого масиву відновлено" << endl;
		 system("pause&cls"); 
	 
		
	 }
	 else if (N == 2)
	 {
		 if (B.size() < 5) { cout << "У векторі недостатньо елеметів щоб виконати дію(повинно бути не менше 5 обєктів" << endl; system("pause&cls"); return; }
		 
		 cout << "Адреса показчиків вашого масиву" << endl;
		 for (shared_ptr<RGZ>& uptr : B)
			 cout << uptr.get() << endl;
		 
		 cout << "кількість покажчиків на кожен об'єкт масиву" << endl;
		 for (shared_ptr<RGZ>& s_ptr : B)
			 cout << s_ptr.use_count() << endl;
		 cout << "\n\nкількість покажчиків на кожен об'єкт масиву(за допомогою копій)" << endl;
		 for (shared_ptr<RGZ> s_ptr : B)
			 cout << s_ptr.use_count() << endl;

         weak_ptr<RGZ> weak;
	
		 cout << endl;
		 cout << "Weak expired(неіснує об'єкт): " << weak.expired() << endl;
		 weak = B[4];
		 cout << "Weak expired((існує об'єкт)): " << weak.expired() << endl;
		
		 cout << "кількість покажчиків на 4-й :" << B[4].use_count() << endl;
		try {cout << "Створено новий вказівниз shared_ptr за допомогою weak_ptr" << endl;
			 shared_ptr<RGZ> sh_from_weak(weak);
			 cout << "кількість покажчиків на 4-й: " << sh_from_weak.use_count() << endl;
		 }
		catch (std::bad_weak_ptr e) { cout << e.what() << endl; }
		 B[4].reset();
		 B.clear();
		 cout << "Ваш масив було очищено" << endl;
		 cout << "Weak expired: " << weak.expired() << endl;
		 if (weak.expired() == 0) cout << "Існує вказівник на ваш обєкт " << endl;
		 else  cout << "Не існує вказівник на ваш обєкт " << endl;

		 try {
			 shared_ptr<RGZ> sh_from_weak(weak);
			 cout << sh_from_weak.use_count() << endl;
		 }
		 catch (std::bad_weak_ptr e) { cout << e.what() << endl; }
		 cout << endl << endl;
		 system("pause&cls");
	 }
	 else if (N == 3)
	 {
		 if (D.size() < 5) { cout << "У векторі недостатньо елеметів щоб виконати дію(повинно бути не менше 5 обєктів" << endl; system("pause&cls"); return; }
		 weak_ptr<RGZ> weak;
		 cout << "Адреса показчиків вашого масиву" << endl;
		 for (my::UNO < RGZ>& uptr : D)
			 cout << uptr.get() << endl;

		 cout << "кількість покажчиків на кожен об'єкт масиву" << endl;
		 for (my::UNO < RGZ>& s_ptr : D)
			 cout << s_ptr.use_count() << endl;
		 cout << "\n\nкількість покажчиків на кожен об'єкт масиву(за допомогою копій)" << endl;
		 for (my::UNO<RGZ> s_ptr : D)
			 cout << s_ptr.use_count() << endl;
		 D[2].swap(D[1]);
		 cout << "\n\nSwap D[2]&D[1]" << endl;
		 cout << "Адреса показчиків вашого масиву" << endl;
		 for (my::UNO < RGZ>& uptr : D)
			 cout << uptr.get() << endl;
		 cout << endl << endl;
		 system("pause&cls");
	 }


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



