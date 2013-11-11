# All Targets
all: UniCoffeeShop

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
UniCoffeeShop: bin/Main.o bin/UniCoffeeShop.o
	@echo 'Building target: UniCoffeeShop'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/UniCoffeeShop bin/Main.o bin/UniCoffeeShop.o
	@echo 'Finished building target: hello'
	@echo ' '

# Depends on the source and header files
bin/Main.o: src/Main.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/Main.o src/Main.cpp
	
bin/UniCoffeeShop.o: src/UniCoffeeShop.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/UniCoffeeShop.o src/UniCoffeeShop.cpp

#Clean the build directory
clean: 
	rm -f bin/*