#include<iostream>
using namespace std;
class LinkedList
{
private:
	// Declare a structure for the list.
	struct ListNode
	{
		int value;        // The value in this node.
		struct ListNode *next;// To point to the next node.
	};

	ListNode *head;        // List head pointer.

public:
	// Constructor.
	LinkedList()
	{
		head = NULL;
	}

	// Destructor
	~LinkedList();

	// Linked list operations.
	void appendNode(int);
	void insertNode(int);
	void insertNodeAt(int, int);
	void deleteNode(int);
	void Reverse();
	void deleteAt(int);
	int Search(int);
	void display() const;
};

// appendNode appends a node containing the       
// value passed into num, to the end of the list.  

void LinkedList::appendNode(int num)
{
	ListNode *newNode; // To point to a new node.
	ListNode *nodePtr; // To move through the list.

					   // Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	// If there are no nodes in the list.
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}    //    end else-if

	display();
}    //    end function appendNode


	 // displayList shows the value stored in each               
	 // node of the linked list pointed to by head.       

void LinkedList::display() const
{
	ListNode *nodePtr; // To move through the list

	if (!head)
	{
		cout << "\n\tThe list is empty.";
		return;
	}

	// Position nodePtr at the head of the list.
	nodePtr = head;

	cout << "\n\n\tThe elements in the list are:\n\t";
	// While nodePtr points to a node, traverse the list.

	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << " -> ";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}    //    end while.
	cout << "Null";
}    //    end function displayList.

	 // Reverse function re-arranges node in the list.

void LinkedList::Reverse()
{
	ListNode *nodePtr;
	ListNode *next;
	ListNode *result = NULL;
	if (!head)
	{
		cout << "\n\tThe list is empty.";
		return;
	}
	// Position nodePtr at the head of the list.
	nodePtr = head;
	while (nodePtr != NULL)
	{
		next = nodePtr->next;
		nodePtr->next = result;
		result = nodePtr;
		nodePtr = next;
	}
	head = result;
	display();
}


// The insertNode function inserts a node with num copied to its value member.                


void LinkedList::insertNode(int num)
{
	ListNode *newNode;             // A new node.
	ListNode *nodePtr;             // To traverse the list.
	ListNode *previousNode = NULL; // The previous node.

								   // Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode.
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		//    Initialize previousNode to NULL.
		previousNode = NULL;

		//    Skip all nodes whose value is less than num.
		while (nodePtr != NULL && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If the new node is to be the 1st in the list,
		//    insert it before all other nodes.
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}    //    end else-if

	display();
}    //    end function insertNode.


	 // The insertNode function inserts a node at pos  
	 //with num copied to its value member.          


void LinkedList::insertNodeAt(int num, int pos)
{
	ListNode *newNode;             // A new node.
	ListNode *nodePtr;             // To traverse the list.
	ListNode *previousNode = NULL; // The previous node.
	int i = 0;
	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	// Position nodePtr at the head of list.
	nodePtr = head;
	if (pos == 0)//to inserted at first.
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		while (nodePtr != NULL && i<pos) //loop to reach position.
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			i++;
		}
		if (nodePtr == NULL)//position not found.
			cout << "Invalid Position :" << endl;
		else//inserts node.
		{
			newNode->next = nodePtr;
			previousNode->next = newNode;
		}
	}

	display();
}


//    The deleteNode function searches for a node with num as its value.   
//The node, if found, is deleted from the list and from memory.

