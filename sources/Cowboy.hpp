#pragma once
#include <string>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        /* data */
    public:
        Cowboy(string name, Point coordinate);
        void shoot(Character* enemy);
        string print();
    };
    
    
} // namespace ariel
