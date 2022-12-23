//ZAIN AHMAD-200798, MUHAMMAD IMRAN-200855, LAIBA WAHEED-200906
//------------SEMESTER PROJECT DSA 2021---------------//

#include <iostream>
#include <string>
using namespace std;

class Node
{
	string name;
	string number;
	Node* nextnode;
	Node* prevnode;

public:
	Node()
	{
		name = "";
		number = "";
		nextnode = NULL;
		prevnode = NULL;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setNumber(string num)
	{
		number = num;
	}

	string getNumber()
	{
		return number;
	}

	void setNextNode(Node* ptr)
	{
		nextnode = ptr;
	}

	Node* getNextNode()
	{
		return nextnode;
	}

	void setPrevNode(Node* ptr)
	{

		prevnode = ptr;
	}

	Node* getPrevNode()
	{
		return prevnode;
	}

}; //ends Class Node

//DOUBLE LINK LIST
class ContactList
{
	Node* head; //To point at the 1st node 
	Node* current; //To point at the current node
	Node* prev; //To point at the previous node
	Node* temp; //To temporarily store value
	int SIZE; //Size of the list
	string listname; //Name of the list
	string* names; //Names of the contacts 

public:
	//-----------------CONSTRUCTOR-----------------//
	ContactList()
	{
		head = NULL;
		current = NULL;
		prev = NULL;
		temp = NULL;
		SIZE = 0;
		listname = "";
		names = NULL;

	}//ENDS CONSTRUCTOR

	//-----------------DESTRUCTOR-----------------//
	~ContactList()
	{
		if (head == NULL) //if the list is empty
		{
			cout << "\nLIST IS EMPTY, NOTHING TO DELETE!" << endl;
		}

		else//if list has elements
		{
			current = head; //both are pointing to the 1st element now
			prev = head;

			while (current->getNextNode() != NULL)
			{
				prev = current;
				current = current->getNextNode();
				current->setPrevNode(NULL);
				delete prev;
			}

			prev = current;
			delete prev;

			head = NULL;

			cout << "\nYour list has been successfully deleted" << endl;

		}//ends else

	}//ENDS DESTRUCTOR

	int getSize() //LinkList Size
	{
		return SIZE;
	}

	void setName(string name) //LinkList Name
	{
		listname = name;
	}

	string getName() //returns linklist name
	{
		return listname;
	}

	//-----------------INSERTION-----------------//
	void Insertion(string name, string num)
	{
		Node* newnode = new Node(); //creating a new node and initializing it

		newnode->setName(name); //Setting new node's data
		newnode->setNumber(num); //Setting new node's data
		newnode->setNextNode(NULL); //Setting next node to NULL
		newnode->setPrevNode(NULL); //Setting prev node to NULL

		if (head == NULL) //if linklist is empty
		{
			head = newnode; //head is now pointing to the newnode
		}

		//Insert at start
		else if (head->getName() > newnode->getName()) //else linklist is not empty
		{
			head->setPrevNode(newnode);
			newnode->setNextNode(head); //Moving head to the next node and inserting newnode at start
			head = newnode; //head now points to the newnode which is at the start
		}

		//Insert at end
		else if (newnode->getName() > current->getName())
		{
			current = head; //current & head both are pointing to the 1st location

			while (current->getNextNode() != NULL) //Loop runs till we get to the last node
			{
				current = current->getNextNode(); //Goes to the next node
			}

			newnode->setPrevNode(current);
			current->setNextNode(newnode); //Pass newnode to setNextNode so that it is inserted at the end
		}

		//Insert at specific location
		else
		{
			current = head; //Current now points at head(1st loc)

			prev = head; //Previous pointer now points at head(1st loc)

			while (current->getNextNode() != NULL)
			{
				prev = current;
				current = current->getNextNode();

				if (newnode->getName() > prev->getName() && newnode->getName() < current->getName())
					break;
			}

			prev->setNextNode(newnode);
			newnode->setPrevNode(prev);
			current->setPrevNode(newnode);
			newnode->setNextNode(current);
		}

		SIZE++; //Increment after adding a node

	}//ENDS INSERTION

