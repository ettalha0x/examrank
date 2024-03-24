#pragma once

#include <iostream>

class Warlock {
    private:
        std::string _name;
        std::string _title;
        Warlock();
        Warlock(Warlock const &copy);
        Warlock& operator=(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void        setTitle(std::string const &title);
        void introduce() const;
};

