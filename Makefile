# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/khoihd/Dropbox/dcop_generator_pdcdcop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/khoihd/Dropbox/dcop_generator_pdcdcop

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.16.5/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.16.5/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/khoihd/Dropbox/dcop_generator_pdcdcop/CMakeFiles /Users/khoihd/Dropbox/dcop_generator_pdcdcop/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/khoihd/Dropbox/dcop_generator_pdcdcop/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named dcop_generator_pdcdcop

# Build rule for target.
dcop_generator_pdcdcop: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dcop_generator_pdcdcop
.PHONY : dcop_generator_pdcdcop

# fast build rule for target.
dcop_generator_pdcdcop/fast:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/build
.PHONY : dcop_generator_pdcdcop/fast

src/Graph/graph-utils.o: src/Graph/graph-utils.cpp.o

.PHONY : src/Graph/graph-utils.o

# target to build an object file
src/Graph/graph-utils.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph-utils.cpp.o
.PHONY : src/Graph/graph-utils.cpp.o

src/Graph/graph-utils.i: src/Graph/graph-utils.cpp.i

.PHONY : src/Graph/graph-utils.i

# target to preprocess a source file
src/Graph/graph-utils.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph-utils.cpp.i
.PHONY : src/Graph/graph-utils.cpp.i

src/Graph/graph-utils.s: src/Graph/graph-utils.cpp.s

.PHONY : src/Graph/graph-utils.s

# target to generate assembly for a file
src/Graph/graph-utils.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph-utils.cpp.s
.PHONY : src/Graph/graph-utils.cpp.s

src/Graph/graph.o: src/Graph/graph.cpp.o

.PHONY : src/Graph/graph.o

# target to build an object file
src/Graph/graph.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph.cpp.o
.PHONY : src/Graph/graph.cpp.o

src/Graph/graph.i: src/Graph/graph.cpp.i

.PHONY : src/Graph/graph.i

# target to preprocess a source file
src/Graph/graph.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph.cpp.i
.PHONY : src/Graph/graph.cpp.i

src/Graph/graph.s: src/Graph/graph.cpp.s

.PHONY : src/Graph/graph.s

# target to generate assembly for a file
src/Graph/graph.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/graph.cpp.s
.PHONY : src/Graph/graph.cpp.s

src/Graph/planar-graph.o: src/Graph/planar-graph.cpp.o

.PHONY : src/Graph/planar-graph.o

# target to build an object file
src/Graph/planar-graph.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/planar-graph.cpp.o
.PHONY : src/Graph/planar-graph.cpp.o

src/Graph/planar-graph.i: src/Graph/planar-graph.cpp.i

.PHONY : src/Graph/planar-graph.i

# target to preprocess a source file
src/Graph/planar-graph.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/planar-graph.cpp.i
.PHONY : src/Graph/planar-graph.cpp.i

src/Graph/planar-graph.s: src/Graph/planar-graph.cpp.s

.PHONY : src/Graph/planar-graph.s

# target to generate assembly for a file
src/Graph/planar-graph.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/planar-graph.cpp.s
.PHONY : src/Graph/planar-graph.cpp.s

src/Graph/random-graph.o: src/Graph/random-graph.cpp.o

.PHONY : src/Graph/random-graph.o

# target to build an object file
src/Graph/random-graph.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/random-graph.cpp.o
.PHONY : src/Graph/random-graph.cpp.o

src/Graph/random-graph.i: src/Graph/random-graph.cpp.i

.PHONY : src/Graph/random-graph.i

# target to preprocess a source file
src/Graph/random-graph.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/random-graph.cpp.i
.PHONY : src/Graph/random-graph.cpp.i

src/Graph/random-graph.s: src/Graph/random-graph.cpp.s

.PHONY : src/Graph/random-graph.s

# target to generate assembly for a file
src/Graph/random-graph.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/random-graph.cpp.s
.PHONY : src/Graph/random-graph.cpp.s

src/Graph/scale-free-graph.o: src/Graph/scale-free-graph.cpp.o

.PHONY : src/Graph/scale-free-graph.o

# target to build an object file
src/Graph/scale-free-graph.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/scale-free-graph.cpp.o
.PHONY : src/Graph/scale-free-graph.cpp.o

src/Graph/scale-free-graph.i: src/Graph/scale-free-graph.cpp.i

.PHONY : src/Graph/scale-free-graph.i

# target to preprocess a source file
src/Graph/scale-free-graph.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/scale-free-graph.cpp.i
.PHONY : src/Graph/scale-free-graph.cpp.i

src/Graph/scale-free-graph.s: src/Graph/scale-free-graph.cpp.s

.PHONY : src/Graph/scale-free-graph.s

# target to generate assembly for a file
src/Graph/scale-free-graph.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Graph/scale-free-graph.cpp.s
.PHONY : src/Graph/scale-free-graph.cpp.s

