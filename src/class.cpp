#include "class.hpp"

int player::get_score() {
    return score;
}

card player::modif_hand(int i, card c) {
    card temp = hand[i];
    hand[i] = c;
    return temp;
}


bool game::start() {

}

card game::draw() {
    
}

void game::discard(card c) {

}

bool game::is_running() {
    return running;
}