#include <iostream>
#include <ctime>
#include<stdlib.h>
#include <fstream>
using namespace std;
struct plyr {
    string name;
    int wins = 0;

}; struct plyr a;


plyr pWin;


char box[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };


void shape1();


void shape2();


void show_box();


void player_1();


void player_2();


void player_c();


void computer_ch();


int count_box(char symbol);


char winner();


void cm_vs_pl();


void pl_vsp_l();



int main()
{
    shape1();
    cout << "#WELCOME#\n";
    shape2();
    char ch;
    do {
        int a;
        cout << "\n\n--> Please select your mode! \n" << endl;
        cout << " --> Press 1 to play Computer vs player mode**" << endl;
        cout << " --> press 2 to play player vs player mode" << endl;
        box[0] = ' ';
        box[1] = ' ';
        box[2] = ' ';
        box[3] = ' ';
        box[4] = ' ';
        box[5] = ' ';
        box[6] = ' ';
        box[7] = ' ';
        box[8] = ' ';
        int v;
        cin >> v;
        switch (v)
        {
        case 1:
            cm_vs_pl();
            break;
        case 2:
            pl_vsp_l();
            break;
        case 3:

            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
        cout << "\n\n--> Please press (r) or (R) to play again and (e) or (E) to exit: " << endl;
        cin >> ch;
    } while (ch == 'r' || ch == 'R');
    return 0;
}


void cm_vs_pl() {

    string name;
    cout << "--> PleaseEnter your Name Please :";
    cin >> name;
    while (true) {
        system("cls");
        show_box();
        if (count_box('X') == count_box('O')) {
            cout << name << "'s turn:" << endl;
            player_c();
        }
        else {
            computer_ch();
        }
        char w = winner();
        if (w == 'X') {
            show_box();
            cout << "||Congrates!|| " << name << " Won!" << endl;
            break;
        }
        else if (w == 'O') {
            show_box();
            cout << " Computer Won !" << endl;
            break;
        }
        else if (w == 'D') {
            show_box();
            cout << "Game is Draw!" << endl;
            break;

        }

    }
}
void pl_vsp_l() {
    system("cls");
    string name1;
    string name2;
    cout << "--> Please enter player [1] name :";
    cin >> name1;
    cout << "--> Please enter player [2] name :";
    cin >> name2;
    while (true) {
        int k = 0;
        system("cls");
        show_box();
        if (count_box('X') == count_box('O')) {
            cout << name1 << "'s turn:" << endl;
            player_1();
            system("cls");
            show_box();
            k++;

            char w = winner();


            if (w == 'X') {
                system("cls");
                show_box();
                pWin.name = name1;
                pWin.wins = pWin.wins + 1;

                cout << "||Congrates!|| " << pWin.name << " Won!" << endl;

                break;


            }
            else if (w == 'O') {
                system("cls");
                show_box();

                pWin.name = name1;
                pWin.wins = pWin.wins + 1;

                cout << "||Congrates!|| " << pWin.name << " Won!" << endl;
                break;
            }
            else if (w == 'D') {
                system("cls");
                show_box();
                cout << "Game is Draw!" << endl;
                break;
            }

        }
        if (k > 0) {
            k--;
            cout << name2 << "'s turn:" << endl;
            player_2();
            system("cls");
            show_box();


            char w = winner();


            if (w == 'X') {
                system("cls");
                show_box();
                pWin.name = name1;
                pWin.wins = pWin.wins + 1;

                cout << "||Congrates!|| " << pWin.name << " Won!" << endl;

                break;


            }
            else if (w == 'O') {
                system("cls");
                show_box();

                pWin.name = name2;
                pWin.wins = pWin.wins + 1;

                cout << "||Congrates!|| " << pWin.name << " Won!" << endl;
                break;
            }
            else if (w == 'D') {
                system("cls");
                show_box();
                cout << "Game is Draw!" << endl;
                break;
            }




        }

    }
}



void show_box() {
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << box[0] << "   |   " << box[1] << "   |   " << box[2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "------------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << box[3] << "   |   " << box[4] << "   |   " << box[5] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "------------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << box[6] << "   |   " << box[7] << "   |   " << box[8] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
}


void player_1() {
    while (true) {
        if (count_box('X') == 3) {
            int k;
            cout << "--> Your symbol is 'X' select any box Where 'X' is present to change its position: \n";
            cin >> k;
            k--;
            if (box[k] != 'X') {
                cout << "--> Please select Box Where 'X' is present:\n";
            }
            else
                box[k] = ' ';
        }
        cout << "--> Your symbol is 'X' Select your Box (1-9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "--> Please select number b/w (1-9) :" << endl;
        }
        else if (box[choice] != ' ') {
            cout << "--> Please select an empty position in the box:" << endl;
        }
        else {
            box[choice] = 'X';
            break;
        }


    }
}
void player_c() {



    while (true) {
        cout << "--> Your symbol is X Select your box (1-9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "--> Please select number b/w (1-9) :" << endl;
        }
        else if (box[choice] != ' ') {
            cout << "--> Please select an empty position in the box:" << endl;
        }
        else {
            box[choice] = 'X';
            break;
        }
    }
}




void player_2() {
    while (true) {
        if (count_box('O') == 3) {
            int k;
            cout << "--> Your symbol is 'O' select any box Where 'O' is present to change its position: \n";
            cin >> k;
            k--;
            if (box[k] != 'O') {
                cout << "--> Please select Box Where 'O' is present:\n";
            }
            else
                box[k] = ' ';
        }
        cout << "--> Your symbol is 'O' Select your box (1-9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "--> Please select number b/w (1-9):" << endl;
        }
        else if (box[choice] != ' ') {
            cout << "Please select an empty position in the box:" << endl;
        }
        else {
            box[choice] = 'O';
            break;


        }
    }
}
void computer_ch() {

    int choice;
    do {
        choice = rand() % 10;
        choice = choice - 1;
    } while (box[choice] != ' ');
    box[choice] = 'O';
}


int count_box(char symbol) {
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (box[i] == symbol)
            total += 1;
    }
    return total;
}
char winner()
{


    if (box[0] == box[1] && box[1] == box[2] && box[0] != ' ') {
        return box[0];
    }
    if (box[3] == box[4] && box[4] == box[5] && box[3] != ' ') {
        return box[3];
    }
    if (box[6] == box[7] && box[7] == box[8] && box[6] != ' ') {
        return box[6];
    }
    if (box[0] == box[3] && box[3] == box[6] && box[0] != ' ') {
        return box[0];
    }
    if (box[1] == box[4] && box[4] == box[7] && box[1] != ' ') {
        return box[1];
    }
    if (box[2] == box[5] && box[5] == box[8] && box[2] != ' ') {
        return box[2];
    }
    if (box[0] == box[4] && box[4] == box[8] && box[0] != ' ') {
        return box[0];
    }
    if (box[2] == box[4] && box[4] == box[6] && box[2] != ' ') {
        return box[2];

    }
    if (count_box('X') + count_box('O') < 9) {
        return 'C';
    }
    else {
        return 'D';
    }


}
void shape1() {
    int i;

    for (i = 0; i < 9; i++) {
        cout << "#";
        if (i == 8) {
            cout << endl;
        }


    }
}

void shape2() {
    int i;
    for (i = 0; i < 9; i++) {
        cout << "#";
        if (i == 8) {
            cout << endl;
        }
    }
}