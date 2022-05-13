CC=/bin/clang
LDFLAGS=-L/lib 
CPPFLAGS=-I/include
CFLAGS=-std=c99 -Wall -Wextra -pedantic -fdiagnostics-color=always
CFLAGS+=$(CPPFLAGS) -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls # -DNDEBUG
LDFLAGS+=-fsanitize=address

RUN_ENV=LSAN_OPTIONS=suppressions=lsan.ignore:print_suppressions=0 ASAN_OPTIONS=detect_leaks=1:symbolize=1 MallocNanoZone=0
#RUN_ENV=ASAN_OPTIONS=detect_leaks=1:symbolize=1
#RUN_ENV=

all: 
	+$(MAKE) -C src
	+$(MAKE) -C tests


clean:
	rm -f ./*/*.o ./*/*_tests

test: getwords_tests
	$(RUN_ENV) /tests/getwords_tests


.SILENT: clean
