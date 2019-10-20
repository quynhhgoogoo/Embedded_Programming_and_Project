GTEST_DIR=~/embedded_programming/googletest/googletest

test : unit_test_case.o code_to_be_tested.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include unit_test_case.c code_to_be_tested.c Gtest_main.c libgtest.a -pthread -o my_test

unit_test_case.o : unit_test_case.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} unit_test_case.c
code_to_be_tested.o : code_to_be_tested.c
	g++ -c code_to_be_tested.c
Gtest_main.o : Gtest_main.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} Gtest_main.c
libgtest.a :
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
clean:
	rm -f *.o
