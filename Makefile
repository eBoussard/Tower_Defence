VPATH = src
CPPFLAGS = -Iinclude -I/usr/local/include/allegro5 -g
LDFLAGS = -L/usr/local/lib -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -g

all: Tower_Defence

Tower_Defence: Player.o Board.o Tower.o Ammunition.o Enemy.o Engine.o Tower_Defence.o ScoreBoard.o
	g++ $(LDFLAGS) -o Tower_Defence Player.o Board.o Tower.o Ammunition.o Enemy.o Engine.o Tower_Defence.o ScoreBoard.o

clean:
	rm -f core *.o Tower_Defence
