#include "class.hpp"


bool player::init() {
    this->score = 0;
    std::array<card*, 4> h;
    this->hand = h;
}

bool player::supr() {
    for(int i{0}; i<4; i++) {
        this->hand[i]->supr();
    }
    delete this;
    return true;
}

int player::get_score() {
    return this->score;
}

card* player::modif_hand(int i, card* c) {
    card* temp = this->hand[i];
    this->hand[i] = c;
    return temp;
}


bool game::start() {
    this->running = true;
    std::vector<player*> joueurs;
    this->j = joueurs;
    pile* p = new pile;
    return p->init();
}

bool game::supr() {
    this->running = false;
    return this->p->supr();
}

bool game::is_running() {
    return this->running;
}

bool game::fill_hands() {

}

void game::add_player() {
    player* p;
    p->init();
    this->j.push_back(p);
}


bool pile::init() {

}

bool pile::supr() {

}

card* pile::draw() {
    
}

void pile::discard(card* c) {

}

bool card::init(int t) {
    this->type = t;
    return true;
}

bool card::supr() {
    delete this;
    return true;
}
