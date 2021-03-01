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
using  std::cout;
#define DDEBUG
//using namespace std;

struct RGZ;
class SR;
void Init(RGZ*&);
int vstup_info(int);
void dop_INFO(RGZ*);
void Riad_FL(RGZ*);
void addProgram1(RGZ*);


int main_menu(int);
int yes_and_no(int&, char[]);