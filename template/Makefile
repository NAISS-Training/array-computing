CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -O2

# OpenMP support (set OPENMP=1, or use openmp/openmp-debug/openmp-release targets)
OPENMP ?= 0
OMPFLAGS :=
ifeq ($(OPENMP),1)
OMPFLAGS += -fopenmp
endif

# Additional project headers
INCLUDES := -I../include

# Eigen include detection order:
# 1) Lmod-exported roots (EBROOTEIGEN / EIGEN_ROOT)
# 2) pkg-config (typical Ubuntu/WSL install)
# 3) Common filesystem paths
ifneq ($(strip $(EBROOTEIGEN)),)
EIGEN_INCLUDE_FLAG ?= -I$(EBROOTEIGEN)/include/eigen3
else ifneq ($(strip $(EIGEN_ROOT)),)
EIGEN_INCLUDE_FLAG ?= -I$(EIGEN_ROOT)/include/eigen3
else ifneq ($(strip $(shell pkg-config --cflags-only-I eigen3 2>/dev/null)),)
EIGEN_INCLUDE_FLAG ?= $(shell pkg-config --cflags-only-I eigen3 2>/dev/null)
else ifneq ($(wildcard /usr/include/eigen3/Eigen/Core),)
EIGEN_INCLUDE_FLAG ?= -I/usr/include/eigen3
else ifneq ($(wildcard /usr/local/include/eigen3/Eigen/Core),)
EIGEN_INCLUDE_FLAG ?= -I/usr/local/include/eigen3
else
$(error Could not locate Eigen headers. Load an Eigen module (Lmod) or install libeigen3-dev)
endif

ifneq ($(strip $(LOADEDMODULES)),)
ifneq ($(findstring eigen,$(shell printf '%s' '$(LOADEDMODULES)' | tr '[:upper:]' '[:lower:]')),)
ifeq ($(strip $(EBROOTEIGEN)$(EIGEN_ROOT)),)
$(warning LOADEDMODULES contains 'eigen' but no EBROOTEIGEN/EIGEN_ROOT was exported; using detected include: $(EIGEN_INCLUDE_FLAG))
endif
endif
endif

INCLUDES += $(EIGEN_INCLUDE_FLAG)

# Build all .cpp files in this directory as separate executables.
SRCS := $(wildcard *.cpp)
TARGETS := $(patsubst %.cpp,%,$(SRCS))

.PHONY: all debug release openmp openmp-debug openmp-release clean list

all: $(TARGETS)

debug: CXXFLAGS := -std=c++23 -Wall -Wextra -O0 -g
debug: clean all

release: CXXFLAGS := -std=c++23 -Wall -Wextra -O3 -DNDEBUG
release: clean all

openmp: OPENMP := 1
openmp: OMPFLAGS := -fopenmp
openmp: clean all

openmp-debug: OPENMP := 1
openmp-debug: OMPFLAGS := -fopenmp
openmp-debug: CXXFLAGS := -std=c++23 -Wall -Wextra -O0 -g
openmp-debug: clean all

openmp-release: OPENMP := 1
openmp-release: OMPFLAGS := -fopenmp
openmp-release: CXXFLAGS := -std=c++23 -Wall -Wextra -O3 -DNDEBUG
openmp-release: clean all

list:
	@echo "Sources : $(SRCS)"
	@echo "Targets : $(TARGETS)"
	@echo "Eigen   : $(EIGEN_INCLUDE_FLAG)"
	@echo "OpenMP  : $(if $(strip $(OMPFLAGS)),enabled,disabled)"

%: %.cpp
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(TARGETS)
