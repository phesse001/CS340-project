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
CMAKE_SOURCE_DIR = /home/patrick/CS340-project/passes/RemoveCalls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrick/CS340-project/passes/RemoveCalls

# Utility rule file for install-RemoveCalls-stripped.

# Include the progress variables for this target.
include CMakeFiles/install-RemoveCalls-stripped.dir/progress.make

CMakeFiles/install-RemoveCalls-stripped:
	/usr/bin/cmake -DCMAKE_INSTALL_COMPONENT="RemoveCalls" -DCMAKE_INSTALL_DO_STRIP=1 -P /home/patrick/CS340-project/passes/RemoveCalls/cmake_install.cmake

install-RemoveCalls-stripped: CMakeFiles/install-RemoveCalls-stripped
install-RemoveCalls-stripped: CMakeFiles/install-RemoveCalls-stripped.dir/build.make

.PHONY : install-RemoveCalls-stripped

# Rule to build all files generated by this target.
CMakeFiles/install-RemoveCalls-stripped.dir/build: install-RemoveCalls-stripped

.PHONY : CMakeFiles/install-RemoveCalls-stripped.dir/build

CMakeFiles/install-RemoveCalls-stripped.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/install-RemoveCalls-stripped.dir/cmake_clean.cmake
.PHONY : CMakeFiles/install-RemoveCalls-stripped.dir/clean

CMakeFiles/install-RemoveCalls-stripped.dir/depend:
	cd /home/patrick/CS340-project/passes/RemoveCalls && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patrick/CS340-project/passes/RemoveCalls /home/patrick/CS340-project/passes/RemoveCalls /home/patrick/CS340-project/passes/RemoveCalls /home/patrick/CS340-project/passes/RemoveCalls /home/patrick/CS340-project/passes/RemoveCalls/CMakeFiles/install-RemoveCalls-stripped.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/install-RemoveCalls-stripped.dir/depend

