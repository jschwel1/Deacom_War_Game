CC = g++
CFLAGS = -g -Wall
LDFLAGS = -std=c++11
OBJFILES = card.o hand.o deck.o war.o
TARGET = war_game

all: $(TARGET)

card.o: card.h card.cpp
	g++ -g -Wall -c card.cpp $(LDFLAGS)

hand.o: hand.h hand.cpp card.o
	g++ -g -Wall -c hand.cpp card.cpp $(LDFLAGS)

deck.o: deck.h deck.cpp hand.o card.o
	g++ -g -Wall -c deck.cpp $(LDFLAGS)

war.o: war.cpp deck.o
	g++ -g -Wall -c war.cpp $(LDFLAGS)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET)



