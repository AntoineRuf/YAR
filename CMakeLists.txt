cmake_minimum_required(VERSION 3.16)

project(YAR VERSION 1.0.0 LANGUAGES CXX)

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED)


file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp
)

# file(GLOB_RECURSE UI_FILES
# 	${CMAKE_SOURCE_DIR}/src/*.ui
# )
add_executable(YAR ${HEADER_FILES} 
				${SOURCE_FILES} 
				# ${UI_FILES}
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
add_library(STB_IMAGE "thirdparty/image_stb.cpp")
add_library(GLAD "thirdparty/glad.c")

set(LIBS glfw3 opengl32 STB_IMAGE GLAD)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLFW3 REQUIRED)


include_directories("${CMAKE_SOURCE_DIR}/src",
					"${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(YAR ${LIBS})
target_link_libraries(YAR Qt6::Widgets)