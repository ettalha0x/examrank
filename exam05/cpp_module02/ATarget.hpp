#pragma once


#include <iostream>
class ASpell;

class ATarget {
    protected:
        std::string _type;
    public:
        ATarget();
        ATarget(std::string const &type);
        ATarget(ATarget const &copy);
        ATarget& operator=(ATarget const &other);
        virtual ~ATarget();
        std::string const &getType() const;
        virtual ATarget*        clone() const = 0;
        void    getHitBySpell(ASpell const &spell) const ;
};

