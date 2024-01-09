#include <fstream>
#include <iostream>

using namespace std;

void talon();

void exposee();

void posee(){
    char mot;
    cin >> mot;

    //vérifier si le mot posé par l'utilisateur est bien présent dans le dictionnaire
    ifstream dictionnaire("ods4.txt");
    char motDico;

    bool est_present = false;

    while( dictionnaire >> motDico ){
        if ( motDico == mot){
            est_present = true;
        }
    }

    if (est_present){
        //poser le mot sur la table
    }
};

void completer();

void remplacer();

