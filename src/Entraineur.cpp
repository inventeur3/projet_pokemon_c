#include <iostream>

#include "Entraineur.h"

using namespace std;


Entraineur::Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4,
            Pokemon poke5, Pokemon poke6, string mes) {
    nomEntraineur = n1;
    pokemons = new Pokemon[6];
    nbPokemons = 0;
    if (poke1.estValide()) pokemons[nbPokemons++] = poke1;
    if (poke2.estValide()) pokemons[nbPokemons++] = poke2;
    if (poke3.estValide()) pokemons[nbPokemons++] = poke3;
    if (poke4.estValide()) pokemons[nbPokemons++] = poke4;
    if (poke5.estValide()) pokemons[nbPokemons++] = poke5;
    if (poke6.estValide()) pokemons[nbPokemons++] = poke6;
    indexActuel = 0;
    actif = nullptr;
    message = mes;
    victoire = false;
}
bool Entraineur::estCapableDeCombattre(){
    return (indexActuel < nbPokemons);
}
Entraineur::~Entraineur() {
    for (int i = 0; i < 6; i++){
        pokemons[i].~Pokemon();
    }
    pokemons = nullptr;
    actif = nullptr;
}

void Entraineur::entrantEnCombat() {
    indexActuel = 0;
    if (nbPokemons > 0) {
        actif = &pokemons[indexActuel];
        summon2(*actif);
    } else {
        cout << nomEntraineur << " n’a pas de Pokémon pour commencer le combat !" << endl;
    }
}

void Entraineur::summon2(Pokemon& p) {
    p.Summon();
    PV = p.getPVmax();
}

int Entraineur::getDegat() const { return actif->getDeg(); }
string Entraineur::getType1() const { return actif->getType1(); }
string Entraineur::getType2() const { return actif->getType2(); }
Pokemon* Entraineur::getActif() const { return actif; }
string Entraineur::getNomEntraineur() const {return nomEntraineur;}

void Entraineur::attaque(Entraineur& cible) {
    cout << actif->getNom() << " attaque " << cible.getActif()->getNom()
            << " avec " << actif->getAttaque() << "." << endl;
    cible.receivedDamage(*this);
}

void Entraineur::receivedDamage(Entraineur& attaquant) {
    float multiplicateur = 1.0;
    string typeAtt1 = attaquant.getType1();
    string typeAtt2 = attaquant.getType2();
    int degatsAdverses = attaquant.getDegat();

    for (int i = 0; i < actif->getNbFaib(); i++) {
        if (actif->getFaib()[i] == typeAtt1 || actif->getFaib()[i] == typeAtt2) {
            multiplicateur *= 2.0;
            break;
        }
    }
    for (int i = 0; i < actif->getNbRes(); i++) {
        if (actif->getRes()[i] == typeAtt1 || actif->getRes()[i] == typeAtt2) {
            multiplicateur *= 0.5;
            break;
        }
    }

    int degatsFinaux = static_cast<int>(degatsAdverses * multiplicateur);
    PV -= degatsFinaux;

    cout << actif->getNom() << " a subi " << degatsFinaux << " dégâts." << endl;

    if (PV <= 0) {
        actif->unsummon();
        indexActuel++;
        if (indexActuel < nbPokemons) {
            cout << "Le prochain Pokémon entre en combat !" << endl;
            actif = &pokemons[indexActuel];
            summon2(*actif);
        } else {
            cout << "Tous les Pokémon de " << nomEntraineur << " sont K.O. !" << endl;
            finCombat();
        }
    }
}

void Entraineur::finCombat() {
    victoire = true;
    cout << nomEntraineur << " est vaincu!" << endl;
}

bool Entraineur::interagir(Entraineur& e) {
    if (victoire) {
        cout << message << endl;
    }
    return false;
}

Joueur::Joueur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
        Pokemon poke4, Pokemon poke5, Pokemon poke6)
    : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6) {
    nbBadges = 0;
    nbCombatsGagnes = 0;
    nbCombatsPerdus = 0;
}


int Joueur::getBadges() const { return nbBadges; }
int Joueur::getCombatsGagnes() const { return nbCombatsGagnes; }
int Joueur::getCombatsPerdus() const { return nbCombatsPerdus; }

void Joueur::ajouterVictoire() { nbCombatsGagnes++; }
void Joueur::ajouterDefaite() { nbCombatsPerdus++; }
void Joueur::ajouterBadge() { nbBadges++; }

Pokemon* Joueur::getPokemon(int i) { return &pokemons[i]; }

