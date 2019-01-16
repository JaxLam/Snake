#ifndef GAME_H
#define GAME_H

class Game {
    public:
        void startGame();
    private:
        bool win() const;
        bool lose() const;
};

#endif