# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fern/Documents/projects/aoc24/day1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fern/Documents/projects/aoc24/day1/build

# Include any dependencies generated for this target.
include CMakeFiles/aoc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aoc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aoc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aoc.dir/flags.make

CMakeFiles/aoc.dir/part1.cpp.o: CMakeFiles/aoc.dir/flags.make
CMakeFiles/aoc.dir/part1.cpp.o: /Users/fern/Documents/projects/aoc24/day1/part1.cpp
CMakeFiles/aoc.dir/part1.cpp.o: CMakeFiles/aoc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fern/Documents/projects/aoc24/day1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aoc.dir/part1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aoc.dir/part1.cpp.o -MF CMakeFiles/aoc.dir/part1.cpp.o.d -o CMakeFiles/aoc.dir/part1.cpp.o -c /Users/fern/Documents/projects/aoc24/day1/part1.cpp

CMakeFiles/aoc.dir/part1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aoc.dir/part1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fern/Documents/projects/aoc24/day1/part1.cpp > CMakeFiles/aoc.dir/part1.cpp.i

CMakeFiles/aoc.dir/part1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aoc.dir/part1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fern/Documents/projects/aoc24/day1/part1.cpp -o CMakeFiles/aoc.dir/part1.cpp.s

CMakeFiles/aoc.dir/part2.cpp.o: CMakeFiles/aoc.dir/flags.make
CMakeFiles/aoc.dir/part2.cpp.o: /Users/fern/Documents/projects/aoc24/day1/part2.cpp
CMakeFiles/aoc.dir/part2.cpp.o: CMakeFiles/aoc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fern/Documents/projects/aoc24/day1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aoc.dir/part2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aoc.dir/part2.cpp.o -MF CMakeFiles/aoc.dir/part2.cpp.o.d -o CMakeFiles/aoc.dir/part2.cpp.o -c /Users/fern/Documents/projects/aoc24/day1/part2.cpp

CMakeFiles/aoc.dir/part2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aoc.dir/part2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fern/Documents/projects/aoc24/day1/part2.cpp > CMakeFiles/aoc.dir/part2.cpp.i

CMakeFiles/aoc.dir/part2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aoc.dir/part2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fern/Documents/projects/aoc24/day1/part2.cpp -o CMakeFiles/aoc.dir/part2.cpp.s

# Object files for target aoc
aoc_OBJECTS = \
"CMakeFiles/aoc.dir/part1.cpp.o" \
"CMakeFiles/aoc.dir/part2.cpp.o"

# External object files for target aoc
aoc_EXTERNAL_OBJECTS =

aoc: CMakeFiles/aoc.dir/part1.cpp.o
aoc: CMakeFiles/aoc.dir/part2.cpp.o
aoc: CMakeFiles/aoc.dir/build.make
aoc: CMakeFiles/aoc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/fern/Documents/projects/aoc24/day1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable aoc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aoc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aoc.dir/build: aoc
.PHONY : CMakeFiles/aoc.dir/build

CMakeFiles/aoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aoc.dir/clean

CMakeFiles/aoc.dir/depend:
	cd /Users/fern/Documents/projects/aoc24/day1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fern/Documents/projects/aoc24/day1 /Users/fern/Documents/projects/aoc24/day1 /Users/fern/Documents/projects/aoc24/day1/build /Users/fern/Documents/projects/aoc24/day1/build /Users/fern/Documents/projects/aoc24/day1/build/CMakeFiles/aoc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/aoc.dir/depend

