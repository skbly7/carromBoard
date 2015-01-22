CC = g++
CFLAGS = -Wall -w
PROG = carrom

SRCS = main.cpp Board.cpp Coin.cpp Corner.cpp Striker.cpp object.cpp Utility.cpp World.cpp CVector3.cpp
LIBS = -lglut -lGL -lGLU

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
