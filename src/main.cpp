/**
 * @file main.cpp
 * @brief To do app programme
 * @author Reda TARGAOUI
 * @version 1.0
 * @date 29/11/2022
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include "../include/liste.h"

using namespace std;

//##################################### Node class functions ##############################

/**
 * @brief Node class's constructor
 * @param -
 * @return -
*/
Node :: Node() {
	this->next = NULL;
}

/**
 * @brief Node class's constructor
 * @param String item
 * @return -
*/
Node :: Node(string item) {
	this->item = item;
}

/**
 * @brief Get current node's item
 * @param -
 * @return string item
*/
string Node :: getItem() {
	return this->item;
}

/**
 * @brief Get current node's next
 * @param -
 * @return Node next
*/
Node *& Node :: getNext() {
	return this->next;
}

/**
 * @brief set node's item
 * @param String item
 * @return -
*/
void Node :: setItem(string item) {
	this->item = item;
}

//******************************** Liste class functions **********************************************

/**
 * @brief Liste class's constructor
 * @param -
 * @return -
*/
Liste :: Liste() {
	this->head = NULL;
	this->nbElements = 0;
}

/**
 * @brief Liste class's destructor
 * @param -
 * @return -
*/
Liste :: ~Liste() {
	Node * current = this->head;
	
	while ( current != NULL ) {
		Node * temp = current;
		current = current->getNext();
		delete(temp);
	}

}

/**
 * @brief Check if an item exist in the list
 * @param String item
 * @return bool true if item exist, false otherwise
*/
bool Liste :: search(string item) {
	Node * temp = this->head; // A pointer on list's head
	bool exist = false;
	
	while ( temp != NULL ) { 
		if ( temp->getItem() == item ) {
			exist = true;
		}
		temp = temp->getNext();
	}
	
	return exist;
}


/**
 * @brief Add item to the list
 * @param String item
 * @return -
*/
void Liste :: addItem(string item) {
	// if the item doesn't exist
	if ( this->search(item) == false ) {
		this->nbElements++;
		Node * temp = new Node(item);
		temp->getNext() = this->head;
		this->head = temp;
	}
	
}

/**
 * @brief Delete an item from the list
 * @param int item's position
 * @return -
*/
void Liste :: deleteItem(int pos) {
	Node * temp = this->head; // Pointer on list's head
	Node * tempPrev = NULL; // Pointer on temp's previous pointer

	int index = 1;

	while ( index != pos ) { 
		tempPrev = temp;
		temp = temp->getNext();
		index++;
	}

	// If temp's previous is empty, that means that the item is the head of the list :
	if ( tempPrev == NULL ) {
		head = head->getNext();
	}

	// Else its in another place in the list, and we are in that place :
	else {
		tempPrev->getNext() = temp->getNext();
	}

	temp->getNext() = NULL ;
	this->nbElements--;

	delete(temp);

}

/**
 * @brief Edit an item
 * @param string the new item text
 * @param int item's position
 * @return -
*/
void Liste :: editItem(string newitem, int pos) {
	Node * temp = this->head; // Pointer on list's head
	Node * tempPrev = NULL; // temp's previous

	// Go through the list until we reach the end, or find pos :
	int index = 1;
	while ( temp != NULL && index != pos ) {
		tempPrev = temp; // Previous gets current
		temp = temp->getNext();
		index++;
	}

	// If we reached the end :
	if ( temp == NULL ) { 
		cout << "Not found !!" << endl;
	}

	// If we found the item pos :
	else {
		temp->setItem(newitem);
    }

}

/**
 * @brief Display List's content
 * @param -
 * @return -
*/
void Liste :: displayList() {
	Node * temp = this->head;

	int index = 1;

	while ( temp != NULL ) {
		cout << "\t" << index << "\t" << temp->getItem() << endl;
		temp = temp->getNext();
		index++;
	}

}

/**
 * @brief add List's item to a file
 * @param -
 * @return -
*/
void Liste :: addData() {
	ofstream File("data.txt"); // Open file
	Node * temp = this->head;

	while ( temp != NULL ) {
		File << temp->getItem() << endl; // Add item to file
		temp = temp->getNext();
	}

}

/**
 * @brief Principale function
*/
int main() {
	cout << "\t\t ** Welcome **" << endl;

	Liste L; // Creating a list

	// Insert data in the list :
    string content; // To store each line
    ifstream ReadFile("data.txt");

    while ( getline(ReadFile, content) ) {
        L.addItem(content);
    }
    ReadFile.close();

	// Display list :
	cout << "\t ** Your notes : **" << endl;
	L.displayList();

	int choice = 1;
	while ( choice != 0 ) {
		string response; // To store user's response
		cout << "** Press 'add' to add an item, 'del' to delete an item, 'edit' to edit an item **" << endl;
	    cout << "-> What do you want to do ? ";
	    cin >> response;

	    if ( response == "add" ) {
		    string newItem;// To store the item to add
		    cout << "-> Write the item that you want to add : ";
		    cin >> newItem ;
		    L.addItem(newItem);
		    L.addData(); // Store the item in data file
		    L.displayList();
	    }

	    else if ( response == "del" ) {
		    int pos; // Item's pos
		    cout << "-> Write the position of the item that you want to delete : ";
		    cin >> pos;
		    L.deleteItem(pos);
			L.addData();
			L.displayList();
	    }

	    else if ( response == "edit" ) {
	    	string item;
	    	int pos;
	    	cout << "-> Write the position of the item that you want to modify : ";
	    	cin >> pos;
	    	cout << "-> Write the item : ";
	    	cin >> item;
	    	L.editItem(item, pos);
			L.addData();
			L.displayList();
		}

	    cout << "** To continue press 1, to stop press 0 : ";
	    cin >> choice;
	}
}
