GTEST_DIR=~/embedded_programming/googletest/googletest

ring : test_code.o ringbuffer.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include test_code.c ringbuffer.c Gtest_main.c libgtest.a -pthread -o my_test
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
