#include "FourHeaps.h"

node FourHeaps::Max()
{
	if (_sizeBig == 0)
	{
		if (_sizeSmall == 0) {
			cout << "The heap is empty" << endl;
			exit(1);
		}
		else
			return _small.MaxReturnRoot();
	}
	else
	return _big.MaxReturnRoot();
}
node FourHeaps::Min()
{
	if (_sizeSmall != 0)
		return _small.MinReturnRoot();
	else 
	{
		cout << "The heap is empty" << endl;
		exit(1);
	}
}
node FourHeaps::Median() {

	if (_sizeSmall != 0)
		return _small.MaxReturnRoot();
	else {
		cout << "the heap is empty" << endl;
		exit(1);
	}
	

}
void FourHeaps::CreateEmpty()
{
	_big.makeEmpty();
	_small.makeEmpty();
	
}

node FourHeaps::DeleteMax()
{
	int i, j;
	node temp, median, newNode;
	if (_sizeSmall > 0) {
		_sizeBig = _big.getSize();
		_sizeSmall = _small.getSize();

		temp = _big.MaxdeletRoot();

		if ((_sizeBig + 1) == _sizeSmall) {

			median = _small.MaxdeletRoot();
			_big.insert(median);

		}

		_sizeBig = _big.getSize();
		_sizeSmall = _small.getSize();

		return temp;
	}
	else {
		cout << "Worng input" << endl;
		exit(1);
	}
}
node FourHeaps::DeleteMin()
{
	int i, j;
	node temp, min, newNode;
	if (_sizeSmall > 0) {
		_sizeBig = _big.getSize();
		_sizeSmall = _small.getSize();

		temp = _small.MindeletRoot();

		if (_sizeBig == _sizeSmall)
		{
			min = _big.MindeletRoot();
			_small.insert(min);
		}



		_sizeBig = _big.getSize();
		_sizeSmall = _small.getSize();

		return temp;
	}
	else {
		cout << "Worng input" << endl;
		exit(1);
	}
}

void FourHeaps::Insert(int priority, string value)
{
	node tempi, newNodi, medi;
	int i, j;
	bool insertToSmall = false;

	_sizeBig = _big.getSize();
	_sizeSmall = _small.getSize();

	if(_sizeSmall>0)
		medi = _small.MaxReturnRoot();

	tempi.priority = priority;
	tempi.data = value;

	if (_sizeSmall <= 0) 
		insertSmallMinMax(tempi);
	
	
	else {

		if (medi.priority > priority) {
			insertSmallMinMax(tempi);
			insertToSmall = true;
		}
		else
			insertBigMinMax(tempi);

	}
	if (insertToSmall)
	{
		if (_sizeSmall == (_sizeBig + 2))//צריך להעביר מערימת הקטנים לערימת הגדולים
		{
			newNodi = _small.MaxdeletRoot();
			insertBigMinMax(newNodi);
		}
	}
	else
	{
		if (_sizeBig == (_sizeSmall + 1))
		{
				newNodi = _big.MindeletRoot();
				insertSmallMinMax(newNodi);
		}
	}

	_sizeBig = _big.getSize();
	_sizeSmall = _small.getSize();
}

void FourHeaps::insertSmallMinMax(node tempi)
{
	 _small.insert(tempi);

	_sizeSmall = _small.getSize();
}

void FourHeaps::insertBigMinMax(node tempi)
{
	_big.insert(tempi);

	_sizeBig = _big.getSize();
}



