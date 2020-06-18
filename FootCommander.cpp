#include "FootCommander.hpp"

    /**
     * Like FootSoldier, but when he moves, not only does he shoot but all the soldier's foot soldiers shoot.
     * @param pos pos Soldier's location on the board
     * @param board
     * @param myTeam
     */
    void FootCommander::play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myTeam)
    {
        //the commander shot
        Soldier** loc = &board[pos.first][pos.second];
        std::pair<int, int> minPos=(*loc)->nearestSoldier( pos, board,  myTeam);
        if(minPos.first!= -1 && minPos.second!=-1)
        {
            Soldier** s=&board[minPos.first][minPos.second];
            if(s!= nullptr)
                (*s)->damage(board[pos.first][pos.second]->getDamagePerActivity(),s);
        }

        //all the footSoldier is shot
        int rowSize = board.size();
        int colSize = board[0].size();
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if(board[i][j]!= nullptr && board[i][j]->getTeam() == myTeam && board[i][j]->getType()==TYPE::FootSoldier)
                {
                    board[i][j]->play(std::pair<int,int>{i,j},board,myTeam);
                }
            }
        }
    }


