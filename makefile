CC=g++
flags=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CFLAGS= -std=c++17 -I include
.PHONY: debug release clean

renderwindow.o: src/renderwindow.cpp
	$(CC) src/renderwindow.cpp -c -o renderwindow.o $(flags) -g $(CFLAGS)

node.o: src/node.cpp
	$(CC) src/node.cpp -c -o node.o $(flags) -g $(CFLAGS)

runner.o: src/runner.cpp
	$(CC) src/runner.cpp -c -o runner.o $(flags) -g $(CFLAGS)

utils.o: src/utils.cpp
	$(CC) src/utils.cpp -c -o utils.o $(flags) -g $(CFLAGS)

entity.o:
	$(CC) src/entity.cpp -c -o entity.o $(flags) -g $(CFLAGS)

main.o: src/main.cpp renderwindow.o entity.o node.o runner.o utils.o
	$(CC) src/main.cpp -c -o main.o $(flags) -g $(CFLAGS)

debug: main.o renderwindow.o entity.o node.o runner.o utils.o
	$(CC) -o bin/debug/main $^ $(flags) -g $(CFLAGS)

release: main.o
	$(CC) -o bin/release/main $^  -s -03 $(flags) -g $(CFLAGS)

clean:
	rm -f *.o
	rm -f bin/debug/main
