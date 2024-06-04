CL = clang++ -Wall -std=c++11 
O = game.o item.o location.o npc.o

game: $(O)
	$(CL) $(O) -o game

%.o: %.cpp %.h
	$(CL) -c $<

clean: 
	rm *.o