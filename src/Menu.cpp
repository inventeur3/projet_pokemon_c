#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


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
    joueur.afficher();
    cout << "0 pour retourner au Menu, 1 pour changer l'ordre" << endl;
    int a;
    cin >> a;
    if (a == 0) {
        joueur.menuSimulation();
        }
        if else (a == 1) {
        joueur.ordre();
        }
        else {
            cout<< "prenez bien un chiffre entre 0 et 1" <<endl;
        }   
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


#include <iostream>
using namespace std;

void afficherMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Afficher les Pokémon et leurs attributs" << endl;
    cout << "2. Afficher les statistiques du joueur" << endl;
    cout << "3. Changer l'ordre des Pokémon" << endl;
    cout << "4. Récupérer les points de vie des Pokémon" << endl;
    cout << "5. Affronter un leader de gymnase" << endl;
    cout << "6. Affronter le Maître Pokémon" << endl;
    cout << "7. Interagir avec les Pokémon" << endl;
    cout << "8. Interagir avec les entraîneurs vaincus" << endl;
    cout << "0. Quitter" << endl;
    cout << "Votre choix: ";
}

int main() {
    Joueur joueur("Red", , , , , , );  // À instancier correctement avec tes Pokémons
    Leader leader1("Pierre", "Argenta", "Roche", "Racaillou", "Onix", "Gravalanch", "Grolem", "Rhinocorne", "Rhinoféros");  // Compléter avec les Pokémons et gymnase
    Leader leader2("Ondine", "Azuria","Cascade","Carabaffe","Akwakwak","Tentacruel","Poissoroy","Lamantine", "Lokhlass");
    Leader leader3("Major Bob","Carmin sur Mer","Foudre","Raichu","Magnéton","Électrode","Voltali","Élektek", "Électhor");
    Leader leader4("Erika", "Céladopole","Prisme","Ortide","Parasect","Empiflor","Rafflesia","Saquedeneu","Noadkoko");
    Maitre maitre("Mewtwo", "Dracolosse", "Lokhlass", "Arcanin", "Rhinoféros", "Électhor");

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
                cout << "Les PV de tous vos Pokémon ont été restaurés." << endl;
                // On restaure la vie des Pokémon
                for (int i = 0; i < 6; i++) {
                    joueur.getPV(i);
                }
                break;
            case 5: {
                cout << "\nChoisissez un leader à affronter:" << endl;
                cout << "1. " << leader1.getNomEntraineur() << " (" << leader1.getGymnase() << ")" << endl;
                cout << "2. " << leader2.getNomEntraineur() << " (" << leader2.getGymnase() << ")" << endl;
                cout << "3. " << leader3.getNomEntraineur() << " (" << leader3.getGymnase() << ")" << endl;
                cout << "4. " << leader4.getNomEntraineur() << " (" << leader4.getGymnase() << ")" << endl;
                int choixLeader;
                cin >> choixLeader;
                switch (choixLeader) {
                    case 1: joueur.attaque(leader1); break;
                    case 2: joueur.attaque(leader2); break;
                    case 3: joueur.attaque(leader3); break;
                    case 4: joueur.attaque(leader4); break;
                    default: cout << "Choix invalide." << endl;
                }
                break;
            }
            case 6:
                maitre.affronterMaitre(joueur, maitre);
                break;
            case 7: {
                cout << "Avec quel Pokémon interagir (1-6)? ";
                int num;
                cin >> num;
                if (num >= 1 && num <= 6) {
                    joueur.getPokemon(num - 1).Interagir();
                } else {
                    cout << "Numéro invalide." << endl;
                }
                break;
            }
            case 8: {
                cout << "Avec quel leader vaincu interagir? (1-4): ";
                int num;
                cin >> num;
                bool resultat = false;
                switch (num) {
                    case 1: resultat = leader1.interagir(joueur); break;
                    case 2: resultat = leader2.interagir(joueur); break;
                    case 3: resultat = leader3.interagir(joueur); break;
                    case 4: resultat = leader4.interagir(joueur); break;
                    default: cout << "Choix invalide." << endl;
                }
                if (!resultat) {
                    cout << "Ce leader n'a pas encore été vaincu." << endl;
                }
                break;
            }
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
















