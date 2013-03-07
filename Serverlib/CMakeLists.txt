# CmakeLists.txt in Hello dir
# Adds a library called Hello (libHello.a under Linux) from the source file hello.cc

file(GLOB_RECURSE SERVERLIB_SRCS
		RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
# SOURCE_GROUP(hello_group FILES $(HELLOLIB_SRCS))

find_package(Boost COMPONENTS system REQUIRED)
if (Boost_FOUND)
	MESSAGE("Boost Found" )
	MESSAGE(${Boost_INCLUDE_DIR})
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

ADD_LIBRARY( Serverlib  ${SERVERLIB_SRCS})