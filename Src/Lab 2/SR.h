#pragma once
#include "prototaype.h"//�������� �� ���������

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
		SR()//�����������
		{
	  	    predmet = "NO name";
			tema = "No name";
			bal = NULL;
			zavdanj = NULL;
			termin = NULL;
			cathedra = NULL;
		
			cout << "\n������� ����������� �� �������������"<<endl;
		}
		SR(const SR& obg) ://����������� ���������

			predmet(obg.predmet), tema(obg.tema), cathedra(obg.cathedra), termin(obg.termin), zavdanj(obg.zavdanj), bal(obg.bal) {
			cout << "\n������� �����������  ���i������" << endl;
		}
		

		SR(string predmet,string tema,int bal,int zavdanj,int termin,int cathedra)//����������� � �����������
		{
			this->predmet= predmet;
			this->tema= tema;
			this->bal=bal;
			this->zavdanj=zavdanj;
			this->termin=termin;
			this->cathedra=cathedra;
			cout << "\n����������� �����������" << endl;
		}
	


		~SR()//����������
		{
			cout << "\n������� ���������� " << endl;
		}

		void printTableHead();
		void Print_run(RGZ* p);//1 ���������� ��������
		void Print_el(RGZ* p);
		void add_el(int ,string, string, int, int, int, RGZ* p);//������ �������
		void add_el(RGZ* p);
		void curriculum(RGZ*);//���������� ����
		
		void error( int&,int&);
		void checking_the_constructor();//�������� ������������

	
	
		void delet_el(RGZ* p);//������� �������
		void delete_List(RGZ* p);//������� ������

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

