#include <iostream>

#include "Entraineur.h"

using namespace std;

Entraineur::Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4,//constructeur de la classe entraineur 
            Pokemon poke5, Pokemon poke6, string mes) {
    nomEntraineur = n1; //nom de l'entraineur 
    pokemons = new Pokemon[6];//On alloue dynamiquement un tableau de 6 Pokémon vides
    nbPokemons = 0;//Compteur du nombre de Pokémon valides réellement assignés.
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
    return (indexActuel < nbPokemons);//car index commence à 0 
}
Entraineur::~Entraineur() { //destructeur de la classe entraineur 
    for (int i = 0; i < 6; i++){ //Appelle explicitement le destructeur de chaque objet Pokemon du tableau pokemons 
        pokemons[i].~Pokemon();
    }
    pokemons = nullptr;
    actif = nullptr;
}

void Entraineur::entrantEnCombat() { //C'est une méthode publique de la classe Entraineur qui prépare un entraîneur pour un combat Pokémon.
    indexActuel = 0;
    if (nbPokemons > 0) {
        actif = &pokemons[indexActuel]; //On pointe le membre actif (qui est un pointeur vers le Pokémon actuellement en combat) vers le premier Pokémon (pokemons[0]).
        summon2(*actif);
    } else {
        cout << nomEntraineur << " n’a pas de Pokémon pour commencer le combat !" << endl;
    }
}

void Entraineur::summon2(Pokemon& p) {
    p.Summon();
    PV = p.getPVmax();
}

int Entraineur::getDegat() const { return actif->getDeg(); }//Cette méthode retourne les dégâts que peut infliger le Pokémon actuellement en combat (celui pointé par actif).
string Entraineur::getType1() const { return actif->getType1(); }//Elle retourne le premier type du Pokémon actif.
string Entraineur::getType2() const { return actif->getType2(); }
Pokemon* Entraineur::getActif() const { return actif; }//Elle retourne un pointeur vers le Pokémon actuellement en combat.

void Entraineur::attaque(Entraineur& cible) {//Cette méthode attaque de la classe Entraineur représente l'action d'un Pokémon attaquant le Pokémon actif d'un autre entraîneur
    cout << actif->getNom() << " attaque " << cible.getActif()->getNom()
            << " avec " << actif->getAttaque() << "." << endl;
    cible.receivedDamage(*this);//L'entraîneur ciblé (cible) subit les dégâts calculés à partir de l’entraîneur attaquant (this).
}

void Entraineur::receivedDamage(Entraineur& attaquant) {
    float multiplicateur = 1.0;
    string typeAtt1 = attaquant.getType1();//On récupère les types 1 et 2 du Pokémon attaquant.
    string typeAtt2 = attaquant.getType2();
    int degatsAdverses = attaquant.getDegat();//Et ses dégâts de base.

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

    int degatsFinaux = static_cast<int>(degatsAdverses * multiplicateur);//On applique le multiplicateur pour obtenir les dégâts réels infligés.
    PV -= degatsFinaux;//On enlève les dégâts aux points de vie actuels du Pokémon actif.

    cout << actif->getNom() << " a subi " << degatsFinaux << " dégâts." << endl;//Affiche le nom du Pokémon défenseur et les dégâts subis.

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

string Entraineur::getNomEntraineur() const { //Cette méthode permet d’obtenir le nom d’un objet de type Entraineur sans autoriser sa modification.
    return nomEntraineur;
}

bool Entraineur::interagir(Entraineur& e) {//La méthode interagir affiche un message si l'entraîneur a été vaincu, puis retourne toujours false.
    if (victoire) {
        cout << message << endl;
    }
    return false;
}

Joueur::Joueur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,//constructeur de Joueur 
        Pokemon poke4, Pokemon poke5, Pokemon poke6)
    : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6) {
    nbBadges = 0;
    nbCombatsGagnes = 0;
    nbCombatsPerdus = 0;
}


int Joueur::getBadges() const { return nbBadges; } //Ces trois méthodes permettent d'accéder aux attributs privés d’un objet Joueur 
int Joueur::getCombatsGagnes() const { return nbCombatsGagnes; }
int Joueur::getCombatsPerdus() const { return nbCombatsPerdus; }

