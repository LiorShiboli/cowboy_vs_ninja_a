#include <string>
using namespace std;
#include "Ninja.hpp"
namespace ariel{
    class OldNinja:public Ninja
    {
    private:
    /* data */
    public:
        OldNinja( string name,Point coordinate);
    };
}