# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/ikhar/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/ikhar/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bubble_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bubble_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bubble_sort.dir/flags.make

CMakeFiles/bubble_sort.dir/main.cpp.o: CMakeFiles/bubble_sort.dir/flags.make
CMakeFiles/bubble_sort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bubble_sort.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bubble_sort.dir/main.cpp.o -c "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/main.cpp"

CMakeFiles/bubble_sort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bubble_sort.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/main.cpp" > CMakeFiles/bubble_sort.dir/main.cpp.i

CMakeFiles/bubble_sort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bubble_sort.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/main.cpp" -o CMakeFiles/bubble_sort.dir/main.cpp.s

# Object files for target bubble_sort
bubble_sort_OBJECTS = \
"CMakeFiles/bubble_sort.dir/main.cpp.o"

# External object files for target bubble_sort
bubble_sort_EXTERNAL_OBJECTS =

bubble_sort.exe: CMakeFiles/bubble_sort.dir/main.cpp.o
bubble_sort.exe: CMakeFiles/bubble_sort.dir/build.make
bubble_sort.exe: CMakeFiles/bubble_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bubble_sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bubble_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bubble_sort.dir/build: bubble_sort.exe

.PHONY : CMakeFiles/bubble_sort.dir/build

CMakeFiles/bubble_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bubble_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bubble_sort.dir/clean

CMakeFiles/bubble_sort.dir/depend:
	cd "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort" "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort" "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug" "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug" "/cygdrive/d/Me/MIPT/Informatics CPP/lab8/bubble_sort/cmake-build-debug/CMakeFiles/bubble_sort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bubble_sort.dir/depend

