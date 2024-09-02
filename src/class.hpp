#include <iostream>
#include <vector>
#include <array>
#include <queue>


class card {
private:
    int type;
public:
    bool init(int t);
    bool supr();
};


class pile {
private:
    std::queue<card> data;
public:
    bool init();
    bool supr();
    card* draw();
    void discard(card* c);
};


class player {
private:
    int score;
    std::array<card*, 4> hand;
    std::string name;
public:
    bool init(std::string name);
    bool supr();
    int get_score();
    std::string get_name();
    card* modif_hand(int i, card* c);
};


class game {
private:
    pile* p;
    bool running;
public:
    bool start();
    bool finish();
    bool is_running();
    int nb_player;
    std::vector<player*> j;
    bool fill_hands();
    void add_player(std::string name);
};
