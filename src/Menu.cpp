#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// À faire : inclure ou déclarer la classe Pokemon ici

// Simuler 4 leaders
vector<Leader> initialiserLeaders() {
    vector<Leader> leaders;

    for (int i = 1; i <= 4; ++i) {
        Pokemon p1("Pikachu", "Electrik", "", "Tonnerre", 100, 30, {"Sol"}, {"Acier"}); // nom/type1/type2/attaque/PV/dégats/faiblesses/résistances
        Pokemon p2("Salameche", "Feu", "", "Flammeche", 90, 25, {"Eau", "Roche"}, {"Plante"});
        Pokemon p3("Carapuce", "Eau", "", "Pistolet à O", 95, 28, {"Electrik"}, {"Feu"});
        Pokemon p4("Bulbizarre", "Plante", "", "Fouet Lianes", 92, 26, {"Feu", "Glace"}, {"Eau"});
        Pokemon p5("Rondoudou", "Fée", "", "Berceuse", 85, 20, {"Acier"}, {"Ténèbres"});
        Pokemon p6("Draco", "Dragon", "", "Draco-Rage", 100, 32, {"Fée", "Glace"}, {"Feu"});

        // Ajout du leader avec son équipe, arène et médaille
        leaders.emplace_back("Leader" + to_string(i),
                             p1, p2, p3, p4, p5, p6,
                             "Arène" + to_string(i), "Badge" + to_string(i));
    }
    return leaders;
}

vector<Maitre> initialiserMaitres() {
    vector<Maitre> maitres;

    Pokemon p1("Dracaufeu", "Feu", "Vol", "Lance-Flammes", 120, 40, {"Eau"}, {"Plante"});
    Pokemon p2("Tortank", "Eau", "", "Hydrocanon", 130, 42, {"Plante"}, {"Feu"});
    Pokemon p3("Florizarre", "Plante", "Poison", "Canon Graine", 125, 38, {"Feu"}, {"Eau"});
    Pokemon p4("Ectoplasma", "Spectre", "Poison", "Ball'Ombre", 110, 35, {"Spectre"}, {"Psy"});
    Pokemon p5("Ronflex", "Normal", "", "Plaquage", 150, 30, {"Combat"}, {});
    Pokemon p6("Drattak", "Dragon", "Vol", "Draco-Météore", 140, 50, {"Fée"}, {"Feu"});

    maitres.emplace_back("Maitre Ultime", p1, p2, p3, p4, p5, p6);
    return maitres;
}
void afficherPokemons(){
    for (int i = 0; i < 6; ++i) {
                    cout << i + 1 << ". ";
                    joueur.getPokemon(i).afficher();
                    cout << endl;
}
    cin >>    
}

void menuSimulation(Joueur& joueur, vector<Leader>& leaders, vector<Maitre>& maitres) {
    int choix;
    do {
        cout << "\n========= MENU DE SIMULATION =========" << endl;
        cout << "1. Afficher les Pokémons et leurs attributs" << endl;
        cout << "2. Récupérer les points de vie des Pokémons" << endl;
        cout << "3. Changer l’ordre des Pokémons" << endl;
        cout << "4. Afficher les statistiques du joueur" << endl;
        cout << "5. Affronter un leader de gymnase" << endl;
        cout << "6. Affronter un Maître Pokémon" << endl;
        cout << "7. Interagir avec les Pokémons ou entraîneurs vaincus" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "\n--- Pokémon du joueur ---" << endl;
                for (int i = 0; i < 6; ++i) {
                    cout << i + 1 << ". ";
                    joueur.getPokemon(i).afficher();
                    cout << endl;
                }
                break;

            case 2:
                for (int i = 0; i < 6; ++i)
                    joueur.getPokemon(i).setPV(joueur.getPokemon(i).getPVmax());
                cout << "Tous les Pokémon ont récupéré leurs PV." << endl;
                break;

            case 3:
                joueur.ordre();
                break;

            case 4:
                cout << "\nNom : " << joueur.getNomEntraineur() << endl;
                cout << "Badges : " << joueur.getBadges() << endl;
                cout << "Victoires : " << joueur.getCombatsGagnes() << endl;
                cout << "Défaites : " << joueur.getCombatsPerdus() << endl;
                break;

            case 5: {
                cout << "\n--- Choisissez un leader ---" << endl;
                for (int i = 0; i < leaders.size(); ++i)
                    cout << i + 1 << ". " << leaders[i].getNomEntraineur()
                         << " - " << leaders[i].getGymnase() << endl;
                int choixLeader;
                cout << "Votre choix : ";
                cin >> choixLeader;
                if (choixLeader >= 1 && choixLeader <= leaders.size()) {
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
                    cout << "Vous devez obtenir 4 badges pour affronter un Maître." << endl;
                } else {
                    srand(static_cast<unsigned>(time(0)));
                    int index = rand() % maitres.size();
                    cout << "Vous affrontez le Maître : " << maitres[index].getNomEntraineur() << endl;
                    maitres[index].affronterMaitre(joueur, maitres[index]);
                }
                break;
            }

            case 7:
                cout << "Vos Pokémons sont heureux de vous voir !" << endl;
                break;

            case 0:
                cout << "Fin de la simulation." << endl;
                break;

            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 0);
}



















