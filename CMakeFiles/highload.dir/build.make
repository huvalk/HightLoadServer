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
CMAKE_COMMAND = /home/huvalk/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/huvalk/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huvalk/CLionProjects/TECHNOPARK/highload

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huvalk/CLionProjects/TECHNOPARK/highload

# Include any dependencies generated for this target.
include CMakeFiles/highload.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/highload.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/highload.dir/flags.make

CMakeFiles/highload.dir/main.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/highload.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/main.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/main.cpp

CMakeFiles/highload.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/main.cpp > CMakeFiles/highload.dir/main.cpp.i

CMakeFiles/highload.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/main.cpp -o CMakeFiles/highload.dir/main.cpp.s

CMakeFiles/highload.dir/src/ConfigParser.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/ConfigParser.cpp.o: src/ConfigParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/highload.dir/src/ConfigParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/ConfigParser.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ConfigParser.cpp

CMakeFiles/highload.dir/src/ConfigParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/ConfigParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ConfigParser.cpp > CMakeFiles/highload.dir/src/ConfigParser.cpp.i

CMakeFiles/highload.dir/src/ConfigParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/ConfigParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ConfigParser.cpp -o CMakeFiles/highload.dir/src/ConfigParser.cpp.s

CMakeFiles/highload.dir/src/Config.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/Config.cpp.o: src/Config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/highload.dir/src/Config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/Config.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Config.cpp

CMakeFiles/highload.dir/src/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/Config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Config.cpp > CMakeFiles/highload.dir/src/Config.cpp.i

CMakeFiles/highload.dir/src/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/Config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Config.cpp -o CMakeFiles/highload.dir/src/Config.cpp.s

CMakeFiles/highload.dir/src/Server.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/Server.cpp.o: src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/highload.dir/src/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/Server.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Server.cpp

CMakeFiles/highload.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Server.cpp > CMakeFiles/highload.dir/src/Server.cpp.i

CMakeFiles/highload.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Server.cpp -o CMakeFiles/highload.dir/src/Server.cpp.s

CMakeFiles/highload.dir/src/Client.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/Client.cpp.o: src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/highload.dir/src/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/Client.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Client.cpp

CMakeFiles/highload.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Client.cpp > CMakeFiles/highload.dir/src/Client.cpp.i

CMakeFiles/highload.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Client.cpp -o CMakeFiles/highload.dir/src/Client.cpp.s

CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o: src/ThreadRoutine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ThreadRoutine.cpp

CMakeFiles/highload.dir/src/ThreadRoutine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/ThreadRoutine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ThreadRoutine.cpp > CMakeFiles/highload.dir/src/ThreadRoutine.cpp.i

CMakeFiles/highload.dir/src/ThreadRoutine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/ThreadRoutine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/ThreadRoutine.cpp -o CMakeFiles/highload.dir/src/ThreadRoutine.cpp.s

CMakeFiles/highload.dir/src/Response.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/Response.cpp.o: src/Response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/highload.dir/src/Response.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/Response.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Response.cpp

CMakeFiles/highload.dir/src/Response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/Response.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Response.cpp > CMakeFiles/highload.dir/src/Response.cpp.i

CMakeFiles/highload.dir/src/Response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/Response.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Response.cpp -o CMakeFiles/highload.dir/src/Response.cpp.s

CMakeFiles/highload.dir/src/Request.cpp.o: CMakeFiles/highload.dir/flags.make
CMakeFiles/highload.dir/src/Request.cpp.o: src/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/highload.dir/src/Request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/highload.dir/src/Request.cpp.o -c /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Request.cpp

CMakeFiles/highload.dir/src/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/highload.dir/src/Request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Request.cpp > CMakeFiles/highload.dir/src/Request.cpp.i

CMakeFiles/highload.dir/src/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/highload.dir/src/Request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/CLionProjects/TECHNOPARK/highload/src/Request.cpp -o CMakeFiles/highload.dir/src/Request.cpp.s

# Object files for target highload
highload_OBJECTS = \
"CMakeFiles/highload.dir/main.cpp.o" \
"CMakeFiles/highload.dir/src/ConfigParser.cpp.o" \
"CMakeFiles/highload.dir/src/Config.cpp.o" \
"CMakeFiles/highload.dir/src/Server.cpp.o" \
"CMakeFiles/highload.dir/src/Client.cpp.o" \
"CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o" \
"CMakeFiles/highload.dir/src/Response.cpp.o" \
"CMakeFiles/highload.dir/src/Request.cpp.o"

# External object files for target highload
highload_EXTERNAL_OBJECTS =

highload: CMakeFiles/highload.dir/main.cpp.o
highload: CMakeFiles/highload.dir/src/ConfigParser.cpp.o
highload: CMakeFiles/highload.dir/src/Config.cpp.o
highload: CMakeFiles/highload.dir/src/Server.cpp.o
highload: CMakeFiles/highload.dir/src/Client.cpp.o
highload: CMakeFiles/highload.dir/src/ThreadRoutine.cpp.o
highload: CMakeFiles/highload.dir/src/Response.cpp.o
highload: CMakeFiles/highload.dir/src/Request.cpp.o
highload: CMakeFiles/highload.dir/build.make
highload: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
highload: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
highload: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
highload: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
highload: CMakeFiles/highload.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable highload"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/highload.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/highload.dir/build: highload

.PHONY : CMakeFiles/highload.dir/build

CMakeFiles/highload.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/highload.dir/cmake_clean.cmake
.PHONY : CMakeFiles/highload.dir/clean

CMakeFiles/highload.dir/depend:
	cd /home/huvalk/CLionProjects/TECHNOPARK/highload && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huvalk/CLionProjects/TECHNOPARK/highload /home/huvalk/CLionProjects/TECHNOPARK/highload /home/huvalk/CLionProjects/TECHNOPARK/highload /home/huvalk/CLionProjects/TECHNOPARK/highload /home/huvalk/CLionProjects/TECHNOPARK/highload/CMakeFiles/highload.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/highload.dir/depend

