# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/wpc/projects/robot/Feature_Capture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wpc/projects/robot/Feature_Capture

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/item.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/item.cpp.o: src/item.cpp
src/CMakeFiles/src.dir/item.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/item.cpp.o"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/item.cpp.o -MF CMakeFiles/src.dir/item.cpp.o.d -o CMakeFiles/src.dir/item.cpp.o -c /home/wpc/projects/robot/Feature_Capture/src/item.cpp

src/CMakeFiles/src.dir/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/item.cpp.i"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpc/projects/robot/Feature_Capture/src/item.cpp > CMakeFiles/src.dir/item.cpp.i

src/CMakeFiles/src.dir/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/item.cpp.s"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpc/projects/robot/Feature_Capture/src/item.cpp -o CMakeFiles/src.dir/item.cpp.s

src/CMakeFiles/src.dir/motor.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/motor.cpp.o: src/motor.cpp
src/CMakeFiles/src.dir/motor.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/motor.cpp.o"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/motor.cpp.o -MF CMakeFiles/src.dir/motor.cpp.o.d -o CMakeFiles/src.dir/motor.cpp.o -c /home/wpc/projects/robot/Feature_Capture/src/motor.cpp

src/CMakeFiles/src.dir/motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/motor.cpp.i"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpc/projects/robot/Feature_Capture/src/motor.cpp > CMakeFiles/src.dir/motor.cpp.i

src/CMakeFiles/src.dir/motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/motor.cpp.s"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpc/projects/robot/Feature_Capture/src/motor.cpp -o CMakeFiles/src.dir/motor.cpp.s

src/CMakeFiles/src.dir/retriving.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/retriving.cpp.o: src/retriving.cpp
src/CMakeFiles/src.dir/retriving.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/retriving.cpp.o"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/retriving.cpp.o -MF CMakeFiles/src.dir/retriving.cpp.o.d -o CMakeFiles/src.dir/retriving.cpp.o -c /home/wpc/projects/robot/Feature_Capture/src/retriving.cpp

src/CMakeFiles/src.dir/retriving.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/retriving.cpp.i"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpc/projects/robot/Feature_Capture/src/retriving.cpp > CMakeFiles/src.dir/retriving.cpp.i

src/CMakeFiles/src.dir/retriving.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/retriving.cpp.s"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpc/projects/robot/Feature_Capture/src/retriving.cpp -o CMakeFiles/src.dir/retriving.cpp.s

src/CMakeFiles/src.dir/robot_control.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/robot_control.cpp.o: src/robot_control.cpp
src/CMakeFiles/src.dir/robot_control.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/robot_control.cpp.o"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/robot_control.cpp.o -MF CMakeFiles/src.dir/robot_control.cpp.o.d -o CMakeFiles/src.dir/robot_control.cpp.o -c /home/wpc/projects/robot/Feature_Capture/src/robot_control.cpp

src/CMakeFiles/src.dir/robot_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/robot_control.cpp.i"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpc/projects/robot/Feature_Capture/src/robot_control.cpp > CMakeFiles/src.dir/robot_control.cpp.i

src/CMakeFiles/src.dir/robot_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/robot_control.cpp.s"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpc/projects/robot/Feature_Capture/src/robot_control.cpp -o CMakeFiles/src.dir/robot_control.cpp.s

src/CMakeFiles/src.dir/surf.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/surf.cpp.o: src/surf.cpp
src/CMakeFiles/src.dir/surf.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/surf.cpp.o"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/surf.cpp.o -MF CMakeFiles/src.dir/surf.cpp.o.d -o CMakeFiles/src.dir/surf.cpp.o -c /home/wpc/projects/robot/Feature_Capture/src/surf.cpp

src/CMakeFiles/src.dir/surf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/surf.cpp.i"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpc/projects/robot/Feature_Capture/src/surf.cpp > CMakeFiles/src.dir/surf.cpp.i

src/CMakeFiles/src.dir/surf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/surf.cpp.s"
	cd /home/wpc/projects/robot/Feature_Capture/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpc/projects/robot/Feature_Capture/src/surf.cpp -o CMakeFiles/src.dir/surf.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/item.cpp.o" \
"CMakeFiles/src.dir/motor.cpp.o" \
"CMakeFiles/src.dir/retriving.cpp.o" \
"CMakeFiles/src.dir/robot_control.cpp.o" \
"CMakeFiles/src.dir/surf.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/item.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/motor.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/retriving.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/robot_control.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/surf.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wpc/projects/robot/Feature_Capture/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libsrc.a"
	cd /home/wpc/projects/robot/Feature_Capture/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /home/wpc/projects/robot/Feature_Capture/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /home/wpc/projects/robot/Feature_Capture/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /home/wpc/projects/robot/Feature_Capture && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wpc/projects/robot/Feature_Capture /home/wpc/projects/robot/Feature_Capture/src /home/wpc/projects/robot/Feature_Capture /home/wpc/projects/robot/Feature_Capture/src /home/wpc/projects/robot/Feature_Capture/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

