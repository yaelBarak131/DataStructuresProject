#pragma once

#include "Heap.h"

const int IND_ROOT = 0;
const int P_SIZE = 100;
class HeapMinAndMax {

public:

	int getSize() { return _maxLSize; }

	void makeEmpty() { 
		_minHeap.makeEmpty();
		_maxHeap.makeEmpty();
	}
	void setSize(const int& size) {
		_maxLSize = size;
	}
	void swap(node& val1, node& val2);
	void insert(node item);


	node MinReturnRoot() { return _minHeap.returnRoot(); }
	node MindeletRoot();
	int Mininsert(node item);
	void MinfixHeap(int node);
	void MindeleteI(int ind);
	void MinindSwap(const int& ind1, const int& ind2);

	int MaxInsert(node item);
	node MaxReturnRoot();
	node MaxdeletRoot();
	void MaxdeleteI(int ind);
	void MaxfixHeap(int node);
	void MaxindSwap(const int& ind1, const int& ind2);


private:
	Heap _maxHeap;
	Heap _minHeap;
	int _minLSize = 0, _maxLSize = 0;
};