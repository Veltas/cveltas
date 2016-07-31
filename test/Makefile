CC        = gcc
CFLAGS    = -std=c90 -Wall -W -pedantic -g -I ../include/ -L ../lib/
LDLIBS    = -lveltas
BINS      = $(patsubst %.c,%,$(wildcard *.c))
ANTI_BINS = $(patsubst antitests/%.c,antitests/%,$(wildcard antitests/*.c))

.PHONY: test
test: $(BINS) $(ANTI_BINS)
	@for test_bin in $(BINS) ; do \
		echo "===== Running $${test_bin}... =====" ; \
		LD_LIBRARY_PATH=../lib/ ./$$test_bin || exit 1; \
	done
	@for test_bin in $(ANTI_BINS) ; do \
		echo "===== Running $${test_bin}... =====" ; \
		LD_LIBRARY_PATH=../lib/ ./$$test_bin && exit 1; \
		true; \
	done

.PHONY: clean
clean:
	rm -f $(BINS) $(ANTI_BINS)
