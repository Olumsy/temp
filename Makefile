# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leali-ha <leali-ha@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 22:44:56 by leali-ha          #+#    #+#              #
#    Updated: 2025/07/21 16:06:19 by leali-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ₍^.w.^₎⟆
CLIENT_NAME := client
SERVER_NAME := server

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

SRCDIR =.
OBJDIR = Obj_build
SUBDIRS = libft

CLIENT_SRCS := client.c
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS := $(addprefix $(OBJDIR)/, $(CLIENT_OBJS))

SERVER_SRCS := server.c server_handler.c
SERVER_OBJS := $(SERVER_SRCS:.c=.o)
SERVER_OBJS := $(addprefix $(OBJDIR)/, $(SERVER_OBJS))

LIB_DEPS = libft/libft.a

define rule_subdirs_deps
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1) --no-print-directory; \
	done
endef

SPINNER_PATH := $(HOME)/.bin/spinner
SPINNER_EXIST := $(wildcard $(SPINNER_PATH))

all:    $(NAME)

$(NAME): $(CLIENT_OBJS) $(SERVER_OBJS) $(LIB_DEPS)
	$(call rule_subdirs_deps,all)
ifeq ($(SPINNER_EXIST),$(SPINNER_PATH))
	@spinner $(CC) $(CCFLAGS) $(CLIENT_OBJS) $(LIB_DEPS) -o $(CLIENT_NAME)
	@spinner $(CC) $(CCFLAGS) $(SERVER_OBJS) $(LIB_DEPS) -o $(SERVER_NAME)
else
	@$(CC) $(CCFLAGS) $(CLIENT_OBJS) $(LIB_DEPS) -o $(CLIENT_NAME)
	@$(CC) $(CCFLAGS) $(SERVER_OBJS) $(LIB_DEPS) -o $(SERVER_NAME)
endif
	@$(info Programs '$(CLIENT_NAME)','$(SERVER_NAME)' successfully created, well done !)

$(LIB_DEPS):
	$(MAKE) -C $(@D) $(@F)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(call rule_subdirs_deps,clean)
	@$(info Building tools and objects successfully cleaned, wonderful job !)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@$(call rule_subdirs_deps,fclean)
	@$(info Project completly cleaned, how superb !)

re:	fclean all

.PHONY:	all clean fclean re
