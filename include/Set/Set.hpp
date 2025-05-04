#ifndef SET_HPP
#define SET_HPP

#include <algorithm>
#include <iostream>
#include <vector>

#include "Exceptions/EmptySetException.hpp"
#include "Exceptions/NoPredecessorException.hpp"
#include "Exceptions/NoSuccessorException.hpp"
#include "Exceptions/ValueNotFoundException.hpp"
#include "Messages/EmptySetMessage.hpp"
#include "Messages/NoPredecessorMessage.hpp"
#include "Messages/NoSuccessorMessage.hpp"
#include "Messages/ValueNotFoundMessage.hpp"
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

  /**
   * @brief Finds the node with the maximum key in the subtree.
   *
   * This function traverses the right children of the subtree rooted at `node`
   * until it reaches the rightmost node, which contains the largest key.
   *
   * @param node Pointer to the root of the subtree to search.
   * @return Node* Pointer to the node with the maximum key, or `nullptr` if the
   * subtree is empty.
   */
  Node *getMax(Node *node) const;

  /**
   * @brief Recursively searches for a node with the given key in the subtree.
   *
   * This function traverses the subtree rooted at `node`, comparing the search
   * key to each node's key and descending left or right accordingly. It returns
   * a pointer to the node if found, or `nullptr` if the key is not present.
   *
   * @param key The key to search for in the subtree.
   * @param node Pointer to the root of the subtree to search.
   * @return Node* Pointer to the node containing the key, or `nullptr` if not
   * found.
   */
  Node *search(int key, Node *node) const;

  /**
   * @brief Inserts all keys from the given subtree into another set.
   *
   * This function performs an in-order traversal of the subtree rooted at `T`,
   * inserting each node’s key into the target set `U`, preserving sorted order.
   *
   * @param T Pointer to the root of the subtree whose keys will be inserted.
   * @param U Reference to the set into which keys from the subtree will be
   * inserted.
   */
  void insertSubtree(Node *T, Set &U) const;

  /**
   * @brief Creates the union of two subtrees into the target set.
   *
   * This function traverses both input subtrees in parallel, inserting all keys
   * from both trees into the target set `U`. It handles cases where one subtree
   * is null by inserting all remaining keys from the other subtree.
   *
   * @param t1 Pointer to the root of the first subtree.
   * @param t2 Pointer to the root of the second subtree.
   * @param U Reference to the set where the union of keys will be stored.
   */
  void unionSet(Node *t1, Node *t2, Set &U) const;

  /**
   * @brief Performs an in-order traversal of the subtree and appends node keys to a vector.
   *
   * Recursively visits the left child, records the current node’s key, and then
   * visits the right child, resulting in a sorted sequence of keys.
   *
   * @param node Pointer to the root of the subtree to traverse.
   * @param v Reference to a vector where the keys will be collected.
   */
  void inOrder(Node *node, vector<int> &v) const;

public:
  /**
   * @brief Set builder
   *
   * Creates a set with no elements
   */
  Set();

  /**
   * @brief Destructor for the Set class.
   *
   * This destructor ensures that all dynamically allocated nodes in the tree
   * are properly deleted by calling the `clear` function.
   */
  ~Set();

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
   * @brief Prints the set’s elements in ascending order.
   *
   * This function retrieves all keys via an in-order traversal,
   * then outputs them enclosed in square brackets for easy viewing.
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
   * @throws EmptySetException If the set is empty.
   */
  int minimum() const;

  /**
   * @brief Returns the largest key in the set.
   *
   * This function checks if the set is empty and throws an `EmptySetException`
   * if it is. Otherwise, it finds the rightmost node in the tree (which holds
   * the maximum key) and returns its key.
   *
   * @return int The maximum key in the set.
   * @throws EmptySetException if the set is empty.
   */
  int maximum() const;

  /**
   * @brief Returns the key of the predecessor for the given key in the set.
   *
   * This function searches for the node with the specified key, then finds the
   * largest key smaller than the given key. If the key is not found, the set is
   * empty, or no predecessor exists, appropriate exceptions are thrown.
   *
   * @param key The key whose predecessor is to be found.
   * @return int The key of the predecessor node.
   * @throws ValueNotFoundException if the specified key is not found in the
   * set.
   * @throws EmptySetException if the set is empty.
   * @throws NoPredecessorException if there is no predecessor for the given
   * key.
   */
  int predecessor(int key) const;

  /**
   * @brief Returns the key of the successor for the given key in the set.
   *
   * This function searches for the node with the specified key, then finds the
   * smallest key greater than the given key. It first checks if the set is
   * empty and throws an exception if so. If the key is not found or no
   * successor exists, appropriate exceptions are thrown.
   *
   * @param key The key whose successor is to be found.
   * @return int The key of the successor node.
   * @throws EmptySetException if the set is empty.
   * @throws ValueNotFoundException if the specified key is not found in the
   * set.
   * @throws NoSuccessorException if there is no successor for the given key.
   */
  int successor(int key) const;

  /**
   * @brief Returns a vector of all keys in the set using in-order traversal.
   *
   * This function allocates a vector with reserved space equal to the set size,
   * performs an in-order traversal starting from the root to collect keys in
   * sorted order, and returns the filled vector.
   *
   * @return std::vector<int> A vector containing all keys in ascending order.
   */
  vector<int> inOrder() const;

  /**
   * @brief Returns a new set representing the union of this set and another.
   *
   * This function creates a temporary set `U`, inserts all elements from
   * both the current set and the given set `T` into it, and returns `U` as
   * the union of the two sets.
   *
   * @param set The set to union with the current set.
   * @return Set A new set containing all unique elements from both sets.
   */
  Set *unionSet(const Set &T) const;

  /**
   * @brief Computes the intersection of this set with another set.
   *
   * This function collects the elements of both sets in sorted order using
   * in-order traversal, then iterates through the two sorted vectors to
   * identify common elements. It inserts each common element into a newly
   * allocated set and returns a pointer to it.
   *
   * @param T The set to intersect with the current set.
   * @return Set* A pointer to a new set containing elements common to both
   * sets.
   */
  Set *intersectionSet(const Set &T) const;

  /**
   * @brief Computes the set difference of this set and another.
   *
   * This function returns a new set containing elements that belong to the current set
   * but not to the given set `T`. Both sets are traversed in sorted order to efficiently
   * identify and insert unique elements into the result.
   *
   * @param T The set to subtract from the current set.
   * @return Set* A pointer to a new set containing elements in this set that are not in `T`.
   */
  Set *differenceSet(const Set &T) const;
#ifdef TEST_MODE
  // Retorna a raiz da árvore (para fins de teste)
  Node *getRoot() const;

  // Retorna o fator de balanceamento de um nó (para testes)
  int getBalanceForTest(Node *node) const;
#endif
};

#endif
