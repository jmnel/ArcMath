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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jacques/repos/jmnel/ArcMath/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jacques/repos/jmnel/ArcMath/build

# Include any dependencies generated for this target.
include arcmath/CMakeFiles/arcmath.dir/depend.make

# Include the progress variables for this target.
include arcmath/CMakeFiles/arcmath.dir/progress.make

# Include the compile flags for this target's objects.
include arcmath/CMakeFiles/arcmath.dir/flags.make

arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Core/CoreMath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Core/CoreMath.cpp

arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Core/CoreMath.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Core/CoreMath.cpp > CMakeFiles/arcmath.dir/Core/CoreMath.cpp.i

arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Core/CoreMath.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Core/CoreMath.cpp -o CMakeFiles/arcmath.dir/Core/CoreMath.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Arc2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Arc2d.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Arc2d.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Arc2d.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Circle2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Circle2d.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Circle2d.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Circle2d.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Line.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Line.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Line.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Plane.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Plane.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Plane.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Ray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Ray.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Ray.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Ray.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.s

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Sphere.cpp

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Sphere.cpp > CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.i

arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arcmath/Geometry/Shapes/Sphere.cpp -o CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.s

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/Result.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/Result.cpp

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/Result.cpp > CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.i

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/Result.cpp -o CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.s

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o: arcmath/CMakeFiles/arcmath.dir/flags.make
arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o: /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/StringUtility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && ccache /usr/lib/llvm/8/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o -c /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/StringUtility.cpp

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.i"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/StringUtility.cpp > CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.i

arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.s"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && /usr/lib/llvm/8/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacques/repos/jmnel/ArcMath/src/arclib/Utility/StringUtility.cpp -o CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.s

# Object files for target arcmath
arcmath_OBJECTS = \
"CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o" \
"CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o" \
"CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o" \
"CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o"

# External object files for target arcmath
arcmath_EXTERNAL_OBJECTS =

lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Core/CoreMath.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Arc2d.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Circle2d.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Line.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Plane.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Ray.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/Geometry/Shapes/Sphere.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/Result.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/__/arclib/Utility/StringUtility.cpp.o
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/build.make
lib/libarcmath.a: arcmath/CMakeFiles/arcmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jacques/repos/jmnel/ArcMath/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library ../lib/libarcmath.a"
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && $(CMAKE_COMMAND) -P CMakeFiles/arcmath.dir/cmake_clean_target.cmake
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arcmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
arcmath/CMakeFiles/arcmath.dir/build: lib/libarcmath.a

.PHONY : arcmath/CMakeFiles/arcmath.dir/build

arcmath/CMakeFiles/arcmath.dir/clean:
	cd /home/jacques/repos/jmnel/ArcMath/build/arcmath && $(CMAKE_COMMAND) -P CMakeFiles/arcmath.dir/cmake_clean.cmake
.PHONY : arcmath/CMakeFiles/arcmath.dir/clean

arcmath/CMakeFiles/arcmath.dir/depend:
	cd /home/jacques/repos/jmnel/ArcMath/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jacques/repos/jmnel/ArcMath/src /home/jacques/repos/jmnel/ArcMath/src/arcmath /home/jacques/repos/jmnel/ArcMath/build /home/jacques/repos/jmnel/ArcMath/build/arcmath /home/jacques/repos/jmnel/ArcMath/build/arcmath/CMakeFiles/arcmath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : arcmath/CMakeFiles/arcmath.dir/depend
