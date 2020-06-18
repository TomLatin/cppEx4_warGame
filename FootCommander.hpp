#include "Soldier.hpp"

class FootCommander:public Soldier
{
public:
    explicit FootCommander (uint teamG,uint damagePerActivityG=20,uint maxHealthPointsG=150, TYPE typeG=TYPE::FootCommander)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myTeam) override;

}; //end FootCommander
