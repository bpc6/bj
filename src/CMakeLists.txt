add_library(Cardgame deck.cpp)

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
