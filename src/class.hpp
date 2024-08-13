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
public:
    card draw();
    void discard(card c);
};

class card {
    int type;
};