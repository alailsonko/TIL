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
CMAKE_SOURCE_DIR = /home/alailson/Documents/github/TIL/qt/getting-started

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/getting-started.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/getting-started.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getting-started.dir/flags.make

getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/qml.qrc
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: CMakeFiles/getting-started_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/Page1Form.ui.qml
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/Page2Form.ui.qml
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/HomeForm.ui.qml
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/qtquickcontrols2.conf
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /home/alailson/Documents/github/TIL/qt/getting-started/main.qml
getting-started_autogen/EWIEGA46WW/qrc_qml.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for qml.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles/getting-started_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json Debug

CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o: CMakeFiles/getting-started.dir/flags.make
CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o: getting-started_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o -c /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/mocs_compilation.cpp

CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/mocs_compilation.cpp > CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.i

CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/mocs_compilation.cpp -o CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.s

CMakeFiles/getting-started.dir/main.cpp.o: CMakeFiles/getting-started.dir/flags.make
CMakeFiles/getting-started.dir/main.cpp.o: /home/alailson/Documents/github/TIL/qt/getting-started/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/getting-started.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getting-started.dir/main.cpp.o -c /home/alailson/Documents/github/TIL/qt/getting-started/main.cpp

CMakeFiles/getting-started.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getting-started.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alailson/Documents/github/TIL/qt/getting-started/main.cpp > CMakeFiles/getting-started.dir/main.cpp.i

CMakeFiles/getting-started.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getting-started.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alailson/Documents/github/TIL/qt/getting-started/main.cpp -o CMakeFiles/getting-started.dir/main.cpp.s

CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o: CMakeFiles/getting-started.dir/flags.make
CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o: getting-started_autogen/EWIEGA46WW/qrc_qml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o -c /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp

CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp > CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.i

CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp -o CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.s

# Object files for target getting-started
getting__started_OBJECTS = \
"CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/getting-started.dir/main.cpp.o" \
"CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o"

# External object files for target getting-started
getting__started_EXTERNAL_OBJECTS =

getting-started: CMakeFiles/getting-started.dir/getting-started_autogen/mocs_compilation.cpp.o
getting-started: CMakeFiles/getting-started.dir/main.cpp.o
getting-started: CMakeFiles/getting-started.dir/getting-started_autogen/EWIEGA46WW/qrc_qml.cpp.o
getting-started: CMakeFiles/getting-started.dir/build.make
getting-started: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.12.8
getting-started: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.12.8
getting-started: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
getting-started: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
getting-started: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
getting-started: CMakeFiles/getting-started.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable getting-started"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getting-started.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getting-started.dir/build: getting-started

.PHONY : CMakeFiles/getting-started.dir/build

CMakeFiles/getting-started.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getting-started.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getting-started.dir/clean

CMakeFiles/getting-started.dir/depend: getting-started_autogen/EWIEGA46WW/qrc_qml.cpp
	cd /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alailson/Documents/github/TIL/qt/getting-started /home/alailson/Documents/github/TIL/qt/getting-started /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug /home/alailson/Documents/github/TIL/qt/build-getting-started-Desktop-Debug/CMakeFiles/getting-started.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getting-started.dir/depend

