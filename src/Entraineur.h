#ifndef ENTRAINEURGLOBAL_H
#define ENTRAINEURGLOBAL_H

#include "Pokemon.h"

#include <string>
#include <vector>

using namespace std;

class Entraineur{
    protected:
        string nomEntraineur;
        int PV;
        Pokemon* actif;
        Pokemon* pokemons;
        int indexActuel;
        int nbPokemons;
        string message;
        bool victoire;

public:
    Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4,
            Pokemon poke5, Pokemon poke6, string mes = "");
    virtual ~Entraineur();

    void entrantEnCombat();
    void summon2(Pokemon& p);

    int getDegat() const;
    string getType1() const;
    string getType2() const;
    Pokemon* getActif() const;
    bool estCapableDeCombattre();
    void attaque(Entraineur& cible);
    void receivedDamage(Entraineur& attaquant);
    void finCombat();
    string getNomEntraineur() const;
    bool interagir(Entraineur& e);
};
class Maitre : public Entraineur {
    public:
        Maitre(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
            Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes="");

};
class Leader : public Entraineur {
    private:
        string gymnase;
        string medaille;
        bool badgeAccorde;

    public:
        Leader(string n1, string nomGym, string badge,
            Pokemon poke1, Pokemon poke2, Pokemon poke3,
            Pokemon poke4, Pokemon poke5, Pokemon poke6, string mes = "");

        string getGymnase() const;
        string getMedaille() const;
        void accorderMedaille(Entraineur& joueur);
        bool interagir(Entraineur& joueur);
};
class Joueur : public Entraineur {
    private:
        int nbBadges;
        int nbCombatsGagnes;
        int nbCombatsPerdus;
        void ajouterBadge();


    public:
        Joueur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
            Pokemon poke4, Pokemon poke5, Pokemon poke6);

        int getBadges() const;
        int getCombatsGagnes() const;
        int getCombatsPerdus() const;

        void ajouterVictoire();
        void ajouterDefaite();
        void receivedDamage(Maitre& m);
        void ordre();
        bool interagir(Entraineur& entraineur);
        bool interagir(Leader& leader);
        void afficher();
        Pokemon* getPokemon(int i);
};


#endif // ENTRAINEURGLOBAL_H
