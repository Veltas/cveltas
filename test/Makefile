CC     = gcc
CFLAGS = -std=c90 -Wall -W -pedantic -g -I ../include/ -L ../lib/
LDLIBS = -lveltas
BINS   = $(patsubst %.c,%,$(wildcard *.c))

.PHONY: test
test: $(BINS)
	for test_bin in $(BINS) ; do \
		echo === Running $${test_bin}... === ; \
		LD_LIBRARY_PATH=../lib/ ./$$test_bin || exit 1; \
	done

.PHONY: clean
clean:
	rm -f $(BINS)
