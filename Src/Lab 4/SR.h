#pragma once
#include "prototaype.h"//�������� �� ���������

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
		SR()//�����������
		{
	  	    predmet = "NO name";
			tema = "No name";
			bal = NULL;
			zavdanj = NULL;
			termin = NULL;
			cathedra = NULL;
	
		}
		SR(const SR& obg) ://����������� ���������

			predmet(obg.predmet), tema(obg.tema), cathedra(obg.cathedra), termin(obg.termin), zavdanj(obg.zavdanj), bal(obg.bal) {
		//	std::cout << "\n������� �����������  ���i������" <<std::endl;
		}
		

		SR(std::string predmet,std::string tema,int bal,int zavdanj,int termin,int cathedra)//����������� � �����������
		{
			this->predmet= predmet;
			this->tema= tema;
			this->bal=bal;
			this->zavdanj=zavdanj;
			this->termin=termin;
			this->cathedra=cathedra;
			//std::cout << "\n����������� �����������" << std::endl;
		}
	
		~SR()//����������
		{
			//std::cout << "\n������� ���������� " << std::endl;
		}

		void printTableHead();

		void Init(RGZ*&);
	
		void Print_run(RGZ* p);//1 ���������� �������� 
		void Print_two_words_in_line(RGZ* p);
		
		void Print_el(RGZ* p);
	//	void add_el(int ,std::string, std::string, int, int, int, RGZ* p);//������ //����� �� ���������������
		void add_el(RGZ* p);// ����������� �� �����������
		void delet_el(RGZ* p);//������� �������
		void delete_list(RGZ* p);//������� ������
		void curriculum(RGZ*);//���������� ����
		void checking_the_constructor();//�������� ������������
        void save_for_Fl(RGZ*);//�������� ��� � ����
		void print_saved_for_Fl();//������� ���� �� �����
	
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

