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
CMAKE_SOURCE_DIR = C:\COURSERA\RedBelt\week1\uniqid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\uniqid.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\uniqid.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\uniqid.dir\flags.make

CMakeFiles\uniqid.dir\main.cpp.obj: CMakeFiles\uniqid.dir\flags.make
CMakeFiles\uniqid.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uniqid.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\uniqid.dir\main.cpp.obj /FdCMakeFiles\uniqid.dir\ /FS -c C:\COURSERA\RedBelt\week1\uniqid\main.cpp
<<

CMakeFiles\uniqid.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uniqid.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\uniqid.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\COURSERA\RedBelt\week1\uniqid\main.cpp
<<

CMakeFiles\uniqid.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uniqid.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\uniqid.dir\main.cpp.s /c C:\COURSERA\RedBelt\week1\uniqid\main.cpp
<<

# Object files for target uniqid
uniqid_OBJECTS = \
"CMakeFiles\uniqid.dir\main.cpp.obj"

# External object files for target uniqid
uniqid_EXTERNAL_OBJECTS =

uniqid.exe: CMakeFiles\uniqid.dir\main.cpp.obj
uniqid.exe: CMakeFiles\uniqid.dir\build.make
uniqid.exe: CMakeFiles\uniqid.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uniqid.exe"
	"C:\Program Files (x86)\CLION\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\uniqid.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\uniqid.dir\objects1.rsp @<<
 /out:uniqid.exe /implib:uniqid.lib /pdb:C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug\uniqid.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\uniqid.dir\build: uniqid.exe

.PHONY : CMakeFiles\uniqid.dir\build

CMakeFiles\uniqid.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\uniqid.dir\cmake_clean.cmake
.PHONY : CMakeFiles\uniqid.dir\clean

CMakeFiles\uniqid.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\COURSERA\RedBelt\week1\uniqid C:\COURSERA\RedBelt\week1\uniqid C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug C:\COURSERA\RedBelt\week1\uniqid\cmake-build-debug\CMakeFiles\uniqid.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\uniqid.dir\depend

