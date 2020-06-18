#include "Soldier.hpp"
class Sniper:public Soldier
{
public:
    explicit Sniper(uint teamG,uint damagePerActivityG=50,uint maxHealthPointsG=100, TYPE typeG=TYPE::Sniper)
            :Soldier(teamG,damagePerActivityG,maxHealthPointsG,typeG){};

    void play(std::pair<int, int> pos, std::vector<std::vector<Soldier*>>& board, uint myType) override;
};//end Sniper

