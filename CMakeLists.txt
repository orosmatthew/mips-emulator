# specify cmake version
cmake_minimum_required(VERSION 3.0)

# create project
project(mips-emulator)

IF (WIN32)
	set(BUILD_SHARED_LIBS OFF)
	set(CMAKE_EXE_LINKER_FLAGS "-static")
ENDIF()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# gather src files
file(GLOB_RECURSE src src/*.c src/*.cpp)

source_group("src" FILES ${src})

# executable
add_executable(mips-emulator
		# source files
		${src}
)

# set up include directories
target_include_directories(mips-emulator PUBLIC
		# source files
		src
)
