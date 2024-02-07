add_library(Cardgame card.cpp deck.cpp)

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
