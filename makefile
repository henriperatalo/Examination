GTEST_DIR = /u/h/e1401187/Kurssit/EmbeddedSystems/googletest-master/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include

my_test: test_case.o linkedlist.o linkedlist.o Gtest_main.c libgtest.a
	g++ -isystem $(GTEST_DIR)/include -pthread test_case.o linkedlist.o Gtest_main.c libgtest.a -o my_test --coverage

test_case.o: test_case.c
	g++ -c $(GTEST_INCLUDE) test_case.c 
	
linkedlist.o: linkedlist.c linkedlist.h
	g++ -c linkedlist.c 
	
libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o
	
gtest-all.o:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc

clean:
	rm my_test *.o libgtest.a