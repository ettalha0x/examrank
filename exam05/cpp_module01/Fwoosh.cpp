#include "Fwoosh.hpp"


Fwoosh::Fwoosh() :ASpell() {
    _name = "Fwoosh";
    _effects = "fwooshed";
};
Fwoosh::Fwoosh(std::string const &name, std::string const &effects) : ASpell() {
    _name = name;
    _effects = effects;
};
Fwoosh::Fwoosh(Fwoosh const &copy) {
    *this = copy;
};
Fwoosh& Fwoosh::operator=(Fwoosh const &other) {
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return *this;
};
Fwoosh::~Fwoosh() {};
Fwoosh*        Fwoosh::clone() const {
    return new Fwoosh();
};