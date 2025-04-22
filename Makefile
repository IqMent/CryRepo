
#OS := $(shell uname)

# ifeq($(OS), Linux)
# 	echo "Linux"
# 	PATH := $(PATH):/usr/local/lib/
# endif

# ifeq($(OS), Darwin)
# 	echo "Mac"
# endif

# ifeq($(OS), Windows_NT)
# 	echo "Windows"
# endif

NAME_SO= CryRepo.so
HEADERS = $(wildcard include/*.h)
SRC = ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA256/sha256.c \
	  ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA512/sha512.c \
	  ${HOME}/Desktop/LummaProjects/CryRepo/src/hash/SHA/SHA384/sha384.c \
INCLUDE = include
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
CFLAGS_RELEASE = -Wall -Wextra -Werror

all: $(NAME_SO)

$(NAME_SO): $(OBJ)
	$(CC) -shared -o $(NAME_SO) $(OBJ)
	#ar rcs $(NAME_SO) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

install:
	@echo "Installing $(NAME_SO)..."
	@mkdir -p /usr/local/include/cryrepo
	@cp include/*.h /usr/local/include/cryrepo/
	@cp $(NAME_SO) /usr/local/lib/
	@echo "Done"

clean:
	@echo "Cleaning $(NAME_SO)..."
	rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning $(NAME_SO)..."
	rm -rf shared

re: fclean all

.PHONY: all re install clean fclean uninstall test install-static
