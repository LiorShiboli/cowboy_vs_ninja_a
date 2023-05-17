#pragma once
#include <string>
using namespace std;
#include "Ninja.hpp"
namespace ariel
{
    class YoungNinja:public Ninja
    {
    private:
        /* data */
    public:
        YoungNinja( string name,Point coordinate);
        void move(Character*);
    };
    
} // namespace ariel
