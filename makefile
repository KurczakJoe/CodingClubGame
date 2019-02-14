CORESRC=main.cpp Map.cpp Player.cpp Point.cpp Game.cpp
COREINC=Console.h  Game.h  Map.h  Player.h  Point.h

all: win

win: $(CORESRC) $(COREINC) ConsoleWindows.cpp
	g++ -o hello  $(CORESRC) ConsoleWindows.cpp
	
lin: $(CORESRC) $(COREINC) ConsoleLinux.cpp
	g++ -o hello  $(CORESRC) ConsoleLinux.cpp
	

