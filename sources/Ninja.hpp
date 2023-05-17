#pragma once
#include <string>
using namespace std;
#include "Character.hpp"
namespace ariel
{
    class Ninja:public Character
    {
    private:
        /* data */
    public:
        Ninja(string name,Point coordinate);
        virtual void move(Character* enemy);
        void slash(Character* enemy);
    };
    
} // namespace ariel
