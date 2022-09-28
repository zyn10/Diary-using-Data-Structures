#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct Node            //------>Person credentials node
{
    Node* next;
    Node* prev;
    string name;
    long long phoneNo;
    int age;
};
Node* head = NULL;
Node* tail = NULL;
class Diary
{
    int length;
public:
    Diary()
    {
        length = 0;
    }
    bool isEmpty() const
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void selectionSort() 
    {    int swap;
        string swapN;
        int swapage;
        long long swapphone;
        for (Node* temp = head; temp != NULL; temp = temp->next)
        {
            for (Node* temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
            {
                if (temp->name > temp2->name)
                {
                    swapN = temp->name;
                    swapage = temp->age;
                    swapphone = temp->phoneNo;

                     temp->name= temp2->name;
                     temp->age= temp2->age;
                     temp->phoneNo= temp2->phoneNo;
                                   
                    
                    temp2->name = swapN;
                    temp2->age = swapage;
                    temp2->phoneNo = swapphone;
                }
            }
        }
    }
    void Insert(string Name, long long ph, int ag)
    {
        Node* newNode = new Node;
        newNode->name = Name;//----->credentials
        newNode->age = ag;
        newNode->phoneNo = ph;
        newNode->next = NULL;
        newNode->prev = NULL;
        Node* temp = head;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
            length++;
            return;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            selectionSort();
        }
    }
    void reverse()
    {
        cout << "Reverse doubly" << endl << endl << endl;
        Node* temp=tail;
        //temp = tail->prev;
        cout << "Name\t\t\tAge\t\t\tPhoneNumber" << endl;
        while (temp->prev != head) {
            cout << temp->name << "\t\t\t" << temp->age
                << "\t\t\t" << temp->phoneNo << endl;
            temp = temp->prev;
        }
        cout << temp->name << "\t\t\t" << temp->age
            << "\t\t\t" << temp->phoneNo << endl;
             cout << head->name << "\t\t\t" << head->age
            << "\t\t\t" << head->phoneNo << endl;
    }
    
    void Display()
    {
        if (isEmpty())
        {
            cout << "No data found " << endl;
        }
        else
        {
            Node* temp = head;
            cout << "Name\t\t\tAge\t\t\tPhoneNumber" << endl;
            while (temp->next != NULL)
            {
                cout << temp->name << "\t\t\t" << temp->age
                    << "\t\t\t" << temp->phoneNo << endl;
                temp = temp->next;
            }
            cout << temp->name << "\t\t\t" << temp->age
                << "\t\t\t" << temp->phoneNo << endl;
        }
    }
           bool checkString(string passed,string inClass) const
    {
    	int size1=passed.length();
    	//cout<<"Length of passed string"<<size1<<endl;
    	int size2=inClass.length();
    	//cout<<"Length of string in ccc"<<size2<<endl;
    	if(size1==size2)
    	{
			for(int i=0;i<size1;i++)
			{
				if(passed[i]!=inClass[i])
				{
					return false;
				}
			}
			return true;
    	}
    	else 
    	return false;
}
void searching (string pass)
{       Node* temp = head;
cout << "Name\t\t\tAge\t\t\tPhoneNumber" << endl;
            
		while (temp->next != NULL)
        {
            if (checkString(pass,temp->name))
        {
          cout << temp->name << "\t\t\t" << temp->age
                    << "\t\t\t" << temp->phoneNo << endl;
                    return;
        }
                temp = temp->next;
        }  
		if(temp->next==NULL&&checkString(pass,temp->name))
        {
         cout << temp->name << "\t\t\t" << temp->age
                    << "\t\t\t" << temp->phoneNo << endl;
                temp = temp->next;
        
         return;	
		}
        else	  
        cout << "Data Not Found " << endl;
}
void Delete(string pass){
  Node* temp = head;
        //----->for first patient
        if (checkString(pass,head->name))
		  { 
			head = head->next;
            length--;
            return;
            }
        //----------> for middle patient            
        while (temp->next != NULL)
		{
            if (checkString(pass,temp->name)){ 
	   		    temp->next->next = temp->next->next;
	   		    temp->next->prev=temp;
	   		    temp=temp->next;
                length--;
                return;
           }
            temp = temp->next;
			}
		//----------> for last patient
		if(temp->next==NULL)
		{	temp->prev->next=NULL;
         return;	
		}
        cout << " Not Found " << endl;
     }
};
int main()
{   cout<<endl;
    cout<<"\t\t|--------------Phone Book------------ |"<<endl;
	Diary obj;
menu:  
    cout<<"\t\t| Press 1 to Add Person               |"<<endl;
    cout<<"\t\t| Press 2 to Delete Person            |"<<endl;
    cout<<"\t\t| Press 3 to Search person            |"<<endl;
    cout<<"\t\t| Press 4 to Dispaly all persons      |"<<endl;
    cout<<"\t\t| Press 5 to reverse the list         |"<<endl;
    cout<<"\t\t| Press 6 to undo                     |"<<endl;
    cout<<"\t\t| Press any other key to exit         |"<<endl<<endl;
    int choice=0;
    cout<<"\n\t\t    Enter choice: ";
    cin>>choice;
    string name;
 long long ph;
    int age;
    char option='y';
    bool check=true;
    while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6)
    {
    	if (choice==1)
    	{
		 while(option=='y'||option=='Y')
    	 {
         cout<<"\t\t    Enter Name        : ";cin>>name;
         cout<<"\t\t    Enter phone       : ";cin>>ph;
         cout<<"\t\t    Enter age         : ";cin>>age;
		 obj.Insert(name,ph,age);
         cout<<"\t\t   you want to add another person y/n  ";
         cin>>option;
         if(option=='n'||option=='N')
		  goto menu;
		}
		
	}
     else if (choice==2){
        	cout<<"\t\t  Enter the name to delete     "<<endl;
        	cin>>name;
	        obj.Delete(name);
	goto menu;
        }	
    else if (choice==3)
        {   
		    cout<<"\t\t  Enter the Name to Search      "<<endl;
        	cin>>name;
	        obj.searching(name);
	        cout<<endl<<endl;
	        goto menu;
        }	
     else if (choice==4)
        {   obj.Display();
	        cout<<endl<<endl;
	        goto menu;
        }
	 else if (choice==5)
        {   obj.reverse();
	        cout<<endl<<endl;
	        goto menu;
        }
        else if(choice==6)
        {
        	cout<<"This function is under construction :-("<<endl;
		}
	}
	
    return 0;
}


