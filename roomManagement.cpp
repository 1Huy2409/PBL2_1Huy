#include "roomManagement.h"

roomManagement::roomManagement() {}
roomManagement::~roomManagement() {}

node<room>* roomManagement::getHead() {
    return head;  // Trả về con trỏ đầu tiên của danh sách phòng chiếu
}

void roomManagement::addRoom(const room &newRoom)
{
    // them room dua vao template doubly linked list
    this->insert(newRoom);
}
bool roomManagement::removeRoom(string id)
{
    room *r = this->search(id);
    if (r == NULL)
    {
        cout << "\nnot found , check again : ";
        return false;
    }

    this->remove(*r);
    return true;
}
bool roomManagement::editRoom(string &id, string &newId)
{
    room *m = this->search(id);
    if (m == NULL)
    {
        cout << "\nnot found check again : \n";
        return false;
    }

    room newRoom;
    cin >> newRoom;
    newId = newRoom.getId();
    this->edit(*m, newRoom);
    return true;
}

// doc ghi file
void roomManagement::readFile()
{
    ifstream file;
    file.open("room.txt");

    if (!file.is_open())
    {
        cout << "\n Can not open file!!! Check again!\n";
    }
    else
    {
        string line;
        room token;
        int pos;
        try
        {
            while (getline(file, line))
            {
                pos = line.find(';');
                token.setRoomId(line.substr(0, pos));
                line.erase(0, pos + 1);
                token.setCapacity(stoi(line));
                this->addRoom(token);
            }
        }
        catch (const std::exception &e)
        {
            cout << "error: " << e.what() << endl;
            cout << "check file again\n";
        }
    }
    file.close();
}
void roomManagement::writeFile()
{
    ofstream file;
    file.open("room.txt");
    if (!file.is_open())
    {
        cout << "can not open file!!! Check again!";
    }
    else
    {
        node<room> *current = this->head;
        while (current != NULL)
        {
            file << current->data.getId() << ";" << current->data.getCapacity() << endl;
            current = current->next;
        }
        file.close();
    }
}
bool roomManagement::checkPrimarykey(const string &id)
{
    node<room> *current = this->head;
    while (current != NULL)
    {
        if (current->data.getId() == id)
        {
            return false;
        }
        current = current->next;
    }
    return true;
}
// in danh sach phong chieu co trong rap
void roomManagement::printListRoom()
{
    node<room> *current = this->head;
    while (current != NULL)
    {
        cout << "Ma phong: " << current->data.getId() << " " << "Suc chua: " << current->data.getCapacity() << endl;
        current = current->next;
    }
}
void roomManagement::start()
{
    system("cls");
    this->readFile();
    char tt;

    do
    {

        this->printListRoom();
        cout << endl;
        cout << "\t\t\t";
        for (int j = 0; j <= 1; j++)
        {
            cout << char(218);
            for (int i = 0; i < 20; i++)
                cout << char(196);
            cout << char(191) << "                     ";
        }
        cout << endl;
        cout << "\t\t\t";
        cout << char(179) << " 1 " << char(179) << "   ADD ROOM    " << char(179);
        cout << "                     " << char(179) << " 2 " << char(179) << "  REMOVE ROOM  " << char(179) << endl;

        cout << "\t\t\t";
        for (int j = 0; j <= 1; j++)
        {
            cout << char(192);
            for (int i = 0; i < 20; i++)
                cout << char(196);
            cout << char(217) << "                     ";
        }
        cout << endl;
        cout << "\t\t\t";
        for (int j = 0; j <= 1; j++)
        {
            cout << char(218);
            for (int i = 0; i < 20; i++)
                cout << char(196);
            cout << char(191) << "                     ";
        }
        cout << endl;
        cout << "\t\t\t";
        cout << char(179) << " 3 " << char(179) << "   EDIT ROOM   " << char(179);
        cout << "                     " << char(179) << " 4 " << char(179) << "   LIST ROOM   " << char(179) << endl;

        cout << "\t\t\t";
        for (int j = 0; j <= 1; j++)
        {
            cout << char(192);
            for (int i = 0; i < 20; i++)
                cout << char(196);
            cout << char(217) << "                     ";
        }
        cout << endl;
        cout << "\t\t\t\t\t\t";

        cout << char(218);
        for (int i = 0; i < 15; i++)
            cout << char(196);
        cout << char(191);
        cout << endl;
        cout << "\t\t\t\t\t\t";
        cout << char(179) << " 5 " << char(179) << "   BACK    " << char(179) << endl;
        cout << "\t\t\t\t\t\t" << char(192);
        for (int i = 0; i < 15; i++)
            cout << char(196);
        cout << char(217) << endl;

        tt = getche();

        switch (tt)
        {
        case '1':
        {
            room new_room;
            cout << endl;
            cin >> new_room;
            suatchieumanager m;
            m.readFile();
            string newId;
            while (this->checkPrimarykey(new_room.getId()) != true)
            {
                cout << "\nPrimary key is exist , retype!!! \n";
                cout << "Id: ";
                cin >> newId;
                new_room.setRoomId(newId);
            }
            // m.createNewSuatchieu(new_room.getId());
            // m.createNewSuatchieuForRoom(new_room.getId());

            this->addRoom(new_room);
            this->writeFile();
            break;
        }
        case '2':
        {
            string id;
            suatchieumanager m;
            m.readFile();
            cout << "\nRoom id : ";
            cin >> id;
            while (this->removeRoom(id) != true)
            {
                cin >> id;
                continue;
            }
            m.removeSuatchieu(id);
            this->writeFile();
            break;
        }
        case '3':
        {
            string id;
            string newId;
            suatchieumanager m;
            m.readFile();
            cout << "\nMovie id : ";
            cin >> id;
            while (this->editRoom(id, newId) != true)
            {
                cin >> id;
                continue;
            }
            m.editSuatchieuForRoom(id, newId);
            this->writeFile();

            break;
        }
        case '4':
        {
            cout << "\n";
            system("cls");
            this->printListRoom();
            cout << "\t\t\tpress any key to continue";
            getch();
            break;
        }
        case '5':
        {
            return;
        }
        default:
            cout << "\a";
        }
        system("cls");

    } while (tt != 5);
}