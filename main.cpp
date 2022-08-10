#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <map>
#include <conio.h>
#include "header.h"
using namespace std;

const int col = 150;
char line[col];

// -----------------function to read file-----------------
void open_file_read_mode(string filename)
{
    cout << endl
         << endl;
    ifstream fin;
    fin.open(filename);

    if (fin.good())
    {
        while (fin)
        {
            fin.getline(line, col);
            cout.width(strlen(line) + 30);
            cout << line << endl;
        }
    }

    else
        cout << setw(54) << "Problem opening the file" << endl;
    fin.close();
}

//================================================== class welcome =============================================================
class Welcome // First class like me ;)
{
public:
    Welcome();  // default constructor declaration
    void wlcm() // diplaying from text file 'pu_header.txt'
    {

        open_file_read_mode("1_Pu_Info_header.txt"); // user defined function to open file and read its content
    }
    ~Welcome()
    {
        thanks(); // calling thanks function from header , print message when the object is destroyed at the end of program
        displayTeam8(); // calling this function from header, using map(stl) & displays team members
    }
};

Welcome ::Welcome() // default constructor definition outside the class
{
    cout << setw(150) << "========================================================================================================" << endl;
    cout.width(100);
    cout << "PU INFO PROJECT" << endl;

    cout << setw(150) << "========================================================================================================" << endl;
    cout<<endl<<endl;
    print_pu_info('#'); // function from header.h --> print pu_info when the object of welcome class is created
}
//======================================================= class display(abstract)=====================================================
// Abstract Class
class Disp
{
public:
    virtual void displayinfo() = 0; // Pure Virtual Function (do - nothing function)
};

//================================================== class PU Category ==========================================================
class Pu_Category : public Welcome, public Disp // Multiple Inheritance
{
protected:
    char yes;

public:
    char getYes(); // Function declaration

    void displayinfo() // Displaying from text file 'pu_categories.txt' , it is declared as virtual function in disp class
    {
        open_file_read_mode("2_pu_categories.txt"); // user defined  function to open file and read its content
    }
    ~Pu_Category()
    {
        // delete yes; // destructor and 'delete'
    }
};

char Pu_Category ::getYes() // Function definition -> Takes yes/no input
{
    cout << endl
         << endl
         << setw(73) << "Enter y/Y to take a look at the category : "; // user input to continue or not
    cin >> yes;
    return yes;
}

//================================================== class PU INFO ==============================================================
class Pu_Info
{
public:
    Pu_Info(void);
};

Pu_Info ::Pu_Info(void)
{
    open_file_read_mode("3_pu_info_class.txt"); // user defined  function to open file and read its content
}

//================================================== class PLACES ============================================================

class Places
{

private:
    int antimeridian, primemeridian;

protected:
    string location;

public:
    void timing(int a, int b) // --------------------->> function overloading
    {
        antimeridian = a;
        primemeridian = b;

        cout << setw(46) << "The timing is = " << antimeridian << " am to " << primemeridian << " pm " << endl;
    }

    void timing(void)
    {
        cout << setw(53) << "This is opened for 24x7" << endl;
    }

    template <typename t> // --------------------->> using function templates to get both int and float values
    void entry(t x)
    {
        if (x == 0)
            cout << setw(51) << "Entry is for everyone" << endl;

        else if (x == 0.5)
            cout << setw(59) << "Entry is for PU students only" << endl;
    }
};

//================================================== class LANDMARKS ============================================================
class Landmarks : public Places
{
private:
    int a;

public:
    Landmarks(void)
    {
        open_file_read_mode("4_0_Landmarks.txt"); // user defined  function to open file and read its content
    }

    Landmarks(int x);

    ~Landmarks()
    {
        // destructor
    }
};

