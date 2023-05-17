#include "Character.hpp"
namespace ariel
{
    


    Character::Character(int hitPoints,string name,Point coordinate){}
    bool Character::isAlive(){return true;}
    void Character::hit(int damage){}
    string Character::get_name(){return "";}
    Point Character::get_location(){
        return Point(0,0);
    }
    string Character::print(){
        return "";
    }
    } // namespace ariel