#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ATarget;

class Warlock {
    private:
        std::string _name;
        std::string _title;
        Warlock();
        Warlock(Warlock const &copy);
        Warlock& operator=(Warlock const &other);

        SpellBook book;
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void    setTitle(std::string const &title);
        void    introduce() const;

        void    learnSpell(ASpell *spell);
        void    forgetSpell(std::string spell_name);
        void    launchSpell(std::string spell_name, ATarget const &target);

};
