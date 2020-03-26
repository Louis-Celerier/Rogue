all : bin/executable_texte bin/exec_gen

bin/executable_texte : obj/main.o obj/Personnages.o
	g++ -Wall -ggdb obj/main.o obj/Personnages.o -o bin/executable_texte

bin/exec_gen : obj/Generation.o obj/Room.o obj/Map.o obj/Corridor.o
	g++ -Wall -ggdb obj/Generation.o obj/Room.o obj/Map.o obj/Corridor.o -o bin/exec_gen

obj/main.o : src/main.cpp src/Personnages.h
	g++ -Wall -ggdb	-c src/main.cpp -o obj/main.o

obj/Personnages.o : src/Personnages.cpp src/Personnages.h
	g++ -Wall -ggdb -c src/Personnages.cpp -o obj/Personnages.o

obj/Generation.o : src/Generation.cpp src/Room.h src/Map.h src/Corridor.h
	g++ -Wall -ggdb -c src/Generation.cpp -o obj/Generation.o

obj/Room.o : src/Room.cpp src/Room.h
	g++ -Wall -ggdb -c src/Room.cpp -o obj/Room.o

obj/Map.o : src/Map.cpp src/Map.h
	g++ -Wall -ggdb -c src/Map.cpp -o obj/Map.o

obj/Corridor.o : src/Corridor.cpp src/Corridor.h
	g++ -Wall -ggdb -c src/Corridor.cpp -o obj/Corridor.o

clean :
		rm obj/*.o && rm bin/*