void Joueur::ajouterVictoire() { nbCombatsGagnes++; }//Ces trois méthodes sont des mutateurs qui modifient l'état d'un objet Joueur.
void Joueur::ajouterDefaite() { nbCombatsPerdus++; }//Elles sont utilisées pour mettre à jour les statistiques du joueur après un combat ou une victoire contre un leader.
void Joueur::ajouterBadge() { nbBadges++; }

void Joueur::ordre() { //permet au joueur de réorganiser manuellement l’ordre de ses Pokémon
    cout << "Ordre actuel des Pokémon : " << endl;
    for (int i = 0; i < nbPokemons; i++) {
        cout << i + 1 << ". " << pokemons[i].getNom() << endl;
    }

    cout << "Entrez le nouvel ordre des Pokémon (" << nbPokemons << " numéros entre 1 et " << nbPokemons << ", séparés par des espaces) : " << endl;
    int nouvelOrdre[6]; //Crée un tableau pour stocker l’ordre demandé
    for (int i = 0; i < nbPokemons; i++) {
        cin >> nouvelOrdre[i];//Remplit le tableau nouvelOrdre avec les indices donnés par l’utilisateur.
    }

    bool valide = true;
    bool dejaVu[6] = {false, false, false, false, false, false};//et un tableau dejaVu pour s’assurer que chaque position est unique.

    for (int i = 0; i < nbPokemons; i++) { //vérifie si l'ordre des pokemons est valide 
        if (nouvelOrdre[i] < 1 || nouvelOrdre[i] > nbPokemons || dejaVu[nouvelOrdre[i] - 1]) {
            valide = false;
            break;
        }
        dejaVu[nouvelOrdre[i] - 1] = true;
    }

    if (valide) {
        Pokemon tempEquipe[nbPokemons];//On copie les Pokémon selon le nouvel ordre dans un tableau temporaire tempEquipe.
        for (int i = 0; i < nbPokemons; i++) {
            tempEquipe[i] = pokemons[nouvelOrdre[i] - 1];
        }
        for (int i = 0; i < nbPokemons; i++) {//On remplace l’équipe du joueur par celle réorganisée.
            pokemons[i] = tempEquipe[i];
        }
        cout << "L'ordre a été mis à jour avec succès !" << endl;
    } else {
        cout << "Ordre invalide. Assurez-vous d'utiliser les numéros de 1 à " << nbPokemons << " sans doublons." << endl;
    }

    cout << "Nouvel ordre des Pokémon :" << endl;//Affiche la liste des Pokémon dans leur nouvel ordre.
    for (int i = 0; i < nbPokemons; i++) {
        cout << i + 1 << ". " << pokemons[i].getNom() << endl;
    }
}

bool Joueur::interagir(Leader& leader) {//Cette fonction permet au joueur d'interagir avec un Leader ; si celui-ci a été vaincu et n’a pas encore remis sa médaille, alors il la remet et le joueur obtient un badge supplémentaire.
    if (leader.interagir(*this)) {
        ajouterBadge();
    }
    return false;
}

bool Joueur::interagir(Entraineur& e){//Cette fonction permet au joueur d’interagir avec un entraîneur, mais elle ignore la valeur de retour de e.interagir et retourne toujours false.
    e.interagir(*this);
    return false;
}

void Joueur::afficher() {//Cette méthode sert à afficher toute l’équipe Pokémon du joueur avec leurs détails complets.
    for (int i = 0; i < nbPokemons; i++) {
        cout << "Pokémon " << i + 1 << " : " << endl;
        this->pokemons[i].afficher();
    }
}

Pokemon* Joueur::getPokemon(int i) { return &pokemons[i]; }//La méthode Pokemon* Joueur::getPokemon(int i) retourne un pointeur vers le i-ème Pokémon de l’équipe du joueur.

