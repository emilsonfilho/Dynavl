#ifndef SET_HPP
#define SET_HPP

#include <algorithm>
#include <iostream>

#include "Exceptions/EmptySetException.hpp"
#include "Messages/EmptySetMessage.hpp"
#include "Node/Node.hpp"

using namespace std;

/**
 * @class Set
 * @brief A mathematical set
 *
 * This class is an AVL Tree that does not allow the insertion of duplicate
 * numbers
 */
class Set {
private:
  Node *root;
  int _size;

  /**
   * @brief Calculates the balancing factor
   *
   * Calculates the balancing factor of a specified node
   *
   * @param node The node to be considered
   * @return int The node's balancing factor
   */
  int getBalance(Node *node) const;

  /**
   * @brief Calculates the height of a node
   *
   * Calculates the height of a node in a tree in cases where the height cannot
   * be given by the attribute
   *
   * @param node The node whose height will be calculated
   * @return int The node real height
   */
  int calcHeight(Node *node) const;

  /**
   * @brief Performs a left rotation on the given node.
   *
   * This operation is typically used to maintain the balance of a binary search
   * tree, such as an AVL tree, when the right subtree of a node becomes taller
   * than the left
   *
   * @param p Pointer to the root of the subtree to rotate
   * @return Node* Pointer to the new root of the rotated subtree
   */
  Node *leftRotation(Node *p);

  /**
   * @brief Performs a right rotation on the given node.
   *
   * This operation is typically used to maintain the balance of a binary search
   * tree, such as an AVL tree, when the left subtree of a node becomes taller
   * than the right
   *
   * @param p Pointer to the root of the subtree to rotate
   * @return Node* Pointer to the new root of the rotated subtree
   */
  Node *rightRotation(Node *p);

  /**
   * @brief Rebalances the subtree rooted at the given node after an insertion
   *
   * Depending on the balance factor and the inserted key's position,
   * this function performs the necessary single or double rotations to maintain
   * the AVL tree properties
   *
   * @param node Pointer to the root of the subtree to rebalance.
   * @param key The key that was recently inserted, used to determine the
   * rotation type
   * @return Node* Pointer to the new root of the rebalanced subtree.
   */
  Node *rebalance(Node *node, int key);

  /**
   * @brief Insert a new value
   *
   * Inserts a new value into a binary tree, balancing the tree in the process
   * recursively.
   *
   * @param key The value to be inserted
   * @param node The root node of the (sub)tree where the value is to be
   * inserted
   * @return Node* The root of the new tree generated after the insertion
   */
  Node *insert(int key, Node *node);

  /**
   * @brief Gets the tree height value
   *
   * Calculates the size of the specified node
   *
   * @param node The node to know the height of
   * @return int The height of the tree
   */
  int getHeight(Node *node) const;

  /**
   * @brief Recursively clears (deletes) all nodes in the subtree rooted at the
   * given node.
   *
   * This function performs a post-order traversal, deleting the left and right
   * children of each node before deleting the node itself, ensuring that memory
   * is properly freed.
   *
   * @param node Pointer to the root of the subtree to delete.
   */
  void clear(Node *node);

  /**
   * @brief Checks if the tree contains a node with the given key.
   *
   * This function recursively traverses the tree to search for a node with the
   * specified key, returning `true` if found and `false` otherwise.
   *
   * @param key The key to search for in the tree.
   * @param node Pointer to the current node in the tree.
   * @return bool `true` if the key is found, `false` otherwise.
   */
  bool contains(int key, Node *node) const;

  /**
   * @brief Displays the tree structure in a formatted way.
   *
   * This function recursively prints the tree sideways, showing the hierarchy
   * of nodes using special characters to represent branches and levels.
   * It helps visualize the structure of the tree for debugging or educational
   * purposes.
   *
   * @param node Pointer to the current node being displayed.
   * @param inheritance A string tracking the path taken to reach the current
   * node, used to format the output.
   */
  void show(Node *node, string inheritance) const;

