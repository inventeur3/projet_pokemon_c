#include <iostream>
#include <string>
#include "Pokemon.h"


using namespace std;

void Pokemon::SetFaibRes(string t1, string t2) {
                int nbF1 = 0;
                int nbF2 = 0;
                int nbR1 = 0;
                int nbR2 = 0;
                string* f1 = nullptr;
                string* f2 = nullptr;
                string* r1 = nullptr;
                string* r2 = nullptr;
                if (t1 == "Feu"){
                        nbF1 = 3;
                        nbR1 = 5;
                        f1 = new string[3];
                        r1 = new string[5];
                        f1[0] = "Eau";
                        f1[1] = "Roche";
                        f1[2] = "Sol";
                        r1[0] = "Plante";
                        r1[1] = "Glace";
                        r1[2] = "Insecte";
                        r1[3] = "Acier";
                        r1[4] = "Fée";
                }
                else if (t1 == "Eau"){
                        nbF1 = 2;
                        nbR1 = 4;
                        f1 = new string[2];
                        r1 = new string[4];
                        f1[0] = "Plante";
                        f1[1] = "Électrik";
                        r1[0] = "Feu";
                        r1[1] = "Eau";
                        r1[2] = "Glace";
                        r1[3] = "Acier";
                }
                else if (t1 == "Plante"){
                        nbF1 = 5;
                        nbR1 = 3;
                        f1 = new string[5];
                        r1 = new string[3];
                        f1[0] = "Feu";
                        f1[1] = "Glace";
                        f1[2] = "Poison";
                        f1[3] = "Vol";
                        f1[4] = "Insecte";
                        r1[0] = "Eau";
                        r1[1] = "Sol";
                        r1[2] = "Roche";
                }
                else if (t1 == "Électrik"){
                        nbF1 = 1;
                        nbR1 = 3;
                        f1 = new string[1];
                        r1 = new string[3];
                        f1[0] = "Sol";
                        r1[0] = "Vol";
                        r1[1] = "Acier";
                        r1[2] = "Électrik";
                }
                else if (t1 == "Glace"){
                        nbF1 = 4;
                        nbR1 = 1;
                        f1 = new string[4];
                        r1 = new string[1];
                        f1[0] = "Feu";
                        f1[1] = "Combat";
                        f1[2] = "Roche";
                        f1[3] = "Acier";
                        r1[0] = "Glace";
                }
                else if (t1 == "Combat"){
                        nbF1 = 3;
                        nbR1 = 3;
                        f1 = new string[3];
                        r1 = new string[3];
                        f1[0] = "Vol";
                        f1[1] = "Psy";
                        f1[2] = "Fée";
                        r1[0] = "Roche";
                        r1[1] = "Insecte";
                        r1[2] = "Ténèbres";
                }
                else if (t1 == "Poison"){
                        nbF1 = 2;
                        nbR1 = 5;
                        f1 = new string[2];
                        r1 = new string[5];
                        f1[0] = "Sol";
                        f1[1] = "Psy";
                        r1[0] = "Plante";
                        r1[1] = "Fée";
                        r1[2] = "Combat";
                        r1[3] = "Poison";
                        r1[4] = "Insecte";
                }
                else if (t1 == "Sol"){
                        nbF1 = 3;
                        nbR1 = 2;
                        f1 = new string[3];
                        r1 = new string[2];
                        f1[0] = "Eau";
                        f1[1] = "Plante";
                        f1[2] = "Glace";
                        r1[0] = "Poison";
                        r1[1] = "Roche";
                }
                else if (t1 == "Vol"){
                        nbF1 = 3;
                        nbR1 = 3;
                        f1 = new string[3];
                        r1 = new string[3];
                        f1[0] = "Électrik";
                        f1[1] = "Glace";
                        f1[2] = "Roche";
                        r1[0] = "Plante";
                        r1[1] = "Combat";
                        r1[2] = "Insecte";
                }
                else if (t1 == "Psy"){
                        nbF1 = 3;
                        nbR1 = 2;
                        f1 = new string[3];
                        r1 = new string[2];
                        f1[0] = "Insecte";
                        f1[1] = "Spectre";
                        f1[2] = "Ténèbres";
                        r1[0] = "Combat";
                        r1[1] = "Psy";
                }
                else if (t1 == "Insecte"){
                        nbF1 = 3;
                        nbR1 = 3;
                        f1 = new string[3];
                        r1 = new string[3];
                        f1[0] = "Feu";
                        f1[1] = "Vol";
                        f1[2] = "Roche";
                        r1[0] = "Plante";
                        r1[1] = "Combat";
                        r1[2] = "Sol";
                }
                else if (t1 == "Roche"){
                        nbF1 = 5;
                        nbR1 = 4;
                        f1 = new string[5];
                        r1 = new string[4];
                        f1[0] = "Eau";
                        f1[1] = "Plante";
                        f1[2] = "Combat";
                        f1[3] = "Sol";
                        f1[4] = "Acier";
                        r1[0] = "Feu";
                        r1[1] = "Vol";
                        r1[2] = "Poison";
                        r1[3] = "Normal";
                }
                else if (t1 == "Spectre"){
                        nbF1 = 2;
                        nbR1 = 2;
                        f1 = new string[2];
                        r1 = new string[2];
                        f1[0] = "Spectre";
                        f1[1] = "Ténèbres";
                        r1[0] = "Poison";
                        r1[1] = "Insecte";
                }
                else if (t1 == "Dragon"){
                        nbF1 = 3;
                        nbR1 = 4;
                        f1 = new string[3];
                        r1 = new string[4];
                        f1[0] = "Glace";
                        f1[1] = "Dragon";
                        f1[2] = "Fée";
                        r1[0] = "Feu";
                        r1[1] = "Eau";
                        r1[2] = "Électrik";
                        r1[3] = "Plante";
                }
                else if (t1 == "Ténèbres"){
                        nbF1 = 3;
                        nbR1 = 3;
                        f1 = new string[3];
                        r1 = new string[3];
                        f1[0] = "Combat";
                        f1[1] = "Insecte";
                        f1[2] = "Fée";
                        r1[0] = "Spectre";
                        r1[1] = "Psy";
                        r1[2] = "Ténèbres";
                }
                else if (t1 == "Acier"){
                        nbF1 = 3;
                        nbR1 = 10;
                        f1 = new string[3];
                        r1 = new string[10];
                        f1[0] = "Feu";
                        f1[1] = "Combat";
                        f1[2] = "Sol";
                        r1[0] = "Normal";
                        r1[1] = "Plante";
                        r1[2] = "Glace";
                        r1[3] = "Vol";
                        r1[4] = "Psy";
                        r1[5] = "Insecte";
                        r1[6] = "Roche";
                        r1[7] = "Dragon";
                        r1[8] = "Acier";
                        r1[9] = "Fée";
                }
                else if (t1 == "Fée"){
                        nbF1 = 2;
                        nbR1 = 4;
                        f1 = new string[2];
                        r1 = new string[4];
                        f1[0] = "Poison";
                        f1[1] = "Acier";
                        r1[0] = "Combat";
                        r1[1] = "Insecte";
                        r1[2] = "Ténèbres";
                        r1[3] = "Dragon";
                }
                else{
                        f1 = new string[0];
                        r1 = new string[0];
                        if (t1 != "Normal"){
                                valid = false;
                        }
                }
                if (t2 == "Feu"){
                        nbF2 = 3;       
                        nbR2 = 5;
                        f2 = new string[3];
                        r2 = new string[5];
                        f2[0] = "Eau";
                        f2[1] = "Roche";
                        f2[2] = "Sol";
                        r2[0] = "Plante";
                        r2[1] = "Glace";
                        r2[2] = "Insecte";
                        r2[3] = "Acier";
                        r2[4] = "Fée";
                }
                else if (t2 == "Eau"){
                        nbF2 = 2;
                        nbR2 = 4;
                        f2 = new string[2];
                        r2 = new string[4];
                        f2[0] = "Plante";
                        f2[1] = "Électrik";
                        r2[0] = "Feu";
                        r2[1] = "Eau";
                        r2[2] = "Glace";
                        r2[3] = "Acier";
                }
                else if (t2 == "Plante"){
                        nbF2 = 5;
                        nbR2 = 3;
                        f2 = new string[5];
                        r2 = new string[3];
                        f2[0] = "Feu";
                        f2[1] = "Glace";
                        f2[2] = "Poison";
                        f2[3] = "Vol";
                        f2[4] = "Insecte";
                        r2[0] = "Eau";
                        r2[1] = "Sol";
                        r2[2] = "Roche";
                }
                else if (t2 == "Électrik"){
                        nbF2 = 1;
                        nbR2 = 3;
                        f2 = new string[1];
                        r2 = new string[3];
                        f2[0] = "Sol";
                        r2[0] = "Vol";
                        r2[1] = "Acier";
                        r2[2] = "Électrik";
                }
                else if (t2 == "Glace"){
                        nbF2 = 4;
                        nbR2 = 1;
                        f2 = new string[4];
                        r2 = new string[1];
                        f2[0] = "Feu";
                        f2[1] = "Combat";
                        f2[2] = "Roche";
                        f2[3] = "Acier";
                        r2[0] = "Glace";
                }
                else if (t2 == "Combat"){
                        nbF2 = 3;
                        nbR2 = 3;
                        f2 = new string[3];
                        r2 = new string[3];
                        f2[0] = "Vol";
                        f2[1] = "Psy";
                        f2[2] = "Fée";
                        r2[0] = "Roche";
                        r2[1] = "Insecte";
                        r2[2] = "Ténèbres";
                }
                else if (t2 == "Poison"){
                        nbF2 = 2;
                        nbR2 = 5;
                        f2 = new string[2];
                        r2 = new string[5];
                        f2[0] = "Sol";
                        f2[1] = "Psy";
                        r2[0] = "Plante";
                        r2[1] = "Fée";
                        r2[2] = "Combat";
                        r2[3] = "Poison";
                        r2[4] = "Insecte";
                }
                else if (t2 == "Sol"){
                        nbF2 = 3;
                        nbR2 = 2;
                        f2 = new string[3];
                        r2 = new string[2];
                        f2[0] = "Eau";
                        f2[1] = "Plante";
                        f2[2] = "Glace";
                        r2[0] = "Poison";
                        r2[1] = "Roche";
                }
                else if (t2 == "Vol"){
                        nbF2 = 3;
                        nbR2 = 3;
                        f2 = new string[3];
                        r2 = new string[3];
                        f2[0] = "Électrik";
                        f2[1] = "Glace";
                        f2[2] = "Roche";
                        r2[0] = "Plante";
                        r2[1] = "Combat";
                        r2[2] = "Insecte";
                }
                else if (t2 == "Psy"){
                        nbF2 = 3;
                        nbR2 = 2;
                        f2 = new string[3];
                        r2 = new string[2];
                        f2[0] = "Insecte";
                        f2[1] = "Spectre";
                        f2[2] = "Ténèbres";
                        r2[0] = "Combat";
                        r2[1] = "Psy";
                }
                else if (t2 == "Insecte"){
                        nbF2 = 3;
                        nbR2 = 3;
                        f2 = new string[3];
                        r2 = new string[3];
                        f2[0] = "Feu";
                        f2[1] = "Vol";
                        f2[2] = "Roche";
                        r2[0] = "Plante";
                        r2[1] = "Combat";
                        r2[2] = "Sol";
                }
                else if (t2 == "Roche"){
                        nbF2 = 5;
                        nbR2 = 4;
                        f2 = new string[5];
                        r2 = new string[4];
                        f2[0] = "Eau";
                        f2[1] = "Plante";
                        f2[2] = "Combat";
                        f2[3] = "Sol";
                        f2[4] = "Acier";
                        r2[0] = "Feu";
                        r2[1] = "Vol";
                        r2[2] = "Poison";
                        r2[3] = "Normal";
                }
                else if (t2 == "Spectre"){
                        nbF2 = 2;
                        nbR2 = 2;
                        f2 = new string[2];
                        r2 = new string[2];
                        f2[0] = "Spectre";
                        f2[1] = "Ténèbres";
                        r2[0] = "Poison";
                        r2[1] = "Insecte";
                }
                else if (t2 == "Dragon"){
                        nbF2 = 3;
                        nbR2 = 4;
                        f2 = new string[3];
                        r2 = new string[4];
                        f2[0] = "Glace";
                        f2[1] = "Dragon";
                        f2[2] = "Fée";
                        r2[0] = "Feu";
                        r2[1] = "Eau";
                        r2[2] = "Électrik";
                        r2[3] = "Plante";
                }
                else if (t2 == "Ténèbres"){
                        nbF2 = 3;
                        nbR2 = 3;
                        f2 = new string[3];
                        r2 = new string[3];
                        f2[0] = "Combat";
                        f2[1] = "Insecte";
                        f2[2] = "Fée";
                        r2[0] = "Spectre";
                        r2[1] = "Psy";
                        r2[2] = "Ténèbres";
                }
                else if (t2 == "Acier"){
                        nbF2 = 3;
                        nbR2 = 10;
                        f2 = new string[3];
                        r2 = new string[10];
                        f2[0] = "Feu";
                        f2[1] = "Combat";
                        f2[2] = "Sol";
                        r2[0] = "Normal";
                        r2[1] = "Plante";
                        r2[2] = "Glace";
                        r2[3] = "Vol";
                        r2[4] = "Psy";
                        r2[5] = "Insecte";
                        r2[6] = "Roche";
                        r2[7] = "Dragon";
                        r2[8] = "Acier";
                        r2[9] = "Fée";
                }
                else if (t2 == "Fée"){
                        nbF2 = 2;
                        nbR2 = 4;
                        f2 = new string[2];
                        r2 = new string[4];
                        f2[0] = "Poison";
                        f2[1] = "Acier";
                        r2[0] = "Combat";
                        r2[1] = "Insecte";
                        r2[2] = "Ténèbres";
                        r2[3] = "Dragon";
                }
                else if (t2 == "" or t2 == "Normal"){
                        f2 = new string[0];
                        r2 = new string[0];
                }
                else{
                        r2 = new string[0];
                        f2 = new string[0];
                        valid = false;
                }
                nbFaiblesses = nbF1 + nbF2;
                faiblesses = new string[nbFaiblesses];
                nbResistances = nbR1 + nbR2;
                resistances = new string[nbResistances];
                for (int i = 0; i < nbF1; i++){
                        faiblesses[i] = f1[i];
                }
                for (int i = 0; i < nbF2; i++){
                        faiblesses[nbF1 + i] = f2[i];
                }
                for (int i = 0; i < nbR1; i++){
                        resistances[i] = r1[i];
                }
                for (int i = 0; i < nbR2; i++){
                        resistances[nbR1 + i] = r2[i];
                }
                delete[] f1;
                delete[] f2;
                delete[] r1;
                delete[] r2;
                f1 = nullptr;
                f2 = nullptr;
                r1 = nullptr;
                r2 = nullptr;
        }

