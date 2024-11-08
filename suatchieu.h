#pragma once
#include "list.h"

class suatchieu {
    private:
    string showTimeId; //ma suat chieu
    string movieId;
    string roomId;
    string time;
    string date;
    string seat_infor;

    public:
    suatchieu(string = "", string ="", string = "", string = "", string ="", string = "");
    ~suatchieu();
    
    string getId();
    string getMovieId();
    string getRoomId();
    string getTime();
    string getDate();
    string getSeatInfor();


    void setShowTimeId(string);
    void setMovieId(string);
    void setRoomId(string);
    void setTime(string);
    void setDate(string);
    void setSeatInfor(string);

    bool operator==(const suatchieu &m);
    friend ostream& operator<<(ostream& os, const suatchieu& m);
    friend istream& operator>>(istream& is, suatchieu& m);
    const suatchieu& operator = (const suatchieu &m);

};