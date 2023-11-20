NAME = main
SRCS = main.cpp ../cpp_module02/Warlock.cpp \
		../cpp_module02/ASpell.cpp ../cpp_module02/ATarget.cpp ../cpp_module02/Dummy.cpp ../cpp_module02/Fwoosh.cpp \
		../cpp_module02/Polymorph.cpp ../cpp_module02/SpellBook.cpp ../cpp_module02/TargetGenerator.cpp ../cpp_module02/Fireball.cpp ../cpp_module02/BrickWall.cpp

OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

%.o:%.cpp easyfind.hpp
		c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		c++ $^ -o $@

all : $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
