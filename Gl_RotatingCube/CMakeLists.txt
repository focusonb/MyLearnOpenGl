cmake_minimum_required(VERSION 3.14.0)

project(GLRotatingCube)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

add_definitions(-DPLATFORM_WINDOWS=1)

include_directories(${CMAKE_SOURCE_DIR}/CallBack)
include_directories(${CMAKE_SOURCE_DIR}/cube)
include_directories(${CMAKE_SOURCE_DIR}/GlfwConfigure)
include_directories(${CMAKE_SOURCE_DIR}/image)
include_directories(${CMAKE_SOURCE_DIR}/shader)
include_directories(${CMAKE_SOURCE_DIR}/ShaderReader)
include_directories(${CMAKE_SOURCE_DIR}/TextureManager)
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/glfw3.3.4/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/glm)
include_directories(${CMAKE_SOURCE_DIR}/ThirdParty/Glad/include)

file(GLOB_RECURSE SRC_DIR_LIST "CallBack/*.cpp" "GlfwConfigure/*.cpp" "image/*.cpp"  "shader/*.cpp" "ShaderReader/*.cpp" "TextureManager/*.cpp" "main.cpp" "ThirdParty/Glad/glad.c" "cube/*.cpp")


link_directories(${CMAKE_SOURCE_DIR}/ThirdParty/lib/libglfw)
add_executable(GLRotatingCube ${SRC_DIR_LIST})





