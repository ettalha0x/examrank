#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook() {};

SpellBook::SpellBook(SpellBook const &copy) {
    
    *this = copy;
};

SpellBook& SpellBook::operator=(SpellBook const &other) {

    (void)other;
    return *this;
};

SpellBook::~SpellBook() {
};

void    SpellBook::learnSpell(ASpell *spell) {
    if (spell)
        arr_spell.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
};
void    SpellBook::forgetSpell(std::string const &spell_name) {
    arr_spell.erase(spell_name);
};
ASpell*    SpellBook::createSpell(std::string const &spell_name) {
    
    std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
    if (it != arr_spell.end())
        return arr_spell[spell_name];
    return NULL;
   
};