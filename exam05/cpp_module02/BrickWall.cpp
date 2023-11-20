#include "BrickWall.hpp"


BrickWall::BrickWall() :ATarget() {
    _type = "Inconspicuous Red-brick Wall";
};
BrickWall::BrickWall(std::string const &type) : ATarget() {
    _type = type;
};
BrickWall::BrickWall(BrickWall const &copy) {
    *this = copy;
};
BrickWall& BrickWall::operator=(BrickWall const &other) {
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
};
BrickWall::~BrickWall() {};
BrickWall*        BrickWall::clone() const {
    return new BrickWall();
};