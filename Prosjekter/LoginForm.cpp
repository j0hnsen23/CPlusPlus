#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loggeInn(){
    string brukernavn, passord, bruker, pass;

    cout << "Skriv inn brukernavn: "; cin >> brukernavn;
    cout << "Skriv inn passord: "; cin >> passord;

    ifstream read(brukernavn + ".txt");

    if(!read){
        return false;
    }
    
    getline(read, bruker);
    getline(read, pass);

    if(bruker == brukernavn && pass == passord){
        return true;
    }

    else{
        return false;
    }
}

int main(){
    int valg;

    cout << "Velg, hva du vil gjoere\n1: Registrere\n2: Logg inn\n Ditt valg: ";
    cin >> valg;
    if(valg == 1){
        string brukernavn, passord;

        cout << "Velg et brukernavn: "; cin >> brukernavn;
        cout << "Velg et passord: "; cin >> passord;

        ofstream fil;
        fil.open(brukernavn + ".txt");
        fil << brukernavn << endl << passord;
        fil.close();

        main();
    }

    else if(valg == 2){
        bool status = loggeInn();
        if(!status){
            cout << "Feil innlogging, Proev igjen!" << endl;
        } else {
            cout << "Riktig innlogging! Bra jobbet!" << endl;
        }

        cin.get();
        cin.get();
        return 0;
}
}