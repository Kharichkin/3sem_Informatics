# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/my_vector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_vector.dir/flags.make

CMakeFiles/my_vector.dir/main.cpp.obj: CMakeFiles/my_vector.dir/flags.make
CMakeFiles/my_vector.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_vector.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\my_vector.dir\main.cpp.obj -c "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\main.cpp"

CMakeFiles/my_vector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_vector.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\main.cpp" > CMakeFiles\my_vector.dir\main.cpp.i

CMakeFiles/my_vector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_vector.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\main.cpp" -o CMakeFiles\my_vector.dir\main.cpp.s

# Object files for target my_vector
my_vector_OBJECTS = \
"CMakeFiles/my_vector.dir/main.cpp.obj"

# External object files for target my_vector
my_vector_EXTERNAL_OBJECTS =

my_vector.exe: CMakeFiles/my_vector.dir/main.cpp.obj
my_vector.exe: CMakeFiles/my_vector.dir/build.make
my_vector.exe: CMakeFiles/my_vector.dir/linklibs.rsp
my_vector.exe: CMakeFiles/my_vector.dir/objects1.rsp
my_vector.exe: CMakeFiles/my_vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_vector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my_vector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_vector.dir/build: my_vector.exe

.PHONY : CMakeFiles/my_vector.dir/build

CMakeFiles/my_vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my_vector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my_vector.dir/clean

CMakeFiles/my_vector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector" "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector" "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug" "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug" "D:\Me\MIPT\(3 sem) Informatics\3sem_Informatics\5_lesson\my_vector\cmake-build-debug\CMakeFiles\my_vector.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/my_vector.dir/depend

