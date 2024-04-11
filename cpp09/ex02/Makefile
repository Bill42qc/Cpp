# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmartin <bmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:31:23 by bmartin           #+#    #+#              #
#    Updated: 2023/11/08 17:44:57 by bmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
G = \033[0;32m #green
R = \033[0;31m #red
RT = \033[0m #reset

#                 \ \ / /_\ | _ |_ _| /_\ | _ | |  | __/ __|                   
#                  \ V / _ \|   /| | / _ \| _ | |__| _|\__ \                    
#                   \_/_/ \_|_|_|___/_/ \_|___|____|___|___/                   

NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJDIR = bin
SRCDIR = .  # Source files are in the same directory as the Makefile
SRCS = $(shell find $(SRCDIR) -type f -name '*.cpp')
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

#                        _____ _   ___  ___ ___ _____                         
#                       |_   _/_\ | _ \/ __| __|_   _|                         
#                         | |/ _ \|   | (_ | _|  | |                          
#                         |_/_/ \_|_|_\\___|___| |_|                           

all: mk_bin $(NAME)

mk_bin:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | mk_bin
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(G)\n ║ MAKE COMPLETE ║$(RT)"

clean: rm_bin
	@echo "\n$(R)clean target called$(RT)"
	@rm -f $(OBJS)

fclean: clean rm_bin
	@echo "\n$(R)fclean target called$(RT)"
	@rm -f $(NAME)

re: fclean all

rm_bin:
	@rm -rf $(OBJDIR)

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full  --show-reachable=yes --track-fds=yes --track-origins=yes  ./$(NAME)


.PHONY: all mk_bin clean fclean rm_bin re run val