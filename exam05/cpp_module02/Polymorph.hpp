#ifndef Polymorph_hpp
#define Polymorph_hpp

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

class Polymorph : public ASpell {
    public:
        Polymorph();
        Polymorph(std::string const &name, std::string const &effects);
        Polymorph(Polymorph const &copy);
        Polymorph& operator=(Polymorph const &other);
        ~Polymorph();
        virtual Polymorph*        clone() const;
};

#endif