Landmarks ::Landmarks(int x)
{
    // processing of int x to open sub category
    a = x;

    // ------------ for StuC -----------
    if (a == 1)
    {
        open_file_read_mode("4_a_landmarks_student_center.txt"); // user defined  function to open file and read its content
        cout << endl;
        timing(12, 9);
        entry<int>(0); // 0 as an argument means entry is for everyone

        cout << endl;

        char option;
        cout << setw(107) << "Enter y/Y to open STUC's location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {
            // stuC location hyperlink
            location = "start https://maps.app.goo.gl/SReYHNHEBu5UWUe59"; // location proteceted data member of place class , inherit into landmark
            cout << endl
                 << setw(79) << "STUC's location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }
        cout << endl;
    }

    // --------- for AC JOSHI -------------
    else if (a == 2)
    {
        open_file_read_mode("4_b_landmarks_ac_joshi.txt"); // user defined  function to open file and read its content

        cout << endl;

        timing();           // no argument means open for 24X7
        entry<double>(0.5); // 0.5 as an argument means entry is for Pu students only

        cout << endl;

        char option;
        cout << setw(117) << "Enter y/Y to open Ac Joshi library location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {

            // AC Joshi Library Hyperlink
            location = "start https://maps.app.goo.gl/9DetjzMCNcEwGCGt6";
            cout << endl
                 << setw(91) << "Ac Joshi's Library location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }

        cout << endl;
    }

    // --------------- for Gandhi Bhawan ------------------
    else if (a == 3)
    {
        open_file_read_mode("4_c_landmarks_gandhi_bhawan.txt"); // user defined  function to open file and read its content

        cout << endl;

        timing(10, 4);
        entry<int>(0); // 1 as an argument means entry is for everyone

        cout << endl;

        char option;
        cout << setw(116) << "Enter y/Y to open Gandhi Bhawan's location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {
            // Gandhi Bhawan Hyperlink
            location = "start https://maps.app.goo.gl/ZcXkdm4HzTwVUbQW8";
            cout << endl
                 << setw(88) << "Gandhi Bhawan's location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }

        cout << endl;
    }

    // -------------- for Fine Arts Museum ----------------------
    else if (a == 4)
    {
        open_file_read_mode("4_d_landmarks_fine_art_museum.txt"); // user defined  function to open file and read its content

        cout << endl;

        timing(10, 4);
        entry<int>(0); // 1 as an argument means entry is for everyone

        cout << endl;

        char option;
        cout << setw(119) << "Enter y/Y to open Fine Arts Museum's location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {

            // Fine Arts Museum Hyperlink
            location = "start https://maps.app.goo.gl/iuBzoHbyyMyRNMQa8";
            cout << endl
                 << setw(91) << "Fine Arts Museum's location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }

        cout << endl;
    }

    //----------- for Gardens -----------
    else if (a == 5)
    {
        open_file_read_mode("4_e_landmarks_gardens.txt"); // user defined  function to open file and read its content

        timing();
        entry<int>(0);
    }

    // ---------------- for Sports -----------
    else if (a == 6)
    {
        open_file_read_mode("4_f_landmarks_sports.txt"); // user defined  function to open file and read its content

        timing();
        entry<int>(0);
    }

    // ----------------- for Admin Block -----------
    else if (a == 7)
    {
        cout << endl;
        cout << setw(154) << "================================================= ADMIN BLOCK ==============================================================" << endl
             << endl;
        char option;
        cout << setw(114) << "Enter y/Y to open Admin Block's location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {
            // Admin Block Hyperlink
            location = "start https://maps.app.goo.gl/FKpHYt3o1VPfpo7q7";
            cout << endl
                 << setw(86) << "Admin Block's location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }

        cout << endl;
    }

    // ----------------- for Examination Hall ---------------
    else
    {
        cout << endl;
        cout << setw(154) << "================================================ Examination Hall ==========================================================" << endl
             << endl;
        char option;
        cout << setw(119) << "Enter y/Y to open Examination hall's location on google map. Enter any key to ignore  :  ";
        cin >> option;

        if ((option == 'y') || (option == 'Y'))
        {

            location = "start https://maps.app.goo.gl/FKpHYt3o1VPfpo7q7";
            cout << endl
                 << setw(91) << "Examination hall's location opening, Please wait............." << endl;
            system(location.c_str());
            cout << setw(56) << "Press Enter to continue : ";
            getch();
        }

        cout << endl;
    }
}

//================================================== class DEPARTMENTS ==========================================================
class Departments
{
    int choice;

public:
    Departments(void);

    Departments(int a)
    {
        choice = a;
    }

    friend void call_department(Departments); // friend function  declaration
};

Departments ::Departments(void)
{
    choice = 0;
    open_file_read_mode("5_0_Departments.txt"); // user defined  function to open file and read its content
}

void call_department(Departments depart)
{
    switch (depart.choice)
    {
    case 1:
        open_file_read_mode("5_a_arts.txt"); // user defined  function to open file and read its content
        break;
    case 2:
        open_file_read_mode("5_b_business_management_and_commerce.txt"); // user defined  function to open file and read its content
        break;
    case 3:
        open_file_read_mode("5_c_engineering_and_technology.txt"); // user defined  function to open file and read its content
        break;
    case 4:
        open_file_read_mode("5_d_law.txt"); // user defined  function to open file and read its content
        break;
    case 5:
        open_file_read_mode("5_e_medical_sciences.txt");
        break;
    default:
        open_file_read_mode("5_f_pharmaceuticals.txt"); // user defined  function to open file and read its content
        break;
    }
}
//================================================== class HOSTELS ==============================================================
class Hostels
{

public:
    virtual void display(void);
};

