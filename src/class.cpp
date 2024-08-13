#include "class.hpp"

int player::get_score() {
    return score;
}

card player::modif_hand(int i, card c) {
    card temp = hand[i];
    hand[i] = c;
    return temp;
}


card game::draw() {
    
}

void game::discard(card c) {

}