#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {};

TargetGenerator::TargetGenerator(TargetGenerator const &copy) {
    
    *this = copy;
};

TargetGenerator& TargetGenerator::operator=(TargetGenerator const &other) {

    (void)other;
    return *this;
};

TargetGenerator::~TargetGenerator() {
    std::map<std::string, ATarget *>::iterator it_begin = this->arr_target.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->arr_target.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->arr_target.clear();
};

void    TargetGenerator::learnTargetType(ATarget* target) {
   if (target)
        arr_target.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
};
void    TargetGenerator::forgetTargetType(std::string const &target) {
    arr_target.erase(target);
};
ATarget*    TargetGenerator::createTarget(std::string const &target) {
    std::map<std::string, ATarget *>::iterator it = arr_target.find(target);
    if (it != arr_target.end())
        return arr_target[target];
    return NULL;
};