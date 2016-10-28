CC       = gcc
CSTD     = -std=c11
COUT     = -O3
CFLAGS   = $(CSTD) -I include/ -Wall -W -pedantic $(COUT)
OBJFILES = $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))

.PHONY: all
all: lib/libveltas.so

$(OBJFILES): CFLAGS += -fpic

lib/libveltas.so: $(OBJFILES) | lib
	$(CC) $(LDFLAGS) -shared -o$@ $^ $(LOADLIBS) $(LDLIBS)

lib:
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf src/*.o lib/
	cd test && $(MAKE) clean

.PHONY: check
check: lib/libveltas.so
	cd test && $(MAKE)
