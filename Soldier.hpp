#pragma once
#include <iostream>
#include <vector>
#define uint unsigned int
using namespace std;

    class Soldier
    {
    protected:
        //Fields
        const uint damagePerActivity;
        const uint team;
        const uint maxHealthPoints;
        int currentHealthPoints;
        enum TYPE{FootCommander,FootSoldier,Paramedic,ParamedicCommander,Sniper,SniperCommander};
        const TYPE type;

    public:
        //Constructor
        Soldier(uint teamG,uint damagePerActivityG,uint maxHealthPointsG, TYPE typeG)
        :team(teamG),damagePerActivity(damagePerActivityG),maxHealthPoints(maxHealthPointsG),currentHealthPoints(maxHealthPointsG),type(typeG){}

        //Gets
        int getCurrentHealthPoints() const ;
        uint getDamagePerActivity() const ;
        uint getTeam() const;
        TYPE getType() const
        {
            return type;
        }

        //Regular function
        void damage(uint damage,Soldier ** pos);
        std::pair<int, int> nearestSoldier (std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam);
        std::pair<int, int> findStrongestSoldier(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam);
        void healsAllSoldiers(std::pair<int, int> pos, std::vector<std::vector<Soldier *>> &board, uint myTeam);
        void refillLife();

        //Virtual functions
        virtual void play(std::pair<int, int> pos, vector<vector<Soldier*>>& board, uint myTeam)=0;

        //Destructor
        virtual ~Soldier(){};
    };
