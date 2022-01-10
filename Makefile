# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 14:14:41 by jjoan             #+#    #+#              #
#    Updated: 2022/01/08 23:53:29 by jjoan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
NAMEB	:= philo_bonus

SRCDIR	:= src
OBJDIR	:= obj
DEPDIR	:= dep
SRCBDIR	:= src_bonus
OBJBDIR	:= obj_bonus
DEPBDIR	:= dep_bonus

SRC 	:=	main.c init.c utils.c \
			threads.c talk.c monitor.c

SRC		:= $(addprefix $(SRCDIR)/,$(SRC))
OBJ		:= $(SRC:$(SRCDIR)/%c=$(OBJDIR)/%o)
DEP		:= $(SRC:$(SRCDIR)/%c=$(DEPDIR)/%d)
SRCB	:= $(addprefix $(SRCBDIR)/,$(SRC))
OBJB	:= $(SRC:$(SRCBDIR)/%c=$(OBJBDIR)/%o)
DEPB	:= $(SRC:$(SRCBDIR)/%c=$(DEPBDIR)/%d)

RM		:= rm -rf
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -MMD

bonus:			$(DEPB) | $(OBJB)
	@$(CC) $^ -o $(NAMEB)
	@printf "philo_bonus was built ✅\n"

all:			$(NAME)

$(NAME):		$(DEP) | $(OBJ)
	@$(CC) $^ -o $(NAME)
	@printf "philo was built ✅\n"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $? -o $@

$(DEPDIR)/%.d:	$(SRCDIR)/%.c | $(DEPDIR)
	@$(CC) $(DFLAGS) -c $? -o $@

$(OBJBDIR)/%.o:	$(SRCBDIR)/%.c | $(OBJBDIR)
	@$(CC) $(CFLAGS) -c $? -o $@

$(DEPBDIR)/%.d:	$(SRCBDIR)/%.c | $(DEPBDIR)
	@$(CC) $(DFLAGS) -c $? -o $@

$(DEPDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

$(DEPBDIR):
	@mkdir -p $@

$(OBJBDIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJDIR) $(DEPDIR) $(OBJBDIR) $(DEPBDIR)
	@printf "obj and dep directory was deleted 🗑\n"

fclean:
	@$(RM) $(OBJDIR) $(DEPDIR) $(NAME) $(OBJBDIR) $(DEPBDIR) $(NAMEB)
	@printf "all was deleted 🗑\n"

re:				fclean $(NAME)

.PHONY: all clean fclean re $(NAME)
