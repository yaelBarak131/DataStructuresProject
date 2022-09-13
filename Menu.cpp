#include "Menu.h"


void Menu::runProgrm()
{
	//cout << "Please enter num of actions:" << endl;
	
	cin >> numOfActions;

	if (numOfActions <= 0){
		cout << "Wrong input" << endl;
		exit(1);
	}
	/*cout << "Choose one from the following functions:" << endl;
	cout << "(a) Max" << endl;
	cout << "(b) DeleteMax" << endl;
	cout << "(c) Min" << endl;
	cout << "(d) DeleteMin" << endl;
	cout << "(e) CreateEmpty" << endl;
	cout << "(f) Insert" << endl;
	cout << "(g) Median" << endl;*/

	cin.get();

	getUserInput();


	if (countInput != numOfActions)
	{
		cout << "Worng Input" << endl;
		exit(1);
	}

}
bool Menu::validInput()
{
	bool good = false;

	if (userInput[0] >= 'a' && userInput[0] <= 'g')
		good = true;

	if (countInput <= numOfActions)
		good = true;


	return good;
}

void Menu::getUserInput()
{
	bool isAllredyMaked = false, firstInput = true;
	if (firstInput) {
		//cout << "user select:" << endl;
		std::getline(std::cin, userInput);
	}

	while (userInput != "") {
		if (!firstInput) {
			//cout << "user select:" << endl;
			std::getline(std::cin, userInput);
		}
		if (!validInput()) {
			cout << "Worng Input" << endl;
			exit(1);
		}
		else
			activateFuncX(isAllredyMaked);

		if (firstInput)
			firstInput = false;
		if(userInput != "")
			countInput++;

	}
}

void Menu::activateFuncX(bool& isAllredyMaked) {
	node temp;

	switch (userInput[0]) {
	case 'a'://check the size is not 0
		if (isAllredyMaked) {
			temp = h.Max();
			printNode(temp);
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}
		break;
	case 'b':
		if (isAllredyMaked) {
			temp = h.DeleteMax();
			printNode(temp);
		}
		else
		{
		cout <<  "Worng Input" << endl;
		exit(1);
		}

		break;
	case 'c':
		if (isAllredyMaked) {
			temp = h.Min();
			printNode(temp);
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}
		break;
	case 'd':
		if (isAllredyMaked) {
			temp = h.DeleteMin();
			printNode(temp);
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}

		break;
	case 'e':
		if (!isAllredyMaked) {
			isAllredyMaked = true;
			h.CreateEmpty();
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}
		break;
	case 'f':
		if (isAllredyMaked) {
			getPair(temp);
			h.Insert(temp.priority, temp.data);
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}
		break;
	case 'g':
		if (isAllredyMaked) {
			temp = h.Median();
			printNode(temp);
		}
		else
		{
			cout <<  "Worng Input" << endl;
			exit(1);
		}
		break;
	default:
		if (userInput != "") {
			cout << "Worng Input" << endl;
			exit(1);
		}
		break;
	}

}
void Menu::getPair(node& temp) {
	
	int i = 2;
	
	if (userInput[1] != ' ') {
		cout << "Worng input" << endl;
		exit(1);
	}
	if(userInput[0]>='0'|| userInput[0] <= '9')
		temp.priority= stoi(userInput.data() + i);

	else {
		cout << "Worng input" << endl;
		exit(1);
	}

	int tempi = temp.priority;

	while (tempi != 0) {
		tempi /= 10;
		i++;
		
	}
	if (temp.priority < 0)
		i++;

	if (userInput[i] != ' ')
	{
		cout << "Worng input" << endl;
		exit(1);
	}
	
	i++;
	temp.data = userInput.data() + i;


}

void Menu::printNode(node temp)
{

	cout << temp.priority << " ";
	cout << temp.data << endl;

}