Leader::Leader(string n1, string nomGym, string badge,//Ce constructeur de la classe Leader initialise un chef de gymnase Pokémon en appelant d’abord le constructeur de la classe Entraineur, puis en définissant les attributs spécifiques au leader.
        Pokemon poke1, Pokemon poke2, Pokemon poke3,
        Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes)
    : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6, mes) {
    gymnase = nomGym;
    medaille = badge;
    badgeAccorde = true;
}

string Leader::getGymnase() const { //Cette méthode getGymnase() est un accesseur (getter) qui permet de récupérer le nom du gymnase associé à un leader, sans le modifier.
    return gymnase; //const signifie que ca ne modifie pas l'objet 
}

string Leader::getMedaille() const {//La méthode getMedaille() est un getter qui retourne la valeur de l’attribut privé medaille de la classe Leader.
    return medaille;
}

void Leader::accorderMedaille(Entraineur& joueur) { //La méthode accorderMedaille affiche un message indiquant que le Leader remet sa médaille à un Entraîneur après un combat gagné.
    cout << nomEntraineur << " remet la médaille " << medaille
            << " à " << joueur.getNomEntraineur() << "." << endl;
}

bool Leader::interagir(Entraineur& joueur){ //Cette méthode permet de gérer l’interaction entre un leader et un joueur après un combat. Elle détermine si le joueur peut recevoir une médaille. 
    if (victoire) { //Cela signifie que le joueur a battu ce leader
        if (badgeAccorde) {
            accorderMedaille(joueur);
            badgeAccorde = false;//passe badgeAccorde à false pour éviter de redonner le badge ;
            return true;//retourne true pour signaler que l’interaction a donné une médaille.
        }
        else{
            cout << message << endl;//Le joueur a déjà battu le leader et reçu la médaille.
            return false;
        }
    }
    else{
        cout << "Tu n'as pas battu ce leader reviens quand ça sera fait!" << endl;
        return false;
    }
}


Maitre::Maitre(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,//Cette ligne de code définit le constructeur de la classe Maitre, qui hérite de Entraineur.
        Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes)
    :Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6, mes) {}//utilise le constructeur de la classe entraineur 


void Joueur::receivedDamage(Maitre& attaquant){//Cette méthode gère la réception de dégâts par un joueur quand il se fait attaquer par le Maître Pokémon.
    float multiplicateur = 1.25;// les attaques du maître sont boostées de 25 % 
    string typeAtt1 = attaquant.getType1();//on récupère les types du Pokémon du maître
    string typeAtt2 = attaquant.getType2();
    int degatsAdverses = attaquant.getDegat();//on récupère les dégâts de base de son attaque.

    for (int i = 0; i < actif->getNbFaib(); i++) {//Si le Pokémon actif du joueur est faible face au type de l'attaque, on double les dégâts.
        if (actif->getFaib()[i] == typeAtt1 || actif->getFaib()[i] == typeAtt2) { //Si l’un des deux types de l'attaquant correspond à une faiblesse du Pokémon du joueur
            multiplicateur *= 2.0;
            break;
        }
    }
    for (int i = 0; i < actif->getNbRes(); i++) {//Si le Pokémon est résistant au type de l'attaque, on divise les dégâts par 2.
        if (actif->getRes()[i] == typeAtt1 || actif->getRes()[i] == typeAtt2) {
            multiplicateur *= 0.5;
            break;
        }
    }

    int degatsFinaux = static_cast<int>(degatsAdverses * multiplicateur);//Les dégâts finaux sont calculés et soustraits aux PV du Pokémon actif.
    PV -= degatsFinaux;

    cout << actif->getNom() << " a subi " << degatsFinaux << " dégâts." << endl;//Affiche le résultat de l’attaque.

    if (PV <= 0) {
        actif->unsummon();
        indexActuel++;
        if (indexActuel < nbPokemons) {
            cout << "Le prochain Pokémon entre en combat !" << endl;
            actif = &pokemons[indexActuel];//Cela signifie que l'on pointe vers le prochain Pokémon actif dans l'équipe.
            summon2(*actif);//*actif signifie qu’on passe le Pokémon lui-même (et non son pointeur).
        } else {
            cout << "Tous les Pokémon de " << nomEntraineur << " sont K.O. !" << endl;
            finCombat();
        }
    }
}
