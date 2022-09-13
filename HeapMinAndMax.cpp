#include "HeapMinAndMax.h"

node HeapMinAndMax::MindeletRoot()
{
	node min = _minHeap.getIndVal(IND_ROOT), temp;
	int index;

	node newNodi = _minHeap.getIndVal(_minLSize - 1);//Move the most left leaf to he root
	_minHeap.setIndVal(IND_ROOT, newNodi);

	index = _minHeap.getInd(IND_ROOT);

	_maxHeap.setInd(index, IND_ROOT);

	_minLSize--;

	if (_minLSize >= 1)
		MinfixHeap(IND_ROOT);

	index = _minHeap.getInd(min.ind);

	MaxdeleteI(index);

	return min;
}

node HeapMinAndMax::MaxReturnRoot() {

		return _maxHeap.returnRoot(); 
}


int HeapMinAndMax::Mininsert(node item) {

	int i;
	if (_minLSize == P_SIZE)
	{
		cout << "The heap is full" << endl;
		exit(1);
	}

	_minLSize++;
	_minHeap.setIndVal((_minLSize - 1) ,item);
	i = _minLSize - 1;

	while ((i >= 1) && (_minHeap.getPriority(_minHeap.parent(i)) > _minHeap.getPriority(i)) )
	{
		MinindSwap(_minHeap.parent(i), i);

		swap(_minHeap.getIndVal(i), _minHeap.getIndVal(_minHeap.parent(i)));
		i = _minHeap.parent(i);
	}

	_minHeap.setIndVal(i, item);

	return i;
}

void HeapMinAndMax::MinfixHeap(int _node) {
	int min, left, right, index;
	left = _minHeap.leftChild(_node);
	right = _minHeap.rightChild(_node);


	// Find maximum among node, left and right.
	if ((left < _minLSize) && ((_minHeap.getPriority(left) < _minHeap.getPriority(_node))))
		min = left;

	else
		min = _node;

	if ((right <= _minLSize) && (_minHeap.getPriority(right) < _minHeap.getPriority(min)))
		min = right;

	if (min != _node) {

		MinindSwap(_node, min);
		MinindSwap(min, _node);

		swap(_minHeap.getIndVal(_node), _minHeap.getIndVal(min));
		MinfixHeap(min);
	}
}

void HeapMinAndMax::MindeleteI(int ind) {

	if (_minLSize > 2) {
		node temp;
		int index, i = ind;

		_minHeap.setIndVal(ind, _minHeap.getIndVal(_minLSize - 1));
		_minLSize--;

		index = _minHeap.getInd(ind);
		_maxHeap.setInd(index, ind);


		while ((i >= 1) && (_minHeap.getPriority(_minHeap.parent(i)) > _minHeap.getPriority(i)))
		{
			MinindSwap(_minHeap.parent(i), i);
			MinindSwap(i, _minHeap.parent(i));
			swap(_minHeap.getIndVal(i), _minHeap.getIndVal(_minHeap.parent(i)));
			i = _minHeap.parent(i);
		}
	}
	else
		_minLSize--;

}


void HeapMinAndMax::MinindSwap(const int& ind1, const int& ind2)
{
	int index;

	index =_minHeap.getInd(ind1);
	_maxHeap.setInd(index,ind2);

}

void HeapMinAndMax::swap(node& val1, node& val2) {

	node temp = val1;
	val1 = val2;
	val2 = temp;

}

node HeapMinAndMax::MaxdeletRoot() {
	node max = _maxHeap.getIndVal(IND_ROOT), temp;
	int index;

	node newNodi= _maxHeap.getIndVal(_maxLSize - 1);
	_maxHeap.setIndVal(IND_ROOT, newNodi);

	index = _maxHeap.getInd(IND_ROOT);
	_minHeap.setInd(index, IND_ROOT);
	
	_maxLSize--;

	if (_maxLSize >= 1)
		MaxfixHeap(IND_ROOT);

	MindeleteI(max.ind);

	return max;
}

void HeapMinAndMax::MaxdeleteI(int ind) {
	
	if (_maxLSize > 2) {
		node temp,newNodi= _maxHeap.getIndVal(_minLSize - 1);
		int index, i = ind;

		_maxHeap.setIndVal(ind, newNodi);
		_maxLSize--;

		index = _maxHeap.getInd(ind);
		_minHeap.setInd(index, ind);

		while ((i >= 1) && (_maxHeap.getPriority(_maxHeap.parent(i)) < _maxHeap.getPriority(i)))
		{
			MaxindSwap(_maxHeap.parent(i), i);
			MaxindSwap(i, _maxHeap.parent(i));
			swap(_maxHeap.getIndVal(i), _maxHeap.getIndVal(_maxHeap.parent(i)));
			i = _maxHeap.parent(i);
		}
	}
	else
		_maxLSize--;

}


void HeapMinAndMax::insert(node item) {

	int i,j;
	node newNodi;

	if (_minLSize == P_SIZE) {
		cout << "The heap is full" << endl;
		exit(1);
	}


	i = MaxInsert(item);

	newNodi.data = item.data;
	newNodi.priority = item.priority;
	newNodi.ind = i;

	j = Mininsert(newNodi);

	_maxHeap.setInd(i, j);


}
int HeapMinAndMax::MaxInsert(node item) {
	int i;

	_maxLSize++;
	_maxHeap.setIndVal(_maxLSize - 1, item);
	i = _maxLSize - 1;

	while ((i >= 1) && (_maxHeap.getPriority(_maxHeap.parent(i)) < _maxHeap.getPriority(i))) {
		MaxindSwap(_maxHeap.parent(i), i);
		swap(_maxHeap.getIndVal(i), _maxHeap.getIndVal(_maxHeap.parent(i)));
		i = _maxHeap.parent(i);
	}
	_maxHeap.setIndVal(i, item);

	return i;
}
void HeapMinAndMax::MaxfixHeap(int _node) {
	int max, left, right, index;
	left = _maxHeap.leftChild(_node);
	right = _maxHeap.rightChild(_node);


	// Find maximum among node, left and right.
	if ((left < _maxLSize) && ((_maxHeap.getPriority(left)  > _maxHeap.getPriority(_node))))
		max = left;
	else
		max = _node;

	if ((right <= _maxLSize) && (_maxHeap.getPriority(right) > _maxHeap.getPriority(max)))
		max = right;

	if (max != _node) {

		MaxindSwap(_node, max);
		MaxindSwap(max, _node);

		swap(_maxHeap.getIndVal(_node), _maxHeap.getIndVal( max));
		MaxfixHeap(max);
	}
}

void HeapMinAndMax::MaxindSwap(const int& ind1, const int& ind2)
{
	int index;

	index = _maxHeap.getInd(ind1);
	_minHeap.setInd(index, ind2);

}
