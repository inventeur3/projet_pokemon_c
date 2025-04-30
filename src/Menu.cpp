#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Simuler 4 leaders
vector<Leader> initialiserLeaders() {
    vector<Leader> leaders;
    // Crée 4 leaders fictifs avec des Pokémon de test
    for (int i = 1; i <= 4; ++i) {
        Pokemon p1("Pikachu", "Electrik", "", "Tonnerre", 100, 30, {"Sol"}, {"Acier"});
        Pokemon p2("Salameche", "Feu", "", "Flammeche", 90, 25, {"Eau", "Roche"}, {"Plante"});
        Pokemon p3("Carapuce", "Eau", "", "Pistolet à O", 95, 28, {"Electrik"}, {"Feu"});
        Pokemon p4("Bulbizarre", "Plante", "", "Fouet Lianes", 92, 26, {"Feu", "Glace"}, {"Eau"});
        Pokemon p5("Rondoudou", "Fée", "", "Berceuse", 85, 20, {"Acier"}, {"Ténèbres"});
        Pokemon p6("Draco", "Dragon", "", "Draco-Rage", 100, 32, {"Fée", "Glace"}, {"Feu"});

        leaders.push_back(Leader("Leader" + to_string(i), "PokéX", "TypeX", "TypeY", "", 100, 30, "Feu", "Eau", 
                                 p1, p2, p3, p4, p5, p6, "Arène" + to_string(i), "Badge" + to_string(i)));
    }
    return leaders;
}

void menuSimulation(Joueur& joueur, vector<Leader>& leaders, vector<Maitre>& maitres) {
    int choix;
    do {
        cout << "\n========= MENU DE SIMULATION =========" << endl;
        cout << "1. Afficher les Pokémon et leurs attributs" << endl;
        cout << "2. Récupérer les points de vie des Pokémon" << endl;
        cout << "3. Changer l’ordre des Pokémon" << endl;
        cout << "4. Afficher les statistiques du joueur" << endl;
        cout << "5. Affronter un leader de gymnase" << endl;
        cout << "6. Affronter un Maître Pokémon" << endl;
        cout << "7. Interagir avec les Pokémon ou entraîneurs vaincus" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "\n--- Pokémon du joueur ---" << endl;
                for (int i = 0; i < 6; ++i) {
                    cout << i + 1 << ". ";
                    joueur.getPokemon(i).afficher();  // méthode à implémenter dans ta classe Pokemon
                    cout << endl;
                }
                break;

            case 2:
                cout << "\n--- Récupération des PV ---" << endl;
                for (int i = 0; i < 6; ++i) {
                    joueur.getPokemon(i).setPV(joueur.getPokemon(i).getPVmax());  // méthode à prévoir
                }
                cout << "Tous les Pokémon ont récupéré leurs PV." << endl;
                break;

            case 3:
                joueur.ordre();
                break;

            case 4:
                cout << "\n--- Statistiques du joueur ---" << endl;
                cout << "Nom : " << joueur.getNomEntraineur() << endl;
                cout << "Badges : " << joueur.getBadges() << endl;
                cout << "Combats gagnés : " << joueur.getCombatsGagnes() << endl;
                cout << "Combats perdus : " << joueur.getCombatsPerdus() << endl;
                break;

            case 5: {
                cout << "\n--- Choisissez un leader à affronter ---" << endl;
                for (int i = 0; i < leaders.size(); ++i) {
                    cout << i + 1 << ". " << leaders[i].getNomEntraineur() << " - " << leaders[i].getGymnase() << endl;
                }
                int choixLeader;
                cout << "Votre choix : ";
                cin >> choixLeader;
                if (choixLeader >= 1 && choixLeader <= leaders.size()) {
                    cout << "\nCombat contre le leader " << leaders[choixLeader - 1].getNomEntraineur() << " commence !" << endl;
                    joueur.attaque(leaders[choixLeader - 1]);
                    leaders[choixLeader - 1].receivedDamage(joueur);
                    joueur.demanderMedaille(leaders[choixLeader - 1]);
                } else {
                    cout << "Choix invalide." << endl;
                }
                break;
            }

            case 6: {
                if (joueur.getBadges() < 4) {
                    cout << "Vous devez d’abord obtenir 4 badges pour affronter un Maître." << endl;
                } else {
                    srand(time(0));
                    int index = rand() % maitres.size();
                    cout << "Vous affrontez le Maître : " << maitres[index].getNomEntraineur() << endl;
                    maitres[index].affronterMaitre(joueur, maitres[index]);
                }
                break;
            }

            case 7:
                cout << "\n--- Interaction simple ---" << endl;
                cout << "Vous discutez avec vos Pokémon. Ils semblent en forme et motivés !" << endl;
                break;

            case 0:
                cout << "Fin de la simulation." << endl;
                break;

            default:
                cout << "Choix invalide." << endl;
        }

    } while (choix != 0);
}





















