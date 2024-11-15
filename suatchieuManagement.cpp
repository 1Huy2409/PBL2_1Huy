#include "suatchieuManagement.h"

suatchieumanager::suatchieumanager() {}

suatchieumanager::~suatchieumanager() {}

void suatchieumanager::addsuatchieu(suatchieu s)
{
    this->insert(s);
}

char S[9][9];
// hàm tạo bảng chỗ ngồi
void createtable()
{
    S[0][0] = ' ';
    int index = 0;
    for (int i = 1; i < 9; i++)
    {
        S[i][0] = 'A' + index;
        index++;
    }
    for (int i = 1; i < 9; i++)
    {
        S[0][i] = '0' + i;
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            S[i][j] = '0';
        }
    }
}
// begin read and write file
void suatchieumanager::readFile()
{
    ifstream inFile("suatchieu.txt");
    if (inFile.is_open() == false)
    {
        cerr << "File not found , check again";
        return;
    }
    string line;
    suatchieu s;
    bool checkseat = false;
    while (getline(inFile, line))
    {
        if (checkseat == true)
        {

            s.setSeatInfor(line);
            this->addsuatchieu(s);
            checkseat = false;
            continue;
        }
        else if (line.find("S") != string::npos)
        {
            istringstream iss(line);
            string token;

            getline(iss, token, ';');
            s.setShowTimeId(token); // Mã suất chiếu

            getline(iss, token, ';');
            s.setMovieId(token); // Mã phim

            getline(iss, token, ';');
            s.setRoomId(token); // Mã phòng chiếu

            getline(iss, token, ';');
            s.setTime(token); // Thời gian chiếu

            getline(iss, token, ';');
            s.setDate(token); // Ngày chiếu

            checkseat = true;
        }
    }
}
void suatchieumanager::writeFile()
{
    ofstream outfile("suatchieu.txt");
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        outfile << current->data.getId() << ";" << current->data.getMovieId() << ";" << current->data.getRoomId() << ";" << current->data.getTime() << ";" << current->data.getDate();
        outfile << "\n";
        outfile << current->data.getSeatInfor();
        outfile << "\n\n";
        current = current->next;
    }

    outfile.close();
}
// end read and wrie file
string suatchieumanager::getmoviedate(string maphim, string masuat, string maphong)
{ // truyen vao ma phim va id cua suat chieu, => truyen them ma phong
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getId() == masuat && current->data.getMovieId() == maphim && current->data.getRoomId() == maphong)
        {
            return current->data.getDate();
        }
        else
            current = current->next;
    }
}
string suatchieumanager::getmovietime(string maphim, string masuat, string maphong)
{ // truyen vao ma phim va id cua suat chieu, => truyen them ma phong
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getId() == masuat && current->data.getMovieId() == maphim && current->data.getRoomId() == maphong)
        {
            return current->data.getTime();
        }
        else
            current = current->next;
    }
}
// string suatchieumanager::getmovietime(string id, string stt){
//     node<suatchieu> * current = this->head;
//     while(current != NULL){
//         if(current->data.getId() == id && current->data.getstt() == stt) {
//             return current->data.gettime();
//         } else current = current->next;
//     }
// }
// string suatchieumanager::getmovieid(string id, string stt){
//     node<suatchieu> * current = this->head;
//     while(current != NULL){
//         if(current->data.getId() == id && current->data.getstt() == stt) {
//             // return current->data.getd();
//         } else current = current->next;
//     }
// }

void suatchieumanager::setmovieseat(string maphim, string masuat, string maphong, string seat)
{ // set cho ngoi trong rap chieu phim
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getId() == masuat && current->data.getMovieId() == maphim && current->data.getRoomId() == maphong)
        {
            current->data.setSeatInfor(seat);
            return;
        }
        else
            current = current->next;
    }
}

string suatchieumanager::getmoviename(string id)
{
    ifstream inFile("Movie_information.txt");
    if (!inFile)
    {
        cout << "File wa doko? ";
    }
    string line;
    string moviename;
    while (getline(inFile, line))
    {
        if (line.find(id) == 0)
        {
            istringstream ss(line);

            getline(getline(ss, moviename, ';'), moviename, ';');
        }
    }
    inFile.close();

    return moviename;
}

// void suatchieumanager::checkId(string id){ //check id cua phim
//     node<suatchieu> * current = this->head;
//     string x = current->data.getId() + current->data.getMovieId() + current->data.getRoomId() + "                   " ;
//     cout << "\n\t\t\to";
//     for(int i=0; i< x.length()+5; i++){
//         cout << "=";
//     }
//     cout << "o" << endl;
//     cout << "\t\t\t\t MOVIE ID: " << id << endl;
//     cout << "\t\t\to";
//     for(int i=0; i< x.length()+5; i++){
//         cout << "=";
//     }
//     cout << "o\n";
//     while(current != NULL) {
//         if(current->data.getMovieId() == id) {
//             cout << "\t\t\to   " << current->data.getstt() << "  |  ";
//             if  ((current->data.gettime()).length() < 5 ){
//                     cout<< "0" ;
//             }
//             cout << current->data.gettime() << "  |  " << current->data.getdate() << "   o";
//             cout << endl;
//             current = current->next;
//         } else current = current->next;
//     }
//     cout << "\n\t\t\to";
//     for(int i=0; i< x.length()+5; i++){
//         cout << "=";
//     }
//     cout << "o\n";
// }

