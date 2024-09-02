#include <iostream>
#include <vector>
#include <array>
#include <queue>


class player {
private:
    int score;
    std::array<card, 4> hand;
public:
    int get_score();
    card modif_hand(int i, card c);
};


class game {
private:
    std::queue<card> pile;
    bool running;
public:
    bool start();
    card draw();
    void discard(card c);
    bool is_running();
};

class card {
    int type;
};