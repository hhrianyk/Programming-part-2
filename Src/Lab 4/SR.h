#pragma once
#include "prototaype.h"//бібліотека та прототипи

	class SR
	{
		
	private:
		std::string predmet;
		std::string tema;
		int bal;
		int zavdanj;
		int termin;
		int cathedra;
		std::stringstream  ss;

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
		SR(const SR& obg) ://конструктор копіювання

			predmet(obg.predmet), tema(obg.tema), cathedra(obg.cathedra), termin(obg.termin), zavdanj(obg.zavdanj), bal(obg.bal) {
		//	std::cout << "\nВизвано конструктор  копiювання" <<std::endl;
		}
		

		SR(std::string predmet,std::string tema,int bal,int zavdanj,int termin,int cathedra)//конструктор з аргуменьами
		{
			this->predmet= predmet;
			this->tema= tema;
			this->bal=bal;
			this->zavdanj=zavdanj;
			this->termin=termin;
			this->cathedra=cathedra;
			//std::cout << "\nКонструктор параметрами" << std::endl;
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
	
		void error( int&,int&);
		
		
		
		
	
		std::string Get_predmet() { return predmet; }
		std::string Get_teme() { return tema; }
		int Get_bal() { return bal; }
		int Get_zavdanj() { return zavdanj; }
		int Get_termin() { return termin; }
		int Get_cathedra() { return cathedra; }


		void Set_predmet(std::string value1) { this->predmet = value1; }
		void Set_teme(std::string value1) { this->tema = value1; }
		void Set_bal(int value) { this->bal = value; }
		void Set_zavdanj(int value) { this->zavdanj = value; }
		void Set_termi(int value) { this->termin = value; }
		void Set_cathedra(int value) { this->cathedra = value; }
	
	};
	struct RGZ {
		SR rgz;
		
		RGZ* next;
	};

