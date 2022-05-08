NAME = Account

SRC = tests.cpp Account.cpp

OBJ = tests.o Account.o

FLAGS = -Wall -Wextra -Werror -std=c++98

CXX = clang++

all: $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -I .

$(OBJ): $(SRC)
	$(CXX) -c $(FLAGS) $(SRC) -I .

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all