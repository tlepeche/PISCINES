# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/06/23 14:59:10 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME= converter

SRC= main.cpp \
	 Converter.cpp \

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
