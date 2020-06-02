# Compiler
GXX := g++

# flags
FLG := -Wall -Wshadow -Wconversion
FLG += -g


#source file 
SRC := main_test.cpp
#SRC += Stack.cpp


#Header files 
Header := -I./


#Ececutable name
EXC := main_test.run 




build:
	@echo "Building the project"
	$(GXX) $(FLG) $(SRC) $(Header) -o $(EXC)


clean:
	@rm *.run


run:
	./$(EXC)


build-run:build run

