cmake_minimum_required(VERSION 3.16)

project(YAR VERSION 1.0.0 LANGUAGES CXX)

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Qt6 COMPONENTS Widgets REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLFW3 REQUIRED)

add_library(STB_IMAGE "thirdparty/image_stb.cpp")
add_library(GLAD "thirdparty/glad.c")

set(LIBS glfw3 opengl32 STB_IMAGE GLAD)

include_directories("${CMAKE_SOURCE_DIR}/src",
					"${CMAKE_SOURCE_DIR}/include"
)

add_executable(YAR
	src/main.cpp
)

target_link_libraries(YAR ${LIBS})
target_link_libraries(YAR Qt6::Widgets)