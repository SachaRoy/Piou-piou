#include "class.hpp"



// ##### Méthode de 'card' #####
void card::init(int t) {
    this->type = t;
}

void card::supr() {
    delete this;
}

int card::get_type() {
    return this->type;
}



// ##### Méthode de 'pile' #####
void pile::init() {
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
    this->data = temp;
}

void pile::supr(int nb_player) {
    card* temp_c;
    for(int i{0}; i<50-(4*nb_player); i++) {
        temp_c = this->data.front();
        this->data.pop();
        temp_c->supr();
    }
}

card* pile::draw() {
    card* temp = this->data.front();
    this->data.pop();
    return temp; 
}

void pile::discard(card* c) {
    this->data.push(c);
}



// ##### Méthode de 'player' #####
void player::init(std::string name) {
    this->score = 0;
    std::array<card*, 4> h;
    for(int i{0}; i<4; i++) {
        h[i] = nullptr;
    }
    this->hand = h;
    this->name = name;
}

void player::supr() {
    for(int i{0}; i<4; i++) {
        if(this->hand[i] != nullptr) {
            this->hand[i]->supr();
        }
    }
    delete this;
}

int player::get_score() {
    return this->score;
}

int player::get_oeufs() {
    return this->oeufs;
}

std::string player::get_name() {
    return this->name;
}

std::array<card*, 4> player::get_hand() {
    return this->hand;
}

void player::aff_hand() {
    int temp;
    std::string l1, l2, l3, l4, l5 = "";
    for(int i{0}; i<4; i++) {
        temp = this->hand[i]->get_type();
        if(temp == 0) {
            l1 += " |◠◠◕◕◕◠| ";
            l2 += " |◠◕◠◠◠◠| ";
            l3 += " |◠◕◠◠◠◠| ";
            l4 += " |◠◕◠◠◠◠| ";
            l5 += " |◠◠◕◕◕◠| ";
        }
        else if(temp == 1) {
            l1 += " |◠◕◕◕◠◠| ";
            l2 += " |◠◕◠◠◕◠| ";
            l3 += " |◠◕◕◕◠◠| ";
            l4 += " |◠◕◠◠◠◠| ";
            l5 += " |◠◕◠◠◠◠| ";
        }
        else if(temp == 2) {
            l1 += " |◠◕◠◠◕◠| ";
            l2 += " |◠◕◕◠◕◠| ";
            l3 += " |◠◕◠◕◕◠| ";
            l4 += " |◠◕◠◠◕◠| ";
            l5 += " |◠◕◠◠◕◠| ";
        }
        else {
            l1 += " |◠◕◕◕◠◠| ";
            l2 += " |◠◕◠◠◕◠| ";
            l3 += " |◠◕◕◕◠◠| ";
            l4 += " |◠◕◠◠◕◠| ";
            l5 += " |◠◕◠◠◕◠| ";
        }
    }
    std::cout << "  ______    ______    ______    ______\n" << l1 << "\n" << l2 << "\n" << l3 << "\n" << l4 << "\n" << l5 << "\n  ______    ______    ______    ______" << std::endl;
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



// ##### Méthode de 'game' #####
void game::start() {
    this->running = true;
    this->nb_player = 0;
    std::vector<player*> joueurs;
    this->j = joueurs;
    pile* temp_p = new pile;
    temp_p->init();
    this->p = temp_p;
}

void game::finish() {
    this->running = false;
    for(int i{0}; i<this->nb_player; i++) {
        this->j[i]->supr();
    }
    this->p->supr(this->nb_player);
}

bool game::is_running() {
    return this->running;
}

void game::fill_hands() {
    for(int i{0}; i<this->nb_player; i++) {
        this->j[i]->fill_hand(this->p);
    }
}

void game::add_player(std::string name) {
    player* p = new player;
    p->init(name);
    this->j.push_back(p);
    this->nb_player++;
}
