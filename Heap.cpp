#include "Heap.h"

void Heap::makeEmpty() {
	_lSize = 0;
}

int Heap::leftChild(int node) {
	return (2 * node);
}
int Heap::rightChild(int node) {
	return (2 * node + 1);
}
int Heap::parent(int node) {
	return node / 2;
}
node Heap::returnRoot() {
	return _heap[0];
}
bool Heap::isEmpty() {
	return _lSize == 0;
}

