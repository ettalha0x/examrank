#include "Dummy.hpp"


Dummy::Dummy() :ATarget() {
    _type = "Target Practice Dummy";
};
Dummy::Dummy(std::string const &type) : ATarget() {
    _type = type;
};
Dummy::Dummy(Dummy const &copy) {
    *this = copy;
};
Dummy& Dummy::operator=(Dummy const &other) {
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
};
Dummy::~Dummy() {};
Dummy*        Dummy::clone() const {
    return new Dummy();
};