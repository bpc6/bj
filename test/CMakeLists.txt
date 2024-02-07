include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
FetchContent_MakeAvailable(googletest)

include_directories (${BLACKJACK_SOURCE_DIR}/src)
add_executable (Tests main_test.cpp deck_test.cpp)
target_link_libraries (Tests Cardgame gtest_main)
add_test(NAME main_test COMMAND Tests)
