//#include <iostream>
//#include <string>s
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
//class myQueue
//{
//    Node* front;
//    Node* rear;
//    Node* temp;
//    string name;
//    string num;
//    int noE;
//
//public:
//    myQueue()
//    {
//        front = NULL;
//        rear = NULL;
//        noE = 0;
//    }
//
//    int get_Q_Elements()
//    {
//        return noE;
//    }
//
//    //INSERT AT END
//    void EnQueue(string name, string num)
//    {
//        Node* newnode = new Node();
//
//        newnode->setName(name);
//        newnode->setNumber(num);
//        newnode->setNextNode(NULL);
//        newnode->setPrevNode(NULL);
//
//        if (rear == NULL) //If queue is empty
//        {
//            rear = newnode;
//            front = newnode;
//        }
//
//        else
//        {
//
//
//            newnode->setPrevNode(rear);
//            rear->setNextNode(newnode);
//
//            rear = newnode;
//        }
//
//        noE++;
//    }
//
//    //POP//
//    void DeQueue()
//    {
//        name = front->getName();
//        num = front->getNumber();
//
//        temp = front;
//
//        //If there is only 1 contact in the queue
//        if (rear == front)
//        {
//            rear = NULL;
//            front = NULL;
//        }
//
//        else
//        {
//            front = front->getNextNode();
//            front->setPrevNode(NULL);
//        }
//
//        delete temp;
//
//        noE--;
//
//        cout << "\n->NAME: " << name << endl;
//      	cout << "->NUMBER: " << num << endl;
//    
//    }//ends Dequeue
//
//    //CHECKS IF QUEUE IS EMPTY
//    int isEmpty()
//    {
//        return front == NULL; //returns 1 if head is NULL, otherwise 0
//    }
//
//
//}; //ENDS CLASS MYQUEUE
//
//
//int main()
//{
//    int n;
//    string name;
//    string num;
//
//    myQueue q1;
//
//    cout << "\nHow many values do you want to insert: ";
//    cin >> n;
//
//    cout << "\nBATCH CALLS" << endl;
//
//    for (int i = 0; i < n; i++)
//    {
//        cout << "\nENTER NAME: ";
//        getline(cin >> std::ws, name);
//        cout << "\nENTER NUM: ";
//        getline(cin >> std::ws, num);
//
//        q1.EnQueue(name, num);
//    }
//
//    cout << "\nDEBATCH" << endl;
//
//    for (int i = 0; i < n; i++)
//        q1.DeQueue();
//
//
//    cout << "\nIS THE QUEUE EMPTY? " << endl;
//
//    if (q1.isEmpty())
//        cout << "\nYES" << endl;
//
//    else
//        cout << "\nNO" << endl;
//
//
//    return 0;