void Joueur::ordre() {
    cout << "Ordre actuel des Pokémon : " << endl;
    for (int i = 0; i < nbPokemons; i++) {
        cout << i + 1 << ". " << pokemons[i].getNom() << endl;
    }

    cout << "Entrez le nouvel ordre des Pokémon (" << nbPokemons << " numéros entre 1 et " << nbPokemons << ", séparés par des espaces) : " << endl;
    int nouvelOrdre[6];
    for (int i = 0; i < nbPokemons; i++) {
        cin >> nouvelOrdre[i];
    }

    bool valide = true;
    bool dejaVu[6] = {false, false, false, false, false, false};

    for (int i = 0; i < nbPokemons; i++) {
        if (nouvelOrdre[i] < 1 || nouvelOrdre[i] > nbPokemons || dejaVu[nouvelOrdre[i] - 1]) {
            valide = false;
            break;
        }
        dejaVu[nouvelOrdre[i] - 1] = true;
    }

    if (valide) {
        Pokemon tempEquipe[nbPokemons];
        for (int i = 0; i < nbPokemons; i++) {
            tempEquipe[i] = pokemons[nouvelOrdre[i] - 1];
        }
        for (int i = 0; i < nbPokemons; i++) {
            pokemons[i] = tempEquipe[i];
        }
        cout << "L'ordre a été mis à jour avec succès !" << endl;
    } else {
        cout << "Ordre invalide. Assurez-vous d'utiliser les numéros de 1 à " << nbPokemons << " sans doublons." << endl;
    }

    cout << "Nouvel ordre des Pokémon :" << endl;
    for (int i = 0; i < nbPokemons; i++) {
        cout << i + 1 << ". " << pokemons[i].getNom() << endl;
    }
}

bool Joueur::interagir(Leader& leader) {
    if (leader.interagir(*this)) {
        ajouterBadge();
    }
    return false;
}
bool Joueur::interagir(Entraineur& e){
    e.interagir(*this);
    return false;
}

void Joueur::afficher() {
    for (int i = 0; i < nbPokemons; i++) {
        cout << "Pokémon " << i + 1 << " : " << endl;
        this->pokemons[i].afficher();
    }
}

Leader::Leader(string n1, string nomGym, string badge,
        Pokemon poke1, Pokemon poke2, Pokemon poke3,
        Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes)
    : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6, mes) {
    gymnase = nomGym;
    medaille = badge;
    badgeAccorde = true;
}

string Leader::getGymnase() const {
    return gymnase;
}

string Leader::getMedaille() const {
    return medaille;
}

void Leader::accorderMedaille(Entraineur& joueur) {
    cout << nomEntraineur << " remet la médaille " << medaille
            << " à " << joueur.getNomEntraineur() << "." << endl;
}

bool Leader::interagir(Entraineur& joueur){
    if (victoire) {
        if (badgeAccorde) {
            accorderMedaille(joueur);
            badgeAccorde = false;
            return true;
        }
        else{
            cout << message << endl;
            return false;
        }
    }
    else{
        cout << "Tu n'as pas battu ce leader reviens quand ça sera fait!" << endl;
        return false;
    }
}


Maitre::Maitre(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
        Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes)
    :Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6, mes) {}


void Joueur::receivedDamage(Maitre& attaquant){
    float multiplicateur = 1.25;
    string typeAtt1 = attaquant.getType1();
    string typeAtt2 = attaquant.getType2();
    int degatsAdverses = attaquant.getDegat();

    for (int i = 0; i < actif->getNbFaib(); i++) {
        if (actif->getFaib()[i] == typeAtt1 || actif->getFaib()[i] == typeAtt2) {
            multiplicateur *= 2.0;
            break;
        }
    }
    for (int i = 0; i < actif->getNbRes(); i++) {
        if (actif->getRes()[i] == typeAtt1 || actif->getRes()[i] == typeAtt2) {
            multiplicateur *= 0.5;
            break;
        }
    }

    int degatsFinaux = static_cast<int>(degatsAdverses * multiplicateur);
    PV -= degatsFinaux;

    cout << actif->getNom() << " a subi " << degatsFinaux << " dégâts." << endl;

    if (PV <= 0) {
        actif->unsummon();
        indexActuel++;
        if (indexActuel < nbPokemons) {
            cout << "Le prochain Pokémon entre en combat !" << endl;
            actif = &pokemons[indexActuel];
            summon2(*actif);
        } else {
            cout << "Tous les Pokémon de " << nomEntraineur << " sont K.O. !" << endl;
            finCombat();
        }
    }
}
