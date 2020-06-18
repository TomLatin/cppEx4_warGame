#include "ParamedicCommander.hpp"

/**
 * Like a paramedic, but when he moves, all the player's paramedic heal the soldiers who are near them.
 * @param pos
 * @param board
 * @param myTeam
 */
void ParamedicCommander::play(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam) {
   //the commander shot
    Soldier** loc = &board[pos.first][pos.second];
    (*loc)->healsAllSoldiers(pos ,board ,myTeam);

    //all the footSoldier is shot
    int rowSize = board.size();
    int colSize = board[0].size();
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            if (board[i][j] != nullptr && board[i][j]->getTeam() == myTeam && board[i][j]->getType() == TYPE::Paramedic) {
                board[i][j]->play(std::pair<int,int>{i,j}, board, myTeam);
            }
        }
    }
}

