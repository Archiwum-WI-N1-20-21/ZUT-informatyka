#include <iostream>
#include <time.h>
#include <math.h>

template <typename T>
class BSTnode {
public:
	int id;
	T var;
	BSTnode* left;
	BSTnode* right;
	BSTnode* parent;
};

template <typename T>
class BST {
private:
	BSTnode<T>* root;
	int nodeAmount = 0;
public:
	BST() {
		root = NULL;
	};
	~BST() {
		delete root;
	};
	BSTnode<T>* addNode(BSTnode<T>* node, T key) {
		if (node == NULL) {
			node = new BSTnode<T>;
			node->var = key;
			node->left = NULL;
			node->right = NULL;
			node->parent = NULL;
			node->id = rand() % 100000;
		}
		else if (node->var < key) {
			node->right = addNode(node->right, key);
			node->right->parent = node;
		}
		else {
			node->left = addNode(node->left, key);
			node->left->parent = node;
		}
		return node;
	}
	void addNode(T key) {
		root = addNode(root, key);
	}
	void inOrder(BSTnode<T>* node) {
		if (node == NULL) {
			return;
		}
		inOrder(node->left);
		std::cout << "Node id: " << node->id << ", Node var: " << node->var << std::endl;
		inOrder(node->right);
	}
	void inOrder() {
		inOrder(root);
		std::cout << std::endl;
	}
	void preOrder(BSTnode<T>* node) {
		if (node == NULL) {
			return;
		}
		std::cout << "Node id: " << node->id << ", Node var: " << node->var << std::endl;
		preOrder(node->left);
		preOrder(node->right);
	}
	void preOrder() {
		preOrder(root);
		std::cout << std::endl;
	}
	BSTnode<T>* findNode(BSTnode<T>* node, T key) {
		if (node == NULL) {
			return NULL;
		}
		else if (node->var == key) {
			return node;
		}
		else if (node->var < key) {
			return findNode(node->right, key);
		}
		else {
			return findNode(node->left, key);
		}
	}
	
	void findNode(T key) {
		BSTnode<T>* result = findNode(root, key);
		if (result == NULL) {
			std::cout << "Node with key: " << key << " not found" << std::endl << std::endl;
			return;
		}
		else {
			std::cout << "Node with key: " << key << " found" << std::endl << std::endl;
		}
	}
	T findMin(BSTnode<T>* node) {
		if (node == NULL) {
			return -1;
		}
		else if (node->left == NULL) {
			return node->var;
		}
		else {
			return findMin(node->left);
		}
	}
	T findMin() {
		return findMin(root);
	}
	T findMax(BSTnode<T>* node) {
		if (node == NULL) {
			return -1;
		}
		else if (node->right == NULL) {
			return node->var;
		}
		else {
			return findMax(node->right);
		}
	}
	T findMax() {
		return findMax(root);
	}
	T next(BSTnode<T>* node) {
		if (node->right != NULL) {
			return findMin(node->right);
		}
		else {
			BSTnode<T>* parent = node->parent;
			BSTnode<T>* current = node;
									
			while (parent != NULL && current == parent->right) {
				current = parent;
				parent = current->parent;
			}
			if (parent == NULL) {
				return parent->var;
			}
			else {
				return -1;
			}
		}
	}
	T next(T key) {
		BSTnode<T>* node = findNode(root, key);
		return node == NULL ? -1 : next(node);
	}
	T previous(BSTnode<T>* node) {
		if (node->left != NULL) {
			return findMax(node->left);
		}
		else {
			BSTnode<T>* parent = node->parent;
			BSTnode<T>* current = node;
			while (parent != NULL && current == parent->left) {
				current = parent;
				parent = current->parent;
			}
			return parent == NULL ? -1 : parent->var;
		}
	}
	T previous(T key) {
		BSTnode* node = findNode(root, key);
			
		if (node == NULL) {
			return previous(node);
		}
		else {
			return -1;
		}
	}
	BSTnode<T>* remove(BSTnode<T>* node, T key) {
		if (node == NULL) {
			return NULL;
		}
		if (node->var == key) {
			if (node->left == NULL && node->right == NULL) {
				node = NULL;
			}
			else if (node->left == NULL && node->right != NULL) {
				node->right->parent = node->parent;
				node = node->right;
			}
			else if (node->left != NULL && node->right == NULL) {
				node->left->parent = node->parent;
				node = node->left;
			}
			else {
				int nextVar = next(key);
				node->var = nextVar;
				node->right = remove(node->right, nextVar);
			}
		}
		else if (node->var < key) {
			node->right = remove(node->right, key);
		}
		else {
			node->left = remove(node->left, key);
		}
		return node;
	}
	void remove(T key) {
		root = remove(root, key);
	}
};

int main() {
	srand(time(0));

	clock_t timeAddStart, timeAddEnd;
	clock_t timeFindStart, timeFindEnd;

	BST<int> bst;

	int p, i, j;

	for (j = 1; j < 7; j++) {
		p = pow(10, j);
		i = 0;

		timeAddStart = clock();
		for (i = 0; i < p; i++) {
			bst.addNode(rand() % 10000000);
		}
		timeAddEnd = clock();
		std::cout << "Time to add: " << p << " elements, " << (double)(timeAddEnd - timeAddStart) / CLOCKS_PER_SEC << "s" << std::endl << std::endl;

		timeFindStart = clock();
		bst.findNode(rand() % 10000000);
		timeFindEnd = clock();
		std::cout << "Time to find an element, " << (double)(timeFindEnd - timeFindStart) / CLOCKS_PER_SEC << "s" << std::endl << std::endl;

		timeAddEnd = timeAddStart = timeFindEnd = timeFindStart = 0;
	}

	return 0;
}