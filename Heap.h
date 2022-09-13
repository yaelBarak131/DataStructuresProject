#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>

#include "string.h"
using namespace std;

struct node {
	int priority;
	string data;
	int ind;

};

class Heap {

public:
	bool isEmpty();
	void makeEmpty();
	node returnRoot();
	int leftChild(int node);
	int rightChild(int node);
	int parent(int node);
	int getSize() { return _lSize; }
	node& getIndVal(const int& ind) { return _heap[ind]; }
	int getInd(const int& i) const { return _heap[i].ind; }
	int getPriority(const int& i) const { return _heap[i].priority; }
	string getData(const int& i) const { return _heap[i].data; }


	void setIndVal(const int& ind,const node& item) { _heap[ind] = item; }//צריך לשלוח העתק או רפרנס?
	void setPriority(const int& ind, const int& newPri) { _heap[ind].priority = newPri; }
	void setData(const int& ind, const string& newData) { _heap[ind].data = newData; }
	void setInd(const int& ind, const int& newInd) { _heap[ind].ind = newInd; }



private:
	node _heap[100];
	int _lSize=0;

};