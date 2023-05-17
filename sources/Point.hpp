#pragma once
#include <string>
namespace ariel
{
    


    class Point
    {
    private:
        /* data */
    public:
        Point(double x, double y);
        double get_y();
        double get_x();
        void set_y(double);
        void set_x(double);
        double distance(Point other);
        std::string print();
        static Point moveTorwards(Point from, Point torwards, double distance);
    };

 }// namespace ariel
