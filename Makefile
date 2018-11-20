CC   =		g++

NAME =		msgq

FSRC =		srcs/

SRCS =		$(FSRC)main.cpp			\

OBJS =		$(SRCS:.cpp=.o)

CXXFLAGS	= -g -I includes/ --std=c++11 -pthread 

all:	$(NAME) $(S_NAME)

$(NAME):	$(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
