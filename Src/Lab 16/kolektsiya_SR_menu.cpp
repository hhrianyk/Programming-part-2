#include "prototaype.h"
#include "SR.h"




void kolektsiya_SR::printTableHead()
{
	std::cout << "\n\n-----------------------------------------------------------------------------------" << std::endl;
	std::cout << "|         |    Предмет   |   Збірник    |     Автор        |Видавництво|   рік      |" << std::endl;
	std::cout << "|         |              |     завдань  |     збіника      |    RGZ    |видавництва |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
}

int kolektsiya_SR::main_menu(number e)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)(11));

	std::cout << " \n  1. Вивести на екран список збірників РГЗ\n";
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	std::cout << "  2. Додати збірник в список\n";
	std::cout << "  3. Видалити збірник з списку за номереом\n";
	std::cout << "  4. Відобразити збірник списку за номером\n";
	std::cout << "  5. Очистити список \n";

  
	std::cout << "  8. Перейти до додаткового меню \n";
	std::cout << "  9. Перейти до попереднього меню \n";

	std::cout << "  11. Завершити роботу \n";


	SetConsoleTextAttribute(hConsole, (WORD)(10));
	std::cout << " \nваш вибiр: ";
	std::cin >> e;
	return e;
}


int kolektsiya_SR::vstup_info(number nov, List_SR& List)
{
	kolektsiya_SR h = kolektsiya_SR();

	system("cls");
	number  a = 1, u = 0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\nВи знаходитесь у класi наслiднику 'збірники завдань' ";
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
				h.add_el(List);

			a = 0;
			break;
		case 2:SetConsoleTextAttribute(hConsole, (WORD)(10));
			h.Riad_FL(List), a = 0;
			break;
		}
	}
	a = h.main_menu(a);
	while (a)
	{
		switch (a)
		{
		case 1:
			system("cls");
			h.printTableHead();
			h.Print_run(List);;
			break;
		case 2:	system("cls"), h.dop_INFO(List);
			break;
		case 3:	system("cls"), h.delet_el(List);
			break;
		case 4:	system("cls"), h.Print_el(List);
			break;
		case 5:
			system("cls");
			List.delete_list_one_Class(h);
			std::cout << "Успішно";
			break;
	
		case 8:system("cls"), List.vstup_info(nov, List);
			break;
		case 9: system("cls"); 
			return 123;
			break;
		case 10:
			List.delete_list_one_Class(h);
			system("cls");
			return nov;

		case 11:List.delete_list(List);
			system("cls");
			nov = 0;
			return 0;
			break;
		}
		string pit = "Бажаєте ще щось зробити?";
		a = yes_and_no(a, pit);
		if (a == 1)
			a = h.main_menu(a);
		else a = 11;


	}
	return 0;
}



void kolektsiya_SR::error(number& a, number& d)
{

	std::cout << "\nНажаль неможливо вiдобразити неiснуючий елемент\n";
	std::cout << "Введiть iнше значення ";
	std::cin >> d;
	a = 1;

}