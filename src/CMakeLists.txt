<<<<<<< HEAD
set(BINARY ${CMAKE_PROJECT_NAME})

# add_executable(ExampleProject main.cpp file1.cpp file1.h)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp) #simplification

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

=======
set(BINARY ${CMAKE_PROJECT_NAME})

# add_executable(ExampleProject main.cpp file1.cpp file1.h)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp) #simplification

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

>>>>>>> 31344a19717938d0a7b13d079f50d8f153da8a85
add_library(${BINARY}_lib STATIC ${SOURCES} Array.h)