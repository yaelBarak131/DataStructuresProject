#pragma once
#include "HeapMinAndMax.h"

class FourHeaps {
public:
	node Max();
	node DeleteMax();
	node Min();
	node DeleteMin();
	void CreateEmpty();
	void Insert(int priority, string value);
	node Median();
	void insertSmallMinMax(node tempi);
	void insertBigMinMax(node tempi);

private:
	HeapMinAndMax _big, _small;
	unsigned int _sizeBig = 0, _sizeSmall = 0;


};