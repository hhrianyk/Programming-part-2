#pragma once
#include "prototaype.h"//бібліотека та прототипи

	class SR
	{
		
	private:
		string predmet;
		string tema;
		int bal;
		int zavdanj;
		int termin;
		int cathedra;


	public:
		SR()//конструктор
		{
	  	    predmet = "NO name";
			tema = "No name";
			bal = NULL;
			zavdanj = NULL;
			termin = NULL;
			cathedra = NULL;
		
			cout << "\nВизвано конструктор за впровадженням"<<endl;
		}
		SR(const SR& obg) ://конструктор копіювання

			predmet(obg.predmet), tema(obg.tema), cathedra(obg.cathedra), termin(obg.termin), zavdanj(obg.zavdanj), bal(obg.bal) {
			cout << "\nВизвано конструктор  копiювання" << endl;
		}
		

		SR(string predmet,string tema,int bal,int zavdanj,int termin,int cathedra)//конструктор з аргуменьами
		{
			this->predmet= predmet;
			this->tema= tema;
			this->bal=bal;
			this->zavdanj=zavdanj;
			this->termin=termin;
			this->cathedra=cathedra;
			cout << "\nКонструктор параметрами" << endl;
		}
	


		~SR()//деструктор
		{
			cout << "\nВизвано деструктор " << endl;
		}

		void printTableHead();
		void Print_run(RGZ* p);//1 відобразити елементи
		void Print_el(RGZ* p);
		void add_el(int ,string, string, int, int, int, RGZ* p);//додати елемент
		void add_el(RGZ* p);
		void curriculum(RGZ*);//навчальний план
		
		void error( int&,int&);
		void checking_the_constructor();//перевірка конструктора

	
	
		void delet_el(RGZ* p);//удалить елемент
		void delete_List(RGZ* p);//удалить список

		string Get_predmet() { return predmet; }
		string Get_teme() { return tema; }
		int Get_bal() { return bal; }
		int Get_zavdanj() { return zavdanj; }
		int Get_termin() { return termin; }
		int Get_cathedra() { return cathedra; }

		void Set_predmet(string value1) { this->predmet = value1; }
		void Set_teme(string value1) { this->tema = value1; }
		void Set_bal(int value) { this->bal = value; }
		void Set_zavdanj(int value) { this->zavdanj = value; }
		void Set_termi(int value) { this->termin = value; }
		void Set_cathedra(int value) { this->cathedra = value; }
	};
	struct RGZ {
		SR rgz;
		RGZ* next;
	};