void LinkedList::deleteNode(int num)
{
	ListNode *nodePtr;       // To traverse the list.
	ListNode *previousNode = nullptr;//To point to the previous node.

						   // If the list is empty, do nothing.
	if (!head)
	{
		cout << "\n\tFailed to delete as list is empty.";
		return;
	}

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		else
			cout << "\n\tFailed to delete as " << num
			<< " not found in the list.";
	}    //    end else-if

	display();
}    //    end function deleteNode
void LinkedList::deleteAt(int pos)
{

	ListNode *nodePtr;       // To traverse the list.
	ListNode *previousNode = nullptr;//To point to the previous node.
	int i = 0;
	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "\n\tFailed to delete as list is empty.";
		return;
	}
	// Position nodePtr at the head of list.
	nodePtr = head;
	if (pos == 0)//to inserted at first.
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		while (nodePtr != NULL && i<pos)//loop to reach position.
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			i++;
		}
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		else
			cout << "\n\tFailed to delete position " << pos << " not found .";
	}    //    end else-if

	display();
}    //    end function deleteNode.




	 //Searches for value and returns position if found returns -1 if not found.

int LinkedList::Search(int value)
{
	ListNode *nodePtr; // To move through the list.
	int pos = -1;
	if (!head)
	{
		cout << "\n\tThe list is empty.\n";
		return-1;
	}

	// Position nodePtr at the head of the list.
	nodePtr = head;
	while (nodePtr)
	{
		pos++;
		if (nodePtr->value == value)
			return pos;
		else
			nodePtr = nodePtr->next;
	}
	return -1;
}



// Destructor
//This function deletes every node in the list.  


LinkedList::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list.
	ListNode *nextNode; // To point to the next node.

						// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list.
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}    //    end while
}

int main()
{
	//    declare a variable of type linked list
	LinkedList myList;

	//    declare other variables
	char choice;
	int n;

	//    let the user know about the program
	cout << "\n\n\tA program to demonstrate LinkedList class.";

	//    print a list of choices to the user
	do {
		cout << "\n\t\tMENU\n ";
		cout << "\n\n\tAppend a node\t : A";
		cout << "\n\tInsert a node\t : I";
		cout << "\n\tInsert a node At : P";
		cout << "\n\tDelete a node\t : D";
		cout << "\n\tRemove node At\t : T";
		cout << "\n\tSearch a node\t : S";
		cout << "\n\tReverse nodes    : R";
		cout << "\n\tQuit \t         : Q";

		//    prompt and read the user's choice.
		cout << "\n\n\tEnter your choice: ";
		cin >> choice;

		//do appropriate action basing on choice selected.
		switch (choice)
		{
		case 'A':
		case 'a':
			//    prompt and read an integer.
			cout << "\tEnter an integer: ";
			cin >> n;

			//    append the number into list.   
			myList.appendNode(n);
			break;

		case 'I':
		case 'i':
			//    prompt and read an integer.
			cout << "\tEnter an integer: ";
			cin >> n;

			//    insert the number into list.   
			myList.insertNode(n);
			break;

		case 'D':
		case 'd':
			//    prompt and read an integer.
			cout << "\tEnter an integer : ";
			cin >> n;

			//    delete the number from list.   
			myList.deleteNode(n);
			break;
		case 'R':

		case 'r': //Reversing nodes of list.
			myList.Reverse();
			break;
		case 'T':
		case 't':    int pos;
			//prompt a integer to search.
			cout << "\tEnter element position to be deleted:";
			cin >> pos;
			myList.deleteAt(pos);
			break;

		case 'S':
		case 's':   int position;
			//prompt a integer to search.
			cout << "Enter element to be searched:";
			cin >> n;
			//Search element.
			position = myList.Search(n);
			if (position == -1)
				cout << "\tElement not found in the list" << endl;
			else
				cout << "\tElement found at:" << position << endl;
			break;
		case 'P':
		case 'p': int Loc;
			//    prompt and read an integer.
			cout << "\tEnter an integer: ";
			cin >> n;
			//prompt a integer to search.
			cout << "\tEnter position to be inserted:";
			cin >> Loc;
			myList.insertNodeAt(n, Loc);
			break;

		case 'Q':
		case 'q':
			choice = 'q';
		}    //    end switch

	} while (choice != 'q');    //    end do-while

	return 0;    // indicate program executed successfully
}            // end of function, main
