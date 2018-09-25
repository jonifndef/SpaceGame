cmake_minimum_required(VERSION 3.1.0)
project (SpaceGame)

#get_target_property(QtCore_location Qt5::Core LOCATION)
#get_target_property(QtWidgets_location Qt5::Widgets LOCATION)
#get_target_property(QtGui_location Qt5::Gui LOCATION)

#set(CMAKE_PREFIX_PATH "C:\\Qt\\5.10.0\\mingw53_32\\")

# find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
#find_package(Qt5OpenGL REQUIRED)
#find_package(Qt5Multimedia REQUIRED)
#find_package(Qt5WebKitWidgets REQUIRED)
#find_package(Qt5Xml REQUIRED)



set (CMAKE_AUTOMOC ON)
#set (CMAKE_AUTORCC ON)
#set (CMAKE_AUTOUIC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON) #?

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

#include_directory(src/)

#if(WIN32)
#  set(CMAKE_WIN32_EXECUTABLE ON) #needed?

#endif(WIN32)

# Source files
set (SOURCES
	src/blasterbolt.cpp
	src/enemyone.cpp
	src/game.cpp
	src/gameobject.cpp
	src/level.cpp
	src/main.cpp
	src/mainmenu.cpp
	src/ship.cpp
	src/spacegame.cpp
	src/timing.cpp)

# Header files
SET (HEADERS
        src/defines.h
        src/blasterbolt.h
        src/enemyone.h
        src/game.h
        src/gameobject.h
        src/level.h
        src/mainmenu.h
        src/ship.h
        src/spacegame.h
        src/timing.h)

# Qt UI
SET (UI spacegame.ui)

# Libraries
set(LIBS 
	Qt5::Widgets # Which ones are needed?
	Qt5::Core
        Qt5::Gui)

add_executable(SpaceGame ${SOURCES} ${HEADERS} ${UI})

# Link to libraries
target_link_libraries(SpaceGame ${LIBS})
