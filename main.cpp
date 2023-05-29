#include <bits/stdc++.h>
using namespace std;
class Item {
public:
    string ItemName;
    int serialNumber;
    double Price;
    Item* next;
    Item* previous;
    Item(){
        Price = 0 ;
        serialNumber = 0 ;
        ItemName = "" ;
    }
    Item(string name , int serial , double price){
        ItemName = name ;
        serialNumber = serial ;
        Price = price ;
    }
};
class Stack{
public:
    void Push_Head(Item**head,string name ,int serial,double price ){
        Item * newItem = new Item ;
        newItem->ItemName = name ;
        newItem->serialNumber = serial ;
        newItem->Price = price ;
        newItem->next=* head;
        newItem->previous=NULL;
        *head= newItem ;
    }
    void Pop_Head(Item*&head){
        if(head==NULL){
            return;
        }
        Item*temp=head;
        head= head->next;
        head->previous=NULL;
        delete temp;
        return;
    }
};
void Opening(Item*head,Stack* s);
void AdminAccess(Item* head,Stack* s);
void UserAccess(Item*head);
void AddItem(Item**head);
void Add_After(Item*head);
void SetItem(Item**head ,string item_name , int serial , double price);
void Addlast(Item**head);
void Addition(Item*head,Stack* s);
void Deletion(Item*head,Stack* s);
int countOfNodes(Item* head);
void Delete_The_Head(Item*&head);
void deleteMid(Item* head);
void Delete_The_Tail(Item*head);
void Search(Item * head  );
void update(Item * head);
void sort(Item* head) ;
void Traversal(Item* head);
void DisplayItems();
void Pick();
double price();
double adding_tax(double price );
double tax(double price);
void receipt();
void clear();
void place_order();
int main() {
    Item *head = NULL ;
    Stack *s;
    SetItem(&head,"Orio",1110,2.5);
    SetItem(&head,"salt",1109,0.5);
    SetItem(&head,"pasta",1108,2.0);
    SetItem(&head,"chips",1107,1.0);
    SetItem(&head,"rice",1106,1.75);
    SetItem(&head,"ice cream",1105,3.00);
    SetItem(&head,"pepsi",1104,0.75);
    SetItem(&head,"eggs",1103,4.00);
    SetItem(&head,"juice",1102,1.5);
    SetItem(&head,"galaxy chocolate",1101,3.5);
    Opening(head,s);
    return 0;
}

void Opening(Item* head,Stack* s) {
    string add;
    do {
        cout << "\t\tSupermarket billing system\n";
        cout << "=================================================\n";
        cout << "1.Admin access\n";
        cout << "2.User access\n";
        cout << "3.Exit\n";
        int n;
        do {
            cin >> n;
            if (n != 1 && n != 2 && n != 3) {
                cout << "please enter a valid option number" << endl;

            }
        } while (n != 1 && n != 2 && n != 3);

        if (n == 1) {
            int attempts = 3;
            string password;//acu
            do {
                cout << "enter your password \n you have " << attempts << " attempts\n";
                cin >> password;
                if (password == "acu") {
                    AdminAccess(head,s);
                    break;
                } else {
                    attempts--;
                }

            } while (attempts > 0);
            if (attempts==0)return;

        } else if (n == 2) {
            UserAccess(head);
        } else if (n == 3) {
            return;
        }
        cout << "if you want to start over again please enter yes or enter no to exit" << endl;
        do {
            cin >> add;
            transform(add.begin(), add.end(), add.begin(), ::tolower);
            if (add != "yes" && add != "no") {
                cout << "please enter a valid option" << endl;
            }
        } while (add != "yes" && add != "no");
    }
    while (add == "yes");
}


void UserAccess(Item* head){
    cout<<"==============================================\n";
    cout<<"\t\t\t\t\tWelcome\n";
    cout<<"==============================================\n";
    cout<<"You've just entered as a user\n";
    cout<<"1.search for an item\n";
    cout<<"2.Make an order\n";
    int n;
         do {
        cin >> n;
        if (n > 2 || n < 1) {
            cout << "please enter a valid option number" << endl;

        }
    } while (n > 2 || n < 1 );
    if (n==1){
        Search(head);
    }else if (n==2){
        place_order();
    }
}

