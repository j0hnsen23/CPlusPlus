#include <iostream>
using namespace std;

int main() {
    char brett[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char spillerX = 'X';
    const char spillerO = 'O';
    char naavaerendeSpiller = spillerX;
    int rad = -1;
    int kolonne = -1;
    char vinner = ' ';

    for (int i = 0; i < 9; i++) {
        // Skriv ut brettet
        cout << "   |   |   " << endl;
        cout << " " << brett[0][0] << " | " << brett[0][1] << " | " << brett[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << brett[1][0] << " | " << brett[1][1] << " | " << brett[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << brett[2][0] << " | " << brett[2][1] << " | " << brett[2][2] << endl;
        cout << "   |   |   " << endl;

        // Få inn brukerinput
        cout << "Naavaerende spiller er " << naavaerendeSpiller << endl;
        while (true) {
            cout << "Skriv inn rad, deretter kolonne 0-2: ";
            cin >> rad >> kolonne;

            if (rad < 0 || rad > 2 || kolonne < 0 || kolonne > 2) {
                cout << "Ikke gyldig input, proev igjen!" << endl;
            }
            else if (brett[rad][kolonne] != ' ') {
                cout << "Ruten er full, proev igjen!" << endl;
            }
            else {
                break;
            }

            rad = -1;
            kolonne = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Sett brikke
        brett[rad][kolonne] = naavaerendeSpiller;

        // Sjekk vinner

        // Horisontalt
        for (int r = 0; r < 3; r++) {
            if (brett[r][0] != ' ' && brett[r][0] == brett[r][1] && brett[r][1] == brett[r][2]) {
                vinner = brett[r][0];
                break;
            }
        }

        // Vertikalt
        if (vinner == ' ') {
            for (int c = 0; c < 3; c++) {
                if (brett[0][c] != ' ' && brett[0][c] == brett[1][c] && brett[1][c] == brett[2][c]) {
                    vinner = brett[0][c];
                    break;
                }
            }
        }

        // Diagonalt
        if (vinner == ' ') {
            if (brett[0][0] != ' ' && brett[0][0] == brett[1][1] && brett[1][1] == brett[2][2]) {
                vinner = brett[0][0];
            }
            else if (brett[0][2] != ' ' && brett[0][2] == brett[1][1] && brett[1][1] == brett[2][0]) {
                vinner = brett[0][2];
            }
        }

        // Avslutt hvis noen vant
        if (vinner != ' ') {
            break;
        }

        // Bytt spiller bare hvis ingen vant
        naavaerendeSpiller = (naavaerendeSpiller == spillerX) ? spillerO : spillerX;
    }

    // Skriv ut sluttbrettet
    cout << "   |   |   " << endl;
    cout << " " << brett[0][0] << " | " << brett[0][1] << " | " << brett[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << brett[1][0] << " | " << brett[1][1] << " | " << brett[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << brett[2][0] << " | " << brett[2][1] << " | " << brett[2][2] << endl;
    cout << "   |   |   " << endl;

    if (vinner != ' ') {
        cout << "Spiller " << vinner << " er vinneren!" << endl;
    }
    else {
        cout << "Uavgjort!" << endl;
    }

    return 0;
}