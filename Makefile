CC = cc
CFLAGC = -Wall -Wextra -Werror

SRC1 = server.c 
SRC2 = client.c

OBG1 = server.o
OBG2 = client.o

NAME = client

NAME1 = server

all : $(NAME) $(NAME1)

$(NAME) : $(OBG2)
	$(CC) $(CFLAGC) $(OBG2) -o $(NAME)

$(NAME1) : $(OBG1)
	$(CC) $(CFLAGC) $(OBG1) -o $(NAME1)

clean:
	$(RM) $(OBG1) $(OBG2)
fclean: clean
	$(RM) $(NAME) $(NAME1)

re: fclean all

.PHONY: clean
.SECONDARY: $(OBG1) $(OBG2)