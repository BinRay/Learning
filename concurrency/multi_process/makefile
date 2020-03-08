all: waitpid signal remove_zombie

waitpid: waitpid.cpp
	g++ -o waitpid waitpid.cpp 

signal: signal.cpp
	g++ -o signal signal.cpp

remove_zombie: remove_zombie.cpp
	g++ -o remove_zombie remove_zombie.cpp

cleanall:
	rm -rf waitpid signal remove_zombie
