#include "Cowboy.hpp"
namespace ariel
{
    Cowboy::Cowboy(string name, Point coordinate):Character(0,name,coordinate){}
    void Cowboy::shoot(Character* enemy){}
    string Cowboy::print(){return "";}
    bool Cowboy::hasboolets(){return true;}
    void Cowboy::reload(){}
} // namespace ariel
