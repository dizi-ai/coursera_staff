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
CMAKE_SOURCE_DIR = C:\COURSERA\YellowBelt\week3\busstopdec

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\busstopdec.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\busstopdec.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\busstopdec.dir\flags.make

CMakeFiles\busstopdec.dir\main.cpp.obj: CMakeFiles\busstopdec.dir\flags.make
CMakeFiles\busstopdec.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/busstopdec.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\busstopdec.dir\main.cpp.obj /FdCMakeFiles\busstopdec.dir\ /FS -c C:\COURSERA\YellowBelt\week3\busstopdec\main.cpp
<<

CMakeFiles\busstopdec.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/busstopdec.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\busstopdec.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\YellowBelt\week3\busstopdec\main.cpp
<<

CMakeFiles\busstopdec.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/busstopdec.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\busstopdec.dir\main.cpp.s /c C:\COURSERA\YellowBelt\week3\busstopdec\main.cpp
<<

CMakeFiles\busstopdec.dir\query.cpp.obj: CMakeFiles\busstopdec.dir\flags.make
CMakeFiles\busstopdec.dir\query.cpp.obj: ..\query.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/busstopdec.dir/query.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\busstopdec.dir\query.cpp.obj /FdCMakeFiles\busstopdec.dir\ /FS -c C:\COURSERA\YellowBelt\week3\busstopdec\query.cpp
<<

CMakeFiles\busstopdec.dir\query.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/busstopdec.dir/query.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\busstopdec.dir\query.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\YellowBelt\week3\busstopdec\query.cpp
<<

CMakeFiles\busstopdec.dir\query.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/busstopdec.dir/query.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\busstopdec.dir\query.cpp.s /c C:\COURSERA\YellowBelt\week3\busstopdec\query.cpp
<<

CMakeFiles\busstopdec.dir\responses.cpp.obj: CMakeFiles\busstopdec.dir\flags.make
CMakeFiles\busstopdec.dir\responses.cpp.obj: ..\responses.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/busstopdec.dir/responses.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\busstopdec.dir\responses.cpp.obj /FdCMakeFiles\busstopdec.dir\ /FS -c C:\COURSERA\YellowBelt\week3\busstopdec\responses.cpp
<<

CMakeFiles\busstopdec.dir\responses.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/busstopdec.dir/responses.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\busstopdec.dir\responses.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\YellowBelt\week3\busstopdec\responses.cpp
<<

CMakeFiles\busstopdec.dir\responses.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/busstopdec.dir/responses.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\busstopdec.dir\responses.cpp.s /c C:\COURSERA\YellowBelt\week3\busstopdec\responses.cpp
<<

CMakeFiles\busstopdec.dir\bus_manager.cpp.obj: CMakeFiles\busstopdec.dir\flags.make
CMakeFiles\busstopdec.dir\bus_manager.cpp.obj: ..\bus_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/busstopdec.dir/bus_manager.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\busstopdec.dir\bus_manager.cpp.obj /FdCMakeFiles\busstopdec.dir\ /FS -c C:\COURSERA\YellowBelt\week3\busstopdec\bus_manager.cpp
<<

CMakeFiles\busstopdec.dir\bus_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/busstopdec.dir/bus_manager.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\busstopdec.dir\bus_manager.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\YellowBelt\week3\busstopdec\bus_manager.cpp
<<

CMakeFiles\busstopdec.dir\bus_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/busstopdec.dir/bus_manager.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\busstopdec.dir\bus_manager.cpp.s /c C:\COURSERA\YellowBelt\week3\busstopdec\bus_manager.cpp
<<

# Object files for target busstopdec
busstopdec_OBJECTS = \
"CMakeFiles\busstopdec.dir\main.cpp.obj" \
"CMakeFiles\busstopdec.dir\query.cpp.obj" \
"CMakeFiles\busstopdec.dir\responses.cpp.obj" \
"CMakeFiles\busstopdec.dir\bus_manager.cpp.obj"

# External object files for target busstopdec
busstopdec_EXTERNAL_OBJECTS =

busstopdec.exe: CMakeFiles\busstopdec.dir\main.cpp.obj
busstopdec.exe: CMakeFiles\busstopdec.dir\query.cpp.obj
busstopdec.exe: CMakeFiles\busstopdec.dir\responses.cpp.obj
busstopdec.exe: CMakeFiles\busstopdec.dir\bus_manager.cpp.obj
busstopdec.exe: CMakeFiles\busstopdec.dir\build.make
busstopdec.exe: CMakeFiles\busstopdec.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable busstopdec.exe"
	"C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\busstopdec.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\busstopdec.dir\objects1.rsp @<<
 /out:busstopdec.exe /implib:busstopdec.lib /pdb:C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\busstopdec.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\busstopdec.dir\build: busstopdec.exe

.PHONY : CMakeFiles\busstopdec.dir\build

CMakeFiles\busstopdec.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\busstopdec.dir\cmake_clean.cmake
.PHONY : CMakeFiles\busstopdec.dir\clean

CMakeFiles\busstopdec.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\COURSERA\YellowBelt\week3\busstopdec C:\COURSERA\YellowBelt\week3\busstopdec C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug C:\COURSERA\YellowBelt\week3\busstopdec\cmake-build-debug\CMakeFiles\busstopdec.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\busstopdec.dir\depend
