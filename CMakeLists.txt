CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(finances)

ADD_EXECUTABLE(finances main.cpp)

FIND_PACKAGE(Boost REQUIRED)
IF (Boost_FOUND)
    MESSAGE ("[library] Boost found.")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ELSE (Boost_FOUND)
    MESSAGE ("[library] Boost not found.")
ENDIF (Boost_FOUND)

#SET (Mysqlclient_DIR /usr/lib/)
#FIND_PACKAGE (Mysqlclient REQUIRED)
#find_library(mysqlclient)
#IF (Mysqlclient_FOUND)
#    MESSAGE ("[library] MySQL client found.")
#    INCLUDE_DIRECTORIES(${MYSQLCLIENT_INCLUDE_DIRS})
#    TARGET_LINK_LIBRARIES (helloworld ${MYSQLCLIENT_LIBRARIES})
#ELSE (Mysqlclient_FOUND)
#    MESSAGE ("[library] MySQL client not found.")
#ENDIF (Mysqlclient_FOUND)

TARGET_LINK_LIBRARIES(finances mysqlclient)