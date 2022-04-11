CC=g++
flags=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CFLAGS= -std=c++17 -I include
.PHONY: debug release clean run_server run_client


renderwindow.o: src/renderwindow.cpp
	$(CC) src/renderwindow.cpp -c -o renderwindow.o $(flags) -g $(CFLAGS)

node.o: src/node.cpp
	$(CC) src/node.cpp -c -o node.o $(flags) -g $(CFLAGS)

runner.o: src/runner.cpp
	$(CC) src/runner.cpp -c -o runner.o $(flags) -g $(CFLAGS)

runner_for_server.o: src/runner_for_server.cpp
	$(CC) src/runner_for_server.cpp -c -o runner_for_server.o $(flags) -g $(CFLAGS)

utils.o: src/utils.cpp
	$(CC) src/utils.cpp -c -o utils.o $(flags) -g $(CFLAGS)

entity.o:
	$(CC) src/entity.cpp -c -o entity.o $(flags) -g $(CFLAGS)

main.o: src/main.cpp renderwindow.o entity.o node.o runner.o utils.o
	$(CC) src/main.cpp -c -o main.o $(flags) -g $(CFLAGS)

debug: main.o renderwindow.o entity.o node.o runner.o utils.o
	$(CC) -o bin/debug/main $^ $(flags) -g $(CFLAGS)


cleanup.o:
	$(CC) src/cleanup.cpp -c -o cleanup.o $(flags) -g $(CFLAGS)

screens.o:
	$(CC) src/screens.cpp -c -o screens.o $(flags) -g $(CFLAGS)

events.o:
	$(CC) src/events.cpp -c -o events.o $(flags) -g $(CFLAGS)

update_gamestate.o:
	$(CC) src/update_gamestate.cpp -c -o update_gamestate.o $(flags) -g $(CFLAGS)

send_input.o:
	$(CC) src/send_input.cpp -c -o send_input.o $(flags) -g $(CFLAGS)



run_client.o: src/run_client.cpp renderwindow.o entity.o node.o runner.o utils.o cleanup.o screens.o events.o update_gamestate.o send_input.o
	$(CC) src/run_client.cpp -c -o run_client.o $(flags) -g $(CFLAGS)

run_client: run_client.o renderwindow.o entity.o node.o runner.o utils.o cleanup.o screens.o events.o update_gamestate.o send_input.o
	$(CC) -o run_client.out $^ $(flags) -lenet -Wl,-rpath -Wl,/usr/local/lib -g $(CFLAGS)

run_server.o: src/run_server.cpp runner_for_server.o
	$(CC) src/run_server.cpp -c -o run_server.o -g $(CFLAGS)

run_server: run_server.o runner_for_server.o
	$(CC) -o run_server.out $^ -lenet -Wl,-rpath -Wl,/usr/local/lib -g $(CFLAGS)

release: main.o
	$(CC) -o bin/release/main $^  -s -03 $(flags) -g $(CFLAGS)

clean:
	rm -f *.o
	rm -f bin/debug/main