	//-----------------DELETE CONTACT-----------------//
	void Deletion(string name)
	{
		if (head == NULL)
		{
			cout << "\nTHE LIST IS EMPTY" << endl;
		}

		else
		{

			current = head;
			prev = head;
			temp = head;

			while (current->getNextNode() != NULL)
			{
				//If we want to delete the 1st node, HEAD
				if (current->getName() == name && current->getPrevNode() == NULL)
				{
					temp = current;

					current = current->getNextNode();
					current->setPrevNode(NULL);
					
					head = current;

					delete temp; //deletes the contact

					SIZE--; //decrement

					break;
				}

				//If any node in between
				else if (current->getName() == name)
				{

					temp = current;

					prev = temp->getPrevNode();
					current = current->getNextNode();

					prev->setNextNode(current);
					current->setPrevNode(prev);

					delete temp; //deletes the contact

					SIZE--; //decrement

					break;
				}

				current = current->getNextNode();

			}//ends while

			//If last node
			if (current->getName() == name && current->getNextNode() == NULL)
			{
				temp = current->getPrevNode();
				temp->setNextNode(NULL);

				delete current; //deletes the contact

				SIZE--; //decrement
			}

			else
				cout << "\nCONTACT NOT FOUND!" << endl;

		}//ends else


	}//ENDS DELETE CONTACT

	//-----------------DISPLAY LIST-----------------//
	void displayList()
	{
		if (head == NULL) //if the list is empty
		{
			cout << "\nLIST IS EMPTY" << endl;
			cout << "\nLIST NAME: " << listname << endl;
		}

		else//if list has elements
		{
			cout << "\nLIST NAME: " << listname << endl;

			current = head; //both are pointing to the 1st element now

			cout << "\nELEMENTS OF THE LIST: ";

			cout << "\nPREV NODE OF 1ST NODE: " << current->getPrevNode() << endl;

			while (current->getNextNode() != NULL) //Loop will work till we get to the last node
			{
				cout << "\n->NAME: " << current->getName() << endl;
				cout << "->NUMBER: " << current->getNumber() << endl;

				current = current->getNextNode(); //moves on to the next node
			}

			cout << "\n->NAME: " << current->getName() << endl;
			cout << "->NUMBER: " << current->getNumber() << endl;

			cout << "\nNEXT NODE OF LAST NODE: " << current->getNextNode() << endl;

		}//ends else

		cout << "\nSIZE OF THE LIST: " << SIZE << endl;

	}//ENDS DISPLAY LIST

	//-----------------DISPLAY REVERSE LIST-----------------//
	void ReverseList()
	{
		if (head == NULL) //if the list is empty
		{
			cout << "\nLIST IS EMPTY" << endl;
			cout << "\nLIST NAME: " << listname << endl;
		}

		else//if list has elements
		{
			cout << "\nLIST NAME: " << listname << endl;

			current = head; //both are pointing to the 1st element now

			cout << "\nELEMENTS OF THE LIST: ";

			while (current->getNextNode() != NULL) //Loop will work till we get to the last node
				current = current->getNextNode(); //moves on to the next node

			while (current->getPrevNode() != NULL)
			{
				cout << "\n->NAME: " << current->getName() << endl;
				cout << "->NUMBER: " << current->getNumber() << endl;

				current = current->getPrevNode(); //moves on to the next node
			}

			cout << "\n->NAME: " << current->getName() << endl;
			cout << "->NUMBER: " << current->getNumber() << endl;

		}//ends else

		cout << "\nSIZE OF THE LIST: " << SIZE << endl;

	}//ENDS DISPLAY REVERSE LIST


