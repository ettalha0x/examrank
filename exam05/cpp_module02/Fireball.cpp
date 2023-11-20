#include "Fireball.hpp"


Fireball::Fireball() :ASpell() {
    _name = "Fireball";
    _effects = "burnt to a crisp";
};
Fireball::Fireball(std::string const &name, std::string const &effects) : ASpell() {
    _name = name;
    _effects = effects;
};
Fireball::Fireball(Fireball const &copy) {
    *this = copy;
};
Fireball& Fireball::operator=(Fireball const &other) {
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return *this;
};
Fireball::~Fireball() {};
Fireball*        Fireball::clone() const {
    return new Fireball();
};