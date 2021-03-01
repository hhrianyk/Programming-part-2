#define kon  clock()/60000//хвилини
#define kon2  (clock()/1000)%60//секунди

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
#define _CRTDBG_MAP_ALLOC
#include <iomanip>
#include <Windows.h>
#include <regex>
#include <cstddef>
#include <stddef.h>

using  std::cout;
using std::string;
using std::endl;
using std::cin;


typedef /*short*/ int number;
///////
///////для кастама класа
    typedef /*short*/ int number_SR;
	typedef string words_SR;
	typedef bool boo_SR;



struct RBGZ;
struct RGZ;
class SR;
class Scientific_SR;


int vstup_info(number);
int vstup_info2(number);


int yes_and_no(number&, char[]);
int Start_Menu(number);