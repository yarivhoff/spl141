# All Targets
all: UniCoffeShop

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
UniCoffeShop: bin/Main.o bin/UniCoffeShop.o
	@echo 'Building target: hello'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/UniCoffeShop bin/main.o bin/UniCoffeShop.o
	@echo 'Finished building target: hello'
	@echo ' '

# Depends on the source and header files
bin/Main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/Main.o src/Main.cpp
	
bin/UniCoffeShop.o: src/UniCoffeShop.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/UniCoffeShop.o src/UniCoffeShop.cpp

#Clean the build directory
clean: 
	rm -f bin/*