src/IO/input.o: src/IO/input.cpp.o

.PHONY : src/IO/input.o

# target to build an object file
src/IO/input.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/input.cpp.o
.PHONY : src/IO/input.cpp.o

src/IO/input.i: src/IO/input.cpp.i

.PHONY : src/IO/input.i

# target to preprocess a source file
src/IO/input.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/input.cpp.i
.PHONY : src/IO/input.cpp.i

src/IO/input.s: src/IO/input.cpp.s

.PHONY : src/IO/input.s

# target to generate assembly for a file
src/IO/input.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/input.cpp.s
.PHONY : src/IO/input.cpp.s

src/IO/output-dalo.o: src/IO/output-dalo.cpp.o

.PHONY : src/IO/output-dalo.o

# target to build an object file
src/IO/output-dalo.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-dalo.cpp.o
.PHONY : src/IO/output-dalo.cpp.o

src/IO/output-dalo.i: src/IO/output-dalo.cpp.i

.PHONY : src/IO/output-dalo.i

# target to preprocess a source file
src/IO/output-dalo.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-dalo.cpp.i
.PHONY : src/IO/output-dalo.cpp.i

src/IO/output-dalo.s: src/IO/output-dalo.cpp.s

.PHONY : src/IO/output-dalo.s

# target to generate assembly for a file
src/IO/output-dalo.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-dalo.cpp.s
.PHONY : src/IO/output-dalo.cpp.s

src/IO/output-max_sum.o: src/IO/output-max_sum.cpp.o

.PHONY : src/IO/output-max_sum.o

# target to build an object file
src/IO/output-max_sum.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-max_sum.cpp.o
.PHONY : src/IO/output-max_sum.cpp.o

src/IO/output-max_sum.i: src/IO/output-max_sum.cpp.i

.PHONY : src/IO/output-max_sum.i

# target to preprocess a source file
src/IO/output-max_sum.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-max_sum.cpp.i
.PHONY : src/IO/output-max_sum.cpp.i

src/IO/output-max_sum.s: src/IO/output-max_sum.cpp.s

.PHONY : src/IO/output-max_sum.s

# target to generate assembly for a file
src/IO/output-max_sum.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-max_sum.cpp.s
.PHONY : src/IO/output-max_sum.cpp.s

src/IO/output-topology.o: src/IO/output-topology.cpp.o

.PHONY : src/IO/output-topology.o

# target to build an object file
src/IO/output-topology.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-topology.cpp.o
.PHONY : src/IO/output-topology.cpp.o

src/IO/output-topology.i: src/IO/output-topology.cpp.i

.PHONY : src/IO/output-topology.i

# target to preprocess a source file
src/IO/output-topology.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-topology.cpp.i
.PHONY : src/IO/output-topology.cpp.i

src/IO/output-topology.s: src/IO/output-topology.cpp.s

.PHONY : src/IO/output-topology.s

# target to generate assembly for a file
src/IO/output-topology.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-topology.cpp.s
.PHONY : src/IO/output-topology.cpp.s

src/IO/output-xml.o: src/IO/output-xml.cpp.o

.PHONY : src/IO/output-xml.o

# target to build an object file
src/IO/output-xml.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-xml.cpp.o
.PHONY : src/IO/output-xml.cpp.o

src/IO/output-xml.i: src/IO/output-xml.cpp.i

.PHONY : src/IO/output-xml.i

# target to preprocess a source file
src/IO/output-xml.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-xml.cpp.i
.PHONY : src/IO/output-xml.cpp.i

src/IO/output-xml.s: src/IO/output-xml.cpp.s

.PHONY : src/IO/output-xml.s

# target to generate assembly for a file
src/IO/output-xml.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output-xml.cpp.s
.PHONY : src/IO/output-xml.cpp.s

src/IO/output.o: src/IO/output.cpp.o

.PHONY : src/IO/output.o

# target to build an object file
src/IO/output.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output.cpp.o
.PHONY : src/IO/output.cpp.o

src/IO/output.i: src/IO/output.cpp.i

.PHONY : src/IO/output.i

# target to preprocess a source file
src/IO/output.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output.cpp.i
.PHONY : src/IO/output.cpp.i

src/IO/output.s: src/IO/output.cpp.s

.PHONY : src/IO/output.s

# target to generate assembly for a file
src/IO/output.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output.cpp.s
.PHONY : src/IO/output.cpp.s

src/IO/output_wcsp.o: src/IO/output_wcsp.cpp.o

.PHONY : src/IO/output_wcsp.o

# target to build an object file
src/IO/output_wcsp.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output_wcsp.cpp.o
.PHONY : src/IO/output_wcsp.cpp.o

src/IO/output_wcsp.i: src/IO/output_wcsp.cpp.i

.PHONY : src/IO/output_wcsp.i

