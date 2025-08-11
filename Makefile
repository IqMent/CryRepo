
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
INCLUDE_DIR = include
HEADERS = $(wildcard include/*.h)
SRC = src/hash/SHA/SHA256/sha256.c \
	  src/hash/SHA/SHA512/sha512.c \
	  src/hash/SHA/SHA384/sha384.c \
	  src/hash/SHA/SHA1/sha1.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -I$(INCLUDE_DIR) -g -fPIC #-Wall -Wextra -Werror
LDFLAGS = -shared
CFLAGS_RELEASE = -Wall -Wextra -Werror

all: $(NAME_SO)

$(NAME_SO): $(OBJ)
	$(CC) -shared -o lib$(NAME_SO) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install:
	@echo "Installing $(NAME_SO)..."
	@mkdir -p /usr/local/include/cryrepo
	@cp include/*.h /usr/local/include/cryrepo/
	@cp lib$(NAME_SO) /usr/local/lib/
	@echo "Done"

clean:
	@echo "Cleaning $(NAME_SO)..."
	rm -f $(OBJ)
	rm -f lib$(NAME_SO)

re: fclean all

uninstall:
	@echo "Uninstalling lib$(NAME_SO)..."
	rm -f /usr/local/lib/lib$(NAME_SO)
	rm -rf /usr/local/include/cryrepo
	@echo "Done"

.PHONY: all re install clean fclean uninstall
