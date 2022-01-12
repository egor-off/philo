# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 14:14:41 by jjoan             #+#    #+#              #
#    Updated: 2022/01/12 19:39:00 by jjoan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
HEADER	:= philo.h

SRCDIR	:= src
OBJDIR	:= obj
DEPDIR	:= dep

SRC 	:=	main.c init.c utils.c \
			threads.c talk.c monitor.c

SRC		:= $(addprefix $(SRCDIR)/,$(SRC))
OBJ		:= $(SRC:$(SRCDIR)/%c=$(OBJDIR)/%o)
DEP		:= $(SRC:$(SRCDIR)/%c=$(DEPDIR)/%d)

RM		:= rm -rf
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -MMD

all:			$(NAME)

$(NAME):		$(OBJ) | $(DEP) Makefile
	$(CC) $? -o $(NAME)
	@printf "philo was built ✅\n"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $? -o $@

$(DEPDIR)/%.d:	$(SRCDIR)/%.c | $(DEPDIR)
	$(CC) $(DFLAGS) -c $? -o $@

$(DEPDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJDIR) $(DEPDIR)
	@printf "obj and dep directory was deleted 🗑\n"

fclean:
	@$(RM) $(OBJDIR) $(DEPDIR) $(NAME) philo.dSYM
	@printf "all was deleted 🗑\n"

re:				fclean $(NAME)

-include:		$(DEP)

.PHONY: all clean fclean re $(NAME)
