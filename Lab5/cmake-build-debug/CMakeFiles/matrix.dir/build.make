# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix.dir/flags.make

CMakeFiles/matrix.dir/complex.o: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/complex.o: ../complex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/matrix.dir/complex.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/matrix.dir/complex.o -c /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/complex.cc

CMakeFiles/matrix.dir/complex.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix.dir/complex.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/complex.cc > CMakeFiles/matrix.dir/complex.i

CMakeFiles/matrix.dir/complex.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix.dir/complex.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/complex.cc -o CMakeFiles/matrix.dir/complex.s

CMakeFiles/matrix.dir/complex.o.requires:

.PHONY : CMakeFiles/matrix.dir/complex.o.requires

CMakeFiles/matrix.dir/complex.o.provides: CMakeFiles/matrix.dir/complex.o.requires
	$(MAKE) -f CMakeFiles/matrix.dir/build.make CMakeFiles/matrix.dir/complex.o.provides.build
.PHONY : CMakeFiles/matrix.dir/complex.o.provides

CMakeFiles/matrix.dir/complex.o.provides.build: CMakeFiles/matrix.dir/complex.o


CMakeFiles/matrix.dir/matrix.o: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/matrix.o: ../matrix.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/matrix.dir/matrix.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/matrix.dir/matrix.o -c /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/matrix.cc

CMakeFiles/matrix.dir/matrix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix.dir/matrix.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/matrix.cc > CMakeFiles/matrix.dir/matrix.i

CMakeFiles/matrix.dir/matrix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix.dir/matrix.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/matrix.cc -o CMakeFiles/matrix.dir/matrix.s

CMakeFiles/matrix.dir/matrix.o.requires:

.PHONY : CMakeFiles/matrix.dir/matrix.o.requires

CMakeFiles/matrix.dir/matrix.o.provides: CMakeFiles/matrix.dir/matrix.o.requires
	$(MAKE) -f CMakeFiles/matrix.dir/build.make CMakeFiles/matrix.dir/matrix.o.provides.build
.PHONY : CMakeFiles/matrix.dir/matrix.o.provides

CMakeFiles/matrix.dir/matrix.o.provides.build: CMakeFiles/matrix.dir/matrix.o


CMakeFiles/matrix.dir/main.o: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/main.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/matrix.dir/main.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/matrix.dir/main.o -c /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/main.cc

CMakeFiles/matrix.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix.dir/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/main.cc > CMakeFiles/matrix.dir/main.i

CMakeFiles/matrix.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix.dir/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/main.cc -o CMakeFiles/matrix.dir/main.s

CMakeFiles/matrix.dir/main.o.requires:

.PHONY : CMakeFiles/matrix.dir/main.o.requires

CMakeFiles/matrix.dir/main.o.provides: CMakeFiles/matrix.dir/main.o.requires
	$(MAKE) -f CMakeFiles/matrix.dir/build.make CMakeFiles/matrix.dir/main.o.provides.build
.PHONY : CMakeFiles/matrix.dir/main.o.provides

CMakeFiles/matrix.dir/main.o.provides.build: CMakeFiles/matrix.dir/main.o


# Object files for target matrix
matrix_OBJECTS = \
"CMakeFiles/matrix.dir/complex.o" \
"CMakeFiles/matrix.dir/matrix.o" \
"CMakeFiles/matrix.dir/main.o"

# External object files for target matrix
matrix_EXTERNAL_OBJECTS =

matrix: CMakeFiles/matrix.dir/complex.o
matrix: CMakeFiles/matrix.dir/matrix.o
matrix: CMakeFiles/matrix.dir/main.o
matrix: CMakeFiles/matrix.dir/build.make
matrix: CMakeFiles/matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix.dir/build: matrix

.PHONY : CMakeFiles/matrix.dir/build

CMakeFiles/matrix.dir/requires: CMakeFiles/matrix.dir/complex.o.requires
CMakeFiles/matrix.dir/requires: CMakeFiles/matrix.dir/matrix.o.requires
CMakeFiles/matrix.dir/requires: CMakeFiles/matrix.dir/main.o.requires

.PHONY : CMakeFiles/matrix.dir/requires

CMakeFiles/matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix.dir/clean

CMakeFiles/matrix.dir/depend:
	cd /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5 /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5 /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug /mnt/c/Users/jivey9/CLionProjects/zStudents/Lab5/cmake-build-debug/CMakeFiles/matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrix.dir/depend

