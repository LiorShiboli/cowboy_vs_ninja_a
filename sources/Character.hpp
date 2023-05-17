#pragma once
#include <string>
using namespace std;
#include "Point.hpp"
namespace ariel
{
    class Character
    {
    private:
        /* data */
    public:
        Character(int hitPoints,string name,Point coordinate);
        bool isAlive();
        virtual void hit(int damage);
        string get_name();
        Point get_location();
        virtual string print();
        int get_HP();
    };
    
} // namespace ariel
