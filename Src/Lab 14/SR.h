#pragma once
#include "prototaype.h"

#define ARRAY_SIZE 255


//Клас ргз ,зо наслідується від абстракного 
class RGZ 
{
private:
	string predmet;///<предмет
	string tema;///<тема
	   int bal;///<кількість балів за завдання
	   int zavdanj;///<кількість завдань
	   int termin;///<строк здачи РГЗ у днях
	 
public :
	
	RGZ()
	{
		predmet = "NO name";
		tema = "No name";
		bal = NULL;
		zavdanj = NULL;
		termin = NULL;
	}

	~RGZ() { ; }//деструктор

	virtual void show()
	{
		cout << "    |" << std::setw(14) << Get_predmet() << "|" << std::setw(14) <<  Get_teme()
			<< "|" << std::setw(18) <<  Get_bal() << "|" << std::setw(11) <<  Get_termin() << "|" << std::setw(11)
			<<  Get_zavdanj() << "|"
			<< "\n------------------------------------------------------------------------------------\n";
		
	}


	string Get_predmet()const  { return predmet; }
    string Get_teme()   const  { return tema;    }
       int Get_bal()    const  { return bal;     }
	   int Get_zavdanj()const  { return zavdanj; }
	   int Get_termin() const  { return termin;  }



	   void Set_predmet(string value1) { this->predmet = value1;}
	   void Set_teme(string value1)    { this->tema = value1;   }
	   void Set_bal(int value)         { this->bal = value;     }
	   void Set_zavdanj(int value)     { this->zavdanj = value; }
	   void Set_termin(int value)      { this->termin = value;  }


