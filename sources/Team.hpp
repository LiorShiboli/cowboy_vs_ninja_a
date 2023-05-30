#pragma once
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
namespace ariel
{
    class Team
    {
    private:
        /* data */
    public:
        Team(Character* );
        ~Team();
        virtual Character* getLeader();
        virtual void add(Character*);
        virtual int stillAlive();
        virtual void attack(Team*);
        virtual string print();
    };
    
} // namespace ariel