	//-----------------DELETE LIST-----------------//
	void deleteList()
	{
		if (head == NULL) //if the list is empty
		{
			cout << "\nLIST IS EMPTY NOTHING TO DELETE!" << endl;
		}

		else//if list has elements
		{
			current = head; //both are pointing to the 1st element now
			prev = head;

			while (current->getNextNode() != NULL)
			{
				prev = current;
				current = current->getNextNode();
				current->setPrevNode(NULL);
				delete prev;
			}

			prev = current;
			delete prev;

			head = NULL;

		}//ends else

	}//ENDS DELETE LIST

	//-----------------NAME EXISTS-----------------//
	bool nameExists(string name)
	{
		int count = 0; //To keep count of contact

		current = head;

		for (int i = 1; i <= SIZE; i++)
		{
			if (current->getName() == name)
			{
				count++;
				break;
			}
			current = current->getNextNode();
		}

		if (count == 0)
			return false;

		else
			return true;

	}//ENDS NAME EXISTS

	//-----------------NUMBER EXISTS-----------------//
	bool numExists(string num)
	{
		int count = 0; //To keep count of contact

		current = head;

		for (int i = 1; i <= SIZE; i++)
		{
			if (current->getNumber() == num)
			{
				count++;
				break;
			}

			current = current->getNextNode();
		}

		if (count == 0)
			return false;

		else
			return true;

	}//ENDS NUMBER EXISTS

	//-----------------FIND NAME-----------------//
	Node* findName(string name)
	{
		int loc = 1; //To keep record of location
		int count = 0; //To keep count of number of time the value is repeated

		current = head;

		for (int i = 1; i <= SIZE; i++)
		{
			if (current->getName() == name)
			{
				cout << "\n" << name << " is found at number " << loc << " in your contacts list!" << endl;
				count++;
				break;
			}

			loc++;
			current = current->getNextNode();
		}

		if (count == 0)
			cout << "Your contact was not found in the list" << endl;

		return current;

	}//ENDS FIND CONTACT


}; //ENDS CLASS DOUBLE LINKLIST

//---------------------FOR CALL HISTORY---------------------//
class myStack
{
	Node* head;
	Node* temp;
	string name;
	string num;
	int noE;

public:
	myStack()
	{
		head = NULL;
		temp = NULL;
		name = "";
		num = "";
		noE = 0;
	}

	int getElements()
	{
		return noE;
	}

	//INSERT CONTACTS IN THE STACK
	void push(Node* ptr)
	{
		Node* newnode = new Node();

		newnode->setName(ptr->getName());
		newnode->setNumber(ptr->getNumber());
		newnode->setNextNode(NULL);
		newnode->setPrevNode(NULL);

		if (head == NULL) //if linklist is empty
			head = newnode; //head is now pointing to the newnode

		else//insert at start
		{
			head->setPrevNode(newnode);
			newnode->setNextNode(head); //Moving head to the next node and inserting newnode at start
			head = newnode; //head now points to the newnode which is at the start
		}

		noE++;

	}//ends insert contacts in the stack

	//EXTRACTS ELEMENTS AND DELETES THEM
	void pop()
	{
		//IF THERE IS ONLY 1 NODE
		if (head->getNextNode() == NULL)
		{
			name = head->getName();
			num = head->getNumber();

			temp = head;

			delete temp;

			noE--;

			cout << "\n->NAME: " << name << endl;
			cout << "->NUMBER: " << num << endl;

			cout << "\n\n\t*CALL HISTORY IS NOW EMPTY, NOTHING TO DELETE*" << endl;

			return;
		}

		name = head->getName();
		num = head->getNumber();

		temp = head;

		head = head->getNextNode();
		head->setPrevNode(NULL);

		delete temp; //deletes the contact

		noE--;

		cout << "\n->NAME: " << name << endl;
		cout << "->NUMBER: " << num << endl;

	}//ends pop

	
	void displayStack()
	{
		if (head == NULL) //if the list is empty
		{
			cout << "\nCALL HISTORY IS EMPTY" << endl;
		}

		else//if list has elements
		{

			temp = head;

			cout << "\nCALL HISTORY CONTACTS: ";

			cout << "\nPREV NODE OF 1ST NODE: " << head->getPrevNode() << endl;

			while (head->getNextNode() != NULL) //Loop will work till we get to the last node
			{
				cout << "\n->NAME: " << head->getName() << endl;
				cout << "->NUMBER: " << head->getNumber() << endl;

				head = head->getNextNode(); //moves on to the next node
			}

			cout << "\n->NAME: " << head->getName() << endl;
			cout << "->NUMBER: " << head->getNumber() << endl;

			cout << "NEXT NODE OF LAST NODE: " << head->getNextNode() << endl;

			head = temp;

		}//ends else

		cout << "\nSIZE OF CALL HISTORY: " << noE << endl;

	}//ends display stack
	

