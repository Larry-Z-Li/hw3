#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
//    if(argc < 2) {
//        cout << "Please provide an input file" << endl;
//        return 1;
//    }
//
//    // -----------------------------------------------
//    // Feel free to update any code below this point
//    // -----------------------------------------------
//    Node* head = readList(argv[1]);
//    cout << "Original list: ";
//    print(head);

    // Test out your linked list code

    Node* node1 = new Node(4, NULL);
    Node* node2 = new Node (3, node1);
    Node* node3 = new Node(2, node2);
    Node* node4 = new Node(1, node3);
    Node* node5 = new Node(23232, node4);
    Node* node6 = new Node(5, node5);
    Node* node7 = new Node(1, node6);
    Node* node8 = new Node(10, node7);


    Node* node10 = new Node(1, NULL);
    Node* node11 = new Node(1, node5);

    llpivot(node8, node10, node11, 2);
    print(node8);
    print(node10);
    print(node11);

    return 0;

}
