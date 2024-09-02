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


int main() {
    bool boucle = true;
    bool start_game = false;
    char input_usr;

    while(boucle) {
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
                boucle = false;
                break;
            default:
                std::cout << "Commande non reconnue" << std::endl;
                break;
        }

        if(start_game) {
            game partie;
            partie.start();


        }
    }


    return 0;
}