Pokemon::Pokemon(string nom, string t1, string t2, int maxPV, string nomA, int nbDeg, string mes) {
        name = nom;
        type1 = t1;
        type2 = t2;
        PVmax = maxPV;
        attaque = nomA;
        degats = nbDeg;
        message = mes;
        valid = (nom != "" && PVmax > 0 && nomA != "" && nbDeg > 0 && mes != "");
        SetFaibRes(t1, t2);
}
Pokemon::Pokemon(){
        valid = false;
        name = "";
        type1 = "";
        type2 = "";
        PVmax = -1;
        attaque = "";
        degats = 0;
        message = "";
        faiblesses = nullptr;
        resistances = nullptr;
        nbFaiblesses = 0;
        nbResistances = 0;
}

Pokemon::~Pokemon() {
        delete[] faiblesses;
        delete[] resistances;
        faiblesses = nullptr;
        resistances = nullptr;
}

void Pokemon::Summon() {
        cout << name << " est invoqué !" << endl;
}

int Pokemon::getPVmax() {
        return PVmax;
}

string Pokemon::getNom() {
        return name;
}

string Pokemon::getAttaque() {
        return attaque;
}

string Pokemon::getType1() {
        return type1;
}

string Pokemon::getType2() {
        return type2;
}

int Pokemon::getDeg() {
        return degats;
}

