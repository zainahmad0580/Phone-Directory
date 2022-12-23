//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node
//{
//	string name;
//	string number;
//	Node* nextnode;
//	Node* prevnode;
//
//public:
//	Node()
//	{
//		name = "";
//		number = "";
//		nextnode = NULL;
//		prevnode = NULL;
//	}
//
//	void setName(string name)
//	{
//		this->name = name;
//	}
//
//	string getName()
//	{
//		return name;
//	}
//
//	void setNumber(string num)
//	{
//		number = num;
//	}
//
//	string getNumber()
//	{
//		return number;
//	}
//
//	void setNextNode(Node* ptr)
//	{
//		nextnode = ptr;
//	}
//
//	Node* getNextNode()
//	{
//		return nextnode;
//	}
//
//	void setPrevNode(Node* ptr)
//	{
//		prevnode = ptr;
//	}
//
//	Node* getPrevNode()
//	{
//		return prevnode;
//	}
//
//}; //ends Class Node
//
//class myStack
//{
//    Node* head;
//    int noE;
//
//public:
//    myStack()
//    {
//        head = NULL;
//        noE = 0;
//    }
//
//    //INSERT ELMENTS IN THE STACK
//    void push(string name, string num)
//    {
//        Node* newnode = new Node();
//
//        newnode->setName(name); //Setting new node's data
//		newnode->setNumber(num); //Setting new node's data
//		newnode->setNextNode(NULL); //Setting next node to NULL
//		newnode->setPrevNode(NULL); //Setting prev node to NULL
//
//        head = newnode;
//
//        noE++;
//    }
//
//    //EXTRACTS ELEMENTS AND DELETES THEM
//    void pop()
//    {
//        string temp1 = head->getName();
//        string temp2 = head->getNumber();
//
//
//        Node* t = head;
//
//        head = head->getNextNode();
//
//        delete t;
//
//        noE--;
//
//        cout << temp1 << " " << temp2 << endl;
//
//    }
//
//    //CHECKS IF LIST IS EMPTY
//    int isEmpty()
//    {
//        return head == NULL; //returns 1 if head is NULL, otherwise 0
//    }
//
//    //RETURNS THE VALUE AT TOP
//    string Top()
//    {
//        return head->getName();
//    }
//
//};//ends class Stack
//
//int main()
//{
//    int n;
//    string name, num;
//
//    myStack s1;
//
//    cout << "\nHow many values do you want to insert: ";
//    cin >> n;
//
//
//    cout << "\nINSERTING VALUES" << endl;
//
//    for (int i = 0; i < n; i++)
//    {
//        cout << "\nEnter name: ";
//        getline(cin >> std::ws, name);
//        cout << "\nEnter number: ";
//        getline(cin >> std::ws, num);
//
//        s1.push(name, num);
//    }
//
//    cout << "\nPOPPING VALUES" << endl;
//
//    for (int i = 0; i < n; i++)
//    {
//        s1.pop();
//    }
//
//
//    cout << "\nIS THE STACK EMPTY? " << endl;
//
//    if (s1.isEmpty())
//        cout << "\nYES" << endl;
//
//    else
//        cout << "\nNO" << endl;
//
//    return 0;
//}