	//CHECKS IF LIST IS EMPTY
	int isEmpty()
	{
		return head == NULL; //returns 1 if head is NULL, otherwise 0
	}

};//ends class Stack

//--------------CLASS MY QUEUE----------------//
class myQueue
{
	Node* front;
	Node* rear;
	Node* temp;
	string name;
	string num;
	int noE;

public:
	myQueue()
	{
		front = NULL;
		rear = NULL;
		temp = NULL;
		name = "";
		num = "";
		noE = 0;
	}

	int get_Q_Elements()
	{
		return noE;
	}

	//INSERT AT END
	void EnQueue(Node *ptr)
	{
		Node* newnode = new Node();

		newnode->setName(ptr->getName());
		newnode->setNumber(ptr->getNumber());
		newnode->setNextNode(NULL);
		newnode->setPrevNode(NULL);

		if (rear == NULL) //If queue is empty
		{
			rear = newnode;
			front = newnode;
		}

		else
		{
			newnode->setPrevNode(rear);
			rear->setNextNode(newnode);
			rear = newnode;
		}

		noE++;
	}

	//POP//
	void DeQueue(myStack &callhistory)
	{
		callhistory.push(front);

		//If there is only 1 contact in the queue
		if (front->getNextNode() == NULL)
		{
			name = front->getName();
			num = front->getNumber();

			temp = front;

			delete temp;

			noE--;

			cout << "\n->NAME: " << name << endl;
			cout << "->NUMBER: " << num << endl;

			cout << "\n\n\t*QUEUE IS EMPTY, ALL CALLS DONE*" << endl;

			return;
		}

		name = front->getName();
		num = front->getNumber();

		temp = front;

		front = front->getNextNode();
		front->setPrevNode(NULL);

		delete temp;

		noE--;

		cout << "\n->NAME: " << name << endl;
		cout << "->NUMBER: " << num << endl;

	}//ends Dequeue

