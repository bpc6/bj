set(CARDGAME_SOURCES
        card.cpp
        deck.cpp
        player.cpp
#        blackjack.cpp
        bj_player.cpp
        bj_careful_player.cpp
        bj_careful_player.h
)

add_library(Cardgame ${CARDGAME_SOURCES})

add_executable(bj main.cpp)

target_link_libraries(bj Cardgame)
