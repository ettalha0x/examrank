#pragma once


#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

class Dummy : public ATarget {
    public:
        Dummy();
        Dummy(std::string const &type);
        Dummy(Dummy const &copy);
        Dummy& operator=(Dummy const &other);
        ~Dummy();
        virtual Dummy*        clone() const;
};

