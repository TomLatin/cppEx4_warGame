#include "Board.hpp"

namespace WarGame {
    /**
     * @param location in the two dimensional vector <row,col>
     * @return reference pointer to a soldier
     */
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

// operator for reading which soldiers are on the game-board.
    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }

/**
    The function "move" tries to move the soldier of player "player"
    from the "source" location to the "target" location,
    and activates the special ability of the soldier.
    If the move is illegal, it throws "std::invalid_argument".
     Illegal moves include:
    * There is no soldier in the source location (i.e., the soldier pointer is null);
    * The soldier in the source location belongs to the other player.
    * There is already another soldier (of this or the other player) in the target location.
     IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
     Your code should be generic. All handling of different types of soldiers
     must be handled by polymorphism.

     The function get a source where a solider is in and an direction he need to move, if All tests from above are valid,
    The soldier moves in the desired direction. His play function is activated with polymorphism
     **/
    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
        bool legalSrcDest = true;
        std::pair<int, int> dest = getDest(source, direction);
        try
        {
            checkLegalSrc(source,player_number);
            //just return pair of int that if their values are valid we will mark the coordinates of the new soldier's location
            checkLegalDest(dest);
        }
        catch (std::invalid_argument& e)
        {
            legalSrcDest = false;
            throw std::invalid_argument(e.what()) ;
        }

        if(legalSrcDest)
        {
            Soldier*& oldLoc = (*this)[source];
            Soldier*& loc = (*this)[dest];
            loc = oldLoc;
            oldLoc= nullptr;
            if (loc != nullptr)  loc->play(dest,(*this).board,loc->getTeam());
        }
    }

    /**
     * @param source <row,col>
     * @param player_number
     * The function checks whether the position it received is valid, whether the position it received really has a
     * soldier and if there is a soldier then is it the player who is now on turn
     */
    void Board::checkLegalSrc(std::pair<int, int> source ,uint player_number) {
        int i = Board::board.size();
        int j = Board::board[0].size();

        if(source.first<0 || source.first>=i || source.second<0 ||  source.second>=j )
        {
            throw std::invalid_argument("Not found within the borders of the board\n");
        }

        if( (*this)[source] == nullptr)
        {
            throw std::invalid_argument("There is no soldier in the source location\n");
        }

        if( (*this)[source]->getTeam() != player_number)
        {
            throw std::invalid_argument("The soldier in the source location belongs to the other player\n");
        }
    }

    /**
     * @param dest <row,col>
     * The function checks whether the position it received is valid, and if the destination is not taken.
     */
    void Board::checkLegalDest(std::pair<int, int> dest)
    {
        int i = Board::board.size();
        int j = Board::board[0].size();

        if(dest.first<0 || dest.first>=i || dest.second<0 ||  dest.second>=j )
        {
            throw std::invalid_argument("Not found within the borders of the board\n");
        }
        if((*this)[dest] != nullptr)
        {
            throw std::invalid_argument("There is already another soldier (of this or the other player) in the target location\n");
        }
    }

    /**
     * @param source <row,col>
     * @return destination <row,col>
     */
    std::pair<int, int> Board::getDest( std::pair<int, int> source, MoveDIR direction)
    {
        std::pair<int, int> dest = source;
        switch(direction){
            case MoveDIR::Up:
                dest.first= dest.first+1;
                break;
            case MoveDIR::Down:
                dest.first= dest.first-1;
                break;
            case MoveDIR::Right:
                dest.second= dest.second+1;
                break;
            case MoveDIR::Left:
                dest.second= dest.second-1;
                break;
        }
        return dest;
    }

// returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const {
        int rowSize = Board::board.size();
        int colSize = Board::board[0].size();
        std::pair<int, int> temp;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j <colSize; ++j) {
                temp.first=i;
                temp.second=j;
                if((*this)[temp] != nullptr && (*this)[temp]->getTeam() == player_number)
                    return true;
            }
        }
        return false;
    }
}