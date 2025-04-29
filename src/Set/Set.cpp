#include "Set/Set.hpp"

/**
 * Private Functions
 */

int Set::getBalance(Node* node) const {
	return getHeight(node->left) - getHeight(node->right);
}

int Set::calcHeight(Node* node) const {
	if (!node) return 0;

	return 1 + max(getHeight(node->left), getHeight(node->right));
}

Node* Set::leftRotation(Node* p) {
	Node* q = p->right;

	p->right = q->left;
	q->left = p;

	p->height = calcHeight(p);
	q->height = calcHeight(q);

	return q;
}

Node* Set::rightRotation(Node* p) {
	Node* q = p->left;

	p->left = q->right;
	q->right = p;

	p->height = calcHeight(p);
	q->height = calcHeight(q);

	return q;
}

Node* Set::rebalance(Node* node, int key) {
	int balance = getBalance(node);

	if (balance > 1 and key < node->left->key) {
		// Single Right-Rotation
		return rightRotation(node);
	}
	if (balance > 1 and key > node->left->key) {
		// Double Right-Rotation
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	if (balance < -1 and key < node->right->key) {
		// Double Left-Rotation
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	if (balance < -1 and key > node->right->key) {
		// Single Left-Rotation
		return leftRotation(node);
	}

	node->height = calcHeight(node);
	return node;
}

Node* Set::insert(int key, Node* node) {
	if (!node) {
		_size++;
		return new Node(key);
	}

	if (node->key == key) return node;

	if (key < node->key) {
		node->left = insert(key, node->left);
	} else {
		node->right = insert(key, node->right);
	}

	node = rebalance(node, key);

	return node;
}

int Set::getHeight(Node* node) const {
	return node ? node->height : 0;
}

void Set::clear(Node* node) {
	if (node) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

bool Set::contains(int key, Node* node) const {
	if (!node) return false;
	if (node->key == key) return true;

	if (key < node->key) return contains(key, node->left);
	else return contains(key, node->right);
}

void Set::show(Node* node, string inheritance) const {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        show(node->right , inheritance + "r");
    for(int i = 0; i < (int) inheritance.size() - 1; i++)
        cout << (inheritance[i] != inheritance[i + 1] ? "│   " : "    ");
    if(inheritance != "")
        cout << (inheritance.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        cout << "#" << endl;
        return;
    }
    cout << node->key << endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
    	show(node->left, inheritance + "l");
}

/**
 * Public Functions
 */

Set::Set(): root(nullptr), _size(0) {}

Set::~Set() {
	clear(root);
	root = nullptr;
}

void Set::insert(int key) {
	root = insert(key, root);
}

bool Set::contains(int key) const { return contains(key, root); }

int Set::getHeight() const { return getHeight(root); }

void Set::swap(Set& t) {
	Node* auxNode = root;

	root = t.root;
	t.root = auxNode;

	int auxSize = _size;

	_size = t._size;
	t._size = auxSize;
}

bool Set::empty() const { return _size == 0 and !root; }

int Set::size() const { return _size; }

void Set::show() const { show(root, ""); }

#ifdef TEST_MODE
	Node* Set::getRoot() const { return root; }
	int Set::getBalanceForTest(Node* node) const { return getBalance(node); }
#endif