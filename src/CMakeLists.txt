add_library(Cardgame
        card.cpp
        deck.cpp
        player.cpp
        blackjack.cpp
        bj_player.cpp
)

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
