NAME = CryRepo
SRC = src/SHA/sha256.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling $(NAME)..."
	ar rcs $(NAME) $(OBJ)

$(SRC): $(OBJ)
	@echo "Compiling $(SRC)..."

%.o: %.c
	cc -c &< -o $@

clean:
	@echo "Cleaning $(NAME)..."
	rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning $(NAME)..."
	rm -f $(NAME)

re: fclean all

.PHONY: all re install clean fclean uninstall test
