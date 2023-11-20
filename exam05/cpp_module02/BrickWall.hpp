#ifndef BrickWall_hpp
#define BrickWall_hpp

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

class BrickWall : public ATarget {
    public:
        BrickWall();
        BrickWall(std::string const &type);
        BrickWall(BrickWall const &copy);
        BrickWall& operator=(BrickWall const &other);
        ~BrickWall();
        virtual BrickWall*        clone() const;
};

#endif