	//CHECKS IF QUEUE IS EMPTY
	int isEmpty()
	{
		return front == NULL; //returns 1 if head is NULL, otherwise 0
	}


}; //ENDS CLASS MYQUEUE

//Function Prototypes
void insertionMenu(ContactList* ptr);
void deletionMenu(ContactList* ptr);
void displayMenu(ContactList* ptr);
void batchCallMenu(ContactList *ptr, myStack &ptr1);
void callHistoryMenu(myStack ptr);

int main()
{
	int choice = 0;
	char call_choice;
	string listname;
	string name; //for contact name
	int no_of_calls;
	
	int PIN = 1234; //SCREEN LOCK PIN
	int count = 5;

	ContactList* L;
	L = NULL; //initializing the pointer to NULL

	myStack callhistory;


	//	LOCK SCREEN PIN	//
	do {
		cout << "\nENTER PIN OF YOUR PHONE ";
		cin >> PIN;

		if (PIN != 1234)
		{
			cout << "\nERROR! WRONG PIN, TRY AGAIN" << endl;
			cout << "\n" << count-1 << " try remaining" << endl;
			count--;
		}

		if (count == 0) //IF 5 TIMES WRONG PIN, PROGRAM WILL END
			exit(0);

	} while (PIN != 1234);


	cout << "\n* * * * * * * * * * * * * * * C O N T A C T   L I S T * * * * * * * * * * * * * * *" << endl;

	do {

		cout << "\n================== M A I N   M E N U ==================" << endl << endl;
		cout << "\n\t 1. Create Contact List" << endl;
		cout << "\n\t 2. Insert Contacts" << endl;
		cout << "\n\t 3. Delete Contacts" << endl;
		cout << "\n\t 4. Display Contacts" << endl;
		cout << "\n\t 5. Make A Call" << endl;
		cout << "\n\t 6. Batch Calls" << endl;
		cout << "\n\t 7. Call History" << endl;
		cout << "\n\t 8. Update A Contact" << endl;
		cout << "\n\t 9. Find A Contact" << endl;
		cout << "\n\t 10. Length Of Contact List" << endl;
		cout << "\n\t 11. Delete Entire Contact List" << endl;
		cout << "\n\t 0. To Exit" << endl;

		cout << "\n\tEnter you choice: ";
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 0: exit(0); //if user enters 0, exit from the program

		case 1: //Create List
			if (L != NULL)
			{
				cout << "\nList is already created!" << endl;

				system("pause");
				system("cls");

				break;
			}

			L = new ContactList(); //calling constructor and initializing data members of LinkList

			cout << "\nEnter a name for your list: ";
			getline(cin >> std::ws, listname);

			L->setName(listname);

			cout << "\nYOUR LIST HAS BEEN CREATED SUCCESSFULLY!" << endl;
			cout << "LIST NAME: " << L->getName() << endl;
			cout << "SIZE = " << L->getSize() << endl;

			system("pause");
			system("cls");

			break; //ends create list

		case 2: //Insert in the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			system("cls");

			cout << "\n\tInserting contact in the list" << endl;

			insertionMenu(L);

			system("cls");

			break; //ends insert list

		case 3: //Delete from the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
			{
				cout << "\nLIST IS EMPTY, NOTHING TO DELETE!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tDeleting from the list" << endl;

				deletionMenu(L); //Function call for deletion menu

				system("cls");

				break; //ends delete from list
			}

		case 4: //Display the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
			{
				cout << "\nLIST IS EMPTY, NOTHING TO DISPLAY!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tDisplaying the list" << endl;

				displayMenu(L); //Function call to display list

				system("cls");

				break; //ends display list
			}


		case 5: //Make a call

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			system("cls");

			do {

				cout << "\nEnter Name of the person you want to call: ";
				getline(cin >> std::ws, name);

				cout << "\n\tCALLING " << name << endl;

				system("pause");

				callhistory.push(L->findName(name));

				cout << "\nDo you want to make another call? (Y/N) ";
				cin >> call_choice;

				system("cls");

			} while (call_choice == 'Y' || call_choice == 'y');

			break; //ends make a call

		case 6: //Make batch calls
		{

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
				cout << "\nCONTACT LIST IS EMPTY, CANNOT MAKE BATCH CALLS" << endl;

			else if (L->getSize() == 1)
				cout << "\nERROR! THERE MUST BE ATLEAST 2 CONTACTS IN THE LIST TO MAKE BATCH CALLS" << endl;

			else
			{
				system("cls");

				batchCallMenu(L, callhistory); 

				system("cls");

				break; //ends batch calls
			}
		}


		case 7: //Call history

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (callhistory.isEmpty())
			{
				cout << "\nCALL HISTORY IS EMPTY, NOTHING TO SHOW!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tCALL HISTORY" << endl;

				callHistoryMenu(callhistory);

				system("cls");

				break; //ends call history
			}
		
		case 8: //Update a contact from the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
			{
				cout << "\nCONTACT LIST IS EMPTY, NOTHING TO UPDATE!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tUpdating Contacts" << endl;

				L->displayList();

				cout << "\nEnter Name of the person you want to update: ";
				getline(cin >> std::ws, name);

				if (L->nameExists(name))
				{
					Node* temp = L->findName(name);

					cout << "\nEnter New Name of the person: ";
					getline(cin >> std::ws, name);

					temp->setName(name);
				}

				else
					cout << "\nNAME NOT FOUND IN THE LIST!" << endl;

				L->displayList();

				system("pause");
				system("cls");

				break;
			
			}//ends update contact

		case 9: //Find a contact from the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
			{
				cout << "\nCONTACT LIST IS EMPTY, NOTHING TO FIND!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tFinding Contact" << endl;

				L->displayList();

				cout << "\nEnter Name of the person you want to find: ";
				getline(cin >> std::ws, name);

				L->findName(name);

				system("pause");
				system("cls");

				break;
			}


		case 10: //Lenght of the list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			system("cls");

			if (L->getSize() == 0)
				cout << "\nTHE LIST IS EMPTY" << endl;

			else
				cout << "\n\tLength of the contact list: " << L->getSize() << endl;

			system("pause");

			system("cls");

			break; //ends length of the list

		case 11: //Delete entire list

			if (L == NULL)
			{
				cout << "\nERROR! FIRST CREATE THE LIST FROM OPTION 1" << endl;
				break;
			}

			if (L->getSize() == 0)
			{
				cout << "\nLIST IS EMPTY, NOTHING TO DELETE!" << endl;
				break;
			}

			else
			{
				system("cls");

				cout << "\n\tDeleting Entire Contact List" << endl;

				delete L; //calls destructor
				L = NULL;

				system("pause");
				system("cls");

				break; //ends delete entire list
			}

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;

			system("pause");

			system("cls");

			break;

		}//ends switch


	} while (choice != 0);

