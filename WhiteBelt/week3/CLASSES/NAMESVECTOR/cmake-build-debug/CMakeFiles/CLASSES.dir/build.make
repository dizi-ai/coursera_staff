# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\COURSERA\week3\CLASSES

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\COURSERA\week3\CLASSES\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\CLASSES.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\CLASSES.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CLASSES.dir\flags.make

CMakeFiles\CLASSES.dir\main.cpp.obj: CMakeFiles\CLASSES.dir\flags.make
CMakeFiles\CLASSES.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\week3\CLASSES\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLASSES.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CLASSES.dir\main.cpp.obj /FdCMakeFiles\CLASSES.dir\ /FS -c C:\COURSERA\week3\CLASSES\main.cpp
<<

CMakeFiles\CLASSES.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLASSES.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\CLASSES.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\week3\CLASSES\main.cpp
<<

CMakeFiles\CLASSES.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLASSES.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CLASSES.dir\main.cpp.s /c C:\COURSERA\week3\CLASSES\main.cpp
<<

# Object files for target CLASSES
CLASSES_OBJECTS = \
"CMakeFiles\CLASSES.dir\main.cpp.obj"

# External object files for target CLASSES
CLASSES_EXTERNAL_OBJECTS =

CLASSES.exe: CMakeFiles\CLASSES.dir\main.cpp.obj
CLASSES.exe: CMakeFiles\CLASSES.dir\build.make
CLASSES.exe: CMakeFiles\CLASSES.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\COURSERA\week3\CLASSES\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CLASSES.exe"
	"C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CLASSES.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\CLASSES.dir\objects1.rsp @<<
 /out:CLASSES.exe /implib:CLASSES.lib /pdb:C:\COURSERA\week3\CLASSES\cmake-build-debug\CLASSES.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CLASSES.dir\build: CLASSES.exe

.PHONY : CMakeFiles\CLASSES.dir\build

CMakeFiles\CLASSES.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CLASSES.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CLASSES.dir\clean

CMakeFiles\CLASSES.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\COURSERA\week3\CLASSES C:\COURSERA\week3\CLASSES C:\COURSERA\week3\CLASSES\cmake-build-debug C:\COURSERA\week3\CLASSES\cmake-build-debug C:\COURSERA\week3\CLASSES\cmake-build-debug\CMakeFiles\CLASSES.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\CLASSES.dir\depend

