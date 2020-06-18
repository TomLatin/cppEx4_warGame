#include "FootSoldier.hpp"

/**
 * FootSoldier fires at the enemy soldier closest to him (if there are any - he fires one of them arbitrarily).
 * @param pos Soldier's location on the board
 * @param board
 * @param myTeam
 */
void FootSoldier::play(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam) {

    Soldier** loc = &board[pos.first][pos.second];
    std::pair<int, int> minPos=(*loc)->nearestSoldier( pos, board,  myTeam);
    if(minPos.first!= -1 && minPos.second!=-1)
    {
        Soldier** s=&board[minPos.first][minPos.second];
        if(s!= nullptr)
            (*s)->damage(board[pos.first][pos.second]->getDamagePerActivity(),s);
    }
}
