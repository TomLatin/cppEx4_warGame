#include "Soldier.hpp"
#include <cmath>
#include<bits/stdc++.h>

/*Gets*/

int Soldier::getCurrentHealthPoints() const
{
    return currentHealthPoints;
}

uint Soldier::getDamagePerActivity() const
{
    return damagePerActivity;
}

uint Soldier::getTeam() const
{
    return team;
}

/*Regular function*/

void Soldier::damage(uint damage,Soldier** soldier)
{
    currentHealthPoints-=damage;
    if(currentHealthPoints<=0)
    {
        *(soldier)= nullptr;
    }
}

void Soldier::refillLife()
{
    currentHealthPoints=maxHealthPoints;
}

/**
 *
 * @param pos
 * @param board
 * @param myTeam
 * @return The position of the enemy soldier closest to the soldier's position that the function get
 */
std::pair<int, int> Soldier::nearestSoldier (std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam)
{
    int rowSize = board.size();
    int colSize = board[0].size();
    std::pair<int, int> minPos={-1,-1};
    int min=INT_MAX;
    int tempMin=INT_MAX;

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j <colSize; ++j) {
            if(board[i][j]!= nullptr && board[i][j]->getTeam()!= myTeam)
            {
                tempMin=sqrt(pow(pos.first-i,2)+pow(pos.second-j,2));
                if(min>tempMin)
                {
                    min=tempMin;
                    minPos=std::pair<int,int>{i,j};
                }
            }
        }
    }

    return minPos;
}

/**
 *
 * @param pos
 * @param board
 * @param myTeam
 * @return The position of the enemy’s strongest soldier
 */
std::pair<int, int> Soldier::findStrongestSoldier(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam)
{
    int rowSize = board.size();
    int colSize = board[0].size();
    std::pair<int, int> maxPos={-1,-1};
    int max=0;
    int tempMax=0;
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j <colSize; ++j) {
            if(board[i][j]!= nullptr && board[i][j]->getTeam()!= myTeam)
            {
                tempMax=board[i][j]->getCurrentHealthPoints();
                if(max<tempMax)
                {
                    max=tempMax;
                    maxPos=std::pair<int,int>{i,j};
                }
            }
        }
    }
    return maxPos;
}

/**
 * Heals all the soldiers of the same player who are in the slot next to him
 * @param pos
 * @param board
 * @param myTeam
 */
void Soldier::healsAllSoldiers(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam)
{
    for (int i = pos.first - 1; i <= pos.first + 1 && i < board.size(); ++i) {
        if(i<0) i=0;
        for (int j = pos.second - 1; j <= pos.second + 1 && j < board[i].size(); ++j) {
            if(j<0) j=0;
            if (board[i][j] != nullptr && board[i][j]->getTeam() == myTeam) {
                if(i!=pos.first || j!=pos.second) board[i][j]->refillLife();
            }
        }
    }
}