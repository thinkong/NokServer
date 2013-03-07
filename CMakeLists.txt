CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

PROJECT( NokServer )
get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
#find boost
find_package(Boost COMPONENTS system REQUIRED)
if (Boost_FOUND)
	MESSAGE("Boost Found" )
	MESSAGE(${Boost_INCLUDE_DIR})
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	#ADD_DEFINITIONS("-DHAS_BOOST")
ENDIF()

ADD_EXECUTABLE(server main.cpp)
TARGET_LINK_LIBRARIES( server ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY})