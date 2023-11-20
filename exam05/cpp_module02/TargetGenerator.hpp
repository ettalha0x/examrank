#ifndef TargetGenerator_hpp
#define TargetGenerator_hpp

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
    private:
        std::map<std::string, ATarget *> arr_target;
        TargetGenerator(TargetGenerator const &copy);
        TargetGenerator& operator=(TargetGenerator const &other);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(std::string const &target);
        ATarget* createTarget(std::string const &target);
};

#endif