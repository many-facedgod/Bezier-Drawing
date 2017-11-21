cmake_minimum_required(VERSION 3.8)
project(Bezier-Drawing)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES *.h *.cpp SurfaceOfRevolution.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(Bezier-Drawing ${SOURCE_FILES} Mesh.h SurfaceOfRevolution.h)
add_executable(main.cpp ${SOURCE_FILES} SurfaceOfRevolution.h)
target_link_libraries (Bezier-Drawing ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_glu_LIBRARY})
target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_glu_LIBRARY})