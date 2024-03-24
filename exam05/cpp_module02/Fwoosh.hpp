#pragma once


#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

class Fwoosh : public ASpell {
    public:
        Fwoosh();
        Fwoosh(std::string const &name, std::string const &effects);
        Fwoosh(Fwoosh const &copy);
        Fwoosh& operator=(Fwoosh const &other);
        ~Fwoosh();
        virtual Fwoosh*        clone() const;
};

