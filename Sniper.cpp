#include "Sniper.hpp"

    /**
     * Sniper - Can go one slot in any direction. Shoots at the enemy’s strongest soldier - the one who has the most
     * health points (if there are some - he chooses one of them arbitrarily).
     * @param pos pos Soldier's location on the board
     * @param board
     * @param myTeam
     */
    void Sniper::play(std::pair<int, int> pos, std::vector <std::vector<Soldier *>> &board, uint myTeam) {

        Soldier** loc = &board[pos.first][pos.second];
        std::pair<int, int> maxPos=(*loc)->findStrongestSoldier(pos ,board ,myTeam);
        if(maxPos.first!= -1 && maxPos.second!=-1)
        {
            Soldier** s=&board[maxPos.first][maxPos.second];
            if(s!= nullptr)
                (*s)->damage(board[pos.first][pos.second]->getDamagePerActivity(),s);
        }
    }

