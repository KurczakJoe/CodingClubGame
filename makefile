

CORESRC=main.cpp Map.cpp Player.cpp Point.cpp Game.cpp
COREINC=Console.h  Game.h  Map.h  Player.h  Point.h

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
	OSFILES := ConsoleWindows.cpp
	OSLIBS :=
else
	OSFILES := ConsoleLinux.cpp
	OSLIBS := -lncurses
endif

all: hello

hello: $(CORESRC) $(COREINC) $(OSFILES)
	g++ -ggdb -o hello  $(OSLIBS) $(CORESRC) $(OSFILES)
	

