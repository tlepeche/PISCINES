# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/06/24 14:21:18 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= iter

SRC= iter.cpp \

OBJDIR= OBJ/

OBJ= $(SRC:%.cpp=$(OBJDIR)%.o)

CC= clang++

CFLAGS= -Wextra -Wall -Werror

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


$(OBJDIR)%.o:%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
