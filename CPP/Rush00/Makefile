# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 10:21:46 by sduprey           #+#    #+#              #
#    Updated: 2015/06/21 11:02:27 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp \
	  Squad.cpp \
	  Player.cpp \
	  AEntity.cpp \
	  Bckgd.cpp \
	  Game.cpp \
	  HorEnemy.cpp \
	  DiagEnemy.cpp \
	  ShootEnemy.cpp \
	  MiniDiagEnemy.cpp \
	  CircleEnemy.cpp \
	  HorAmmo.cpp \
	  MegaAmmo.cpp \
	  BossAmmo.cpp \
	  Weapon.cpp \
	  MenuTop.cpp \
	  MenuStart.cpp \
	  Hitbox.cpp \
	  Boss.cpp \

CC = g++

CFLAGS = -Wall -Wextra -Werror

OBJDIR = obj/

OBJ = $(SRC:%.cpp=$(OBJDIR)%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lncurses -o $(NAME) $^

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

