GTEST_DIR=~/embedded_programming/googletest/googletest
COPTS=-fprofile-arcs -ftest-coverage

ring : test_code.o ringbuffer.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include test_code.c ringbuffer.c Gtest_main.c libgtest.a $(COPTS) -pthread -o my_test
test_code.o : test_code.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} test_code.c
ringbuffer.o : ringbuffer.c
	g++ -c ringbuffer.c
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