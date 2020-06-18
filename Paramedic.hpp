#include "Soldier.hpp"
class Paramedic:public Soldier
{
public:
    explicit Paramedic(uint teamG,uint damagePerActivityG=0,uint maxHealthPointsG=100, TYPE typeG=TYPE::Paramedic)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myTeam) override;
};
