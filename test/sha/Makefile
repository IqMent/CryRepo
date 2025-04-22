NAME = sha_test
SRC = ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA256/sha256.c \
	  ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA512/sha512.c \
	  ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA384/sha384.c \
	  ${HOME}/Desktop/LummaProjects/CryRepo/test/sha/sha.c
OBJ = ${SRC:.c=.o}

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	$(CC) -o $(NAME) $(OBJ) -I ${HOME}/Desktop/LummaProjects/CryRepo/src/SHA/SHA256/ -I ${HOME}/Desktop/LummaProjects/CryRepo/test/sha/
	@echo "Done"

%.o: %.c
	@echo "Compiling $<..."
	$(CC) -c $< -o $@ -I ${HOME}/Desktop/LummaProjects/CryRepo/src/SHA/SHA256/ -I ${HOME}/Desktop/LummaProjects/CryRepo/test/sha/
	@echo "Done"

clean:
	@echo "Cleaning $(NAME)..."
	rm -f $(OBJ)
	@echo "Done"

fclean: clean
	@echo "Full cleaning $(NAME)..."
	rm -f $(NAME)
	@echo "Done"

re: fclean all

#.PHONY: all re install clean fclean