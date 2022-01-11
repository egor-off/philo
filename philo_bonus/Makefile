# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 14:14:41 by jjoan             #+#    #+#              #
#    Updated: 2022/01/11 18:31:34 by jjoan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEB	:= philo_bonus

SRCBDIR	:= src_bonus
OBJBDIR	:= obj_bonus
DEPBDIR	:= dep_bonus

SRCB	:=	main_b.c init_b.c \
			utils_b.c forks_b.c

SRCB	:= $(addprefix $(SRCBDIR)/,$(SRCB))
OBJB	:= $(SRCB:$(SRCBDIR)/%c=$(OBJBDIR)/%o)
DEPB	:= $(SRCB:$(SRCBDIR)/%c=$(DEPBDIR)/%d)

RM		:= rm -rf
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -MMD

all:			$(NAMEB)

$(NAMEB):		$(DEPB) | $(OBJB) Makefile
	@$(CC) $^ -o $(NAMEB)
	@printf "philo_bonus was built ✅\n"

$(OBJBDIR)/%.o:	$(SRCBDIR)/%.c | $(OBJBDIR)
	@$(CC) $(CFLAGS) -c $? -o $@

$(DEPBDIR)/%.d:	$(SRCBDIR)/%.c | $(DEPBDIR)
	@$(CC) $(DFLAGS) -c $? -o $@

$(DEPBDIR):
	@mkdir -p $@

$(OBJBDIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJBDIR) $(DEPBDIR)
	@printf "obj and dep directory was deleted 🗑\n"

fclean:
	@$(RM) $(OBJBDIR) $(DEPBDIR) $(NAMEB)
	@printf "all was deleted 🗑\n"

re:				fclean $(NAMEB)

.PHONY: all clean fclean re $(NAMEB)
