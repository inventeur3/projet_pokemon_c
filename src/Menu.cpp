#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Entraineur.h"

using namespace std;

void Combat(Joueur& j, Leader& e) {

    j.entrantEnCombat();
    e.entrantEnCombat();
    bool a = j.estCapableDeCombattre(); // tu devras remplacer par j.estCapableDeCombattre()
    bool b = e.estCapableDeCombattre(); // idem pour e
    while (a && b) {
        j.attaque(e);
        b = e.estCapableDeCombattre();
        if (b) {
            e.attaque(j);
            a = j.estCapableDeCombattre();
        }
    }
    if (a){
        j.ajouterVictoire();
        j.interagir(e);
    }
    if (b){
        j.ajouterDefaite();
    }
}
void Combat(Joueur& j, Entraineur& e) {

    j.entrantEnCombat();
    e.entrantEnCombat();
    bool a = j.estCapableDeCombattre(); // tu devras remplacer par j.estCapableDeCombattre()
    bool b = e.estCapableDeCombattre(); // idem pour e
    while (a && b) {
        j.attaque(e);
        b = e.estCapableDeCombattre();
        if (b) {
            e.attaque(j);
            a = j.estCapableDeCombattre();
        }
    }
    if (a){
        j.ajouterVictoire();
    }
    if (b){
        j.ajouterDefaite();
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
     // Pokémon du joueur
    Pokemon Dracolosse("Dracolosse", "Dragon", "Vol", 91, "Colère", 140, "Drrracoooo!");
    Pokemon Electhor("Électhor", "Électrik", "Vol", 90, "Fatal-Foudre", 125, "Eleleeeee!");
    Pokemon Lokhlass("Lokhlass", "Eau", "Plante", 130, "Laser-Glace", 120, "Lokhiii!");
    Pokemon Mackogneur("Mackogneur", "Combat", "", 90, "Coup Cross", 120, "Mackognoo!");
    Pokemon Ectoplasma ("Ectoplasma ", "Spectre", "Poison", 60, "Ball'Ombre", 120, "Plaaasmaaa!");
    Pokemon Kabutops("Kabutops", "Roche", "Eau", 60, "Lame de Roc", 115, "Kabu Kabu Topssss!");

    Joueur joueur("Sacha", Dracolosse, Electhor, Lokhlass,  Mackogneur, Ectoplasma , Kabutops);

    // Leader 1 : Pierre (Roche)
    Pokemon racaillou("Racaillou", "Roche", "Sol", 55, "Jet-Pierres", 60, "Raca!");
    Pokemon onix("Onix", "Roche", "Sol", 35, "Étreinte", 70, "Onix!");
    Pokemon gravalanch("Gravalanch", "Roche", "Sol", 55, "Roulade", 80, "Grav!");
    Pokemon grolem("Grolem", "Roche", "Sol", 80, "Séisme", 120, "Grol!");
    Pokemon rhinocorne("Rhinocorne", "Sol", "Roche", 80, "Charge", 85, "Rhino!");
    Pokemon rhinoféros("Rhinoféros", "Sol", "Roche", 105, "Cornes", 120, "Rhinof!");

    Leader leader1("Pierre", "Argenta", "Roche", racaillou, onix, gravalanch, grolem, rhinocorne, rhinoféros, "Bravo tu m'as debut! Comme-ci je mettais reçu une pierre sur la tête.");
    
    // Leader 2 : Ondine (Eau)
    Pokemon carabaffe("Carabaffe", "Eau", "", 59, "Pistolet à O", 80, "Carab!");
    Pokemon akwakwak("Akwakwak", "Eau", "", 100, "Hydrocanon", 110, "Akwak!");
    Pokemon tentacruel("Tentacruel", "Eau", "Poison", 80, "Dard-Venin", 95, "Tentac!");
    Pokemon poissoroy("Poissoroy", "Eau", "", 80, "Aqua-Jet", 95, "Poiss!");
    Pokemon lamantine("Lamantine", "Eau", "Glace", 90, "Laser Glace", 110, "Lama!");
    Pokemon lokhlass("Lokhlass", "Eau", "Glace", 130, "Surf", 120, "Lokh!");

    Leader leader2("Ondine", "Azuria", "Cascade", carabaffe, akwakwak, tentacruel, poissoroy, lamantine, lokhlass, "Wooow , tu m'as battu plus vite que prévu.");

    // Leader 3 : Major Bob (Électrik)
    Pokemon raichu("Raichu", "Électrik", "", 60, "Tonnerre", 100, "Rai!");
    Pokemon magneton("Magnéton", "Électrik", "Acier", 50, "Éclair", 95, "Magnet!");
    Pokemon electrode("Électrode", "Électrik", "", 60, "Boule Élek", 95, "Boom!");
    Pokemon voltali("Voltali", "Électrik", "", 65, "Fatal-Foudre", 110, "Volt!");
    Pokemon elektek("Élektek", "Électrik", "", 65, "Poing Élek", 110, "Elekt!");
    Pokemon electhor("Électhor", "Électrik", "Vol", 90, "Éclair", 125, "Zaaap!");

    Leader leader3("Major Bob", "Carmin sur Mer", "Foudre", raichu, magneton, electrode, voltali, elektek, electhor, "Impressionnant, même à l'armée on ne reçoit pas de giffle comme ça.");

    // Leader 4 : Erika (Plante)
    Pokemon ortide("Ortide", "Plante", "Poison", 60, "Poudre Dodo", 75, "Orti!");
    Pokemon parasect("Parasect", "Plante", "Insecte", 60, "Spore", 85, "Para!");
    Pokemon empiflor("Empiflor", "Plante", "Poison", 80, "Tranch'Herbe", 100, "Empi!");
    Pokemon rafflesia("Rafflesia", "Plante", "Poison", 75, "Canon Graine", 80, "Raff!");
    Pokemon saquedeneu("Saquedeneu", "Plante", "", 65, "Fouet Lianes", 50, "Saqu!");
    Pokemon noadkoko("Noadkoko", "Plante", "Psy", 95, "Psyko", 120, "Noad!");

    Leader leader4("Erika", "Céladopole", "Prisme", ortide, parasect, empiflor, rafflesia, saquedeneu, noadkoko, "Bravo tu m'érites cette médaille!!");
    
    // Maître Pokémon
    Pokemon dracolosse("Dracolosse", "Dragon", "Vol", 91, "Draco-Rage", (int)(140*1.25), "Draco!");
    Pokemon arcanin("Arcanin", "Feu", "", 90, "Flamme Ultime", (int)(1.25*120), "Arca!");
    Pokemon lokhlassMaitre("Lokhlass", "Eau", "Glace", 130, "Surf", (int)(1.25*120), "Lokh!");
    Pokemon rhinoférosMaitre("Rhinoféros", "Sol", "Roche", 105, "Cornes", (int)(1.25*120), "Rhinof!");
    Pokemon electhorMaitre("Électhor", "Électrik", "Vol", 90, "Éclair", (int)(1.25*125), "Zaaap!");
    Pokemon raichuMaitre("Raichu", "Électrik", "", 60, "Tonnerre", (int)(1.25*100), "Rai!");

    Maitre maitre("Mewtwo", dracolosse, lokhlassMaitre, arcanin, rhinoférosMaitre, electhorMaitre, raichuMaitre, "Je suis inpresionné par ton talent de dresseur!");
    int choix;
    bool continuer = true;
    string s;
    while (continuer) {
        afficherMenu();
        cin >> choix;
        switch (choix) {
            case 1:
                joueur.afficher();
                cout<<"";
                cin >> s;
                break;
            case 2:
                cout << "Nombre de badges: " << joueur.getBadges() << endl;
                cout << "Combats gagnés: " << joueur.getCombatsGagnes() << endl;
                cout << "Combats perdus: " << joueur.getCombatsPerdus() << endl;
                cout<<"";
                cin >> s;
                break;
            case 3:
                joueur.ordre();
                cout<<"";
                cin >> s;
                break;
            case 4:
                for (int i = 0; i < 6; i++) {
                    cout << "Le Pokémon " << i << " a " << joueur.getPokemon(i)->getPVmax() << " PV en tout." << endl;
                }
                cout<<"";
                cin >> s;
                break;
            case 5:
                cout << "Quel leader voulez-vous affronter ? (1: Pierre(Roche), 2: Ondine(Cascade), 3: Major Bob(Foudre), 4: Erika(Prisme) : ";
                int choixLeader;
                cin >> choixLeader;
                switch (choixLeader) {
                    case 1: Combat(joueur, leader1); break;
                    case 2: Combat(joueur, leader2); break;
                    case 3: Combat(joueur, leader3); break;
                    case 4: Combat(joueur, leader4); break;
                    default: cout << "Choix invalide." << endl;
                }
                cout<<"";
                cin >> s;
                break;
            case 6:
                cout << "Vous devez obtenir toutes les médailles pour affronter le Maître." << endl;
                if (joueur.getBadges() >= 4){
                    Combat(joueur, maitre);
                }
                cout<<"";
                cin >> s;
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
                cout<<"";
                cin >> s;
                break;
            case 8: {
                cout << "Avec quel leader voulez-vous interagir ? (1: Pierre(Roche), 2: Ondine(Cascade), 3: Major Bob, 4: Erika) : ";
                int choixLeaderInter;
                cin >> choixLeaderInter;
                switch (choixLeaderInter) {
                    case 1:
                        joueur.interagir(leader1);
                        break;
                    case 2:
                        joueur.interagir(leader2);
                        break;
                    case 3:
                        joueur.interagir(leader3);
                        break;
                    case 4:
                        joueur.interagir(leader4);
                        break;
                    default:
                        cout << "Choix invalide." << endl;
                        
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
