#define kon  clock()/60000///< ��� � �������
#define kon2  (clock()/1000)%60///< ��� � �������

#include <ctime>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include <crtdbg.h>
#include <fstream>
#include <string>
#include "time.h"
#include <random> 
#include <iostream>
#include <ostream> 
#include <sstream> 
#include <iomanip>
#include <Windows.h>
#include <regex>
#include <cstddef>
#include <stddef.h>
#define _CRTDBG_MAP_ALLOC



using std::cout;
using std::string;
using std::endl;
using std::cin;


	typedef /*short*/ int number;

    typedef /*short*/ int number_SR;
	typedef string words_SR;
	typedef bool boo_SR;







class RGZ;

class SR;
class Scientific_SR;
class Kolektsiyj_SR;
int vstup_info(number);///������� �����
int vstup_info2(number);///�������� ������ �����
int vstup_info3(number);///�������� �������
int Start_Menu(number);

int yes_and_no(number&,string);///����
