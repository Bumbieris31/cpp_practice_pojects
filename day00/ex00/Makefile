NAME = megaphone

SRC = megaphone.cpp

OBJ = megaphone.o

CXX = clang++

make: megaphone.o
	$(CXX) -o $(NAME) $(OBJ)

%.o: SRC
	$(CXX) -c -Wall -Wextra -Werror -std=c++98 $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all