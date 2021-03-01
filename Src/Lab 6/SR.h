#pragma once

#include "prototaype.h"//бібліотека та прототипи
class  Scientific_SR;

class obkladynka ////агрегація
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




class SR {	
	private:
		string predmet;
		string tema;
		int bal;
		int zavdanj;
		int termin;
		int cathedra;
	

		class cathedr//композиция
		{
		private:
			number_SR cathedra;
		public:
			void Set_cathedra(int value) { this->cathedra = value; }
			int Get_cathedra() { return cathedra; }
		};

		

	public:
		class SR()//конструктор
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

		void Init(RGZ*&);
	
		
		void Print_two_words_in_line(RGZ* p);

		/////
		virtual void Print_run(RGZ* p);//1 відобразити елементи 
		virtual void Print_el(RGZ* p);
		virtual void add_el(RGZ* p);// перероблено та модрнзовано
		virtual void Riad_FL(RGZ*);//читання із файла
		virtual int  main_menu(number);
        virtual void printTableHead();
		//////

		void delet_el(RGZ* p);//удалить елемент
		void delete_list(RGZ* p);//удалить список
		void curriculum(RGZ*);//навчальний план
		void checking_the_constructor();//перевірка конструктора
        void save_for_Fl(RGZ*);//зберегти все у файл
		 void print_saved_for_Fl();//вивести файл на екран
		
		void dop_INFO(RGZ*);//питання про виводна екран
		
	
		void error(number&, number&);
		
		void sortSTR(RGZ*);
		int kriter(number);
		void sortN(RGZ*& , RGZ*& , RGZ*& );
		void sortK(RGZ*& , RGZ*& , RGZ*& );
		
		
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
	

	


	class  Scientific_SR final: public SR
	{
	private:
	
		string surname;//прізвище викладача 
		string cientific_topic;//наукова тема

	public:
		class Scientific_SR()//конструктор
		{
			surname = "NO name";
			cientific_topic = "No name";
		}

		~Scientific_SR()//деструктор
		{
			//std::cout << "\nВизвано деструктор " << std::endl;
		}

		string Get_surname() { return surname; }
		string Get_cientific_topic() { return cientific_topic; }

		void Set_surname(string value1) { surname  = value1; }
		void Set_cientific_topic(string value) { cientific_topic = value; }



		void add_el(RGZ* p) override;
		void Riad_FL(RGZ* h) override;
		void Print_el(RGZ* p)override;
		int  main_menu(number e) override;
		void dop_INFO(RGZ* h);
		void printTableHead() override;
		void Print_run(RGZ* h) override;
	};

	struct RGZ {
		SR rgz;
		Scientific_SR rBgz;
		RGZ* next;
	};
