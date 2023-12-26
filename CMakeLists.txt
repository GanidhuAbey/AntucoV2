cmake_minimum_required(VERSION 3.5)

project(Antuco VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# find vulkan
find_package(Vulkan REQUIRED)

# find all project source files
file (GLOB_RECURSE SOURCE_FILES inc/*.cpp)
file (GLOB_RECURSE HEADER_FILES inc/*.hpp)

# add fmt to project
add_subdirectory(${PROJECT_SOURCE_DIR}/external/fmt)
# add glfw to project
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)

# create library from project source files and header files
add_library(project_lib ${SOURCE_FILES} ${HEADER_FILES})

# include directories for project source files
target_include_directories(project_lib PUBLIC "${Vulkan_INCLUDE_DIRS}" ${PROJECT_SOURCE_DIR}/inc)

# link external libraries for project source files
target_link_libraries(project_lib PUBLIC ${Vulkan_LIBRARIES} 
                                          fmt::fmt 
                                          glfw)

# compile exe
add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES} ${HEADER_FILES})

# include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc ${Vulkan_INCLUDE_DIRS})

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC ${Vulkan_LIBRARIES} 
                                              project_lib
                                              fmt::fmt
                                              glfw)

# move compile_commands.json (required for intellisense) to project source dir
if (EXISTS ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
  configure_file(${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}/compile_commands.json COPYONLY)
else()
  message(WARNING "Failed to move compile_commands.json to root directly, try re-running the cmake, or move it manually to the root directory")
endif()
