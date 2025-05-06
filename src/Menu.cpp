#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void Combat(Joueur& j, Entraineur& e) {
    j.entrantEnCombat();
    e.entrantEnCombat();
    bool a = j.estCapableDeCombattre();  // Remplace 'a' par une méthode concrète
    bool b = e.estCapableDeCombattre();  // Idem pour 'b'
    
    while (a && b) {
        j.attaque(e);
        b = e.estCapableDeCombattre();
        if (b) {
            e.attaque(j);
            a = j.estCapableDeCombattre();
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
    Joueur joueur("Red", poke1, poke2, poke3, poke4, poke5, poke6);  // À instancier correctement avec tes Pokémon
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
                for (int i = 0; i < 6; i++) {
                    cout << " Le Pokémon " << i << " a " << joueur.getPokemon(i).getPVmax() <<" PV en tout." << endl;
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
