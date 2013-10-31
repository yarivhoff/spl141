# All Targets
all: main

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
main: bin/main.o 
	@echo 'Building target: hello'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/hello bin/main.o 
	@echo 'Finished building target: hello'
	@echo ' '

# Depends on the source and header files
bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/main.o src/main.cpp


#Clean the build directory
clean: 
	rm -f bin/*