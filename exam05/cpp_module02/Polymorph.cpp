#include "Polymorph.hpp"


Polymorph::Polymorph() :ASpell() {
    _name = "Polymorph";
    _effects = "turned into a critter";
};
Polymorph::Polymorph(std::string const &name, std::string const &effects) : ASpell() {
    _name = name;
    _effects = effects;
};
Polymorph::Polymorph(Polymorph const &copy) {
    *this = copy;
};
Polymorph& Polymorph::operator=(Polymorph const &other) {
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return *this;
};
Polymorph::~Polymorph() {};
Polymorph*        Polymorph::clone() const {
    return new Polymorph();
};