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
CMAKE_SOURCE_DIR = /home/yogi/Project/2019_AUTUMN/Algorithmn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug

# Include any dependencies generated for this target.
include print_group/CMakeFiles/print_group.dir/depend.make

# Include the progress variables for this target.
include print_group/CMakeFiles/print_group.dir/progress.make

# Include the compile flags for this target's objects.
include print_group/CMakeFiles/print_group.dir/flags.make

print_group/CMakeFiles/print_group.dir/main.cpp.o: print_group/CMakeFiles/print_group.dir/flags.make
print_group/CMakeFiles/print_group.dir/main.cpp.o: ../print_group/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object print_group/CMakeFiles/print_group.dir/main.cpp.o"
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/print_group.dir/main.cpp.o -c /home/yogi/Project/2019_AUTUMN/Algorithmn/print_group/main.cpp

print_group/CMakeFiles/print_group.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/print_group.dir/main.cpp.i"
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yogi/Project/2019_AUTUMN/Algorithmn/print_group/main.cpp > CMakeFiles/print_group.dir/main.cpp.i

print_group/CMakeFiles/print_group.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/print_group.dir/main.cpp.s"
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yogi/Project/2019_AUTUMN/Algorithmn/print_group/main.cpp -o CMakeFiles/print_group.dir/main.cpp.s

# Object files for target print_group
print_group_OBJECTS = \
"CMakeFiles/print_group.dir/main.cpp.o"

# External object files for target print_group
print_group_EXTERNAL_OBJECTS =

print_group/print_group: print_group/CMakeFiles/print_group.dir/main.cpp.o
print_group/print_group: print_group/CMakeFiles/print_group.dir/build.make
print_group/print_group: print_group/CMakeFiles/print_group.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable print_group"
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print_group.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
print_group/CMakeFiles/print_group.dir/build: print_group/print_group

.PHONY : print_group/CMakeFiles/print_group.dir/build

print_group/CMakeFiles/print_group.dir/clean:
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group && $(CMAKE_COMMAND) -P CMakeFiles/print_group.dir/cmake_clean.cmake
.PHONY : print_group/CMakeFiles/print_group.dir/clean

print_group/CMakeFiles/print_group.dir/depend:
	cd /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yogi/Project/2019_AUTUMN/Algorithmn /home/yogi/Project/2019_AUTUMN/Algorithmn/print_group /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group /home/yogi/Project/2019_AUTUMN/Algorithmn/cmake-build-debug/print_group/CMakeFiles/print_group.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : print_group/CMakeFiles/print_group.dir/depend

