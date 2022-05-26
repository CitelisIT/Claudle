CC=/bin/clang
LDFLAGS=-L/lib 
CPPFLAGS=-I/include
CFLAGS=-std=c99 -Wall -Wextra -pedantic -fdiagnostics-color=always
CFLAGS+=$(CPPFLAGS) -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -Qunused-arguments # -DNDEBUG
LDFLAGS+=-fsanitize=address

RUN_ENV=LSAN_OPTIONS=suppressions=lsan.ignore:print_suppressions=0 ASAN_OPTIONS=detect_leaks=1:symbolize=1 MallocNanoZone=0
#RUN_ENV=ASAN_OPTIONS=detect_leaks=1:symbolize=1
#RUN_ENV=

OBJS = src/linked_list.o src/table.o src/halfsiphash.o src/dico.o src/entropy.o src/io.o src/main.o
SOURCE = src/linked_list.c src/table.c src/halfsiphash.c src/dico.c src/entropy.c src/io.c src/main.c
HEADER = src/linked_list.h src/table.h src/halfsiphash.h src/dico.h src/entropy.h src/io.h
OUT	= solver

run: install
	$(RUN_ENV) ./$(OUT)

install: $(OBJS) $(OUT)
	$(CC) $(CFLAGS) $(OBJS) -c -o $(OUT)

src/linked_list.o: src/linked_list.h src/linked_list.c

src/table.o: src/table.h src/table.c

src/halfsiphash.o: src/halfsiphash.h src/halfsiphash.c

src/dico.o: src/dico.h src/dico.c

src/entropy.o: src/entropy.h src/entropy.c

src/io.o: src/io.h src/io.c

src/main.o: src/main.c

solver: src/main.o
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

clean:
	rm -f $(OBJS)

.PHONY: clean