string* Pokemon::getFaib() {
        return faiblesses;
}

string* Pokemon::getRes() {
        return resistances;
}

void Pokemon::unsummon() {
        cout << name << " est K.O. !" << endl;
}

void Pokemon::Interagir() {
        cout << message << endl;
}

bool Pokemon::estValide() {
        return valid;
}

void Pokemon::afficher() {
        cout << "    Nom du Pokémon : " << name << endl;
        cout << "    Types          : " << type1 << "/" << type2 << endl;
        cout << "    PV             : " << PVmax << endl;
        cout << "    Attaque/dégâts : " << attaque << "/" << degats << endl;
}
Pokemon::Pokemon(const Pokemon& other) {
    name = other.name;
    type1 = other.type1;
    type2 = other.type2;
    PVmax = other.PVmax;
    attaque = other.attaque;
    degats = other.degats;
    message = other.message;
    valid = other.valid;
    nbFaiblesses = other.nbFaiblesses;
    nbResistances = other.nbResistances;

    // Copier les faiblesses
    if (nbFaiblesses >= 0 && other.faiblesses != nullptr) {
        faiblesses = new string[nbFaiblesses];
        for (int i = 0; i < nbFaiblesses; i++) {
            faiblesses[i] = other.faiblesses[i];
        }
    } else {
        faiblesses = new string[0];
    }

    // Copier les resistances
    if (nbResistances >= 0 && other.resistances != nullptr) {
        resistances = new string[nbResistances];
        for (int i = 0; i < nbResistances; i++) {
            resistances[i] = other.resistances[i];
        }
    } else {
        resistances = new string[0];
    }

    
}

