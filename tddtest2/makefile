GTEST_DIR=~/embedded_programming/googletest/googletest

test : string_test_case.o string.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include string_test_case.c string.c Gtest_main.c libgtest.a -pthread -o my_test

string_test_case.o : string_test_case.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} string_test_case.c
string.o : string.c
	g++ -c string.c
Gtest_main.o : Gtest_main.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} Gtest_main.c
libgtest.a :
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
clean:
	rm -f *.o