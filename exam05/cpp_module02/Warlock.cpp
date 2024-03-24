#include "Warlock.hpp"

Warlock::Warlock() {};

Warlock::Warlock(std::string const &name, std::string const &title) :_name(name), _title(title){
    std::cout << _name << ": " << "This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const &copy) {
    
    *this = copy;
};

Warlock& Warlock::operator=(Warlock const &other) {
    this->_name = other.getName();
    this->_title = other.getTitle();

    return *this;
};

Warlock::~Warlock() {
    std::cout << _name << ": " << "My job here is done!" << std::endl;
};

std::string const &Warlock::getName() const {
    return _name;
}

std::string const &Warlock::getTitle() const {
    return _title;
}

void Warlock::setTitle(std::string const &title) {
    _title = title;
}

void Warlock::introduce() const {
    std::cout << _name << ": " << "I am " << _name << ", " << _title  << "!"<< std::endl;
}

void    Warlock::learnSpell(ASpell *spell) {
    if (spell)
        book.learnSpell(spell);
};
void    Warlock::forgetSpell(std::string spell_name) {
  book.forgetSpell(spell_name);
};
void    Warlock::launchSpell(std::string spell_name, ATarget const &target) {
    ASpell* spell = book.createSpell(spell_name);
    if (spell)
        spell->launch(target);
};