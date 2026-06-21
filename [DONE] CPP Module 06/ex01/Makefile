# :>

NAME = reinterpret_cast

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
 
SRC = Serializer.cpp main.cpp 
HPP = Serializer.hpp Data.hpp

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
