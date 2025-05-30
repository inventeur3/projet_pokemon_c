#ifndef POKEMONGLOBAL_H
#define POKEMONGLOBAL_H

#include <string>
#include <vector>

using namespace std;

class Pokemon {
    private:
        string name;
        string type1;
        string type2;
        int PVmax;
        string attaque;
        int degats;
        string* faiblesses;
        string* resistances;
        string message;
        int nbFaiblesses;
        int nbResistances;
        bool valid;
        void SetFaibRes(string t1, string t2);
        
    public:
        Pokemon& operator=(const Pokemon& other);
        Pokemon(const Pokemon& other);
        Pokemon(string nom, string t1, string t2, int maxPV, string nomA, int nbDeg, string mes);
        Pokemon();
        ~Pokemon();
        void Summon();
        int getPVmax();
        string getNom();
        string getAttaque();
        string getType1();
        string getType2();
        int getDeg();
        string* getFaib();
        string* getRes();
        void unsummon();
        void Interagir();
        bool estValide();
        void afficher();
        int getNbFaib();
        int getNbRes();
};

#endif // POKEMONGLOBAL_H
