# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /root/bytedance-database-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/bytedance-database-project/build

# Include any dependencies generated for this target.
include src/data/CMakeFiles/data_obj.dir/depend.make

# Include the progress variables for this target.
include src/data/CMakeFiles/data_obj.dir/progress.make

# Include the compile flags for this target's objects.
include src/data/CMakeFiles/data_obj.dir/flags.make

src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.o: src/data/CMakeFiles/data_obj.dir/flags.make
src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.o: ../src/data/csv_data_loader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/bytedance-database-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.o"
	cd /root/bytedance-database-project/build/src/data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_obj.dir/csv_data_loader.cc.o -c /root/bytedance-database-project/src/data/csv_data_loader.cc

src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_obj.dir/csv_data_loader.cc.i"
	cd /root/bytedance-database-project/build/src/data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/bytedance-database-project/src/data/csv_data_loader.cc > CMakeFiles/data_obj.dir/csv_data_loader.cc.i

src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_obj.dir/csv_data_loader.cc.s"
	cd /root/bytedance-database-project/build/src/data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/bytedance-database-project/src/data/csv_data_loader.cc -o CMakeFiles/data_obj.dir/csv_data_loader.cc.s

data_obj: src/data/CMakeFiles/data_obj.dir/csv_data_loader.cc.o
data_obj: src/data/CMakeFiles/data_obj.dir/build.make

.PHONY : data_obj

# Rule to build all files generated by this target.
src/data/CMakeFiles/data_obj.dir/build: data_obj

.PHONY : src/data/CMakeFiles/data_obj.dir/build

src/data/CMakeFiles/data_obj.dir/clean:
	cd /root/bytedance-database-project/build/src/data && $(CMAKE_COMMAND) -P CMakeFiles/data_obj.dir/cmake_clean.cmake
.PHONY : src/data/CMakeFiles/data_obj.dir/clean

src/data/CMakeFiles/data_obj.dir/depend:
	cd /root/bytedance-database-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/bytedance-database-project /root/bytedance-database-project/src/data /root/bytedance-database-project/build /root/bytedance-database-project/build/src/data /root/bytedance-database-project/build/src/data/CMakeFiles/data_obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/data/CMakeFiles/data_obj.dir/depend

