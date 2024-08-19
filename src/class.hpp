#include <iostream>
#include <vector>
#include <array>
#include <queue>


class player {
private:
    int score;
    std::array<card*, 4> hand;
public:
    bool init();
    bool supr();
    int get_score();
    card* modif_hand(int i, card* c);
};


class game {
private:
    pile* p;
    std::vector<player*> j;
public:
    bool init();
    bool supr();
    void add_player();
    bool running;
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


class card {
    private:
        int type;
    public:
        bool init(int t);
        bool supr();
};
