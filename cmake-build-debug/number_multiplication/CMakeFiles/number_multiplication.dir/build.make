# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/yogi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6262.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yogi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6262.62/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yogi/Project/2019_AUTUMN/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include number_multiplication/CMakeFiles/number_multiplication.dir/depend.make

# Include the progress variables for this target.
include number_multiplication/CMakeFiles/number_multiplication.dir/progress.make

# Include the compile flags for this target's objects.
include number_multiplication/CMakeFiles/number_multiplication.dir/flags.make

number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.o: number_multiplication/CMakeFiles/number_multiplication.dir/flags.make
number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.o: ../number_multiplication/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.o"
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/number_multiplication.dir/main.cpp.o -c /home/yogi/Project/2019_AUTUMN/Algorithm/number_multiplication/main.cpp

number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/number_multiplication.dir/main.cpp.i"
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yogi/Project/2019_AUTUMN/Algorithm/number_multiplication/main.cpp > CMakeFiles/number_multiplication.dir/main.cpp.i

number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/number_multiplication.dir/main.cpp.s"
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yogi/Project/2019_AUTUMN/Algorithm/number_multiplication/main.cpp -o CMakeFiles/number_multiplication.dir/main.cpp.s

# Object files for target number_multiplication
number_multiplication_OBJECTS = \
"CMakeFiles/number_multiplication.dir/main.cpp.o"

# External object files for target number_multiplication
number_multiplication_EXTERNAL_OBJECTS =

number_multiplication/number_multiplication: number_multiplication/CMakeFiles/number_multiplication.dir/main.cpp.o
number_multiplication/number_multiplication: number_multiplication/CMakeFiles/number_multiplication.dir/build.make
number_multiplication/number_multiplication: number_multiplication/CMakeFiles/number_multiplication.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable number_multiplication"
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/number_multiplication.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
number_multiplication/CMakeFiles/number_multiplication.dir/build: number_multiplication/number_multiplication

.PHONY : number_multiplication/CMakeFiles/number_multiplication.dir/build

number_multiplication/CMakeFiles/number_multiplication.dir/clean:
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication && $(CMAKE_COMMAND) -P CMakeFiles/number_multiplication.dir/cmake_clean.cmake
.PHONY : number_multiplication/CMakeFiles/number_multiplication.dir/clean

number_multiplication/CMakeFiles/number_multiplication.dir/depend:
	cd /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yogi/Project/2019_AUTUMN/Algorithm /home/yogi/Project/2019_AUTUMN/Algorithm/number_multiplication /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication /home/yogi/Project/2019_AUTUMN/Algorithm/cmake-build-debug/number_multiplication/CMakeFiles/number_multiplication.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : number_multiplication/CMakeFiles/number_multiplication.dir/depend

