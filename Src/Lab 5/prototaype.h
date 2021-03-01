#define kon  clock()/60000//хвилини
#define kon2  (clock()/1000)%60//секунди

#include <ctime>
#include "stdlib.h"
#include "string.h"
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
#include <stdlib.h>
#include "crtdbg.h"

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


#define DDEBUG
//using namespace std;

struct RGZ;
class SR;
int vstup_info(number);
void dop_INFO(RGZ*);
void Riad_FL(RGZ*);
void addProgram1(RGZ*);


int main_menu(number);
int yes_and_no(number&, char[]);