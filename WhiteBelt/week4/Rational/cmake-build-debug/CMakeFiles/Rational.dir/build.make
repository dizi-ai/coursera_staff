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
CMAKE_SOURCE_DIR = C:\COURSERA\week4\Rational

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\COURSERA\week4\Rational\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Rational.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Rational.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Rational.dir\flags.make

CMakeFiles\Rational.dir\main.cpp.obj: CMakeFiles\Rational.dir\flags.make
CMakeFiles\Rational.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\week4\Rational\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rational.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Rational.dir\main.cpp.obj /FdCMakeFiles\Rational.dir\ /FS -c C:\COURSERA\week4\Rational\main.cpp
<<

CMakeFiles\Rational.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rational.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\Rational.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\week4\Rational\main.cpp
<<

CMakeFiles\Rational.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rational.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Rational.dir\main.cpp.s /c C:\COURSERA\week4\Rational\main.cpp
<<

# Object files for target Rational
Rational_OBJECTS = \
"CMakeFiles\Rational.dir\main.cpp.obj"

# External object files for target Rational
Rational_EXTERNAL_OBJECTS =

Rational.exe: CMakeFiles\Rational.dir\main.cpp.obj
Rational.exe: CMakeFiles\Rational.dir\build.make
Rational.exe: CMakeFiles\Rational.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\COURSERA\week4\Rational\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Rational.exe"
	"C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Rational.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Rational.dir\objects1.rsp @<<
 /out:Rational.exe /implib:Rational.lib /pdb:C:\COURSERA\week4\Rational\cmake-build-debug\Rational.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Rational.dir\build: Rational.exe

.PHONY : CMakeFiles\Rational.dir\build

CMakeFiles\Rational.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Rational.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Rational.dir\clean

CMakeFiles\Rational.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\COURSERA\week4\Rational C:\COURSERA\week4\Rational C:\COURSERA\week4\Rational\cmake-build-debug C:\COURSERA\week4\Rational\cmake-build-debug C:\COURSERA\week4\Rational\cmake-build-debug\CMakeFiles\Rational.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Rational.dir\depend

