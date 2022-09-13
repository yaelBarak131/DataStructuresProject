#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

#include "FourHeaps.h"

using namespace std;

class Menu {

	public:
		void runProgrm();
		int getNumOfAction()const { return numOfActions; }
		string getUserInput() const{ return userInput; }
		bool validInput();
		void activateFuncX(bool& isAllredyMaked);//לחשוב אם לקחת את זה רק בקייס F ולבדוק שנקלט או תמיד
		void printNode(node temp);
		void getPair(node& temp);
		void getUserInput();

	private:
		string userInput;
		int numOfActions;
		int countInput=0;
		FourHeaps h;
};