// string suatchieumanager::readseat(string id, string stt) {
//     node<suatchieu> * current = this->head;
//     while(current != NULL) {
//         if (current->data.getId() == id && current->data.getstt() == stt) {
//             cout << current->data.getId() << ";" << current->data.getstt() << ";" << current->data.gettime() << ";" << current->data.getdate();
//             cout << endl;
//             return current->data.getseat();
//         } else current = current->next;
//     }
//     cout<<"khong tim thay suat chieu";

// }

string getCurrentDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m");
    return oss.str();
}

string GetTomorrowDate()
{
    // Lấy thời gian hiện tại
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    localTime->tm_mday += 1;
    mktime(localTime);
    ostringstream oss;
    oss << setw(2) << setfill('0') << localTime->tm_mday << '/'
        << setw(2) << setfill('0') << localTime->tm_mon + 1;
    return oss.str();
}

bool CheckTime(const string &targetTime)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *timeinfo;
    timeinfo = localtime(&currentTime);
    int targetHour, targetMinute;
    sscanf(targetTime.c_str(), "%dH%d", &targetHour, &targetMinute);
    if (timeinfo->tm_hour > targetHour || (timeinfo->tm_hour == targetHour && timeinfo->tm_min >= targetMinute))
    {
        return true; // Nếu thời gian hiện tại đã vượt qua thời gian target
    }
    else
    {
        return false;
    }
}

int CompareDate(const string &dateString)
{
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    tm inputDate = {};
    istringstream iss(dateString);
    char delimiter;
    iss >> inputDate.tm_mday >> delimiter >> inputDate.tm_mon;
    inputDate.tm_mon -= 1;
    if (localTime->tm_mon > inputDate.tm_mon ||
        (localTime->tm_mon == inputDate.tm_mon && localTime->tm_mday > inputDate.tm_mday))
    {
        return 0; // trước ngày hiện tại
    }
    else if (localTime->tm_mon == inputDate.tm_mon && localTime->tm_mday == inputDate.tm_mday)
    {
        return 1; // là ngày hiện tại
    }
    else
    {
        return 2; // sau ngày hiện tại
    }
}

// void suatchieumanager::resetseat(){
//     node<suatchieu>* current = this->head;
//     while(current != NULL) {
//         if((CompareDate(current->data.getdate()) == 1 && CheckTime(current->data.gettime()) == false) || CompareDate(current->data.getdate()) == 2){ //TODO::
//             current = current->next;
//         } else if(CompareDate(current->data.getdate()) == 1 && CheckTime(current->data.gettime()) == true) { //da qua roi
//             current->data.setseat("");
//             current->data.setdate(GetTomorrowDate());
//             current= current->next;
//         } else if(CompareDate(current->data.getdate()) == 0 && CheckTime(current->data.gettime()) == false) { //  ngay hom trươc va chua qua gio
//             current->data.setseat("");
//             current->data.setdate(getCurrentDate());
//             current = current->next;
//         } else if(CompareDate(current->data.getdate()) == 0 && CheckTime(current->data.gettime()) == true) { // hom truo va da qua gio
//             current->data.setseat("");
//             current->data.setdate(GetTomorrowDate());
//             current = current->next;
//         }
//     }
//     this->writeFile();
// }

void suatchieumanager::print_Pre_seat(string seat)
{
    createtable();
    istringstream ss(seat);
    string field;
    while (getline(ss, field, ';'))
    {
        char hangghe = field[0];
        int hang = hangghe - 64;
        char soghe = field[1];
        int ghe = soghe - '0';
        if (S[hang][ghe] == '0')
        {
            S[hang][ghe] = 'X';
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << S[i][j] << "   ";
        }
        cout << endl
             << endl;
    }
}

