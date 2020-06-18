#include "Soldier.hpp"

class SniperCommander:public Soldier
{
public:
    explicit SniperCommander (uint teamG,uint damagePerActivityG=100,uint maxHealthPointsG=120, TYPE typeG=TYPE::SniperCommander)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myType) override;

};//end SniperCommander

