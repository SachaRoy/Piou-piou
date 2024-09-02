#include "class.hpp"


bool player::init() {
    this->score = 0;
    std::array<card*, 4>;
}

bool player::supr() {

}

int player::get_score() {
    return score;
}

card* player::modif_hand(int i, card* c) {
    card* temp = this->hand[i];
    this->hand[i] = c;
    return temp;
}


bool game::start() {
    this->running = true;
    std::vector<player*> j;
    pile* p = new pile;
    return p->init();
}

card game::draw() {

}

bool game::supr() {
    this->running = false;
    return this->p->supr();
}

void game::add_player() {
    player* p;
    p->init();
}


bool pile::init() {

}

bool pile::supr() {

}

card* pile::draw() {
    
}

void pile::discard(card* c) {

}

bool game::is_running() {
    return running;
}

bool card::init(int t) {
    this->type = t;
    return true;
}

bool card::supr() {
    delete this;
    return true;
}
