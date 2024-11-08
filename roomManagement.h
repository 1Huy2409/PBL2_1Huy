#pragma once
#include "room.h"
#include "list.h"
#include "suatchieuManagement.h"

using namespace std;

class roomManagement:protected list<room> {
    //ham dung va huy
    public:
    roomManagement();
    ~roomManagement();
    
    //cac phuong thuc quan ly phong chieu
    void start();
    //tra ve con tro room dau tien
    node<room>* getHead();
    //add rm edit printList
    void addRoom(const room &);
    bool removeRoom(string);
    bool editRoom(string& , string&);
    //doc ghi file
    void readFile();
    void writeFile();
    void printListRoom();
    bool checkPrimarykey(const string&);
};