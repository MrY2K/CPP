# :>

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp  main.cpp
HPP = AMateria.hpp Character.hpp Cure.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp ICharacter.hpp

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
