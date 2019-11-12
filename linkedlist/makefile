GTEST_DIR=~/embedded_programming/googletest/googletest

linkedlist : linked_list_testcase.o linkedlist.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include linked_list_testcase.c linkedlist.c Gtest_main.c libgtest.a -pthread -o my_test
linked_list_testcase.o : linked_list_testcase.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} linked_list_testcase.c
linkedlist.o : linkedlist.c
	g++ -c linkedlist.c
Gtest_main.o : Gtest_main.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} Gtest_main.c
libgtest.a :
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
clean:
	rm -f *.o
