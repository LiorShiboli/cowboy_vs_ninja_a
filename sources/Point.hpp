#include <string>
    class Point
    {
    private:
        /* data */
    public:
        Point(double x, double y);
        double distance(Point other);
        std::string print();
        void moveTorwards(Point other);
    };

 // namespace ariel
