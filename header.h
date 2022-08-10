#include <iostream> // char_code
using namespace std;

// function to print pu_info on screen
void print_pu_info(char chr_code)
{

    int char_code = int(chr_code);
    int arr_P[5][5], arr_U[5][5], arr_I[5][5], arr_N[5][5], arr_F[5][5], arr_O[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0 || ((i == 0 || i == 2) && j != 4) || (i == 1 && j == 4))
                arr_P[i][j] = char_code;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (((j == 0 || j == 4) && i != 4) || (i == 4 && j != 0 && j != 4))
                arr_U[i][j] = char_code;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 4 || j == 2)
                arr_I[i][j] = char_code;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j || j == 0 || j == 4)
                arr_N[i][j] = char_code;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0 || i == 0 || (i == 2 && j < 3))
                arr_F[i][j] = char_code;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (((i == 0 || i == 4) && j != 0 && j != 4) || ((j == 0 || j == 4) && i != 0 && i != 4))
                arr_O[i][j] = char_code;
        }
    }

    // printing pu info
    for (int i = 0; i < 5; i++)
    {
        cout.width(70);

        for (int j = 0; j < 5; j++)
        {
            if (arr_P[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }
        cout << '\t';
        for (int j = 0; j < 5; j++)
        {
            if (arr_U[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }

        cout << "\t\t\t";
        for (int j = 0; j < 5; j++)
        {
            if (arr_I[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }

        cout << '\t';
        for (int j = 0; j < 5; j++)
        {
            if (arr_N[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }

        cout << '\t';
        for (int j = 0; j < 5; j++)
        {
            if (arr_F[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }

        cout << '\t';
        for (int j = 0; j < 5; j++)
        {
            if (arr_O[i][j] == char_code)
                cout << char(char_code);
            else
                cout << " ";
        }
        cout << endl;
    }
}

// function to print thanks on screen
void thanks()
{
    cout << endl;
    cout.width();
    cout << setw(113) << "=========================" << endl;
    cout << setw(135) << "~-~-~-~-~-~-~-~-~-~ || THANKS FOR VISITING || ~-~-~-~-~-~-~-~-~-~-~" << endl;
    cout << setw(113) << "=========================" << endl;
}

void displayTeam8()
{
    cout << endl
         << endl;
    cout << "~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~ Team Members ~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~" << endl
         << endl;
    map<string, int> team8Members;
    team8Members["Avjeet Rathi ~ UE"] = 213021;
    team8Members["DamanPreet Singh ~ UE"] = 213028;
    team8Members["Devansh Shekhar Shukla ~ UE"] = 213031;
    team8Members["Devinder Kumar ~ UE"] = 213032;
    team8Members["Dhruv Goyal ~ UE"] = 213034;
    team8Members["Eros Dhillon ~ UE"] = 213035;
    map<string, int>::iterator iter;
    for (iter = team8Members.begin(); iter != team8Members.end(); iter++)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t" << iter->first << iter->second << endl;
    }
}