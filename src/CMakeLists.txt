set(CARDGAME_SOURCES
        card.cpp
        deck.cpp
        game.cpp
        player.cpp
        bj_cli_player.cpp
)

add_library(Cardgame ${CARDGAME_SOURCES})

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
