
#include "prototaype.h"

int VSTUProzmova(int e)
{
	printf(" \n  1.������� �� ����� ������\n");
	system("ping 1.1.1.1 -n 0.001 -w 0.001 > nul");
	printf("  2.������ ������� � ������\n");
	printf("  3.�������� ������� � ������ �� ��������\n");

	printf("  4.³��������� ������� ������ �� �������\n");

	printf("  5.�������� ������ \n");

	printf("  6.��������� ������ \n");
	printf("  7.��������������� �������� �������� \n");

	printf(" \n��� ���i�: ");
	scanf_s(" %d", &e);

	return e;
}




int  sche(int& t, char p[])
{
	printf("\n\n%s\n ", p);
	printf("���- 1\n ");
	printf("�i- 2\n ");
	printf("������� ������ :");
	scanf("%i", &t);
	if (t == 2)
	{
		int oo = 12;

	}
	return t;
}

