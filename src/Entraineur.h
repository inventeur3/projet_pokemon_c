#ifndef ENTRAINEURGLOBAL_H
#define ENTRAINEURGLOBAL_H

#include <string>
#include <vector>
using namespace std;

class Pokemon;


class Entraineur {
protected:
    string nomEntraineur;
    int PV;
    Pokemon* actif;
    Pokemon* pokemons;
    int indexActuel;
    int nbPokemons;

public:
    Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4,
               Pokemon poke5, Pokemon poke6);
    virtual ~Entraineur();

    void entrantEnCombat();
    void summon2(Pokemon& p);

    int getDegat() const;
    string getType1() const;
    string getType2() const;

    void attaque(Entraineur& cible);
    void receivedDamage(Entraineur& attaquant);
    void finCombat();
    string getNomEntraineur() const;
};

class Joueur : public Entraineur {
private:
    int nbBadges;
    int nbCombatsGagnes;
    int nbCombatsPerdus;
    void ajouterBadge();
    void ajouterVictoire();
    void ajouterDefaite();

public:
    Joueur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
           Pokemon poke4, Pokemon poke5, Pokemon poke6);

    int getBadges() const;
    int getCombatsGagnes() const;
    int getCombatsPerdus() const;

    void ordre();
    void demanderMedaille(class Leader& leader);
};

class Leader : public Entraineur {
private:
    string gymnase;
    string medaille;
    int victoire;
    string badgeAccorde;

public:
    Leader(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
           Pokemon poke4, Pokemon poke5, Pokemon poke6,
           string nomGym, string badge, string badgeAccorde);

    string getGymnase() const;
    string getMedaille() const;
    void accorderMedaille(Joueur& joueur);
};

class Maitre : public Entraineur {
public:
    Maitre(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
           Pokemon poke4, Pokemon poke5, Pokemon poke6);

    int getDegatBoosted() const;
    void affronterMaitre(Joueur& joueur, Maitre& maitre);
};

#endif // ENTRAINEURGLOBAL_H

