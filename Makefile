
OS := $(shell uname)

ifeq($(OS), Linux)
	echo "Linux"
	PATH := $(PATH):/usr/local/lib/
endif

ifeq($(OS), Darwin)
	echo "Mac"
endif

ifeq($(OS), Windows_NT)
	echo "Windows"
endif

NAME = CryRepo.a
HEADERS = $(wildcard include/*.h)
SRC = src/SHA/SHA256/sha256.c
OBJ = $(SRC:.c=.o)
TEST = test/test.c
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

all: $(NAME)
	mkdir -p "shared"
	mv $(NAME) shared

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning $(NAME)..."
	rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning $(NAME)..."
	rm -rf shared

re: fclean all

.PHONY: all re install clean fclean uninstall test
