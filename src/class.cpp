#include "class.hpp"


bool player::init(std::string name) {
    this->score = 0;
    std::array<card*, 4> h;
    this->hand = h;
    this->name = name;
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

std::string player::get_name() {
    return this->name;
}

card* player::modif_hand(int i, card* c) {
    card* temp = this->hand[i];
    this->hand[i] = c;
    return temp;
}


bool game::start() {
    this->running = true;
    this->nb_player = 0;
    std::vector<player*> joueurs;
    this->j = joueurs;
    pile* p = new pile;
    return p->init();
}

bool game::finish() {
    this->running = false;
    return this->p->supr();
}

bool game::is_running() {
    return this->running;
}

bool game::fill_hands() {

}

void game::add_player(std::string name) {
    player* p;
    p->init(name);
    this->j.push_back(p);
    this->nb_player++;
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
