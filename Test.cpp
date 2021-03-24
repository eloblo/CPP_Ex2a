#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("Tests") {
    ariel::Board board;
    CHECK(board.read(1,2, Direction::Horizontal, 3) == string("___"));
    board.post(1, 2, Direction::Horizontal, "123");
    CHECK(board.read(1,2, Direction::Horizontal, 3) == string("123"));
    CHECK(board.read(0,3, Direction::Vertical, 3) == string("_2_"));
    board.post(1, 2, Direction::Horizontal, "asd");
    CHECK(board.read(1,2, Direction::Horizontal, 3) == string("asd"));
    CHECK(board.read(0,2, Direction::Vertical, 3) == string("_a_"));
    CHECK(board.read(0,3, Direction::Vertical, 3) == string("_s_"));
    CHECK(board.read(0,4, Direction::Vertical, 3) == string("_d_"));
    board.post(4, 6, Direction::Vertical, "abc");
    CHECK(board.read(4,6, Direction::Vertical, 3) == string("abc"));
    CHECK(board.read(4,5, Direction::Horizontal, 3) == string("_a_"));
    CHECK(board.read(5,5, Direction::Horizontal, 3) == string("_b_"));
    CHECK(board.read(6,5, Direction::Horizontal, 3) == string("_c_"));
    board.post(5, 5, Direction::Horizontal, "xyz");
    CHECK(board.read(5,5, Direction::Horizontal, 3) == string("xyz"));
    CHECK(board.read(4,6, Direction::Vertical, 3) == string("ayc"));
    CHECK(board.read(5,6, Direction::Vertical, 1) == string("y"));
    CHECK(board.read(5,6, Direction::Horizontal, 1) == string("y"));
}

TEST_CASE("empty message") {
    ariel::Board board;
    CHECK_THROWS(board.read(0,0, Direction::Horizontal, 0));
    CHECK_THROWS(board.post(0,0, Direction::Horizontal, ""));
}

TEST_CASE("out of default bound"){
    ariel::Board board;
    CHECK(board.read(1000,1000, Direction::Horizontal, 3) == string("___"));
    board.post(20, 20, Direction::Horizontal, "new bounds");
    CHECK(board.read(20,20, Direction::Horizontal, 10) == string("new bounds"));
    board.post(20, 25, Direction::Horizontal, "!!!!!!!!!!");
    CHECK(board.read(20,20, Direction::Horizontal, 15) == string("new b!!!!!!!!!!"));
    board.post(17, 15, Direction::Vertical, "new bounds");
    CHECK(board.read(17,15, Direction::Vertical, 10) == string("new bounds"));
    board.post(22, 15, Direction::Vertical, "!!!!!!!!!!");
    CHECK(board.read(17,15, Direction::Vertical, 15) == string("new b!!!!!!!!!!"));
}