	return 0;

}//ENDS MAIN FUNCTION

//-------------INSERTION MENU-------------//
void insertionMenu(ContactList* L)
{
	int choice_2; //To get choice from the user
	string name; //Name of contact
	string num; //Number of contact

	do {

		L->displayList();

		cout << "\n---------------------INSERTION MENU---------------------" << endl << endl;
		cout << "1. Insert A Contact" << endl;
		cout << "2. Back to main menu" << endl;
		cout << "0. To Exit" << endl;

		cout << "Enter you choice: ";
		cin >> choice_2;

		switch (choice_2)
		{
		case 0: exit(0);

		case 1:

			cout << "\n\tInserting New Contact" << endl;

			cout << "\nEnter Name: ";
			getline(cin >> std::ws, name);
			cout << "Enter Number: ";
			getline(cin >> std::ws, num);

			L->Insertion(name, num);
				
			system("cls");

			break;

		case 2:
			return;

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;
			break;

		}//ends switch


	} while (choice_2 != 0);

}//ENDS INSERTION MENU

//-------------DELETION MENU-------------//
void deletionMenu(ContactList* L)
{
	int choice_3;
	string name;

	do {

		L->displayList();

		cout << "\n---------------------DELETION MENU---------------------" << endl << endl;
		cout << "1. Delete contact" << endl;
		cout << "2. Back to main menu" << endl;
		cout << "0. To Exit" << endl;

		cout << "Enter you choice: ";
		cin >> choice_3;

		switch (choice_3)
		{
		case 0: exit(0);

		case 1:
			cout << "\n\tDeleting A Contact" << endl;

			cout << "\nEnter Name of the person you want to delete: ";
			getline(cin >> std::ws, name);

			if (L->nameExists(name))
				L->Deletion(name); //Function call to delete contact

			else
				cout << "\nNAME NOT FOUND IN THE LIST!" << endl;

			system("cls");

			break;

		case 2:
			return;

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;
			break;

		}//ends switch


	} while (choice_3 != 0);

}//ENDS DELETION MENU

