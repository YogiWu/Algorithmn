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
CMAKE_COMMAND = /home/yogi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yogi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yogi/Project/2019/Algorithmn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yogi/Project/2019/Algorithmn/cmake-build-debug

# Include any dependencies generated for this target.
include number_split/CMakeFiles/number_split.dir/depend.make

# Include the progress variables for this target.
include number_split/CMakeFiles/number_split.dir/progress.make

# Include the compile flags for this target's objects.
include number_split/CMakeFiles/number_split.dir/flags.make

number_split/CMakeFiles/number_split.dir/main.cpp.o: number_split/CMakeFiles/number_split.dir/flags.make
number_split/CMakeFiles/number_split.dir/main.cpp.o: ../number_split/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yogi/Project/2019/Algorithmn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object number_split/CMakeFiles/number_split.dir/main.cpp.o"
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/number_split.dir/main.cpp.o -c /home/yogi/Project/2019/Algorithmn/number_split/main.cpp

number_split/CMakeFiles/number_split.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/number_split.dir/main.cpp.i"
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yogi/Project/2019/Algorithmn/number_split/main.cpp > CMakeFiles/number_split.dir/main.cpp.i

number_split/CMakeFiles/number_split.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/number_split.dir/main.cpp.s"
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yogi/Project/2019/Algorithmn/number_split/main.cpp -o CMakeFiles/number_split.dir/main.cpp.s

# Object files for target number_split
number_split_OBJECTS = \
"CMakeFiles/number_split.dir/main.cpp.o"

# External object files for target number_split
number_split_EXTERNAL_OBJECTS =

number_split/number_split: number_split/CMakeFiles/number_split.dir/main.cpp.o
number_split/number_split: number_split/CMakeFiles/number_split.dir/build.make
number_split/number_split: number_split/CMakeFiles/number_split.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yogi/Project/2019/Algorithmn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable number_split"
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/number_split.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
number_split/CMakeFiles/number_split.dir/build: number_split/number_split

.PHONY : number_split/CMakeFiles/number_split.dir/build

number_split/CMakeFiles/number_split.dir/clean:
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split && $(CMAKE_COMMAND) -P CMakeFiles/number_split.dir/cmake_clean.cmake
.PHONY : number_split/CMakeFiles/number_split.dir/clean

number_split/CMakeFiles/number_split.dir/depend:
	cd /home/yogi/Project/2019/Algorithmn/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yogi/Project/2019/Algorithmn /home/yogi/Project/2019/Algorithmn/number_split /home/yogi/Project/2019/Algorithmn/cmake-build-debug /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split /home/yogi/Project/2019/Algorithmn/cmake-build-debug/number_split/CMakeFiles/number_split.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : number_split/CMakeFiles/number_split.dir/depend