# target to preprocess a source file
src/IO/output_wcsp.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output_wcsp.cpp.i
.PHONY : src/IO/output_wcsp.cpp.i

src/IO/output_wcsp.s: src/IO/output_wcsp.cpp.s

.PHONY : src/IO/output_wcsp.s

# target to generate assembly for a file
src/IO/output_wcsp.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/IO/output_wcsp.cpp.s
.PHONY : src/IO/output_wcsp.cpp.s

src/Instance/acgdr_instance.o: src/Instance/acgdr_instance.cpp.o

.PHONY : src/Instance/acgdr_instance.o

# target to build an object file
src/Instance/acgdr_instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/acgdr_instance.cpp.o
.PHONY : src/Instance/acgdr_instance.cpp.o

src/Instance/acgdr_instance.i: src/Instance/acgdr_instance.cpp.i

.PHONY : src/Instance/acgdr_instance.i

# target to preprocess a source file
src/Instance/acgdr_instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/acgdr_instance.cpp.i
.PHONY : src/Instance/acgdr_instance.cpp.i

src/Instance/acgdr_instance.s: src/Instance/acgdr_instance.cpp.s

.PHONY : src/Instance/acgdr_instance.s

# target to generate assembly for a file
src/Instance/acgdr_instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/acgdr_instance.cpp.s
.PHONY : src/Instance/acgdr_instance.cpp.s

src/Instance/grid-instance.o: src/Instance/grid-instance.cpp.o

.PHONY : src/Instance/grid-instance.o

# target to build an object file
src/Instance/grid-instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/grid-instance.cpp.o
.PHONY : src/Instance/grid-instance.cpp.o

src/Instance/grid-instance.i: src/Instance/grid-instance.cpp.i

.PHONY : src/Instance/grid-instance.i

# target to preprocess a source file
src/Instance/grid-instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/grid-instance.cpp.i
.PHONY : src/Instance/grid-instance.cpp.i

src/Instance/grid-instance.s: src/Instance/grid-instance.cpp.s

.PHONY : src/Instance/grid-instance.s

# target to generate assembly for a file
src/Instance/grid-instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/grid-instance.cpp.s
.PHONY : src/Instance/grid-instance.cpp.s

src/Instance/instance-factory.o: src/Instance/instance-factory.cpp.o

.PHONY : src/Instance/instance-factory.o

# target to build an object file
src/Instance/instance-factory.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance-factory.cpp.o
.PHONY : src/Instance/instance-factory.cpp.o

src/Instance/instance-factory.i: src/Instance/instance-factory.cpp.i

.PHONY : src/Instance/instance-factory.i

# target to preprocess a source file
src/Instance/instance-factory.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance-factory.cpp.i
.PHONY : src/Instance/instance-factory.cpp.i

src/Instance/instance-factory.s: src/Instance/instance-factory.cpp.s

.PHONY : src/Instance/instance-factory.s

# target to generate assembly for a file
src/Instance/instance-factory.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance-factory.cpp.s
.PHONY : src/Instance/instance-factory.cpp.s

src/Instance/instance.o: src/Instance/instance.cpp.o

.PHONY : src/Instance/instance.o

# target to build an object file
src/Instance/instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance.cpp.o
.PHONY : src/Instance/instance.cpp.o

src/Instance/instance.i: src/Instance/instance.cpp.i

.PHONY : src/Instance/instance.i

# target to preprocess a source file
src/Instance/instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance.cpp.i
.PHONY : src/Instance/instance.cpp.i

src/Instance/instance.s: src/Instance/instance.cpp.s

.PHONY : src/Instance/instance.s

# target to generate assembly for a file
src/Instance/instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/instance.cpp.s
.PHONY : src/Instance/instance.cpp.s

src/Instance/meeting_scheduling_instance.o: src/Instance/meeting_scheduling_instance.cpp.o

.PHONY : src/Instance/meeting_scheduling_instance.o

# target to build an object file
src/Instance/meeting_scheduling_instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/meeting_scheduling_instance.cpp.o
.PHONY : src/Instance/meeting_scheduling_instance.cpp.o

src/Instance/meeting_scheduling_instance.i: src/Instance/meeting_scheduling_instance.cpp.i

.PHONY : src/Instance/meeting_scheduling_instance.i

# target to preprocess a source file
src/Instance/meeting_scheduling_instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/meeting_scheduling_instance.cpp.i
.PHONY : src/Instance/meeting_scheduling_instance.cpp.i

src/Instance/meeting_scheduling_instance.s: src/Instance/meeting_scheduling_instance.cpp.s

.PHONY : src/Instance/meeting_scheduling_instance.s

# target to generate assembly for a file
src/Instance/meeting_scheduling_instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/meeting_scheduling_instance.cpp.s
.PHONY : src/Instance/meeting_scheduling_instance.cpp.s