	   virtual void el(RGZ& add);
	   virtual                int vstup_info(number nov, int N, vector<RGZ>& A, set<RGZ>& B, list<RGZ>& C, map<int, RGZ>& D,vector<RGZ*>& E);
	   template<typename T>  void Print_run(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	   template<typename T>  void Print_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	   template<typename T>  void add_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	   template<typename T>  void Riad_FL(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	   template<typename T>  void number_items(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
       template<typename T, typename T2> void count_hopper(int N, T A,T2);
	   template<typename T, typename T2> void count_hopper_map(int N, T A, T2);
	   template<typename T, typename T2> void count_hopper_star(int N, T A, T2);
	   
	   template<typename T>  void Poshuk(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	                          int Poshuk_menu(int e);
	   template<typename T, typename T2>  void Poshuk_hopper(int N, T A,T2);
	   template<typename T, typename T2>  void Poshuk_hopper_star(int N, T A, T2 h);
	   template<typename T, typename T2>  void Poshuk_hopper_map(int N, T A, T2 h);

	   template<typename T> void dop_INFO(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	   template<typename T> void delet_el(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);
	 
	   template<typename T> void Print_container(T a);
	 

	   template<typename T> void Sort(int N, vector<T>& A, set<T>& B, list<T>& C, map<int, T>& D, vector<RGZ*>& E);


	   template<typename T> void insert_vector(int N, vector<T>& A,  vector<RGZ*>& E); 
	   void additional_tasks();

	    int main_menu(number);
	    int Count_menu(int e);
	   void printTableHead();
	   void error(number& a, number& d);
	   RGZ* clone() { return new RGZ(*this); }

	 
		
		

	

		/////Перегрузки//////	

	    RGZ& operator = (const RGZ&);
		RGZ& operator = (const RGZ*);
		

        bool operator>(const RGZ& right) const {
			return Get_predmet() > right.Get_predmet();
		}
		bool operator<(const RGZ& right) const {
			return Get_predmet() < right.Get_predmet();
		}
		bool operator==(const RGZ& right) const {
			return Get_predmet() == right.Get_predmet() && Get_teme() == right.Get_teme() && Get_bal() == right.Get_bal() && Get_zavdanj() == right.Get_zavdanj() && Get_zavdanj() == right.Get_zavdanj();
		}
    
		friend bool operator >  (RGZ& p, RGZ&);
		friend bool operator <  (RGZ& p, RGZ&);
        friend bool operator == (RGZ& p, RGZ&);
		friend bool operator != (RGZ& p, RGZ& p2);
		friend bool operator <= (RGZ& p, RGZ& p2);
		friend bool operator >= (RGZ& p, RGZ& p2);

		
		friend  ostream& operator << (ostream&, const RGZ&);
		friend ifstream& operator >> (ifstream&,RGZ&);



};



///клас ,що наслідується від   RGZ основна задача поширити РГЗ додається два поля surname та cientific_topic
class  Scientific_SR final :  public RGZ
{
private:

	string surname;///<прізвище викладача 
	string cientific_topic;///<наукова тема
	string predmet;
	int zavdanj;
	int termin;

public:
	
	Scientific_SR()//конструктор
	{
		surname = "NO name";
		cientific_topic = "No name";	
		predmet = "No name";
		zavdanj=NULL;
		termin=NULL;
	}

	~Scientific_SR()//деструктор
	{}

	void show() {
		cout << "    |" << std::setw(14) << Get_surname() << "|" << std::setw(14) << Get_predmet()
			<< "|" << std::setw(18) <<  Get_cientific_topic()
			<< "|" << std::setw(11) <<  Get_termin() << "|" << std::setw(11) <<  Get_zavdanj() << "|"
			<< "\n------------------------------------------------------------------------------------\n";
	}
	string Get_surname()        const        { return surname;         }
	string Get_cientific_topic()const { return cientific_topic; }
	string Get_predmet()        const        { return predmet;         }
	   int Get_zavdanj()        const        { return zavdanj;         }
	   int Get_termin()         const        { return termin;          }


	void Set_surname(string value1)        { surname = value1;        }
	void Set_cientific_topic(string value) { cientific_topic = value; }	
	void Set_predmet(string value1)        { this->predmet = value1;  }
	void Set_zavdanj(int value)            { this->zavdanj = value;   }
	void Set_termin(int value)             { this->termin = value;    }


	
	Scientific_SR* clone() {return new Scientific_SR(*this);	}
	 
	           
// int main_menu(number)                   
	void el(Scientific_SR& add);
	int vstup_info( number nov, int N, vector<Scientific_SR>& A, set<Scientific_SR>& B, list<Scientific_SR>& C, map<int, Scientific_SR>& D, vector<RGZ*>& E);
	void printTableHead();



	 Scientific_SR& operator = (const Scientific_SR&);
	 Scientific_SR& operator = (const Scientific_SR*);



	 bool operator>(const Scientific_SR& right) const {
		 return Get_predmet() > right.Get_predmet();
	 }
	 bool operator<(const Scientific_SR& right) const {
		 return Get_predmet() < right.Get_predmet();
	 }
	 bool operator==(const Scientific_SR& right) const {
		 return Get_predmet() == right.Get_predmet() && Get_surname() == right.Get_surname() && Get_predmet() == right.Get_predmet() && Get_zavdanj() == right.Get_zavdanj() && Get_termin() == right.Get_termin();
	 }

	/* friend bool operator >  (Scientific_SR& p, Scientific_SR&);
	 friend bool operator <  (Scientific_SR& p, Scientific_SR&);
	 friend bool operator == (Scientific_SR& p, Scientific_SR&);*/
	 friend bool operator != (Scientific_SR& p, Scientific_SR&);
	 friend bool operator <= (Scientific_SR& p, Scientific_SR&);
	 friend bool operator >= (Scientific_SR& p, Scientific_SR&);



	 friend  ostream& operator <<  (ostream&, Scientific_SR&);
	 friend ifstream& operator >> (ifstream&, Scientific_SR&);

};

template<typename T>
class Funct {
public:
	bool operator()(const T& a) const {
		return a.Get_predmet() < a.Get_predmet();
	}
};







