# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jdp/custom-scripts/trashify

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jdp/custom-scripts/trashify/Debug

# Include any dependencies generated for this target.
include CMakeFiles/trashify.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trashify.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trashify.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trashify.dir/flags.make

CMakeFiles/trashify.dir/main.cpp.o: CMakeFiles/trashify.dir/flags.make
CMakeFiles/trashify.dir/main.cpp.o: /home/jdp/custom-scripts/trashify/main.cpp
CMakeFiles/trashify.dir/main.cpp.o: CMakeFiles/trashify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jdp/custom-scripts/trashify/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trashify.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/trashify.dir/main.cpp.o -MF CMakeFiles/trashify.dir/main.cpp.o.d -o CMakeFiles/trashify.dir/main.cpp.o -c /home/jdp/custom-scripts/trashify/main.cpp

CMakeFiles/trashify.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/trashify.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jdp/custom-scripts/trashify/main.cpp > CMakeFiles/trashify.dir/main.cpp.i

CMakeFiles/trashify.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/trashify.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jdp/custom-scripts/trashify/main.cpp -o CMakeFiles/trashify.dir/main.cpp.s

# Object files for target trashify
trashify_OBJECTS = \
"CMakeFiles/trashify.dir/main.cpp.o"

# External object files for target trashify
trashify_EXTERNAL_OBJECTS =

trashify: CMakeFiles/trashify.dir/main.cpp.o
trashify: CMakeFiles/trashify.dir/build.make
trashify: CMakeFiles/trashify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jdp/custom-scripts/trashify/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable trashify"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trashify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trashify.dir/build: trashify
.PHONY : CMakeFiles/trashify.dir/build

CMakeFiles/trashify.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trashify.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trashify.dir/clean

CMakeFiles/trashify.dir/depend:
	cd /home/jdp/custom-scripts/trashify/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jdp/custom-scripts/trashify /home/jdp/custom-scripts/trashify /home/jdp/custom-scripts/trashify/Debug /home/jdp/custom-scripts/trashify/Debug /home/jdp/custom-scripts/trashify/Debug/CMakeFiles/trashify.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/trashify.dir/depend