int Pokemon::getNbFaib(){
        return nbFaiblesses;
        }


int Pokemon::getNbRes(){
        return nbResistances;
}

Pokemon& Pokemon::operator=(const Pokemon& other) {
    if (this != &other) {
        // Libérer la mémoire existante
        delete[] faiblesses;
        delete[] resistances;

        // Copier les champs simples
        name = other.name;
        type1 = other.type1;
        type2 = other.type2;
        PVmax = other.PVmax;
        attaque = other.attaque;
        degats = other.degats;
        message = other.message;
        valid = other.valid;
        nbFaiblesses = other.nbFaiblesses;
        nbResistances = other.nbResistances;

        // Allouer et copier les faiblesses 
        if (nbFaiblesses > 0 && other.faiblesses != nullptr) {
            faiblesses = new string[nbFaiblesses];
            for (int i = 0; i < nbFaiblesses; i++) {
                faiblesses[i] = other.faiblesses[i];
            }
        } else {
            faiblesses = nullptr;
        }

        // Allouer et copier les resistances
        if (nbResistances > 0 && other.resistances != nullptr) {
            resistances = new string[nbResistances];
            for (int i = 0; i < nbResistances; i++) {
                resistances[i] = other.resistances[i];
            }
        } else {
            resistances = nullptr;
        }
    }
    return *this;
}

