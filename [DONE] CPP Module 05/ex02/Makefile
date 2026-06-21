# :>

NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AForm.cpp  Bureaucrat.cpp  main.cpp  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp
HPP = AForm.hpp  Bureaucrat.hpp PresidentialPardonForm.hpp  RobotomyRequestForm.hpp  ShrubberyCreationForm.hpp

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
	rm -rf *_shrubbery

re: clean all

.PHONY: all clean fclean re
