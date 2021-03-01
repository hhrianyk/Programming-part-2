#pragma once
#include "prototaype.h"

#define ARRAY_SIZE 255
class List_SR;

class obkladynka ////агрегація
{
private:
	boo_SR cover;
public:
	//конструктор
	obkladynka() { cover = rand() % 2; }

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
public:
	
	virtual SR* clone() = 0;

	virtual void Print_run(List_SR&)= 0;///< віртуальна функція для вивода списка
	virtual void Print_el(List_SR&) = 0;///< віртуальна функція для вивода одного елементу спуска
	virtual void add_el(List_SR&)   = 0;///< віртуальна функція для додавання данних з клавіатури
	virtual void Riad_FL(List_SR&)  = 0;///< віртуальна функція для додавання данних із файлу
	virtual int  main_menu(number)  = 0;///< віртуальна функція для реалізацію головного меню для класу
	virtual void printTableHead()   = 0;///< віртуальна функція для реалізації вивода шапки таблиці
	virtual	int  vstup_info(number) = 0;///< віртуальна функція для реалізації початку програми
	virtual void dop_INFO(List_SR&) = 0;
    virtual void sortSTR(List_SR&)  = 0;
	virtual int  kriter(number n)   = 0;
};


class RGZ : public SR
{
private:
	string predmet;///<предмет
	string tema;///<тема
	   int bal;///<кількість балів за завдання
	   int zavdanj;///<кількість завдань
	   int termin;///<строк здачи РГЗ у днях
	   int cathedra;///<кафедра

	   class cathedr//композиция
	   {
	   private:
		   number_SR cathedra;
	   public:
		   void Set_cathedra(int value) { this->cathedra = value; }
		   int Get_cathedra() { return cathedra; }
	   };
public :
	RGZ()
	{
		predmet = "NO name";
		tema = "No name";
		bal = NULL;
		zavdanj = NULL;
		termin = NULL;
		cathedra = NULL;
	}

	~RGZ() { ; }//деструктор

	string Get_predmet() { return predmet; }
    string Get_teme()    { return tema;    }
       int Get_bal()     { return bal;     }
	   int Get_zavdanj() { return zavdanj; }
	   int Get_termin()  { return termin;  }



	   void Set_predmet(string value1) { this->predmet = value1;}
	   void Set_teme(string value1)    { this->tema = value1;   }
	   void Set_bal(int value)         { this->bal = value;     }
	   void Set_zavdanj(int value)     { this->zavdanj = value; }
	   void Set_termi(int value)       { this->termin = value;  }

	   void Print_run(List_SR&)       override;
	   void Print_el(List_SR&)        override;
	   void add_el(List_SR&)          override;
	   void Riad_FL(List_SR&)         override;
	    int main_menu(number)         override;
	   void printTableHead()          override;
	    int vstup_info(number)        override;
	   void dop_INFO(List_SR&)        override;
	   void sortSTR(List_SR&)         override;
	   
	    SR* clone() { return (SR*)new RGZ(*this);}

		void delet_el(List_SR&);
		void error(number& a, number& d);
		int  kriter(number n);
		//void delete_list(List_SR&);
		void curriculum(List_SR&);
		void Print_two_words_in_line(List_SR&);
		void save_for_Fl(List_SR&);
		void print_saved_for_Fl();

		
		
		cathedr    cathedr;//композіция
		obkladynka AG;//агрегація

};

class  Scientific_SR final :  public RGZ
{
private:

	string surname;///<прізвище викладача 
	string cientific_topic;///<наукова тема

public:

	Scientific_SR()//конструктор
	{
		surname = "NO name";
		cientific_topic = "No name";
	}

	~Scientific_SR()//деструктор
	{}

	string Get_surname()         { return surname; }
	string Get_cientific_topic() { return cientific_topic; }


	void Set_surname(string value1)        { surname = value1; }
	void Set_cientific_topic(string value) { cientific_topic = value; }



	
	SR* clone() {return (SR*)new Scientific_SR(*this);	}

	void Print_run(List_SR&)      override;
	void Print_el(List_SR&)       override;
	void add_el(List_SR&)         override;
	void Riad_FL(List_SR&)        override;
	 int main_menu(number)        override;
	void printTableHead()         override;
	 int vstup_info(number)       override;
	void dop_INFO(List_SR&)       override;
	void sortSTR(List_SR&)        override;
	 int kriter(number n)         override;


};


class kolektsiya_SR :public SR
{
private:
	string predmet;
	string author;///<Автор збірника
	string collection;///<Назва збірника
	string Vydavnytstvo;///<Видавництво
	   int data;///<дата публікації
public:
	string Get_predmet()       { return predmet;      }
	string Get_author()        { return author;       }
	string Get_collection()    { return collection;   }
	string Get_Vydavnytstvo()  { return Vydavnytstvo; }
	   int Get_data()          { return data;         }


	void Set_predmet(string value)       { predmet = value;       }
	void Set_data(int value1)            { data = value1;         }
	void Set_author(string value1)       { author = value1;       }
	void Set_collection(string value)    { collection = value;    }
	void Set_Vydavnytstvo(string value1) { Vydavnytstvo = value1; }
	
	SR* clone() { return (SR*)new kolektsiya_SR(*this); }

	void Print_run(List_SR&)      override;
	void Print_el(List_SR&)       override;
	void add_el(List_SR&)         override;
	void Riad_FL(List_SR&)        override;
	 int main_menu(number)        override;
	void printTableHead()         override;
	 int vstup_info(number)       override;
	void dop_INFO(List_SR&)       override;
	void sortSTR(List_SR&)        override;
	 int kriter(number n)         override;


	 void poshuk(List_SR& );
	 void delet_el(List_SR&);
	 void error(number& a, number& d);
	// void delete_list(List_SR& A);
};


class List_SR {
protected:
	int index = -1;
	SR* data[ARRAY_SIZE];
public:
	
	List_SR() { ; }
	List_SR(List_SR& rhs) {
		for (int i = 0; i < rhs.index; i++) {
			data[i] = rhs.data[i]->clone();
		}
		index = rhs.index;
	}
	~List_SR() 
	{
		while (index >= 0)
		delete data[index--];
     }	
	void add(SR* a) {
		if (index + 1 >= 255) return;
		data[++index] = a->clone();
	}
	

	SR* Get_Elem(int Index) {return data[Index]->clone();}
	int Get_kol_Index()     {return index+1             ;}

	List_SR& operator=(const List_SR& rhs) {
		if (this == &rhs) // a = a;
			return *this;
		while (index >= 0)
			delete data[index--];
		for (int i = 0; i < rhs.index; i++) {
			data[i] = rhs.data[i]->clone();
		}
		index = rhs.index;
	}
	void del() {
		if (index - 1 < -1) return;
		delete data[index--];
	}
	void del_el(int i)
	{
		for ( i--; i < index; i++)
		{
			data[i] = data[i + 1];
		}
		del();
	}
	void sort(int i) {
		
		SR* temp;
		temp    = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}

	void delete_list(List_SR& A)//
	{
		while (A.Get_kol_Index() > 0)
			A.del();
	}



};

class mass
{
private:
        RGZ A;
		Scientific_SR B;
		kolektsiya_SR C;
public:
	int operator[] (const int index)
	{
		
		if (index == 1) return  A.vstup_info(index);
		else if (index == 2) return  B.vstup_info(index);
		else if (index == 3) return  C.vstup_info(index);
		else return 0;
	}

};