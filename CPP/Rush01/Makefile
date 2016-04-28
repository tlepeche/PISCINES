#var
CC = g++
NAME = ft_gkrellm
CFLAGS = -Wall -Wextra -Werror

LIBS = -framework sfml-graphics -framework sfml-window -framework sfml-system\
		-F SFML/Frameworks -lncurses

INC = -lncurses $(LIBS)
OBJDIR = obj/
SRCS = main.cpp \
	   AMonitorModule.class.cpp \
	   GKrellM.class.cpp \
	   AMonitorDisplay.class.cpp \
	   AText.class.cpp \
	   TextNCurses.class.cpp \
	   TextSfml.class.cpp \
	   ACourbe.class.cpp \
	   ACourbeb.class.cpp \
	   CourbeSfml.class.cpp \
	   CourbeSfmlb.class.cpp \
	   CourbeNCurses.class.cpp \
	   CourbebNCurses.class.cpp \
	   AWindow.class.cpp \
	   SessionModule.class.cpp \
	   WindowNCurses.class.cpp \
	   WindowSfml.class.cpp \
	   OSinfoModule.class.cpp \
	   DateModule.class.cpp \
	   NetworkModule.class.cpp \
	   RamModule.class.cpp \
	   CpuModule.class.cpp \


OBJS = $(addprefix $(OBJDIR),$(subst .cpp,.o,$(SRCS)))
TOTO = $(addprefix TOTO,$(OBJS))
INCLUDES = -I ./SFML/include

CHECK = \#/bin/bash @\
		TOTO=`grep ".hpp\"" $$1| cut -d\" -f2 | uniq | tr "\n" " "`;\
		echo $$1 >> .black_list;\
		for i in $$TOTO;\
		do\
			/bin/echo -n $$i" " >> .depend_list;\
			grep $$i .black_list > /dev/null || ./.check.sh $$i;\
		done

all: init sfml $(TOTO) $(NAME) end

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME) $(INCLUDES)

$(OBJS): | $(OBJDIR)


init:
	@/bin/echo '$(CHECK)' | tr '@' '\n' > .check.sh
	@chmod 744 .check.sh

end:
	@rm .check.sh

TOTO$(OBJDIR)%.o : %.cpp
	@/bin/echo -n "" > .black_list
	@/bin/echo -n "" > .depend_list
	@sh .check.sh $<
	@make `echo $@ | sed "s/TOTO//"` HEADER="`uniq .depend_list`";
	@rm .black_list .depend_list

$(OBJDIR)%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean sfmlrem
	rm -rf $(NAME)

proper: all clean

re: fclean all

#SFML

SFMLENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"

run: sfmlenv
	@DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./$(NAME) $(PARAM)

ncurses: sfmlenv
	@DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./$(NAME) toto totot totot

sfmlrem:
	rm -rf SFML

sfml:
	curl -O "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz"
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

sfmlenv:
	@echo export $(SFMLENV)
