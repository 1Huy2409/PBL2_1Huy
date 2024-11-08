#pragma once
#include "suatchieu.h"
#include "movie.h"
#include "room.h"
#include "roomManagement.h"
#include "movieManagement.h"
#include "list.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <sstream>
using namespace std;

class suatchieumanager : protected list<suatchieu> {
    public:
    suatchieumanager();
    ~suatchieumanager();

    // string getmovieid(string, string, string); 
    string getmovietime(string, string, string);
    string getmoviedate(string, string, string);
    string getmoviename(string);
    
    void setmovieseat(string, string, string, string);
    void addsuatchieu(suatchieu);  
    void readFile();
    void writeFile();
    void checkId(string);
    string readseat(string, string);
    void resetseat();
    void print_Pre_seat(string);
    string pickseat();
    void createNewSuatchieuForMovie(string);
    void createNewSuatchieuForRoom(string);
    void createNewSuatchieu(string, string);
    void removeSuatchieu(string);
    void editSuatchieuForMovie(string, string);
    void editSuatchieuForRoom(string, string);
};