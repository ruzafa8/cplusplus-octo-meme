CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = ${SRCS:.cpp=.o}
RM = rm -f
NAME = main
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

all: ${NAME}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
