# wall flag turns on warnings and -g turns on debuggin
set( CMAKE_C_FLAGES "-Wall -g")

file( GLOB SRCS *.cpp *.h)

# Added to executer game-challangers
add_executable( game-challangers $(SRCS) )