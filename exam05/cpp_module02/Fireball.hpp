#pragma once


#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

class Fireball : public ASpell {
    public:
        Fireball();
        Fireball(std::string const &name, std::string const &effects);
        Fireball(Fireball const &copy);
        Fireball& operator=(Fireball const &other);
        ~Fireball();
        virtual Fireball*        clone() const;
};

