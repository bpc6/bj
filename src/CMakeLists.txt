set(CARDGAME_SOURCES
        card.cpp
        deck.cpp
        player.cpp
        bj_game.cpp
        bj_player.cpp
        game.cpp
)

add_library(Cardgame ${CARDGAME_SOURCES})

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
