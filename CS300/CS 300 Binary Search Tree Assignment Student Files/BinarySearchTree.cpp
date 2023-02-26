//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Yona Voss-Andreae
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid
{
  string bidId; // unique identifier
  string title;
  string fund;
  double amount;
  Bid()
  {
    amount = 0.0;
  }
};

// Internal structure for tree node
struct Node
{
  Bid bid;
  Node *left;
  Node *right;

  // default constructor
  Node()
  {
    left = nullptr;
    right = nullptr;
  }

  // initialize with a bid
  Node(Bid aBid) : Node()
  {
    bid = aBid;
  }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree
{

private:
  Node *root;

  void addNode(Node *node, Bid bid);
  void inOrder(Node *node);
  void postOrder(Node *node);
  void preOrder(Node *node);
  Node *removeNode(Node *node, string bidId);

public:
  BinarySearchTree();
  virtual ~BinarySearchTree();
  void InOrder();
  void Insert(Bid bid);
  void Remove(string bidId);
  Bid Search(string bidId);
  void PostOrder();
  void PreOrder();
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree()
{
  // root is equal to nullptr
  root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree()
{
  // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder()
{
  // call inOrder fuction and pass root
  inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder()
{
  // postOrder root
  postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder()
{
  // preOrder root
  preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid)
{
  // if root equal to nullptr
  // root is equal to new node bid
  // else
  // add Node root and bid
  if (root == nullptr) {
    root = new Node(bid);
  } else {
    addNode(root, bid);
  }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId)
{
  // remove node root bidID
  removeNode(root, bidId);
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId)
{
  // set current node equal to root
  Node *current = root;

  // keep looping downwards until bottom reached or matching bidId found
  while (current != nullptr) {
    // if match found, return current bid
    if (current->bid.bidId == bidId) {
      return current->bid;
    // if bid is smaller than current node then traverse left
    } else if (current->bid.bidId > bidId) {
      current = current->left;
    // else larger so traverse right
    } else {
      current = current->right;
    }
  }

  Bid bid;
  return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node *node, Bid bid)
{
  // if node is larger then add to left
  if (node->bid.bidId > bid.bidId) {
    // if no left node
    if (node->left == nullptr) {
      // this node becomes left
      node->left = new Node(bid);
    // else recurse down the left node
    } else {
      addNode(node->left, bid);
    }
  // else
  } else {
    // if no right node
    if (node->right == nullptr) {
      // this node becomes right
      node->right = new Node(bid);
    // else
    } else {
      // recurse down the right node
      addNode(node->right, bid);
    }
  }
}

/**
 * Remove a bid from some node (recursive)
 *
 * @param node Current node in tree
 * @param bidId Bid to be removed
 */
Node *BinarySearchTree::removeNode(Node *node, string bidId) {
  // if node is nullptr
  if (node == nullptr) {
    return nullptr;
  // else if bidId is smaller than node bidId
  } else if (bidId < node->bid.bidId) {
    // recurse down left node
    node->left = removeNode(node->left, bidId);
  // else if bidId is larger than node bidId
  } else if (bidId > node->bid.bidId) {
    // recurse down right node
    node->right = removeNode(node->right, bidId);
  // else
  } else {
    // if no left node
    if (node->left == nullptr) {
      // set temp node to right node
      Node *temp = node->right;
      // delete node
      delete node;
      // return temp
      return temp;
    // else if no right node
    } else if (node->right == nullptr) {
      // set temp node to left node
      Node *temp = node->left;
      // delete node
      delete node;
      // return temp
      return temp;
    // else
    } else {
      // set temp node to right node
      Node *temp = node->right;
      // while temp left node is not nullptr
      while (temp->left != nullptr) {
        // set temp to temp left node
        temp = temp->left;
      }
      // set node bid to temp bid
      node->bid = temp->bid;
      // recurse down right node
      node->right = removeNode(node->right, temp->bid.bidId);
    }
  }
  // return node
  return node;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid)
{
  cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
       << bid.fund << endl;
  return;
}

void BinarySearchTree::inOrder(Node *node)
{
  if (node != nullptr) {
    inOrder(node->left);
    displayBid(node->bid);
    inOrder(node->right);
  }
}

void BinarySearchTree::postOrder(Node *node)
{
  if (node != nullptr) {
    postOrder(node->left);
    postOrder(node->right);
    displayBid(node->bid);
  }
}

void BinarySearchTree::preOrder(Node *node)
{
  if (node != nullptr) {
    displayBid(node->bid);
    preOrder(node->left);
    preOrder(node->right);
  }
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree *bst)
{
  cout << "Loading CSV file " << csvPath << endl;

  // initialize the CSV Parser using the given path
  csv::Parser file = csv::Parser(csvPath);

  // read and display header row - optional
  vector<string> header = file.getHeader();
  for (auto const &c : header)
  {
    cout << c << " | ";
  }
  cout << "" << endl;

  try
  {
    // loop to read rows of a CSV file
    for (unsigned int i = 0; i < file.rowCount(); i++)
    {

      // Create a data structure and add to the collection of bids
      Bid bid;
      bid.bidId = file[i][1];
      bid.title = file[i][0];
      bid.fund = file[i][8];
      bid.amount = strToDouble(file[i][4], '$');

      // cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

      // push this bid to the end
      bst->Insert(bid);
    }
  }
  catch (csv::Error &e)
  {
    std::cerr << e.what() << std::endl;
  }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch)
{
  str.erase(remove(str.begin(), str.end(), ch), str.end());
  return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char *argv[])
{

  // process command line arguments
  string csvPath, bidKey;
  switch (argc)
  {
  case 2:
    csvPath = argv[1];
    bidKey = "98109";
    break;
  case 3:
    csvPath = argv[1];
    bidKey = argv[2];
    break;
  default:
    csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
    bidKey = "98109";
  }

  // Define a timer variable
  clock_t ticks;

  // Define a binary search tree to hold all bids
  BinarySearchTree *bst;
  bst = new BinarySearchTree();
  Bid bid;

  int choice = 0;
  while (choice != 9)
  {
    cout << "Menu:" << endl;
    cout << "  1. Load Bids" << endl;
    cout << "  2. Display All Bids" << endl;
    cout << "  3. Find Bid" << endl;
    cout << "  4. Remove Bid" << endl;
    cout << "  9. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {

    case 1:

      // Initialize a timer variable before loading bids
      ticks = clock();

      // Complete the method call to load the bids
      loadBids(csvPath, bst);

      // cout << bst->Size() << " bids read" << endl;

      // Calculate elapsed time and display result
      ticks = clock() - ticks; // current clock ticks minus starting clock ticks
      cout << "time: " << ticks << " clock ticks" << endl;
      cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
      break;

    case 2:
      bst->PreOrder();
      break;

    case 3:
      cout << "Enter bid ID to find: ";
      cin >> bidKey;
      ticks = clock();

      bid = bst->Search(bidKey);

      ticks = clock() - ticks; // current clock ticks minus starting clock ticks

      if (!bid.bidId.empty())
      {
        displayBid(bid);
      }
      else
      {
        cout << "Bid Id " << bidKey << " not found." << endl;
      }

      cout << "time: " << ticks << " clock ticks" << endl;
      cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

      break;

    case 4:
      cout << "Enter bid ID to remove: ";
      cin >> bidKey;
      bst->Remove(bidKey);
      break;
    }
  }

  cout << "Good bye." << endl;

  return 0;
}
