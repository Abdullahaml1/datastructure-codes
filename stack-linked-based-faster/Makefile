# Compiler
GXX := g++

# flags
FLG := -Wall -Wshadow -Wconversion
FLG += -g


#source file
SRC := main_test.cpp
#SRC += Stack.cpp


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
# for the vector stress testing
################################################################################
build-vec:
	@echo "Building the vector"
	cd src; \
	$(GXX) $(FLG) test_vector.cpp -o test_vector.run


run-vec:
	cd src; \
	./test_vector.run



################################################################################
# for the stack stress testing
################################################################################
build-stack-test:
	@echo "Building the stack tes"
	cd src; \
	$(GXX) $(FLG) test_stack.cpp $(Header) -o test_stack.run


run-stack-test:
	cd src; \
	./test_stack.run
