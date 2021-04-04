# Compiler
GXX := g++

# flags
FLG := -Wall -Wshadow -Wconversion
FLG += -g


#source file
SRC := main_test.cpp


#Header files
Header := -I../include
Header += -I./ #for the BinarySearchTree.tpp file


#Ececutable name
EXC := main_test.run



build:
	@echo "Building the project"
	cd src; \
	$(GXX) $(FLG) $(SRC) $(Header) -o $(EXC)


clean:
	@cd src; \
	rm *.run


run:
	cd src; \
	./$(EXC)


build-run: build run