  /**
   * @brief Recursively removes a node with the specified key from a subtree and
   * rebalances it.
   *
   * This function searches the subtree rooted at `node` for the given key. If
   * found, it removes the node—replacing it with its only child or in-order
   * successor as needed— then applies AVL rebalancing to maintain tree balance.
   * If `node` is null, it returns nullptr.
   *
   * @param key The key of the node to remove.
   * @param node Pointer to the root of the subtree to delete from
   * @return Node* Pointer to the new root of the subtree after deletion and
   * rebalancing, or nullptr if the subtree is empty.
   */
  Node *erase(int key, Node *node);

  /**
   * @brief Finds the node with the minimum key in the subtree.
   *
   * This function traverses the left children of the subtree rooted at `node`
   * until it reaches the leftmost node, which contains the smallest key.
   *
   * @param node Pointer to the root of the subtree to search.
   * @return Node* Pointer to the node with the minimum key, or `nullptr` if the
   * subtree is empty.
   */
  Node *getMin(Node *node) const;

public:
  /**
   * @brief Set builder
   *
   * Creates a set with no elements
   */
  Set();

  /**
   * @brief Inserts a new value
   *
   * Updates the root node with the new tree generated after the recursive
   * insertion
   *
   * @param key The value to be inserted
   */
  void insert(int key);

  /**
   * @brief Returns the number of nodes in the tree.
   *
   * This function returns the size of the tree, which is the number of elements
   * currently stored in the set.
   *
   * @return int The number of nodes in the tree.
   */
  int size() const;

  /**
   * @brief Checks if the tree contains a node with the given key, starting from
   * the root.
   *
   * This function is a wrapper around the recursive `contains` function,
   * starting the search from the root node of the tree.
   *
   * @param key The key to search for in the tree.
   * @return bool `true` if the key is found, `false` otherwise.
   */
  bool contains(int key) const;

  /**
   * @brief Returns the height of the tree, starting from the root.
   *
   * This function is a wrapper around the recursive `getHeight` function,
   * calculating the height of the tree by starting from the root node.
   *
   * @return int The height of the tree.
   */
  int getHeight() const;

  /**
   * @brief Swaps the contents of two sets.
   *
   * This function swaps the root nodes and sizes of the current set and the
   * given set `t`. After the swap, both sets will contain the data and size of
   * the other.
   *
   * @param t The set to swap with the current set.
   */
  void swap(Set &t);

  /**
   * @brief Checks if the tree is empty.
   *
   * This function returns `true` if the tree has no nodes (i.e., size is zero
   * and root is null), and `false` otherwise.
   *
   * @return bool `true` if the tree is empty, `false` otherwise.
   */
  bool empty() const;

  /**
   * @brief Destructor for the Set class.
   *
   * This destructor ensures that all dynamically allocated nodes in the tree
   * are properly deleted by calling the `clear` function.
   */
  ~Set();

  /**
   * @brief Displays the entire tree structure starting from the root.
   *
   * This function is a wrapper that initiates the recursive `show` function,
   * printing a formatted view of the entire tree for visualization.
   */
  void show() const;

  /**
   * @brief Clears all nodes from the tree.
   *
   * This function deletes all nodes in the tree by calling the recursive
   * `clear` function starting from the root, and then sets the root to
   * `nullptr`.
   */
  void clear();

  /**
   * @brief Removes a key from the set.
   *
   * This function removes the node with the specified key from the tree,
   * updates the root if necessary, and decrements the size of the set.
   *
   * @param key The key to be removed from the set.
   */
  void erase(int key);

  /**
   * @brief Returns the smallest key in the set.
   *
   * This function finds the leftmost node in the tree (which holds the minimum
   * key) and returns its key.
   *
   * @return int The minimum key in the set.
   */
  int minimum() const;
#ifdef TEST_MODE
  // Retorna a raiz da árvore (para fins de teste)
  Node *getRoot() const;

  // Retorna o fator de balanceamento de um nó (para testes)
  int getBalanceForTest(Node *node) const;
#endif
};

#endif
