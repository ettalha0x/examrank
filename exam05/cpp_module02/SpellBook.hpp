#pragma once

#include "ATarget.hpp"
#include <map>
class SpellBook {
    private:
        std::map<std::string, ASpell *> arr_spell;

        SpellBook(SpellBook const &copy);
        SpellBook& operator=(SpellBook const &other);
    public:
        SpellBook();
        virtual ~SpellBook();
        void    learnSpell(ASpell *spell);
        void    forgetSpell(std::string const &spell_name);
        ASpell*    createSpell(std::string const &spell_name);
};
