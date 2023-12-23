cmake_minimum_required(VERSION 3.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

project(Antuco VERSION 1.0.0)

# find vulkan
find_package(Vulkan REQUIRED)

# find all project source files
file (GLOB_RECURSE SOURCE_FILES inc/*.cpp)
file (GLOB_RECURSE HEADER_FILES inc/*.hpp)

# create library from project source files and header files
add_library(project_lib ${SOURCE_FILES} ${HEADER_FILES})

# include directories for project source files
target_include_directories(project_lib PUBLIC "${Vulkan_INCLUDE_DIRS}")

# compile exe
add_executable(${PROJECT_NAME} main.cpp)

# include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc ${Vulkan_INCLUDE_DIRS})

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC ${Vulkan_LIBRARIES} project_lib)

# move compile_commands.json (required for intellisense) to project source dir
configure_file(${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}/compile_commands.json COPYONLY)
