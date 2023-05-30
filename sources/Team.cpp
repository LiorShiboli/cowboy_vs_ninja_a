#include "Team.hpp"
namespace ariel
{
    Team::Team(Character* ){}
    Team::~Team(){}
    void Team::add(Character*){}
    Character* Team::getLeader(){
        return new Cowboy("django",Point(0,0));
    }
    int  Team::stillAlive(){return 0;}
    void  Team::attack(Team*){}
    string  Team::print(){return "";}
} // namespace ariel
