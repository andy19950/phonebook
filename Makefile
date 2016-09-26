CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_orig = -O0
CFLAGS_opt_v1  = -O0
CFLAGS_opt_v2  = -O0

EXEC = phonebook_orig phonebook_opt_v1 phonebook_opt_v2
all: $(EXEC)

SRCS_common = main.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) $(CFLAGS_orig) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt_v1: $(SRCS_common) phonebook_opt_v1.c phonebook_opt_v1.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt_v1) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt_v2: $(SRCS_common) phonebook_opt_v2.c phonebook_opt_v2.h
	 $(CC) $(CFLAGS_common) $(CFLAGS_opt_v2) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c


run: $(EXEC)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	watch -d -t "./phonebook_orig && echo 3 | sudo tee /proc/sys/vm/drop_caches"

cache-test: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_orig
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt_v1
	perf stat --repeat 100 \
                -e cache-misses,cache-references,instructions,cycles \
                ./phonebook_opt_v2


output.txt: cache-test calculate
	./calculate

plot: output.txt
	gnuplot scripts/runtime.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt opt_v1.txt opt_v2.txt output.txt runtime.png
