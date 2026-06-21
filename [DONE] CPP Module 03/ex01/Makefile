# :>

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ScavTrap.cpp ClapTrap.cpp main.cpp #! NO .HPP FILES HERE 

OBJ = $(SRC:%.cpp=obj/%.o)

$(NAME): $(OBJ)
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
