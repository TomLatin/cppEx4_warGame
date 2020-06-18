#include "SniperCommander.hpp"

/**
 * Like a sniper, but when he moves, not only does he shoot but all the sniper's shoot.
 * @param pos
 * @param board
 * @param myTeam
 */
void SniperCommander::play(std::pair<int, int> pos, std::vector <std::vector<Soldier *>> &board, uint myTeam) {
    //the commander shot
    Soldier** loc = &board[pos.first][pos.second];
    std::pair<int, int> maxPos=(*loc)->findStrongestSoldier(pos ,board ,myTeam);
    if(maxPos.first!= -1 && maxPos.second!=-1)
    {
        Soldier** s=&board[maxPos.first][maxPos.second];
        if(s!= nullptr)
            (*s)->damage(board[pos.first][pos.second]->getDamagePerActivity(),s);
    }

    //all the footSoldier is shot
    int rowSize = board.size();
    int colSize = board[0].size();
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            if (board[i][j]!= nullptr && board[i][j]->getTeam() == myTeam && board[i][j]->getType() == TYPE::Sniper)
            {
                board[i][j]->play(std::pair<int,int>{i,j}, board, myTeam);
            }
        }
    }
}



