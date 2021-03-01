#pragma once
#include "prototaype.h"//бібліотека та прототипи
class obkladynka////агрегація
{
private:
	boo_SR cover;
public:
	//конструктор
		obkladynka(){ cover = rand()%2;	}

		~obkladynka()//деструктор
		{
		}	void Set_obkladynka(boo_SR value) { this->cover = value; }
	    int Get_obkladynka() { return cover; }
		void kəvər() {
		if (cover == true)  cout << "\n\nВашому РГЗ потрiбна обкладинка обов'язково\n та не забутьте правильно написати Прiзвище та групу" << endl;
		else cout << "Вашому РГЗ не потрiбна обкладинка взагалі" << endl;
	}
};

class SR
{

private:
	string predmet;
	string tema;
	int bal;
	int zavdanj;
	int termin;
	int cathedra;
	std::stringstream  ss;
	  

	class cathedr//композиция
	{
	private:
		number_SR cathedra;
	public:
		void Set_cathedra(int value) { this->cathedra = value; }
		int Get_cathedra() { return cathedra; }
	};



public:

	SR()//конструктор
	{
		predmet = "NO name";
		tema = "No name";
		bal = NULL;
		zavdanj = NULL;
		termin = NULL;
		cathedra = NULL;

	}


	~SR()//деструктор
	{
		//std::cout << "\nВизвано деструктор " << std::endl;
	}

	void printTableHead();

	void Init(RGZ*&);

	void Print_run(RGZ* p);//1 відобразити елементи 
	void Print_two_words_in_line(RGZ* p);

	void Print_el(RGZ* p);
	//	void add_el(int ,std::string, std::string, int, int, int, RGZ* p);//додати //більше не використовується
	void add_el(RGZ* p);// перероблено та модрнзовано
	void delet_el(RGZ* p);//удалить елемент
	void delete_list(RGZ* p);//удалить список
	void curriculum(RGZ*);//навчальний план
	void checking_the_constructor();//перевірка конструктора
	void save_for_Fl(RGZ*);//зберегти все у файл
	void print_saved_for_Fl();//вивести файл на екран

	void error(number&, number&);

	void sortSTR(RGZ*);
	int kriter(number);
	void sortN(RGZ*&, RGZ*&, RGZ*&);
	void sortK(RGZ*&, RGZ*&, RGZ*&);



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

		cathedr cathedr;//композіция
		obkladynka AG;//агрегація
	

	};
	struct RGZ {
		SR rgz;

		RGZ* next;
	};