void Add_After(Item*head){

    Item *current;
    Item* temp;
    string newname;
    int flag=0;
    int newprice ;
    int Newserial;
    int oldserial;
    if (head == NULL) {
        cout << "Linked List not initialized" << endl;
        return;
    }
    cout<<"enter the serial number of the previous item\n";
    cin>>oldserial;
    temp=head;
    while (temp!=NULL){
        if (temp->serialNumber==oldserial){
            flag++;
            break;
        }
        temp=temp->next;
    }
    if (flag==0){
        cout<<"couldn't find the serial number\n";
        return;
    } else {
        Item* NewItem=new Item;
        cout << "enter the name of the new item\n";
        cin >> newname;
        cout << "enter the serial number of the new item\n";
        cin >> Newserial;
        cout << "enter the price of the new item\n";
        cin >> newprice;
        NewItem->ItemName=newname;
        NewItem->serialNumber=Newserial;
        NewItem->Price=newprice;
    current = head;
    while (current != NULL) {
        if (current->serialNumber == oldserial) {
            break;
        }
        current = current->next;
    }
    NewItem->next=current->next;
    current->next=NewItem;
    NewItem->previous= current ;
    }
}
void AddItem(Item**head ){
    string item_name;
    int serial;
    double price;
    cout<<"Enter the item name \n";
    cin>>item_name;
    cout<<"Enter the serial number of the item\n";
    cin>>serial;
    cout<<"Enter the price of the item \n";
    cin>>price;
    Item * newItem = new Item ;
    newItem->ItemName = item_name ;
    newItem->serialNumber = serial ;
    newItem->Price = price ;
    newItem->next=* head;
    newItem->previous=NULL;
    *head= newItem ;
}
void Traversal(Item* head){
    Item* temp = head;

    if(temp != NULL) {
        cout<<"the current items in the supermarket : "<<endl;
        while (temp != NULL) {
            cout<<"the item name :" << temp->ItemName << endl ;
            cout<<"the item serial number:"<< temp->serialNumber << endl;
            cout<<"the item price :" << temp->Price << endl;
            temp = temp->next;
        }
    } else{
        cout<<"The list is empty.\n";
    }
}

void AdminAccess(Item*head,Stack* s) {
    cout << "==============================================\n";
    cout << "\t\t\t\t\tWelcome\n";
    cout << "==============================================\n";
    cout << "You've just entered as an admin\n";
    cout << "1.Add an item \n";
    cout << "2.Delete an item\n";
    cout << "3.Traversal the items\n";
    cout << "4.search for an item\n";
    cout << "5.update an item\n";
    cout << "6.sort the linked list\n";
    int n;

    do {
        cin >> n;
        if (n > 6 || n < 1) {
            cout << "please enter a valid option number" << endl;

        }
    } while (n > 6 || n < 1);

    if (n == 1) {
        Addition(head,s);
    } else if (n == 2) {
        Deletion(head,s);
    } else if (n == 3) {
        Traversal(head);
    } else if (n == 4) {
        Search(head);
    } else if (n == 5) {
        update(head);
        cout<<"the list of items after the edit\n";
        Traversal(head);
    } else if (n == 6) {
        sort(head);
        cout<<"the list of items after the edit\n";
        Traversal(head);
    }
}

void Delete_The_Head(Item*&head){
    if(head==NULL){
        return;
    }
    Item*temp=head;
    head= head->next;
    head->previous=NULL;
    delete temp;
    return;

}

