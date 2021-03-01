
#include "prototaype.h"

int VSTUProzmova(int e)
{
	printf(" \n  1.Вивести на екран список\n");
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	printf("  2.Додати елемент в список\n");
	printf("  3.Видалити елемент з списку за номереом\n");

	printf("  4.Відобразити елемент списку за номером\n");

	printf("  5.Очистити список \n");

	printf("  6.Завершити роботу \n");
	printf("  7.Перезавантажити програму програму \n");

	printf(" \nваш вибiр: ");
	scanf_s(" %d", &e);

	return e;
}




int  sche(int& t, char p[])
{
	printf("\n\n%s\n ", p);
	printf("так- 1\n ");
	printf("нi- 2\n ");
	printf("вибрана робота :");
	scanf("%i", &t);
	if (t == 2)
	{
		int oo = 12;

	}
	return t;
}

