#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
#include "Entraineur.h"

using namespace std;

void Combat(Joueur& j, Entraineur& e) {
    j.entrantEnCombat();
    e.entrantEnCombat();
    bool a = true; // tu devras remplacer par j.estCapableDeCombattre()
    bool b = true; // idem pour e
    while (a && b) {
        j.attaque(e);
        b = true;
        if (b) {
            e.attaque(j);
            a = true;
        }
    }
}

void afficherMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Afficher les Pokémons et leurs attributs" << endl;
    cout << "2. Afficher les statistiques du joueur" << endl;
    cout << "3. Changer l'ordre des Pokémons" << endl;
    cout << "4. Récupérer les points de vie des Pokémons" << endl;
    cout << "5. Affronter un leader de gymnase" << endl;
    cout << "6. Affronter le Maître Pokémon" << endl;
    cout << "7. Interagir avec les Pokémon" << endl;
    cout << "8. Interagir avec les entraîneurs vaincus" << endl;
    cout << "0. Quitter" << endl;
    cout << "Votre choix: ";
}

int main() {
    Pokemon poke1("Pikachu", "Électrik", "", 100, "Tonnerre", 50, "Pika!");
    Pokemon poke2("Salameche", "Feu", "", 100, "Flammeche", 40, "Sala!");
    Pokemon poke3("Bulbizarre", "Plante", "", 100, "Fouet Lianes", 40, "Buli!");
    Pokemon poke4("Carapuce", "Eau", "", 100, "Pistolet à O", 40, "Cara!");
    Pokemon poke5("Rondoudou", "Fée", "", 100, "Berceuse", 20, "Rondou!");
    Pokemon poke6("Evoli", "Normal", "", 100, "Morsure", 30, "Evo!");

    Joueur joueur("Red", poke1, poke2, poke3, poke4, poke5, poke6);

    Pokemon racaillou("Racaillou", "Roche", "Sol", 100, "Jet-Pierres", 50, "Raca!");
    Pokemon onix("Onix", "Roche", "Sol", 100, "Étreinte", 40, "Onix!");
    Pokemon gravalanch("Gravalanch", "Roche", "Sol", 100, "Roulade", 40, "Grav!");
    Pokemon grolem("Grolem", "Roche", "Sol", 100, "Séisme", 60, "Grol!");
    Pokemon rhinocorne("Rhinocorne", "Sol", "Roche", 100, "Charge", 30, "Rhino!");
    Pokemon rhinoféros("Rhinoféros", "Sol", "Roche", 100, "Cornes", 50, "Rhinof!");

    Leader leader1("Pierre", "Argenta", "Roche", racaillou, onix, gravalanch, grolem, rhinocorne, rhinoféros);

    int choix;
    bool continuer = true;
    while (continuer) {
        afficherMenu();
        cin >> choix;
        switch (choix) {
            case 1:
                joueur.afficher();
                break;
            case 2:
                cout << "Nombre de badges: " << joueur.getBadges() << endl;
                cout << "Combats gagnés: " << joueur.getCombatsGagnes() << endl;
                cout << "Combats perdus: " << joueur.getCombatsPerdus() << endl;
                break;
            case 3:
                joueur.ordre();
                break;
            case 4:
                for (int i = 0; i < 6; i++) {
                    cout << "Le Pokémon " << i << " a " << joueur.getPokemon(i)->getPVmax() << " PV en tout." << endl;
                }
                break;
            case 5:
                joueur.attaque(leader1);
                break;
            case 6:
                cout << "Vous devez obtenir toutes les médailles pour affronter le Maître." << endl;
                break;
            case 7:
                cout << "Avec quel Pokémon interagir (1-6)? ";
                int num;
                cin >> num;
                if (num >= 1 && num <= 6) {
                    joueur.getPokemon(num - 1)->Interagir();
                } else {
                    cout << "Numéro invalide." << endl;
                }
                break;
            case 8:
                leader1.interagir(joueur);
                break;
            case 0:
                continuer = false;
                cout << "Merci d'avoir joué !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    }
    return 0;
}
