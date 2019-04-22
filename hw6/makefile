CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

INCLUDE = -I inc  # add include and test dirs to include path
FLAGS += $(INCLUDE)

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

bin/test_mean_collect: bin/test_mean_collect.o bin/mean.o
	$(LINK) $@ $^
bin/test_mean_collect.o: src/test_mean_collect.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@

bin/test_mean_calculate: bin/test_mean_calculate.o bin/mean.o
	$(LINK) $@ $^
bin/test_mean_calculate.o: src/test_mean_calculate.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@


bin/test_median_collect: bin/test_median_collect.o bin/median.o
	$(LINK) $@ $^
bin/test_median_collect.o: src/test_median_collect.cc inc/median.h \
        inc/statistic.h
	$(COMPILE) $< -o $@

bin/test_median_calculate: bin/test_median_calculate.o bin/median.o
	$(LINK) $@ $^
bin/test_median_calculate.o: src/test_median_calculate.cc inc/median.h \
        inc/statistic.h
	$(COMPILE) $< -o $@


bin/mean.o: src/mean.cc inc/mean.h inc/statistic.h
	$(COMPILE) $< -o $@

bin/median.o: src/median.cc inc/median.h inc/statistic.h
	$(COMPILE) $< -o $@

clean:
	rm -f bin/*
