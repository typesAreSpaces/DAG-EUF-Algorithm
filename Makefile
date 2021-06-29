CURRENT_DIR=$(shell pwd)
IDIR=$(CURRENT_DIR)/include
ODIR=$(CURRENT_DIR)/obj
SDIR=$(CURRENT_DIR)/src
LDIR=$(CURRENT_DIR)/lib
TDIR=$(CURRENT_DIR)/tests

CXX=g++
OS=$(shell uname)
ifeq ($(OS), Darwin)
	PYTHON_CMD=python
	SO_EXT=dylib
	DYLD_LIBRARY_PATH=$(LDIR)
	export DYLD_LIBRARY_PATH
	NUM_PROCS=$(shell sysctl -n hw.logicalcpu)
endif
ifeq ($(OS), Linux)
	PYTHON_CMD=python
	SO_EXT=so
	NUM_PROCS=$(shell nproc)
endif
NUM_PROCS_H=$$(($(NUM_PROCS)/2))

SRC=$(wildcard $(SDIR)/*.cpp)
DEPS=$(wildcard $(IDIR)/*.h)
OBJS=$(SRC:$(SDIR)/%.cpp=$(ODIR)/%.o) $(LDIR)/libz3.$(SO_EXT)
FLAGS=-I$(SDIR) -I$(IDIR) -std=c++11 -Wall

all: test2

# -------------------------------------------------------------------------------
#  Rules to build the project
$(LDIR)/libz3.$(SO_EXT):
	@mkdir -p $(CURRENT_DIR)/lib
	cd dependencies/z3-interp-plus;\
		$(PYTHON_CMD) scripts/mk_make.py --prefix=$(CURRENT_DIR);\
		cd build; make install -j$(NUM_PROCS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(LDIR)/libz3.$(SO_EXT)
	@mkdir -p $(CURRENT_DIR)/obj
	$(CXX) -g -c -o $@ $(FLAGS) $<

bin/euf_interpolator: $(LDIR)/libz3.$(SO_EXT) $(OBJS) 
	@mkdir -p $(CURRENT_DIR)/bin
	$(CXX) -g -o $@ $(OBJS) $(FLAGS) -lpthread
# -------------------------------------------------------------------------------

# -------------------------------------------------------
#  Rules to test a single or many smt2 files
.PHONY: test1
test1: bin/euf_interpolator
	./bin/euf_interpolator ./tests/smt2-files/test_1.smt2 e e1 e2
.PHONY: test2
test2: bin/euf_interpolator
	./bin/euf_interpolator ./tests/smt2-files/example_2.smt2 e0
# -------------------------------------------------------

# ------------------------------
#  Cleaning
.PHONY: clean
clean:
	rm -rf $(CURRENT_DIR)/bin/euf_interpolator
	rm -rf $(CURRENT_DIR)/obj/*

.PHONY: z3_clean
z3_clean:
	cd dependencies/z3-interp-plus/build;\
		make uninstall

.PHONY: deep_clean
deep_clean: clean z3_clean
# ------------------------------