src/Instance/random-instance.o: src/Instance/random-instance.cpp.o

.PHONY : src/Instance/random-instance.o

# target to build an object file
src/Instance/random-instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/random-instance.cpp.o
.PHONY : src/Instance/random-instance.cpp.o

src/Instance/random-instance.i: src/Instance/random-instance.cpp.i

.PHONY : src/Instance/random-instance.i

# target to preprocess a source file
src/Instance/random-instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/random-instance.cpp.i
.PHONY : src/Instance/random-instance.cpp.i

src/Instance/random-instance.s: src/Instance/random-instance.cpp.s

.PHONY : src/Instance/random-instance.s

# target to generate assembly for a file
src/Instance/random-instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/random-instance.cpp.s
.PHONY : src/Instance/random-instance.cpp.s

src/Instance/scale-free-instance.o: src/Instance/scale-free-instance.cpp.o

.PHONY : src/Instance/scale-free-instance.o

# target to build an object file
src/Instance/scale-free-instance.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/scale-free-instance.cpp.o
.PHONY : src/Instance/scale-free-instance.cpp.o

src/Instance/scale-free-instance.i: src/Instance/scale-free-instance.cpp.i

.PHONY : src/Instance/scale-free-instance.i

# target to preprocess a source file
src/Instance/scale-free-instance.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/scale-free-instance.cpp.i
.PHONY : src/Instance/scale-free-instance.cpp.i

src/Instance/scale-free-instance.s: src/Instance/scale-free-instance.cpp.s

.PHONY : src/Instance/scale-free-instance.s

# target to generate assembly for a file
src/Instance/scale-free-instance.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/Instance/scale-free-instance.cpp.s
.PHONY : src/Instance/scale-free-instance.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/dcop_generator_pdcdcop.dir/build.make CMakeFiles/dcop_generator_pdcdcop.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... dcop_generator_pdcdcop"
	@echo "... src/Graph/graph-utils.o"
	@echo "... src/Graph/graph-utils.i"
	@echo "... src/Graph/graph-utils.s"
	@echo "... src/Graph/graph.o"
	@echo "... src/Graph/graph.i"
	@echo "... src/Graph/graph.s"
	@echo "... src/Graph/planar-graph.o"
	@echo "... src/Graph/planar-graph.i"
	@echo "... src/Graph/planar-graph.s"
	@echo "... src/Graph/random-graph.o"
	@echo "... src/Graph/random-graph.i"
	@echo "... src/Graph/random-graph.s"
	@echo "... src/Graph/scale-free-graph.o"
	@echo "... src/Graph/scale-free-graph.i"
	@echo "... src/Graph/scale-free-graph.s"
	@echo "... src/IO/input.o"
	@echo "... src/IO/input.i"
	@echo "... src/IO/input.s"
	@echo "... src/IO/output-dalo.o"
	@echo "... src/IO/output-dalo.i"
	@echo "... src/IO/output-dalo.s"
	@echo "... src/IO/output-max_sum.o"
	@echo "... src/IO/output-max_sum.i"
	@echo "... src/IO/output-max_sum.s"
	@echo "... src/IO/output-topology.o"
	@echo "... src/IO/output-topology.i"
	@echo "... src/IO/output-topology.s"
	@echo "... src/IO/output-xml.o"
	@echo "... src/IO/output-xml.i"
	@echo "... src/IO/output-xml.s"
	@echo "... src/IO/output.o"
	@echo "... src/IO/output.i"
	@echo "... src/IO/output.s"
	@echo "... src/IO/output_wcsp.o"
	@echo "... src/IO/output_wcsp.i"
	@echo "... src/IO/output_wcsp.s"
	@echo "... src/Instance/acgdr_instance.o"
	@echo "... src/Instance/acgdr_instance.i"
	@echo "... src/Instance/acgdr_instance.s"
	@echo "... src/Instance/grid-instance.o"
	@echo "... src/Instance/grid-instance.i"
	@echo "... src/Instance/grid-instance.s"
	@echo "... src/Instance/instance-factory.o"
	@echo "... src/Instance/instance-factory.i"
	@echo "... src/Instance/instance-factory.s"
	@echo "... src/Instance/instance.o"
	@echo "... src/Instance/instance.i"
	@echo "... src/Instance/instance.s"
	@echo "... src/Instance/meeting_scheduling_instance.o"
	@echo "... src/Instance/meeting_scheduling_instance.i"
	@echo "... src/Instance/meeting_scheduling_instance.s"
	@echo "... src/Instance/random-instance.o"
	@echo "... src/Instance/random-instance.i"
	@echo "... src/Instance/random-instance.s"
	@echo "... src/Instance/scale-free-instance.o"
	@echo "... src/Instance/scale-free-instance.i"
	@echo "... src/Instance/scale-free-instance.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

