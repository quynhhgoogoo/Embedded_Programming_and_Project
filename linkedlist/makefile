GTEST_DIR=~/embedded_programming/googletest/googletest
COPTS=-fprofile-arcs -ftest-coverage

linkedlist : linked_list_testcase.o linkedlist.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include linked_list_testcase.c linkedlist.c Gtest_main.c libgtest.a $(COPTS) -pthread -o my_test
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
report:
	export COV_OUTPUT=./cov_output
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o ${COV_OUTPUT} .coverage.total
	rm -f .coverage.base .coverage.run .coverage.total