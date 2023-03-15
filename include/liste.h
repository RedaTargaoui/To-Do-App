/**
 * @file liste.h
 * @brief Linked list to handle the item on the to do app
 * @author Reda TARGAOUI
 * @version 1.0
 * @date 29/11/2022
*/

#ifndef LISTE

using namespace std;

/**
 * @brief Class to handle nodes on the list
*/
class Node {
    // Attributs :
    private :
	    string item;
	    Node * next;
	public :
        // Constrcutor :
		Node();
        Node(string item);
        // Methods :
        string getItem();
        Node *& getNext();
        void setItem(string item);
};

/**
 * @brief Liste class
*/
class Liste {
    // Attributs :
    private :
	    Node * head;
        unsigned int nbElements;
	public :
        // Constructor & destructor :
		Liste();
        ~Liste();
        // Methods : 
		bool search(string item);
		void addItem(string item);
		void deleteItem(int pos);
		void editItem(string item, int pos);
        void displayList();
		void addData();
};

#endif