/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

//////////////////////// ---------------HNLRXYTB------------////////////////////////////
TEST_CASE("Good snowman code") {
    //Test regular snowman with diff hats.
    CHECK(nospaces(snowman(11114411)) == nospaces("       \n_===_ \n (.,.) \n( : )\n( : )")); //Straw
    CHECK(nospaces(snowman(21114411)) == nospaces("  ___  \n ..... \n (.,.) \n( : )\n( : )")); //Mexican
    //CHECK(nospaces(snowman(31114411)) == nospaces("  _  \n /_\ \n(.,.)\n( : )\n( : )")); //Fez
    CHECK(nospaces(snowman(41114411)) == nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )")); //Russian
    //Test regular snowman with diff noses.
    CHECK(nospaces(snowman(12114411)) == nospaces("       \n _===_ \n(...)\n( : )\n( : )")); //Dot
    CHECK(nospaces(snowman(13114411)) == nospaces("       \n _===_ \n(._.)\n( : )\n( : )")); //Line
    CHECK(nospaces(snowman(14114411)) == nospaces("       \n _===_ \n(. .)\n( : )\n( : )")); //None
    //Test different bodies.
    CHECK(nospaces(snowman(11114412)) == nospaces("       \n _===_ \n(.,.)\n( : )\n(" ")")); //Feet
    CHECK(nospaces(snowman(11114413)) == nospaces("       \n _===_ \n(.,.)\n( : )\n(___)")); //Flat
    CHECK(nospaces(snowman(11114414)) == nospaces("       \n _===_ \n(.,.)\n( : )\n(   )")); //None
    //Test different torsos
    CHECK(nospaces(snowman(11114422)) == nospaces("       \n _===_ \n(.,.)\n(] [)\n(" ")")); //Vest
    CHECK(nospaces(snowman(11114433)) == nospaces("       \n _===_ \n(.,.)\n(> <)\n(___)")); //Inward Arms
    CHECK(nospaces(snowman(11114444)) == nospaces("       \n _===_ \n(.,.)\n(   )\n(   )")); //None
    //Test different eyes.
    CHECK(nospaces(snowman(11224422)) == nospaces("       \n _===_ \n(o,o)\n(] [)\n(" ")")); //Vest
    CHECK(nospaces(snowman(11334433)) == nospaces("       \n _===_ \n(0,0)\n(> <)\n(___)")); //Inward Arms
    CHECK(nospaces(snowman(11444444)) == nospaces("       \n _===_ \n(-,-)\n(   )\n(   )")); //None
    //Test different arms.
    CHECK(nospaces(snowman(11221122)) == nospaces("       \n _===_ \n(o,o)\n<(] [)>\n(" ")")); //Vest
    CHECK(nospaces(snowman(11334233)) == nospaces("       \n _===_ \n(0,0)/\n(> <)\n(___)")); //Inward Arms
    CHECK(nospaces(snowman(11444344)) == nospaces("       \n _===_ \n(-,-)\n(   )\\n(   )")); //None
}

TEST_CASE("Bad snowman code") {
    CHECK(nospaces(snowman(41114413)) != nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )")); //Russian
    CHECK(nospaces(snowman(31114411)) != nospaces(" ___ \n(_*_)\n(. .)\n( : )\n( : )")); //Russian
    CHECK(nospaces(snowman(41114421)) != nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( _ )")); //Russian
    CHECK(nospaces(snowman(21114411)) != nospaces(" ___ \n(_._)\n(.,.)\n( : )\n( : )")); //Russian

}
TEST_CASE("Bad input"){
    
    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(24266630));
    CHECK_THROWS(snowman(424242444)); //long input.
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(444));

}

/* Add more test cases here */
