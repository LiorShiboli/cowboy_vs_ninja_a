#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;
#include "doctest.h"
#include "sources/Team.hpp" //no need for other includes

using namespace ariel;
TEST_SUITE("point"){
    TEST_CASE("intialize point"){
        //zero 
        CHECK_NOTHROW(Point(0,0));
        //negative numbers
        CHECK_NOTHROW(Point(-1,1));
        CHECK_NOTHROW( Point(-3,-4));
        //decimal numbers
        CHECK_NOTHROW(Point(15.7,0.06));
        //big numbers and small numbers
        double biggest = numeric_limits<double>::max();
        double smallest = numeric_limits<double>::min();
        CHECK_NOTHROW(Point(biggest,smallest));

    }
    TEST_CASE("getters and setters"){
        Point origin = Point(0,0);
        CHECK_EQ(origin.get_x(),0);
        CHECK_EQ(origin.get_y(),0);
        origin.set_x(3.75);
        origin.set_y(-7);
        CHECK_EQ(origin.get_x(),3.75);
        CHECK_EQ(origin.get_y(),-7);
    }
    TEST_CASE("distance"){
        SUBCASE("pythogaras triplets(integars)"){
            Point origin = Point(0,0);
            Point pythoTrip =Point(3,4);
            CHECK_EQ(origin.distance(pythoTrip),5);
            CHECK_EQ(pythoTrip.distance(origin),5);
            origin = Point(7,-8);
            pythoTrip = Point(12,4);
            CHECK_EQ(origin.distance(pythoTrip),13);
            CHECK_EQ(pythoTrip.distance(origin),13);
        }
        SUBCASE("decimal"){
            Point coordinate1= Point(0.5,5.89);
            Point coordinate2 = Point(-7.9,16.3);
            CHECK_EQ(coordinate1.distance(coordinate2)-13.37640,doctest::Approx(0.0001));
            coordinate1= Point(-11.9885,80.4487);
            coordinate2 = Point(-59.6908,-0.373);
            CHECK_EQ(coordinate1.distance(coordinate2)-	93.8491,doctest::Approx(0.001));
        }
        SUBCASE("overflow"){
            double biggest = numeric_limits<double>::max();
            Point coordinate1 = Point(biggest,1);
            Point coordinate2 = Point(3,-biggest+15);
            CHECK_THROWS_AS(coordinate1.distance(coordinate2),std::overflow_error);
            CHECK_THROWS_AS(coordinate2.distance(coordinate1),std::overflow_error);

        }
    }
    TEST_CASE("move torwards"){
        SUBCASE("closer than distance"){
            Point move_to = Point(0,0);
            Point from = Point(8.5,-9.75);
            Point newPoint = Point::moveTorwards(from,move_to,13);
            CHECK_EQ(newPoint.get_x(),0);
            CHECK_EQ(newPoint.get_y(),0);
        }
        SUBCASE("further than"){
            Point move_to = Point(0,0);
            Point from = Point(8.5,-9.75);
            Point newPoint = Point::moveTorwards(from,move_to,5);
            CHECK_EQ(newPoint.distance(move_to)-8,doctest::Approx(0.001));
            move_to = Point(-3,-4);
            from = Point(9,7);
            newPoint = Point::moveTorwards(from,move_to,5);
            CHECK_EQ(newPoint.distance(move_to)-11.27882,doctest::Approx(0.001));
        }
    }

}
TEST_SUITE("characters"){
    TEST_CASE("initialization and getters"){
        SUBCASE("cowboy"){
            Character django = Cowboy("django",Point(0,0));
            Cowboy McRee = Cowboy("jesse",Point(4,20));
            CHECK_EQ(django.get_name(),"django");
            CHECK_EQ(McRee.get_name(),"jesse");
            Point location=django.get_location();
            CHECK_EQ(location.get_x(),0);
            CHECK_EQ(location.get_y(),0);
            location = McRee.get_location();
            CHECK_EQ(location.get_x(),4);
            CHECK_EQ(location.get_y(),20);
        }
        SUBCASE("Ninja"){
            Character rock = Ninja("lee",Point(0,0));
            Ninja punk = Ninja("boruto",Point(4,20));
            CHECK_EQ(rock.get_name(),"lee");
            CHECK_EQ(punk.get_name(),"boruto");
            Point location=rock.get_location();
            CHECK_EQ(location.get_x(),0);
            CHECK_EQ(location.get_y(),0);
            location = punk.get_location();
            CHECK_EQ(location.get_x(),4);
            CHECK_EQ(location.get_y(),20);
        }
        SUBCASE("OldNinja"){
            Ninja bruce = OldNinja("lee",Point(0,0));
            OldNinja sensei = OldNinja("kakashi",Point(4,20));
            CHECK_EQ(bruce.get_name(),"lee");
            CHECK_EQ(sensei.get_name(),"kakashi");
            Point location=bruce.get_location();
            CHECK_EQ(location.get_x(),0);
            CHECK_EQ(location.get_y(),0);
            location = sensei.get_location();
            CHECK_EQ(location.get_x(),4);
            CHECK_EQ(location.get_y(),20);
        }
        SUBCASE("YoungNinja"){
            Ninja naruto= YoungNinja("naruto",Point(0,0));
            YoungNinja sakura = YoungNinja("sakura",Point(4,20));
            CHECK_EQ(naruto.get_name(),"django");
            CHECK_EQ(sakura.get_name(),"jesse");
            Point location=naruto.get_location();
            CHECK_EQ(location.get_x(),0);
            CHECK_EQ(location.get_y(),0);
            location = sakura.get_location();
            CHECK_EQ(location.get_x(),4);
            CHECK_EQ(location.get_y(),20);
        }
        SUBCASE("TrainedNinja"){
            Ninja zoro = TrainedNinja("zoro",Point(0,0));
            TrainedNinja luffy = TrainedNinja("luffy",Point(4,20));
            CHECK_EQ(zoro.get_name(),"zoro");
            CHECK_EQ(luffy.get_name(),"zoro");
            Point location=zoro.get_location();
            CHECK_EQ(location.get_x(),0);
            CHECK_EQ(location.get_y(),0);
            location = luffy.get_location();
            CHECK_EQ(location.get_x(),4);
            CHECK_EQ(location.get_y(),20);
        }
    }
    TEST_CASE("move towards"){
        SUBCASE("OldNinja"){
            Ninja bruce = Ninja("lee",Point(0,0));
            OldNinja sensei = OldNinja("kakashi",Point(8,8));
            sensei.move(&bruce);
            Point location=sensei.get_location();
            CHECK_EQ(sensei.get_location().distance(Point(0,0)),bruce.get_location().distance(Point(8,8))-8);
            sensei.move(&bruce);
            CHECK_EQ(sensei.get_location().distance(bruce.get_location()),0);
        }
        SUBCASE("YoungNinja"){
            Ninja bruce = Ninja("lee",Point(0,0));
            OldNinja sensei = OldNinja("kakashi",Point(14,14));
            sensei.move(&bruce);
            Point location=sensei.get_location();
            CHECK_EQ(sensei.get_location().distance(Point(0,0)),bruce.get_location().distance(Point(14,14))-14);
            sensei.move(&bruce);
            CHECK_EQ(sensei.get_location().distance(bruce.get_location()),0);
        }
        SUBCASE("TrainedNinja"){
            Ninja bruce = Ninja("lee",Point(0,0));
            OldNinja sensei = OldNinja("kakashi",Point(12,12));
            sensei.move(&bruce);
            Point location=sensei.get_location();
            CHECK_EQ(sensei.get_location().distance(Point(0,0)),bruce.get_location().distance(Point(12,12))-12);
            sensei.move(&bruce);
            CHECK_EQ(sensei.get_location().distance(bruce.get_location()),0);
        }
    }
    TEST_CASE("hit points"){
        SUBCASE("hit and is alive"){
            Character dummy = Character(500,"generic name",Point(0,0));
            CHECK(dummy.isAlive());
            dummy.hit(250);
            CHECK(dummy.isAlive());
            CHECK_EQ(dummy.get_HP(),250);
            dummy.hit(250);
            CHECK(!dummy.isAlive());
            CHECK_EQ(dummy.get_HP(),0);
            dummy.hit(250);
            CHECK(!dummy.isAlive());
            CHECK_EQ(dummy.get_HP(),0);
        }
        SUBCASE("slash"){
            Character dummy = Character(500,"generic name",Point(0,0));
            Ninja cut = YoungNinja("name",Point(1,1));
            cut.slash(&dummy);
            CHECK_EQ(dummy.get_HP(),500);
            cut.move(&dummy);
            cut.slash(&dummy);
            CHECK_EQ(dummy.get_HP(),460);
            cut.hit(1000);
            cut.slash(&dummy);
            CHECK_EQ(dummy.get_HP(),460);            
        }
        SUBCASE("shoot"){
            Character dummy = Character(500,"generic name",Point(0,0));
            Cowboy shooty = Cowboy("name",Point(0,0));
            CHECK(shooty.hasboolets());
            for (int i = 1; i <= 6; i++)
            {
                shooty.shoot(&dummy);
                CHECK_EQ(dummy.get_HP(),500-10*i);
            }
            CHECK(!shooty.hasboolets());
            shooty.shoot(&dummy);
            CHECK_EQ(dummy.get_HP(),440);
            shooty.reload();
            CHECK(shooty.hasboolets());
            shooty.shoot(&dummy);
            CHECK_EQ(dummy.get_HP(),430);            
        }
    }
    
    
}
TEST_SUITE("Team"){
    TEST_CASE("intialize"){
        Team team1 = Team(new Cowboy("jango",Point(0,0)));
        Team team2 = Team(new OldNinja("miyagi",Point(1,2)));
        CHECK_EQ(team1.getLeader()->get_location().get_x(),0);
        CHECK_EQ(team1.getLeader()->get_location().get_y(),0);
        CHECK_EQ(team2.getLeader()->get_location().get_x(),1);
        CHECK_EQ(team2.getLeader()->get_location().get_y(),2);
        CHECK_EQ(team1.getLeader()->get_name(),"jango");
        CHECK_EQ(team1.getLeader()->get_name(),"miyagi");
        CHECK_EQ(team1.stillAlive(),1);
        CHECK_EQ(team2.stillAlive(),1);
    }
    TEST_CASE("attack"){
        SUBCASE("ninja attacks"){
            Character* leader =new Cowboy("jango",Point(0,0));
            Team team1 = Team(leader);
            team1.add(new Cowboy("jango",Point(1,2)));
            Team team2 = Team(new OldNinja("miyagi",Point(1,2)));
            team2.attack(&team1);
            CHECK(team2.stillAlive()==2);
            while (team1.stillAlive()>0)
            {
                team2.attack(&team1);
            }
            CHECK_FALSE(leader->isAlive());
            CHECK(team2.stillAlive()==1);
            
        }
        SUBCASE("ninja attacks"){
            Character* leader =new OldNinja("miyagi",Point(1,2));
            Team team1 = Team(new Cowboy("jango",Point(0,0)));
            team1.add(new Cowboy("jango",Point(1,2)));
            Team team2 = Team(leader);
            team1.attack(&team2);
            CHECK(team2.stillAlive()==1);
            while (team2.stillAlive()>0)
            {
                team1.attack(&team2);
            }
            CHECK_FALSE(leader->isAlive());
            CHECK(team1.stillAlive()==2);
            
        }
        SUBCASE("cant attack itself"){
            Team team1 = Team(new Cowboy("jango",Point(0,0)));
            CHECK_THROWS(team1.attack(&team1));
        }
    }
}