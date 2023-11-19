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
        arr.insert(std::pair<std::string, ASpell*> (spell->getName(), spell->clone()));
};
void    Warlock::forgetSpell(std::string spell_name) {
    std::map<std::string, ASpell*>::iterator it = arr.find(spell_name);
    if (it != arr.end())
        delete it->second;
    arr.erase(spell_name);
};
void    Warlock::launchSpell(std::string spell_name, ATarget const &target) {
    ASpell* spell = arr[spell_name];
    if (spell)
        spell->launch(target);
};