void Hostels ::display()
{
    open_file_read_mode("6_0_Hostels.txt"); // user defined  function to open file and read its content
}
//-------------------------------------------------------------
class GirlsHostels;

class BoysHostels : public Hostels
{
public:
    void display(void);

    void operator+(GirlsHostels);
};

void BoysHostels ::display()
{
    open_file_read_mode("6_a_boys_hostel.txt"); // user defined  function to open file and read its content
}

//------------------------------------------------------
class GirlsHostels : public Hostels
{

public:
    void display(void);

    void operator+(BoysHostels);
};

void GirlsHostels ::display()
{
    open_file_read_mode("6_b_girls_hostel.txt"); // user defined  function to open file and read its content
}

void GirlsHostels ::operator+(BoysHostels bh)
{
    Hostels ::display();
    display();
    bh.display();
}

void BoysHostels ::operator+(GirlsHostels gh)
{
    Hostels ::display();
    display();
    gh.display();
}
//================================================== class CYCLE STANDS =========================================================
class CycleStands
{
public:
    CycleStands(void);
};

CycleStands ::CycleStands(void)
{
    open_file_read_mode("8_Cyclestands.txt"); // user defined  function to open file and read its content
}
//================================================== class ACADEMICS ============================================================
class Academics
{
public:
    Academics(void);
};

Academics ::Academics(void)
{
    open_file_read_mode("7_Academics.txt"); // user defined  function to open file and read its content
}
//================================================== QUICK FACTS ================================================================
char choice;
class QuickFacts
{
private:
    static int count;  // static data member to count the number of times the display function is being called
    static int length; // to calculate length of string

public:
    static char display_fact(void);
};

int QuickFacts ::count = 1;
int QuickFacts ::length = 0;

char QuickFacts ::display_fact(void)
{
    cout << endl;
    ifstream fin;
    fin.open("9_Quickfacts.txt");

    fin.seekg(length, ios ::beg); // moving the position of get pointer to next line

    fin.getline(line, col);             // reading line from files
    length = length + strlen(line) + 2; // increasing the length to read next line(  +2  is nessecary to add)

    if (fin.eof() == 0) // checking the end of file , if the end of file is not reached the if block will execute
    {
        cout << setw(52) << "This is fact number : " << count << endl;

        cout.width(strlen(line) + 30);
        cout << line << endl;
        count = count + 1; // increasing the value of static variable

        cout << endl
             << setw(83) << "Enter y/Y for more facts else enter any key to exit: ";
        cin >> choice;
        return choice;
    }
    else
    {
        cout << setw(45) << "No more facts ." << endl;
        count = 1;
        length = 0;
        fin.close();
        return 'n';
    }
}

