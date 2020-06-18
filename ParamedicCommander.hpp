#include "Soldier.hpp"
class ParamedicCommander:public Soldier
{
public:
    explicit ParamedicCommander (uint teamG,uint damagePerActivityG=0,uint maxHealthPointsG=200, TYPE typeG=TYPE::ParamedicCommander)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myTeam) override;
};
