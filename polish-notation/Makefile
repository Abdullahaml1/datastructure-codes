# Compiler
GXX := g++

# flags
FLG := -Wall -Wshadow -Wconversion
FLG += -g
# FLG += -std=c++17


#source file
SRC := main.cpp
SRC += PolishConverter.cpp


#Header files
Header := -I../include
Header += -I./ #for the Stack.tpp file


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

################################################################################
# for testing
################################################################################

#test files
TEST := tests.cpp
TEST += PolishConverter.cpp

TEST_EXC := tests.run



test:
	@echo "Testing the project "
	cd src; \
	$(GXX) $(FLG) $(TEST) $(Header) -o $(TEST_EXC); \
	./$(TEST_EXC)
