# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/patrick/CS340-project/passes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrick/CS340-project/passes

# Utility rule file for install-NumOpCodes.

# Include the progress variables for this target.
include NumOpCodes/CMakeFiles/install-NumOpCodes.dir/progress.make

NumOpCodes/CMakeFiles/install-NumOpCodes:
	cd /home/patrick/CS340-project/passes/NumOpCodes && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT="NumOpCodes" -P /home/patrick/CS340-project/passes/cmake_install.cmake

install-NumOpCodes: NumOpCodes/CMakeFiles/install-NumOpCodes
install-NumOpCodes: NumOpCodes/CMakeFiles/install-NumOpCodes.dir/build.make

.PHONY : install-NumOpCodes

# Rule to build all files generated by this target.
NumOpCodes/CMakeFiles/install-NumOpCodes.dir/build: install-NumOpCodes

.PHONY : NumOpCodes/CMakeFiles/install-NumOpCodes.dir/build

NumOpCodes/CMakeFiles/install-NumOpCodes.dir/clean:
	cd /home/patrick/CS340-project/passes/NumOpCodes && $(CMAKE_COMMAND) -P CMakeFiles/install-NumOpCodes.dir/cmake_clean.cmake
.PHONY : NumOpCodes/CMakeFiles/install-NumOpCodes.dir/clean

NumOpCodes/CMakeFiles/install-NumOpCodes.dir/depend:
	cd /home/patrick/CS340-project/passes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patrick/CS340-project/passes /home/patrick/CS340-project/passes/NumOpCodes /home/patrick/CS340-project/passes /home/patrick/CS340-project/passes/NumOpCodes /home/patrick/CS340-project/passes/NumOpCodes/CMakeFiles/install-NumOpCodes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : NumOpCodes/CMakeFiles/install-NumOpCodes.dir/depend

