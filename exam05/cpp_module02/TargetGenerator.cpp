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