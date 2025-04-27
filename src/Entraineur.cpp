#include <iostream>
using namespace std;

class Entraineur{
    protected:
        string nomEntraineur;
        int PV;
        Pokemon* actif= nullptr;
        Pokemon* pokemons = new Pokemon[6];
        int indexActuel = 0;

        
    public:
        Entraineur(string n1, Pokemon poke1, Pokemon poke2, Pokemon poke3, Pokemon poke4, 
                Pokemon poke5, Pokemon poke6
            ){                            
            nomEntraineur = n1;
            pokemons[0] = poke1;
            pokemons[1] = poke2;
            pokemons[2] = poke3;
            pokemons[3] = poke4;
            pokemons[4] = poke5;
            pokemons[5] = poke6;
        
        }

        ~Entraineur() {
            delete[] pokemons;
            pokemons=nullptr;
            delete actif;
            actif = nullptr;
        }

        void summon2(Pokemon& p) {

            p.Summon();
            PV=p.getPVmax();

        }

        int getDegat() const { return actif.getDeg(); }
        string getType1() const { return actif.getType1(); }
        string getType2() const { return actif.getType2(); }

        void attaque(Entraineur& cible) {
            cout << actif.getNom() << " attaque " << cible.actif.getNom()<< " avec l'attaque " << actif.getAttaque() << "." << endl;
            cible.receivedDamage(*this);
        }

        void receivedDamage(Entraineur& attaquant){
            float multiplicateur = 1.0;
        
            // Récupérer les types d’attaque de l’attaquant
            string typeAtt1 = attaquant.getType1();
            string typeAtt2 = attaquant.getType2();
            int degatsAdverses = attaquant.getDegat();
        
            // Calcul du multiplicateur en fonction des types
            for (string el:actif.getFaib()){
                if (typeAtt1 == el or typeAtt2==el){
                    multiplicateur *=2.0;
                }
            }

            for (string el:actif.getRes()){
                if (typeAtt1 == el or typeAtt2==el){
                    multiplicateur *=0.5;
                }
            }
        
            int degatsFinaux = static_cast<int>(degatsAdverses * multiplicateur);
        
            // Appliquer les dégâts au Pokémon actif
            PV -= degatsFinaux;
            
        
            cout << actif.getNom() << " a subi " << degatsFinaux << " dégâts." << endl;
        
            if (PV <= 0) {
                actif.unsummon();
                
        
                indexActuel++;
                if (indexActuel < 6) {
                    cout << "Le prochain Pokémon entre en combat !" << endl;
                    actif = pokemons[indexActuel];
                    summon2(actif);
                } else {
                    cout << "Tous les Pokémon de " << nomEntraineur << " sont K.O. !" << endl;
                }
            }
        }
        
};

class Joueur : public Entraineur {
    private:
        int nbBadges;
        int nbCombatsGagnes;
        int nbCombatsPerdus;
    
    public:
        Joueur(string n1, string n2, string a, string t1, string t2, int pv, int deg,
               string faib, string res,
               Pokemon poke1, Pokemon poke2, Pokemon poke3,
               Pokemon poke4, Pokemon poke5, Pokemon poke6)
            : Entraineur(n1, n2, a, t1, t2, pv, deg, faib, res,
                         poke1, poke2, poke3, poke4, poke5, poke6) {
            nbBadges = 0;
            nbCombatsGagnes = 0;
            nbCombatsPerdus = 0;
        }
    
        // Accesseurs
        int getBadges() const { return nbBadges; }
        int getCombatsGagnes() const { return nbCombatsGagnes; }
        int getCombatsPerdus() const { return nbCombatsPerdus; }
    
        // Modificateurs
        void ajouterBadge() { nbBadges++; }
        void ajouterVictoire() { nbCombatsGagnes++; }
        void ajouterDefaite() { nbCombatsPerdus++; }

        void ordre() {
            cout << "Ordre actuel des Pokémon :" << endl;
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << ". " << pokemons[i].getNom() << endl;
            }
        
            cout << "Entrez le nouvel ordre des Pokémon (6 numéros entre 1 et 6, séparés par des espaces) : ";
            int nouvelOrdre[6];
            for (int i = 0; i < 6; i++) {
                cin >> nouvelOrdre[i];
            }
        
            // Vérification des indices
            bool valide = true;
            bool dejaVu[6] = {false};
        
            for (int i = 0; i < 6; i++) {
                if (nouvelOrdre[i] < 1 || nouvelOrdre[i] > 6 || dejaVu[nouvelOrdre[i] - 1]) {
                    valide = false;
                    break;
                }
                dejaVu[nouvelOrdre[i] - 1] = true;
            }
        
            if (valide) {
                Pokemon tempEquipe[6];
                for (int i = 0; i < 6; i++) {
                    tempEquipe[i] = pokemons[nouvelOrdre[i] - 1];
                }
                for (int i = 0; i < 6; i++) {
                    pokemons[i] = tempEquipe[i];
                }
                cout << "L'ordre a été mis à jour avec succès !" << endl;
            } else {
                cout << "Ordre invalide. Assurez-vous d'utiliser les numéros de 1 à 6 sans doublons." << endl;
            }
        
            cout << "Nouvel ordre des Pokémon :" << endl;
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << ". " << pokemons[i].getNom() << endl;
            }
        }
        
        void demanderMedaille(Leader& leader) {
            cout << nomEntraineur << " a gagné contre le leader !" << endl;
            cout << "Il reçoit la médaille : " << leader.getMedaille() << endl;
            ajouterBadge(); 
        }

        string getNomEntraineur() const {
            return nomEntraineur;
        }
        
        
};



class Leader : public Entraineur {
    private:
        string gymnase;
        string medaille;
    
    public:
        Leader(string n1, string n2, string a, string t1, string t2, int pv, int deg,
                string faib, string res,
                Pokemon poke1, Pokemon poke2, Pokemon poke3,
                Pokemon poke4, Pokemon poke5, Pokemon poke6,
                string nomGym, string badge)
            : Entraineur(n1, n2, a, t1, t2, pv, deg, faib, res,
                            poke1, poke2, poke3, poke4, poke5, poke6) {
            gymnase = nomGym;
            medaille = badge;
        }
    
        string getGymnase() const {
            return gymnase;
        }
    
        string getMedaille() const {
            return medaille;
        }

        void accorderMedaille(Joueur& joueur) {
            cout << nomEntraineur << " remet la médaille " << medaille
                 << " à " << joueur.getNomEntraineur() << "." << endl;
            joueur.ajouterBadge();
        }
        
};

class Maitre : public Entraineur {
    public:
        Maitre(string n1, string n2, string a, string t1, string t2, int pv, int deg,
               string faib, string res,
               Pokemon poke1, Pokemon poke2, Pokemon poke3,
               Pokemon poke4, Pokemon poke5, Pokemon poke6)
            : Entraineur(n1, n2, a, t1, t2, pv, deg, faib, res,
                         poke1, poke2, poke3, poke4, poke5, poke6) {}
    

        int getDegatBoosted() const {
            return static_cast<int>(degat * 1.25);
        }

        void affronterMaitre(Joueur& joueur, Maitre& maitre) {
            if (joueur.getBadges() >= 4) {
                cout << "Vous avez toutes les médailles ! Le combat contre le Maître commence !" << endl;
        
                // Exemple : un seul tour de combat (à toi de gérer le tour par tour plus tard)
        
                // Le Maître attaque le Joueur avec dégâts boostés
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
    
    


