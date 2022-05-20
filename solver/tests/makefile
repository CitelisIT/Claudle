CC=/bin/clang
LDFLAGS=-L/lib 
CPPFLAGS=-I/include
CFLAGS=-std=c99 -Wall -Wextra -pedantic -fdiagnostics-color=always
CFLAGS+=$(CPPFLAGS) -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls # -DNDEBUG
LDFLAGS+=-fsanitize=address

RUN_ENV=LSAN_OPTIONS=suppressions=lsan.ignore:print_suppressions=0 ASAN_OPTIONS=detect_leaks=1:symbolize=1 MallocNanoZone=0
#RUN_ENV=ASAN_OPTIONS=detect_leaks=1:symbolize=1
#RUN_ENV=

getwords_tests: getwords_tests.o ../src/getwords.o ../src/linked_list.o

getwords_tests.o: getwords_tests.c ../src/getwords.o

list_tests : list_tests.o ../src/list.o

list_tests.o : list_tests.c ../src/list.o

strat_in_6_tests : strat_in_6_tests.o ../src/strat_in_6.o ../src/dico.o ../src/linked_list.o ../src/table.o

strat_in_6_tests.o : strat_in_6_tests.c ../src/strat_in_6.o

linked_list_test : linked_list_test.o ../src/linked_list.o 

linked_list_test.o : linked_list_test.c ../src/linked_list.o




clean:
	rm -f *.o *_tests

test_getword: getwords_tests
	$(RUN_ENV) ./getwords_tests

test_list: list_tests
	$(RUN_ENV) ./list_tests

test_strat_in_6: strat_in_6_tests
	$(RUN_ENV) ./strat_in_6_tests

test_linked_list: linked_list_test
	$(RUN_ENV) ./linked_list_test

.SILENT: clean
