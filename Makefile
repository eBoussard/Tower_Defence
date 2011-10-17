VPATH = src
CPPFLAGS = -Iinclude -I/usr/local/include/allegro5 -g
LDFLAGS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -L/usr/local/lib -g

all: Tower_Defence

Tower_Defence: Player.o Board.o Tower.o Ammunition.o Enemy.o Engine.o Tower_Defence.o ScoreBoard.o
	g++ $(LDFLAGS) -o Tower_Defence Player.o Board.o Tower.o Ammunition.o Enemy.o Engine.o Tower_Defence.o ScoreBoard.o
