# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Apps\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Apps\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\COMP-2510\Practice\DynamicMemoryPractice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DynamicMemoryPractice.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DynamicMemoryPractice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DynamicMemoryPractice.dir/flags.make

CMakeFiles/DynamicMemoryPractice.dir/main.c.obj: CMakeFiles/DynamicMemoryPractice.dir/flags.make
CMakeFiles/DynamicMemoryPractice.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DynamicMemoryPractice.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DynamicMemoryPractice.dir\main.c.obj -c D:\COMP-2510\Practice\DynamicMemoryPractice\main.c

CMakeFiles/DynamicMemoryPractice.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DynamicMemoryPractice.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\COMP-2510\Practice\DynamicMemoryPractice\main.c > CMakeFiles\DynamicMemoryPractice.dir\main.c.i

CMakeFiles/DynamicMemoryPractice.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DynamicMemoryPractice.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\COMP-2510\Practice\DynamicMemoryPractice\main.c -o CMakeFiles\DynamicMemoryPractice.dir\main.c.s

# Object files for target DynamicMemoryPractice
DynamicMemoryPractice_OBJECTS = \
"CMakeFiles/DynamicMemoryPractice.dir/main.c.obj"

# External object files for target DynamicMemoryPractice
DynamicMemoryPractice_EXTERNAL_OBJECTS =

DynamicMemoryPractice.exe: CMakeFiles/DynamicMemoryPractice.dir/main.c.obj
DynamicMemoryPractice.exe: CMakeFiles/DynamicMemoryPractice.dir/build.make
DynamicMemoryPractice.exe: CMakeFiles/DynamicMemoryPractice.dir/linklibs.rsp
DynamicMemoryPractice.exe: CMakeFiles/DynamicMemoryPractice.dir/objects1.rsp
DynamicMemoryPractice.exe: CMakeFiles/DynamicMemoryPractice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DynamicMemoryPractice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DynamicMemoryPractice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DynamicMemoryPractice.dir/build: DynamicMemoryPractice.exe
.PHONY : CMakeFiles/DynamicMemoryPractice.dir/build

CMakeFiles/DynamicMemoryPractice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DynamicMemoryPractice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DynamicMemoryPractice.dir/clean

CMakeFiles/DynamicMemoryPractice.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\COMP-2510\Practice\DynamicMemoryPractice D:\COMP-2510\Practice\DynamicMemoryPractice D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug D:\COMP-2510\Practice\DynamicMemoryPractice\cmake-build-debug\CMakeFiles\DynamicMemoryPractice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DynamicMemoryPractice.dir/depend

