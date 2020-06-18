#include "Paramedic.hpp"

/**
 * Paramedic does not fire at all, but only heals all the soldiers of the same player who are in the slot
 * (returns their number of health points to the starting number).
 * @param pos
 * @param board
 * @param myTeam
 */
void Paramedic::play(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam) {
    Soldier** loc = &board[pos.first][pos.second];
   (*loc)->healsAllSoldiers(pos ,board ,myTeam);
}
