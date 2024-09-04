#include "class.hpp"


bool player::init(std::string name) {
    this->score = 0;
    std::array<card*, 4> h;
    for(int i{0}; i<4; i++) {
        h[i] = nullptr;
    }
    this->hand = h;
    this->name = name;
}

bool player::supr() {
    for(int i{0}; i<4; i++) {
        if(this->hand[i] != nullptr) {
            this->hand[i]->supr();
        }
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

void player::aff_hand() {
    for(int i{0}; i<4; i++) {
        this->hand[i]
    }
}

void player::fill_hand(pile* p) {
    for(int i{0}; i<4; i++) {
        this->hand[i] = p->draw();
    }
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
    for(int i{0}; i<this->nb_player; i++) {
        (this->j)[i]->fill_hand(this->p);
    }
}

void game::add_player(std::string name) {
    player* p;
    p->init(name);
    this->j.push_back(p);
    this->nb_player++;
}


bool pile::init() {
    std::queue<card*> temp;
    int nb_rand;
    for(int i{0}; i<50; i++) {
        card* temp_card = new card;
        nb_rand = rand()%31;
        if(nb_rand<10) {
            temp_card->init(0);
        }
        else if(nb_rand<20) {
            temp_card->init(1);
        }
        else if(nb_rand<27) {
            temp_card->init(2);
        }
        else {
            temp_card->init(3);
        }
        temp.push(temp_card);
    }
    return true;
}

bool pile::supr() {

}

card* pile::draw() {
    card* temp = this->data.front();
    this->data.pop();
    return temp; 
}

void pile::discard(card* c) {
    this->data.push(c);
}

bool card::init(int t) {
    this->type = t;
    return true;
}

bool card::supr() {
    delete this;
    return true;
}
