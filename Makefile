NAME		= push_swap
SRCS		= getters.c getters_extras.c helpers.c makers.c movers.c movers_extras.c parsers.c parsers_extra.c pushers.c quitters.c setters.c sorters.c main.c 
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Werror -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJS)
	CC $(CFLAFS) $(OBJS) -o $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
