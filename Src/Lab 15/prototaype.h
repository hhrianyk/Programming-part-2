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

#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <array>
#include <algorithm> // ��� ����������
#include <functional> // ��� ���������

#define _CRTDBG_MAP_ALLOC



using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::out_of_range;

using std::vector;
using std::set; 
using std::list; 
using std::map;
using std::pair;
using std::for_each;
using std::count;
using std::count_if;
using std::min_element;
using std::max_element;
using std::minmax_element;
using std::find;
using std::find_if; 

using std::weak_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;



	typedef /*short*/ int number;

    typedef /*short*/ int number_SR;
	typedef string words_SR;
	typedef bool boo_SR;



int Start_Menu(number);

int yes_and_no(number&,string);///����
 
