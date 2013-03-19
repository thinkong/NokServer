# CmakeLists.txt in Hello dir
# Adds a library called Hello (libHello.a under Linux) from the source file hello.cc

SET(CMAKE_CXX_FLAGS	"-std=c++11 ${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

file(GLOB_RECURSE SERVERLIB_SRCS
		RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
# SOURCE_GROUP(hello_group FILES $(HELLOLIB_SRCS))

set (MSVC_RUNTIME static)
#set (Boost_USE_STATIC_RUNTIME TRUE)
set (Boost_USE_STATIC_LIBS TRUE)
set (Boost_USE_STATIC_RUNTIME TRUE)
ADD_DEFINITIONS( -DBOOST_ALL_NO_LIB )
find_package(Boost COMPONENTS system atomic REQUIRED)
if (Boost_FOUND)
	#MESSAGE("Boost Found" )
	MESSAGE(${Boost_INCLUDE_DIR})
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

if(MSVC)
#We statically link to reduce dependancies
foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
    if(${flag_var} MATCHES "/MDd")
        string(REGEX REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MDd")
endforeach(flag_var)
endif(MSVC)

ADD_LIBRARY( Serverlib  ${SERVERLIB_SRCS})