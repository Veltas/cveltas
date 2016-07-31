CC       = gcc
CSTD     = -std=c11
COUT     = -O3
CFLAGS   = $(CSTD) -I include/ -Wall -W -pedantic $(COUT) -fpic
OBJFILES = $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))

.PHONY: all
all: lib/libveltas.so test

lib/libveltas.so: $(OBJFILES) | lib
	$(CC) $(LDFLAGS) -shared -o$@ $^ $(LOADLIBES) $(LDLIBS)

lib:
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf src/*.o lib/
	cd test && make clean

.PHONY: test
test: lib/libveltas.so
	cd test && make
