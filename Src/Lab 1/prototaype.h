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

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include "crtdbg.h"

#include <iostream>
#include <Windows.h>
#define DDEBUG
using namespace std;

struct RGZ;
class SR;
void Init(RGZ*&);
int  sche(int&, char[]);
int VSTUProzmova(int);
void Riad_FL(RGZ*);
void dop_INFO(RGZ*);
int vstup_info(int);