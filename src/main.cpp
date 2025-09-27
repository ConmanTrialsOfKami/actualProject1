#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "AVL.h"
using namespace std;

int main(){
    int numCommands;
    cin >> numCommands; //reads the amount of commands.
    cin.ignore(); //skip the newline

    Node* n = nullptr;
    for (int i = 0; i < numCommands; i++) {
        string line;
        getline(cin, line); //read one command

        // check if insert

        if (line.rfind("insert ", 0) == 0) {
            string name;
            // if no name is extracted, print unsuccessful
            if (extractQuote(line, name) == false || validName(name) == false) {
                cout << "unsuccessful\n";
                continue;
            }
            // find the last space before the ID
            int pos = (int)line.find_last_of(' ');

            if (pos == -1) { //if it isnt found, print unsuccessful
                cout << "unsuccessful\n";
                continue;
            }


            // id if previous if statement isnt triggered
            string idStr = line.substr(pos + 1);

            // if the id isn't 8 digits and valid, prints unsuccessful
            if (eightDigitId(idStr) == false) {
                cout << "unsuccessful\n";
                continue;
            }

            int id = stoi(idStr);
            bool success = false; //tracks if insertion worked

            // inserts node
            n = insertAVL(n, name, id, success);

            // if bool variable turns true, we print successful, else unsuccessful
            if (success == true) {
                cout << "successful\n";
            }
            else {
                cout << "unsuccessful\n";
            }

        }

        // now after insert we check remove
        else if (line.rfind("remove ", 0) == 0) {
            string idStr = line.substr(7);

            // same as before, if it isnt 8 digit valid id, prints unsuccessful
            if (eightDigitId(idStr) == false) {
                cout << "unsuccessful\n";
                continue;
            }

            // get id to int
            int id = stoi(idStr);
            bool success = false;
            // delete node
            n = deleteNode(n, id, success);

            // print according to whether bool variable indicates success or not
            if (success == true) {
                cout << "successful\n";
            }
            else {
                cout << "unsuccessful\n";
            }
        }


        // now after remove, we tackle removeInorder, removing the kth node in inorder
        else if (line.rfind("removeInorder ", 0) == 0) {
            string kStr = line.substr(13);
            int k = stoi(kStr); // convert to int

            bool success = false;
            n = removeInOrder(n, k, success); //remove in order traversal


            // same thing we've done for insert, remove, etc. print if successful, else print unsuccessful if unsuccessful
            if (success == true) {
                cout << "successful\n";
            }
            else {
                cout << "unsuccessful\n";
            }

        }

        // now we move on to search
        else if (line.rfind("search ", 0) == 0) {

            // check if line contains quotation marks
            if (line.find('"') != string::npos) {
                string name;

                // checks if name can be extracted
                if (extractQuote(line, name) == false) {

                    // no valid thing is found, so we print unsuccessful
                    cout << "unsuccessful\n";
                    continue;
                }

                // collect all IDS, using preorder traversal

                vector<int> ids;
                preorderCollectID(n, name, ids);

                // If no ids found, print unsucessful, else print IDS

                if (ids.empty()){
                    cout << "unsuccessful\n";
                }

                else {
                    for (int i = 0; i < (int)ids.size(); i++) {
                        cout << ids[i] << "\n"; //for loop to print ids
                    }
                }

            }

            // this else is for if there are no quotes in the statement
            else {
                //grabs the string after "search "
                string idStr = line.substr(7);

                // makes sure ID is good
                if (eightDigitId(idStr) == false) {
                    cout << "unsuccessful\n";
                    continue;
                }

                // makes id int
                int id = stoi(idStr);
                string foundName;

                // attempts to find ID
                if (searchId(n, id, foundName) == true) {
                    cout << foundName << "\n"; // if it finds the name, print
                }
                else {
                    cout << "unsuccessful\n";
                }
            }
        }
        // print names in inorder traversal
        else if (line == "printInorder") {
            vector<string> names;
            inOrderNames(n, names);
            printNamesByComma(names);
        }
        // print names in preorder traversal
        else if (line == "printPreorder") {
            vector<string> names;
            preOrderNames(n, names);
            printNamesByComma(names);
        }
        //print names in postorder
        else if (line == "printPostorder") {
            vector<string> names;
            postOrderNames(n, names);
            printNamesByComma(names);
        }
        // print level count
        else if (line == "printLevelCount") {
            cout << lvlCount(n) << "\n";
        }

        else {
            cout << "unsuccessful\n";
        }

    }
    return 0;

}
