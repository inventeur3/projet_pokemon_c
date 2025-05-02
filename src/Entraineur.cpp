#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Entraineur {
protected:
    string nomEntraineur;
    int PV;
    Pokemon* actif = nullptr;
    Pokemon* pokemons = new Pokemon[6];
    int indexActuel;
    int nbPokemons = 0;
    bool victoire;

public:
    Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4,
               Pokemon poke5, Pokemon poke6) {
        nomEntraineur = n1;
        if (poke1.estValide()) pokemons[nbPokemons++] = poke1;
        if (poke2.estValide()) pokemons[nbPokemons++] = poke2;
        if (poke3.estValide()) pokemons[nbPokemons++] = poke3;
        if (poke4.estValide()) pokemons[nbPokemons++] = poke4;
        if (poke5.estValide()) pokemons[nbPokemons++] = poke5;
        if (poke6.estValide()) pokemons[nbPokemons++] = poke6;
        indexActuel = 0;
    }

    ~Entraineur() {
        delete[] pokemons;
        pokemons = nullptr;
        delete actif;
        actif = nullptr;
    }


    void entrantEnCombat() {
        indexActuel = 0;
        if (nbPokemons > 0) {
            actif = &pokemons[indexActuel];
            summon2(*actif);
        } else {
            cout << nomEntraineur << " n’a pas de Pokémon pour commencer le combat !" << endl;
        }
    }

    void summon2(Pokemon& p) {
        p.Summon();
        PV = p.getPVmax();
    }

    int getDegat() const { return actif->getDeg(); }
    string getType1() const { return actif->getType1(); }
    string getType2() const { return actif->getType2(); }

    void attaque(Entraineur& cible) {
        cout << *actif.getNom() << " attaque " << cible.*actif.getNom() << " avec " << *actif.getAttaque() << "." << endl;
        cible.receivedDamage(*this);
    }

    void receivedDamage(Entraineur& attaquant) {
        float multiplicateur = 1.0;
        string typeAtt1 = attaquant.getType1();
        string typeAtt2 = attaquant.getType2();
        int degatsAdverses = attaquant.getDegat();

        for (const string& el : actif->getFaib()) {
            if (typeAtt1 == el || typeAtt2 == el) {
                multiplicateur *= 2.0;
            }
        }

        for (const string& el : actif->getRes()) {
            if (typeAtt1 == el || typeAtt2 == el) {
                multiplicateur *= 0.5;
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

    void finCombat() {
        victoire=true;
        
        cout << NomEntr    aineur<<" est vaincu" << endl;
    }

    string getNomEntraineur() const {
        return nomEntraineur;
    }
};


class Joueur : public Entraineur {
    private:
        int nbBadges;
        int nbCombatsGagnes;
        int nbCombatsPerdus;
        //modificateurs
        void ajouterBadge() { nbBadges++; }
        void ajouterVictoire() { nbCombatsGagnes++; }
        void ajouterDefaite() { nbCombatsPerdus++; }
    
    public:
        Joueur(string n1, 
               Pokemon poke1, Pokemon poke2, Pokemon poke3,
               Pokemon poke4, Pokemon poke5, Pokemon poke6)
            : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6) {
            nbBadges = 0;
            nbCombatsGagnes = 0;
            nbCombatsPerdus = 0;
            victoire=false;
        }
    
        // Accesseurs
        int getBadges() const { return nbBadges; }
        int getCombatsGagnes() const { return nbCombatsGagnes; }
        int getCombatsPerdus() const { return nbCombatsPerdus; }

        void ordre() {
            cout << "Ordre actuel des Pokémon :" << endl;
            for (int i = 0; i < nbPokemons; i++) {
                cout << i + 1 << ". " << pokemons[i].getNom() << endl;
            }
        
            cout << "Entrez le nouvel ordre des Pokémon (" << nbPokemons << " numéros entre 1 et " << nbPokemons << ", séparés par des espaces) : ";
            int nouvelOrdre[nbPokemons];
            for (int i = 0; i < nbPokemons; i++) {
                cin >> nouvelOrdre[i];
            }
        
            // Vérification des indices
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
                cout << "Ordre invalide. Assurez-vous d'utiliser les numéros de 1 à "<<nbPokemons<<" sans doublons." << endl;
            }
        
            cout << "Nouvel ordre des Pokémon :" << endl;
            for (int i = 0; i < nbPokemons; i++) {
                cout << i + 1 << ". " << pokemons[i].getNom() << endl;
            }
        }
        
        void demanderMedaille(Leader& leader) {
            static vector<string> medaillesObtenues;
            string medaille = leader.getMedaille();

            cout << nomEntraineur << " a gagné contre le leader !" << endl;

            if (find(medaillesObtenues.begin(), medaillesObtenues.end(), medaille) != medaillesObtenues.end()) {
                cout << "Cette médaille a déjà été obtenue. Elle ne peut pas être reçue deux fois." << endl;
            } else {
                cout << "Il reçoit la médaille : " << medaille << endl;
                medaillesObtenues.push_back(medaille);
                ajouterBadge();
                }
    }   
};



class Leader : public Entraineur {
    private:
        string gymnase;
        string medaille;
        string badgeAccorde;
    
    public:
        Leader(string n1,
                Pokemon poke1, Pokemon poke2, Pokemon poke3,
                Pokemon poke4, Pokemon poke5, Pokemon poke6,
                string nomGym, string badge, string badgeAccorde)
            : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6) {
            gymnase = nomGym;
            medaille = badge;
            this->badgeAccorde = badgeAccorde;
            victoire=0;
        }
    
        string getGymnase() const {
            return gymnase;
        }
    
        string getMedaille() const {
            return medaille;
        }

        void accorderMedaille(Joueur& joueur) {
            victoire++;
            cout << nomEntraineur << " remet la médaille " << medaille
                 << " à " << joueur.getNomEntraineur() << "." << endl;
            cout << "Il s'agit de la médaille spéciale : " << badgeAccorde << "." << endl;
        }      
};

class Maitre : public Entraineur {
    public:
        Maitre(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3,
               Pokemon poke4, Pokemon poke5, Pokemon poke6)
            : Entraineur(n1, poke1, poke2, poke3, poke4, poke5, poke6) {}
    

        int getDegatBoosted() const {
            return static_cast<int>(actif->getDeg() * 1.25);
        }


        void affronterMaitre(Joueur& joueur, Maitre& maitre) {
            if (joueur.getBadges() >= 4) {
                cout << "Vous avez toutes les médailles ! Le combat contre le Maître commence !" << endl;

                maitre.entrantEnCombat(); // invoque le premier Pokémon du Maitre
                joueur.entrantEnCombat(); // invoque le premier Pokémon du joueur

                // Le Maître attaque avec dégâts boostés
                int degatsBoost = maitre.getDegatBoosted();
                string type1 = maitre.getType1();
                string type2 = maitre.getType2();

                cout << maitre.getNomEntraineur() << " utilise une attaque spéciale renforcée !" << endl;
                joueur.receivedDamage(degatsBoost, type1, type2);

            } else {
                cout << "Vous devez obtenir toutes les médailles pour affronter le Maître." << endl;
                cout << "Médailles actuelles : " << joueur.getBadges() << " / 4" << endl;
            }
        }

        
    };
    
    


