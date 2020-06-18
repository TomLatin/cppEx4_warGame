#pragma once
#include "Soldier.hpp"

class FootSoldier:public Soldier
{
public:
    explicit FootSoldier (uint teamG,uint damagePerActivityG=10,uint maxHealthPointsG=100, TYPE typeG=TYPE::FootSoldier)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myTeam) override;
};//end FootSoldier