void deleteMid(Item* head)
{
    // Base cases
    if (head == NULL)
        if (head->next == NULL) {
            delete head;
        }
    Item* copyHead = head;
    // Find the count of nodes
    int count = countOfNodes(head);
    // Find the middle node
    int mid = count / 2;
    // Delete the middle node
    while (mid-- > 1)
        head = head->next;
    // Delete the middle node
    head->next = head->next->next;

}
void Delete_The_Tail(Item*head){
    if(head != NULL) {
        if(head->next == NULL) {
            head = NULL;
        } else {
            Item* temp = head;
            while(temp->next->next != NULL)
                temp = temp->next;
            Item* lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}
int countOfNodes(Item* head)
{
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}
void Addlast(Item**head) {
    string item_name;
    int serial;
    double price;
    cout<<"Enter the item name \n";
    cin>>item_name;
    cout<<"Enter the serial number of the item\n";
    cin>>serial;
    cout<<"Enter the price of the item \n";
    cin>>price;
    Item*NewTail = new Item;
    NewTail->ItemName = item_name;
    NewTail->Price = price;
    NewTail->serialNumber = serial;
    NewTail->next = NULL;
    if (*head == NULL) {
        *head = NewTail;
        return;
    }
    Item* tail=*head;
    while (tail->next!=NULL){
        tail=tail->next;
    }
    tail->next= NewTail;
    NewTail->previous = tail ;
}
void Addition(Item*head,Stack* s) {

        cout << "=================================================\n";
        cout << "1.Add at the beginning \n";
        cout << "2.Add after an exist item \n";
        cout << "3.Add at the end \n";
        int n;
        do {
            cin >> n;
            if (n > 3 || n < 1) {
                cout << "please enter a valid option number" << endl;

            }
        } while (n > 3 || n < 1);
        if (n == 1) {
            string item_name;
            int serial;
            double price;
            cout<<"Enter the item name \n";
            cin>>item_name;
            cout<<"Enter the serial number of the item\n";
            cin>>serial;
            cout<<"Enter the price of the item \n";
            cin>>price;
            s->Push_Head(&head,item_name,serial,price);
            cout<<"the list of items after the edit\n";
            Traversal(head);
        } else if (n == 2) {
            Add_After(head);
            cout<<"the list of items after the edit\n";
            Traversal(head);
        } else if (n == 3) {
            Addlast(&head);
            cout<<"the list of items after the edit\n";
            Traversal(head);
        }
    }
void Deletion(Item*head,Stack* s) {

    cout << "=================================================\n";
    cout << "1.Delete at the beginning \n";
    cout << "2.Delete the middle  \n";
    cout << "3.Delete the tail \n";
    int n;
    do {
        cin >> n;
        if (n > 3 || n < 1) {
            cout << "please enter a valid option number" << endl;

        }
    } while (n > 3 || n < 1);

    if (n == 1) {
       s->Pop_Head(head);
        cout<<"the list of items after the edit\n";
        Traversal(head);
    } else if (n == 2) {
        deleteMid(head);
        cout<<"the list of items after the edit\n";
        Traversal(head);
    } else if (n == 3) {
        Delete_The_Tail(head);
        cout<<"the list of items after the edit\n";
        Traversal(head);
    }
}
void Search(Item * head ) {
    int serial;
    cout<<"Enter the serial number of the product tha you're searching for\n";
    cin>>serial;
    Item* temp = head;

    int found = 0;
    int i = 0;

    if(temp != NULL) {
        while(temp != NULL) {
            i++;
            if(temp->serialNumber == serial) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1) {
            cout << serial << " is found at index = " << i << ".\n";
            cout<<"Item name:"<<temp->ItemName<<endl;
            cout<<"Item price: "<<temp->Price<<endl;
            cout<<"Item serial number:"<<temp->serialNumber<<endl;
        } else {
            cout << serial << " is not found in the list.\n";
        }
    } else {
        cout<<"The list is empty.\n";
    }
}

void update(Item * head) {
    Item *current;
    Item* temp;
    string newname;
    int flag=0;
    int newprice ;
    int Newserial;
    int oldserial;
    if (head == NULL) {
        cout << "Linked List not initialized" << endl;
        return;
    }
    cout<<"enter the old serial number of the item\n";
    cin>>oldserial;
    temp=head;
    while (temp!=NULL){
        if (temp->serialNumber==oldserial){
            flag++;
            break;
        }
        temp=temp->next;
    }
    if (flag==0){
        cout<<"couldn't find the serial number\n";
        return;
    } else {
        cout << "enter the new name of the item\n";
        cin >> newname;
        cout << "enter the new serial number of the item\n";
        cin >> Newserial;
        cout << "enter the new price of the item\n";
        cin >> newprice;
        current = head;
        while (current != NULL) {
            if (current->serialNumber == oldserial) {
                current->serialNumber = Newserial;
                current->ItemName = newname;
                current->Price = newprice;
                break;
            }
            current = current->next;
        }
    }
}

void sort(Item* head ) {
    Item*current ;
    Item*index ;
    current = head ;
    index = NULL;
    int temp;
    string temp2 ;
    double temp3 ;
    if(head == NULL) {
        return;
    }
    else {
        while(current != NULL) {
            index = current->next;
            //If current node's data is greater than index's node data, swap the data between them
            while(index != NULL) {
                if(current->serialNumber > index->serialNumber ) {
                    temp = current->serialNumber;
                    temp2 = current->ItemName ;
                    temp3 = current->Price ;
                    current->serialNumber = index->serialNumber;
                    current->Price = index->Price ;
                    current->ItemName = index->ItemName;
                    index->serialNumber = temp;
                    index->ItemName = temp2 ;
                    index->Price = temp3 ;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void SetItem(Item**head ,string item_name , int serial , double price){
    Item * newItem = new Item ;
    newItem->ItemName = item_name ;
    newItem->serialNumber = serial ;
    newItem->Price = price ;
    newItem->next= *head;
    *head = newItem ;
}
void DisplayItems(){
    cout << "==============================================\n";
    cout << "\t\t\t\t\tItems\n";
    cout << "==============================================\n";
    cout <<"1.Orio                                  $2.50 \n";
    cout <<"2.Salt                                  $0.50 \n";
    cout <<"3.Pasta                                 $2.00 \n";
    cout <<"4.Chips                                 $1.00 \n";
    cout <<"5.Rice                                  $1.75 \n";
    cout <<"6.IceCream                              $3.00 \n";
    cout <<"7.Pepsi                                 $0.75 \n";
    cout <<"8.Eggs                                  $4.00 \n";
    cout <<"9.Juice                                 $1.50 \n";
    cout <<"10.Galaxy Chocolate                     $3.50 \n";
}
void Pick(){
    DisplayItems();
    cout << "Please choose the number of the item that you want from the list from 1 to 10" << endl;
    int n;
    fstream receipt;
    fstream price;
    receipt.open("receipt.txt", ios::app);
    price.open("price.txt", ios::app);
    do {
        cin >> n;
        if (n > 10 || n < 1){cout<<"enter a valid option number\n";}
    } while (n > 10 || n < 1);
    if (n == 1) {
        receipt<<"Orio                                  $2.50 \n";
        price<<2.50;
    } else if (n == 2) {
        receipt<<"Salt                                  $0.50 \n";
        price<<0.50;
    } else if (n == 3) {
        receipt<<"Pasta                                 $2.00 \n";
        price<<2.00;
    } else if (n == 4) {
        receipt<<"Chips                                 $1.00 \n";
        price<<1.00;
    } else if (n == 5) {
        receipt<<"Rice                                  $1.75 \n";
        price<<1.75;
    } else if (n == 6) {
        receipt<<"IceCream                              $3.00 \n";
        price<<3.00;
    } else if (n == 7) {
        receipt<<"Pepsi                                 $0.75 \n";
        price<<0.75;
    } else if (n == 8) {
        receipt<<"Eggs                                  $4.00 \n";
        price<<4.00;
    } else if (n == 9) {
        receipt<<"Juice                                 $1.50 \n";
        price<<1.50;
    } else if (n == 10) {
        receipt<<"Galaxy Chocolate                      $3.50 \n";
        price<<3.50;
    }
    receipt.close();
    price.close();
}
double price(){
    fstream price;
    double total=0;
    price.open("price.txt",ios::in);
    double n;
    while (price){
        price>>n;
        total=total+n;
    }
    total=total-n;
    return total;
}
double adding_tax(double price ){
    double after_tax=price+(price*0.14);
    return  after_tax;
}
double tax(double price){
    double tax=price*0.14;
    return  tax;
}
void receipt(){
    fstream receipt;
    receipt.open("receipt.txt",ios::in);
    string s;
    cout<<"=========================================================\n";
    cout<<"\tyour order is : \n";
    while (receipt){
        getline(receipt,s);
        cout<<"\t"<<s<<endl;
    }
    receipt.close();
    cout<<"=========================================================\n";
    cout<<"\tyour order price is: $"<<price()<<endl ;
    cout<<"\tthe tax amount is : $"<<tax(price())<<endl;
    cout<<"\ttotal price after adding 14% tax is: $"<<adding_tax(price())<<endl;
    cout<<"=========================================================\n";
}
void clear(){
    fstream receipt;
    receipt.open("receipt.txt",ios::out|ios::trunc);
    receipt.close();
    fstream price;
    price.open("price.txt",ios::out|ios::trunc);
    price.close();
}
void place_order (){
    string add;
    do {
        Pick();
        cout << "if you want to add something else please enter yes or enter no to exit" << endl;
        do {
            cin >> add;
            transform(add.begin(),add.end(),add.begin(),::tolower);
            if(add!="yes" && add!="no" ){
                cout<<"please enter a valid option "<<endl;
            }
        }while (add!="yes" && add!="no");
    }while (add == "yes");
    receipt();
    clear();
}