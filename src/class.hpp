#include <iostream>
#include <vector>
#include <array>
#include <queue>


class card {
private:
    int type;
public:
    void init(int t);
    void supr();
    int get_type();
};


class pile {
private:
    std::queue<card*> data;
public:
    void init();
    void supr(int nb_player);
    card* draw();
    void discard(card* c);
};


class player {
private:
    int score;
    int oeufs;
    std::array<card*, 4> hand;
    std::string name;
public:
    void init(std::string name);
    void supr();
    int get_score();
    int get_oeufs();
    std::string get_name();
    std::array<card*, 4> get_hand();
    void aff_hand();
    void fill_hand(pile* p);
    card* modif_hand(int i, card* c);
};


class game {
private:
    pile* p;
    bool running;
public:
    void start();
    void finish();
    bool is_running();
    int nb_player;
    std::vector<player*> j;
    void fill_hands();
    void add_player(std::string name);
};
