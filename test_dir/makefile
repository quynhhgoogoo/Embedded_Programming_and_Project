GTEST_DIR=~/embedded_programming/googletest/googletest

# Make targets

main: main.o $(PROJ).o
	gcc main.o $(PROJ).o -o main $(LDFLAGS)

test: Gtest_main.o test_case.o $(PROJ)_test.o libgtest.a
	g++  $(LDFLAGS) -I $(GTEST_DIR)/include -pthread $(PROJ)_test.o test_case.o Gtest_main.o libgtest.a -o test

#Unit test

Gtest_main.o: Gtest_main.c
	g++ -c -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) Gtest_main.c

$(PROJ)_test.o: $(PROJ).c 
	g++  -c $(PROJ).c -o $(PROJ)_test.o

test_case.o: test_case.c
	g++ -c -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) $(COPTS) test_case.c

#Google Test framework
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

#Clean
clean:
	rm -f *.o
