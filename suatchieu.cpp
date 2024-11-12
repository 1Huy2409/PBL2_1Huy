#include "suatchieu.h"

suatchieu::suatchieu(string masuat, string maphim, string maphong, string gio, string ngay, string ghengoi) : showTimeId(masuat), movieId(maphim), roomId(maphong), time(gio), date(ngay), seat_infor(ghengoi) {}

suatchieu::~suatchieu() {}

string suatchieu::getId()
{
    return this->showTimeId;
}

string suatchieu::getMovieId()
{
    return this->movieId;
}

string suatchieu::getRoomId() {
    return this->roomId;
}
string suatchieu::getTime() {
    return this->time;
}
string suatchieu::getDate() {
    return this->date;
}
string suatchieu::getSeatInfor() {
    return this->seat_infor;
}

void suatchieu::setShowTimeId(string masuat) {
    this->showTimeId = masuat;
}
void suatchieu::setMovieId(string maphim) {
    this->movieId = maphim;
}
void suatchieu::setRoomId(string maphong) {
    this->roomId = maphong;
}
void suatchieu::setTime(string gio) {
    this->time = gio;
}
void suatchieu::setDate(string ngay) {
    this->date = ngay;
}
void suatchieu::setSeatInfor(string ghengoi) {
    this->seat_infor = ghengoi;
}
const suatchieu &suatchieu::operator=(const suatchieu &s)
{
    this->showTimeId = s.showTimeId;
    this->movieId = s.movieId;
    this->roomId = s.roomId;
    this->date = s.date;
    this->seat_infor = s.seat_infor;
    this->time = s.time;
    return *this;
}

istream &operator>>(istream &i, suatchieu &s)
{
    cout << "Show Time ID: ";
    i >> s.showTimeId;
    i.ignore();
    cout << "Movie ID: ";
    i >> s.movieId;
    cout << "Room ID: ";
    i >> s.roomId;
    cout << "Time: ";
    i >> s.time;
    cout << "Date: ";
    i >> s.date;
    cout << "Seat: ";
    i >> s.seat_infor;

    return i;
}

bool suatchieu::operator==(const suatchieu &s)
{
    return (this->showTimeId == s.showTimeId);
}

ostream &operator<<(ostream &o, const suatchieu &s)
{
    o << "Show Time ID: " << s.showTimeId << " Movie ID: " << s.movieId << "Room ID: " << s.roomId << " Time: " << s.time << " Date: " << s.date << endl;
    o << s.seat_infor;
    return o;
}
