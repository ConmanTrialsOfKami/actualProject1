#include <catch2/catch_test_macros.hpp>
#include <iostream>

// uncomment and replace the following with your own headers
#include "AVL.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[flag]"){
	// instantiate any class members that you need to test here
	int one = 1;

	// anything that evaluates to false in a REQUIRE block will result in a failing test
	REQUIRE(one == 1); // fix me!

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(true); // also fix me!
}

TEST_CASE("Test 2", "[flag]"){
	// you can also use "sections" to share setup code between tests, for example:
	int one = 1;

	SECTION("num is 2") {
		int num = one + 1;
		REQUIRE(num == 2);
	};

	SECTION("num is 3") {
		int num = one + 2;
		REQUIRE(num == 3);
	};

	// each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
}

// 1st test case, 5 incorrect commands
TEST_CASE("5 incorrect commands") {

	// First command, invalid name, digits on it
	REQUIRE(validName("A11y") == false);

	// Invalid ID, not having 8 digits
	REQUIRE(eightDigitId("1234") == false);

	// empty Name
	REQUIRE(validName("") == false);

	// name with symbol
	REQUIRE(validName("Al!ice") == false);

	//duplicate ID
	Node* n = nullptr;
	bool success= false;

	n = insertAVL(n, "Alice", 12345678, success);
	REQUIRE(success == true);
	n = insertAVL(n, "Dupe", 12345678, success);
	REQUIRE(success == false);

}

// Test case 2, 3 edge cases
TEST_CASE("3 edge cases") {
	Node* n = nullptr;
	bool success = false;

	//removing node that doesnt exist
	n = deleteNode(n, 12345678, success);
	REQUIRE(success == false);

	// remove from empty tree
	n = removeInOrder(n, 0, success);
	REQUIRE(success == false);

	// search empty tree
	string o;
	REQUIRE(searchId(n, 12345678, o) == false);
}