//================================================== MAIN FUNCTION ==============================================================
int main()
{
    map<string, int> login;
    login["AvjeetRathi"] = 213021;
    login["DamanPreetSingh"] = 213028;
    login["DevanshShekharShukla"] = 213031;
    login["DevinderKumar"] = 213032;
    login["DhruvGoyal"] = 213034;
    login["ErosDhillon"] = 213035;
    map<string, int>::iterator itr;
    string username, usern;
    int password;
    cout<<endl<<"\t\t\t\t\t\t\t\t\t\tWELCOME TO PU INFO LOGIN PAGE"<<endl<<endl;
    cout << "Enter Username" << endl;
    cin >> username;
    int usrName = 0, psswrd = -1;
    for (itr = login.begin(); itr != login.end(); itr++)
    {
        if (username == (itr->first))
        {
            usrName = 1;
            usern = itr->first;
            break;
        }
    }
    if (usrName == 0)
    {
        cout << "INCORRECT Username" << endl;
    }
    else if (usrName == 1)
    {
        cout << "Enter Password" << endl;
        cin >> password;
        for (itr = login.begin(); itr != login.end(); itr++)
        {
            psswrd=0;
            if ((usern == (itr->first)) && (password == (itr->second)))
            {
                psswrd = 1;
                break;
            }
        }
    }
    if (psswrd == 1)
    {
        Pu_Category obj;            // object of class Pu_Info
        obj.wlcm();                 // calling wlcm() function in class 'Welcome' from the object of class 'Pu_Info' bcoz class 'Pu_Info' is inherited from class 'Welcome'
        char choice = obj.getYes(); // calling getYes() function

        int option;
        int TempOption;

        if ((choice == 'y') || (choice == 'Y'))
        {
            do
            {
                obj.displayinfo(); // displaying pu_categories Pu_category class

                cout << setw(70) << "Enter PU category you want to look at . " << endl
                     << setw(74) << "Enter 0 if you don't want to continue   :   ";

                cin >> option; // user input for looking into above category

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(512, '\n');

                    cout << endl
                         << setw(110) << " It's a character. Please enter a number \n";
                }
                try
                {
                    if ((option < 0 || option > 7))
                    {
                        throw option;
                    }

                    else if (option == 1)
                    {
                        Pu_Info pu; // creating object of pu
                    }

                    else if (option == 2)
                    {
                        Landmarks lndmrk; // creating object of landmarks

                        TempOption = 0;

                        do
                        {

                            cout << setw(80) << "Enter the Landmark category you want to look at : " << endl;
                            cout << setw(48) << "Enter 0 to exit : ";
                            cin >> TempOption;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(512, '\n');

                                cout << endl
                                     << setw(110) << " It's a character. Please enter a number \n";
                            }
                            try
                            {
                                if ((TempOption < 0) || (TempOption > 8))
                                {
                                    throw TempOption;
                                }

                                else if (TempOption != 0)
                                {
                                    lndmrk = Landmarks(TempOption);
                                    lndmrk = Landmarks();
                                }
                            }
                            catch (int y)
                            {
                                cout << endl
                                     << endl
                                     << setw(75) << y << " - No such category in landmarks" << endl
                                     << endl;
                            }

                        } while (TempOption != 0);
                    }

                    else if (option == 3)
                    {
                        Departments depart;

                        TempOption = 0;

                        do
                        {
                            cout << endl
                                 << endl;
                            open_file_read_mode("5_0_list_Departments.txt"); // opening list of departments files

                            cout << endl
                                 << setw(85) << "Enter which departement category you want to look at . " << endl
                                 << setw(74) << "Enter 0 if you don't want to continue   :   ";

                            cin >> TempOption;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(512, '\n');
                                cout << endl
                                     << setw(110) << " It's a character. Please enter a number \n";
                            }

                            try
                            {
                                if ((TempOption < 0) || (TempOption > 6))
                                {
                                    throw(TempOption);
                                }

                                else if (TempOption != 0)
                                {
                                    depart = Departments(TempOption);
                                    call_department(depart); // calling friend functions
                                }
                            }

                            catch (int z)
                            {
                                cout << endl
                                     << endl
                                     << setw(74) << z << " No such category in departments" << endl
                                     << endl;
                            }

                        } while (TempOption != 0);
                    }

                    else if (option == 4)
                    {
                        TempOption = 0;

                        do
                        {
                            cout << endl
                                 << endl
                                 << setw(53) << "Enter 1 for Boys hostel" << endl;
                            cout << setw(55) << "Enter 2 for Girls hostels" << endl;
                            cout << setw(73) << "Enter 3 for Complete information on hostels" << endl;
                            cout << setw(45) << "Enter 0 to exit" << endl;
                            cout << setw(52) << "Enter your option  :  ";
                            cin >> TempOption;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(512, '\n');
                                cout << endl
                                     << setw(110) << " It's a character. Please enter a number \n";
                            }

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(512, '\n');
                                cout << endl
                                     << setw(70) << " It's a character. Please enter a number \n";
                            }
                            Hostels *hpointer; // base class pointer
                            BoysHostels boyshost;
                            GirlsHostels girlshost;

                            try
                            {
                                if ((TempOption < 0) || (TempOption > 3))
                                {
                                    throw(TempOption);
                                }

                                else if (TempOption == 1)
                                {
                                    hpointer = &boyshost; // derived class pointer
                                    hpointer->display();
                                }

                                else if (TempOption == 2)
                                {
                                    hpointer = &girlshost;
                                    hpointer->display();
                                }
                                else if (TempOption == 3)
                                {
                                    boyshost + girlshost; // operator overloading
                                }
                            }

                            catch (int x)
                            {
                                cout << endl
                                     << endl
                                     << setw(70) << x << " is Wrong option" << endl;
                            }

                        } while (TempOption != 0);
                    }

                    else if (option == 5)
                    {
                        CycleStands cycstnds;
                    }

                    else if (option == 6)
                    {
                        Academics acad;
                    }

                    else if (option == 7)
                    {
                        QuickFacts *pointer = new QuickFacts;

                        do
                        {
                            choice = pointer->display_fact();
                        } while ((choice == 'y') || (choice == 'Y'));

                        delete pointer;
                    }
                    else if (option == 0)
                        continue;
                }

                catch (int x)
                {
                    cout << endl
                         << endl;
                    cout.width(90);
                    cout << "No such category in PU" << endl
                         << endl;
                }
            } while (option != 0);
        }
    }
    else if(psswrd==0)
    {
        cout<<"INCORRECT Password"<<endl;
    }

    return 0;
}