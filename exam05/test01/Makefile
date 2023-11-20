NAME = main
SRCS = main.cpp ../cpp_module01/Warlock.cpp \
		../cpp_module01/ASpell.cpp ../cpp_module01/ATarget.cpp ../cpp_module01/Dummy.cpp ../cpp_module01/Fwoosh.cpp

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
