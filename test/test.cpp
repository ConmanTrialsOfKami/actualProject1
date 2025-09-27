// Ricardo Bezi, 95461037

/*
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



// 1st test case, 5 incorrect commands
TEST_CASE("Test1: 5 incorrect commands") {

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
TEST_CASE("Test2: 3 edge cases") {
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

// Test case 3: rotations
TEST_CASE ("Test3: Rotations"){
	bool success = false;

	// left rotation
	{
		Node* n = nullptr;
		n = insertAVL(n, "A", 10, success);
		n = insertAVL(n, "B", 20, success);
		n = insertAVL(n, "C", 30, success);

		REQUIRE(n != nullptr);
		REQUIRE(n->id == 20);
	}

	// right rotation
	{
		Node* n = nullptr;
		n = insertAVL(n, "C", 30, success);
		n = insertAVL(n, "B", 20, success);
		n = insertAVL(n, "A", 10, success);

		REQUIRE(n != nullptr);
		REQUIRE(n->id == 20);
	}

	// left right rotation
	{
		Node* n = nullptr;
		n = insertAVL(n, "C", 30, success);
		n = insertAVL(n, "A", 10, success);
		n = insertAVL(n, "B", 20, success);

		REQUIRE(n != nullptr);
		REQUIRE(n->id == 20);
	}

	// right left rotation
	{
		Node* n = nullptr;
		n = insertAVL(n, "A", 10, success);
		n = insertAVL(n, "C", 30, success);
		n = insertAVL(n, "B", 20, success);

		REQUIRE(n != nullptr);
		REQUIRE(n->id == 20);
	}
}

// Test case 4: Deletion cases
TEST_CASE("Test4: Deletions") {
	Node* n = nullptr;
	bool success = false;

	n = insertAVL(n, "A", 20, success);
	REQUIRE(success == true);
	n = insertAVL(n, "B", 10, success);
	REQUIRE(success == true);
	n = insertAVL(n, "C", 30, success);
	REQUIRE(success == true);
	n = insertAVL(n, "D", 25, success);
	REQUIRE(success == true);
	n = insertAVL(n, "E", 5, success);
	REQUIRE(success == true);

	// leaf
	n = deleteNode(n, 5, success);
	REQUIRE(success == true);

	// one child
	n = deleteNode(n, 30, success);
	REQUIRE(success == true);

	// two children
	n = insertAVL(n, "F", 22, success);
	REQUIRE(success == true);
	n = insertAVL(n, "G", 28, success);
	REQUIRE(success == true);
	n = deleteNode(n, 20, success);
	REQUIRE(success == true);

}

// Testcase 5: 100 inserts, remove 10, checkinorder size 90

TEST_CASE("Test5: 100 inserts") {
	Node* n = nullptr;
	bool success = false;

	// 100 inserts
	for (int i = 1; i <= 100; i++) {
		n = insertAVL(n, "N", i, success);
		REQUIRE(success == true);
	}

	// remove 10 deterministic
	int num[] = {3,7,10,15,21,34,55,68,89,100};
	for (int i = 0; i < 10; i++) {
		n = deleteNode(n, num[i], success);
		REQUIRE(success == true);
	}

	// inorder should have 90 ids and be sorted
	vector<int> ids;
	inOrderIDS(n, ids);
	REQUIRE((int)ids.size() == 90);
	for (int i = 1; i < (int)ids.size(); i++) {
		REQUIRE(ids[i-1] < ids[i]);
	}
}

*/