//-------------DISPLAY MENU-------------//
void displayMenu(ContactList* L)
{
	int choice_4; //To get choice from the user

	do {

		cout << "\n---------------------DISPLAY MENU---------------------" << endl << endl;
		cout << "1. Display entire contact list" << endl;
		cout << "2. Display list in reverse order" << endl;
		cout << "3. Back to main menu" << endl;
		cout << "0. To Exit" << endl;

		cout << "Enter you choice: ";
		cin >> choice_4;

		switch (choice_4)
		{
		case 0: exit(0);

		case 1:

			cout << "\n\tDisplaying Entire List" << endl;

			L->displayList();

			system("pause");
			system("cls");

			break;
		
		case 2:

			cout << "\n\tDisplaying Reverse List" << endl;

			L->ReverseList();

			system("pause");
			system("cls");

			break;

		case 3:
			return;

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;
			break;

		}//ends switch


	} while (choice_4 != 0);

}//ENDS DISPLAY MENU

//-------------BATCH CALL MENU-------------//
void batchCallMenu(ContactList *L, myStack &callhistory)
{
	int choice_6; //To get choice from the user
	int batch_size = 0; //To get no of batch calls user wants to make
	string name; //Name of contact

	myQueue q1;

	do {

		cout << "\n---------------------BATCH CALL MENU---------------------" << endl << endl;
		cout << "1. Add Contacts To Batch Call" << endl;
		cout << "2. De-Batch" << endl;
		cout << "3. Back to main menu" << endl;
		cout << "0. To Exit" << endl;

		cout << "Enter you choice: ";
		cin >> choice_6;

		switch (choice_6)
		{
		case 0: exit(0);

		case 1: //ENQUEUE

			cout << "\n\tAdding Contacts to Batch Call List" << endl;

			L->displayList();

			cout << "\nHow many people do you want to call? ";
			cin >> batch_size;

			for (int i = 1; i <= batch_size; i++)
			{
				cout << "\nEnter Name of the person you want to add to batch call list: ";
				getline(cin >> std::ws, name); 

				if (L->nameExists(name))
				{
					q1.EnQueue(L->findName(name));
					cout << "\n" << name << " successfully added to batch call list" << endl;
				}

				else
					cout << "\nERROR, NAME NOT FOUND!" << endl;
			}

			cout << "\nYOUR BATCH LIST IS COMPLETED!" << endl;

			system("pause");
			system("cls");

			break;
		
		case 2: //DEQUEUE

			if (batch_size == 0)
				cout << "\nPLEASE FIRST INSERT CONTACTS IN THE BATCH CALL LIST!" << endl;

			else
			{
				cout << "\n\tDE-BATCHING..." << endl;

				for (int i = 1; i <= batch_size; i++)
				{
					cout << "\nCALLING PERSON " << i;
					q1.DeQueue(callhistory);
				}

				system("pause");
				system("cls");
				
			}

			break;

		case 3:
			return;

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;
			break;

		}//ends switch


	} while (choice_6 != 0);

}//ENDS BATCH CALL MENU

void callHistoryMenu(myStack s1)
{
	int choice_7; //To get choice from the user
	string name; //Name of contact
	string num; //Number of contact

	do {

		cout << "\n---------------------CALL HISTORY MENU---------------------" << endl << endl;
		cout << "1. Display Call History" << endl;
		cout << "2. Display & Delete Call History" << endl;
		cout << "3. Back to main menu" << endl;
		cout << "0. To Exit" << endl;

		cout << "Enter you choice: ";
		cin >> choice_7;

		switch (choice_7)
		{
		case 0: exit(0);

		case 1: //display stack

			cout << "\n\tDisplaying Call History" << endl;

			s1.displayStack();

			system("pause");
			system("cls");

			break;

		case 2: //pop stack

			cout << "\n\tDisplaying & Deleting History" << endl;
			cout << "\n\nCALLS WILL BE DELETE 1 BY 1 STARTING FROM THE OLDEST CALL" << endl;

			s1.pop();

			system("pause");
			system("cls");

			break;

		case 3:
			return;

		default:
			cout << "\n\tERROR! YOU DID NOT ENTER A VALID CHOICE" << endl;
			break;

		}//ends switch


	} while (choice_7 != 0);

}//ENDS CALL HISTORY MENU

//----------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------P R O G R A M  E N D S  H E R E-------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------//
