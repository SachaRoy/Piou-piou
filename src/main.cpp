#include <iostream>
#include "class.hpp"


void title_screen() {
    std::cout << "  ____    _                     ____    _                 " << std::endl;
    std::cout << " |  _ \\  (_)   ___    _   _    |  _ \\  (_)   ___    _   _ " << std::endl;
    std::cout << " | |_) | | |  / _ \\  | | | |   | |_) | | |  / _ \\  | | | |" << std::endl;
    std::cout << " |  __/  | | | (_) | | |_| |   |  __/  | | | (_) | | |_| |" << std::endl;
    std::cout << " |_|     |_|  \\___/   \\__,_|   |_|     |_|  \\___/   \\__,_|\n" << std::endl;
    std::cout << "1) Jouer" << std::endl;
    std::cout << "2) Règles" << std::endl;
    std::cout << "3) Quitter" << std::endl;
}

void print_rules() {
    std::cout << "Voici les règles:" << std::endl;
}

void running_game() {
    system("clear");
    game* partie = new game;
    partie->start();

    int nb_joueur = 0;
    while(nb_joueur > 7 || nb_joueur < 3) {
        std::cout << "Combien de joueurs ? (max. 7) ";
        std::cin >> nb_joueur;
    }

    std::string temp_name;
    for(int i{0}; i<nb_joueur; i++) {
        std::cout << "Nom du joueur " << i+1 << ": ";
        std::cin >> temp_name;
        partie->add_player(temp_name);
    }
    partie->fill_hands();

    std::string winner = "";
    player* temp_j;
    std::string temp_name;
    int tour = 0;
    while(winner == "") {
        temp_j = partie->j[tour];
        temp_name = temp_j->get_name();
        std::cout << "Tour de " << temp_name << std::endl;

        if(temp_j->get_score() > 2) {
            winner = temp_name;
        }
        tour = (tour+1)%nb_joueur;
    }
    std::cout << "Le gagnant est " << winner << "." << std::endl;

    
}


int main() {
    bool boucle = true;
    bool start_game;
    char input_usr;

    while(boucle) {
        start_game = false;
        system("clear");
        title_screen();
        std::cin >> input_usr;
        
        switch (input_usr){
            case '1':
                start_game = true;
                break;
            case '2':
                print_rules();
                break;
            case '3':
                system("clear");
                boucle = false;
                break;
            default:
                std::cout << "Commande non reconnue" << std::endl;
                break;
        }

        if(start_game) {
            running_game();
        }        
    }

    return 0;
}