string suatchieumanager::pickseat()
{
    cout << "Pick the seat you desire: ";
    string seat;
    bool booking = false;
    while (booking == false)
    {
        cin >> seat;
        char hangghe = seat[0];
        int hang = hangghe - 64;
        char soghe = seat[1];
        int ghe = soghe - '0';
        if (ghe >= 9 || hangghe > 'H' || seat.size() >= 3)
        {
            cout << "Check again: ";
        }
        else if (S[hang][ghe] == '0')
        {
            S[hang][ghe] = 'X';
            break;
        }
        else
        {
            cout << "Someone else had booked this seat. Please pick another seat!: ";
        }
    }
    return seat;
}
void suatchieumanager::createNewSuatchieuForMovie(string movieId)
{

    roomManagement rm;
    rm.readFile();
    ofstream outFile("suatchieu.txt", ios::app);
    node<room> *currentRoom = rm.getHead();
    while (currentRoom != NULL)
    {
        suatchieu s;
        int timehour = 7;
        string timeminute = "H30";
        int numberOfShowTimes = 6;
        for (int i = 0; i < 6; i++)
        {
            string showTimeId = "S" + to_string(i + 1);
            string time = to_string(timehour) + timeminute;
            timehour += 2;
            string date = getCurrentDate();
            string seat_infor = "";

            // tao them mot suat chieu khi them phong, moi phim duoc dua vao phong do => duyet qua tat ca cac phim
            suatchieu s(showTimeId, movieId, currentRoom->data.getId(), time, date, seat_infor);
            outFile << s.getId() << ";" << s.getMovieId() << ";" << s.getRoomId() << ";" << s.getTime() << ";" << s.getDate() << ";" << s.getSeatInfor();
            outFile << endl << endl << endl;
            showTimeId = "";
        }
        currentRoom = currentRoom->next;
    }
    outFile.close();
}
void suatchieumanager::createNewSuatchieuForRoom(string roomId)
{
    movieManagement mm;
    mm.readFile();
    ofstream outFile("suatchieu.txt", ios::app);
    // node<movie>* currentMovie = mm.getHead();
    suatchieu s;
    int timehour = 7;
    string timeminute = "H30";
    int numberOfShowTimes = 6;
    //can mot string cho movieId
    string movieId = "MP";
    for (int i = 0; i < 6; i++)
    {   
        movieId += to_string(i+1);
        string showTimeId = "S" + to_string(i + 1);
        string time = to_string(timehour) + timeminute;
        time += 2;
        string date = getCurrentDate();
        string seat_infor = "";

        // tao them mot suat chieu khi them phong, moi phim duoc dua vao phong do => duyet qua tat ca cac phim
        suatchieu s(showTimeId, movieId, roomId, time, date, seat_infor);
        outFile << s.getId() << ";" << s.getMovieId() << ";" << s.getRoomId() << ";" << s.getTime() << ";" << s.getSeatInfor();
        outFile << endl
                << endl
                << endl;
    }
    outFile.close();
}

// void suatchieumanager::createNewSuatchieu(string movieId = "", string roomId = ""){
//     ofstream outFile("suatchieu.txt", ios::app);
//     suatchieu s;
//     int timehour = 7;
//     string timeminute = "H30";
//     int numberOfShowTimes = 6; //moi ngay co 6 suat chieu
// for(int i = 0; i < 6; i++) {
//     string showTimeId = "S" + to_string(i+1);
//     string time = to_string(timehour) + timeminute;
//     time += 2;
//     string date = getCurrentDate();
//     string seat_infor = "";

//     //tao them mot suat chieu khi them phong, moi phim duoc dua vao phong do => duyet qua tat ca cac phim

//     outFile << s.getId() << ";" << s.getstt() << ";" << s.gettime() << ";" << s.getdate();
//     outFile << endl << endl << endl;
// }
// outFile.close();
// }

// void suatchieumanager::removeSuatchieu(string id)
// {
//     ifstream inFile("suatchieu.txt");
//     string line;
//     string File;
//     bool check = false;
//     while (getline(inFile, line))
//     {
//         if (check == true)
//         {
//             File += "";
//             check = false;
//         }
//         else if (line.find(id) == string::npos)
//         {
//             check = true;
//             File += "";
//         }
//         else
//         {
//             File += line;
//             File += "\n";
//         }
//     }
//     inFile.close();
//     ofstream outFile("suatchieu.txt");
//     outFile << File;
//     outFile.close();
// }

void suatchieumanager::removeSuatchieu(string id)
{
    ifstream inFile("suatchieu.txt");
    if (!inFile.is_open()) {
        cerr << "Could not open file for reading." << endl;
        return;
    }

    string line;
    string updatedFileContent;
    bool skipNextLine = false;

    // Đọc từng dòng trong file
    while (getline(inFile, line))
    {
        if (skipNextLine) {
            // Nếu dòng trước chứa ID cần xóa, bỏ qua dòng hiện tại
            skipNextLine = false;
            continue;
        }

        // Kiểm tra nếu dòng này chứa ID cần xóa
        if (line.find(id) != string::npos) {
            skipNextLine = true; // Đánh dấu để bỏ qua dòng tiếp theo
        } else {
            // Nếu không chứa ID, thêm dòng vào nội dung cập nhật
            updatedFileContent += line + "\n";
        }
    }

    inFile.close();

    // Mở file để ghi đè với nội dung đã cập nhật
    ofstream outFile("suatchieu.txt");
    if (!outFile.is_open()) {
        cerr << "Could not open file for writing." << endl;
        return;
    }
    outFile << updatedFileContent;
    outFile.close();
}
//edit id lai cho movie => sua lai trong suat chieu
//edit id lai cho room => sua lai trong suat chieu
void suatchieumanager::editSuatchieuForMovie(string old_id, string new_id)
{
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getMovieId() == old_id)
        {
            current->data.setMovieId(new_id);
            current = current->next;
        }
        else
            current = current->next;
    }
    this->writeFile();
}
void suatchieumanager::editSuatchieuForRoom(string old_id, string new_id)
{
    node<suatchieu> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getRoomId() == old_id)
        {
            current->data.setRoomId(new_id);
            current = current->next;
        }
        else
            current = current->next;
    }
    this->writeFile();
}