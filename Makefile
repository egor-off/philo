NAME	:= philo

SRCDIR	:= src
OBJDIR	:= obj

SRC 	:=	main.c init.c utils.c \
			threads.c talk.c

SRC 	:= $(addprefix $(SRCDIR)/,$(SRC))
OBJ 	:= $(SRC:$(SRCDIR)/%c=$(OBJDIR)/%o)

RM		:= rm -rf
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -MMD

all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $? -o $(NAME)
	@printf "philo was build ✅\n"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $? -o $@

$(OBJDIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJDIR)
	@printf "obj directory was deleted 🗑\n"

fclean:
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME)
	@printf "all was deleted 🗑\n"

re:				fclean $(NAME)

.PHONY: all clean fclean re $(NAME)
