# :>

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
HPP = WrongAnimal.hpp WrongCat.hpp Animal.hpp Cat.hpp Dog.hpp

OBJ = $(SRC:%.cpp=obj/%.o)

$(NAME): $(OBJ) $(HPP)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

obj/%.o: %.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
