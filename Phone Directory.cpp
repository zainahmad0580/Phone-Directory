//#include <iostream>
//#include <string>

//using namespace std;
//
//int main()
//{
//    int SIZE;
//
//    cout << "How many contacts do you want to insert? ";
//    cin >> SIZE;
//
//    string* names = new string[SIZE];
//
//    //Loop to input contact names
//    for (int i = 0; i < SIZE; i++)
//        getline(cin >> std::ws, names[i]); //To also input spaces btw names
//
//    cout << endl;
//
//    sort(names, names + SIZE); //To sort in ascending order
//
//    //Displaying contacts in Alphabetical order
//    for (int i = 0; i < SIZE; i++)
//        cout << names[i] << endl;
//
//    sort(names, names + SIZE, greater<string>()); //To sort in descending order
//
//    //Displaying contacts in descending order
//    for (int i = 0; i < SIZE; i++)
//        cout << names[i] << endl;
//
//
//    return 0;
//}