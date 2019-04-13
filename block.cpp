#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <stdlib.h>

using namespace std;

struct node{
    int prevhash;
    int hash;
    string transinfo;
    int nonce;
};

int n;
struct node a[10000];
int users = 0;

map <int , int> m;

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{

    return alphanum[rand() % stringLength];
}


class nodesinnetwork {
	public :

	struct node b[10000];
	void broadcast(){
		for(int i=0;i<n;i++){
			b[i].prevhash = a[i].prevhash;
			b[i].hash = a[i].hash;
			b[i].transinfo = a[i].transinfo;
			b[i].nonce = a[i].nonce;
		}		
	}
	void print(){
		cout<<"\nFor this node in network blockchain is : \n";
		for(int i=0;i<n;i++){
			cout<<"\nBlock Number : "<<i<<"\nprevhash : "<<a[i].prevhash<<"\tblock hash : "<<a[i].hash<<"\tmerkle root value : "<<a[i].transinfo<<""<<"\tnonce :"<<a[i].nonce<<"\n";	
		}
		cout<<"\n";
	}

};
int in = 0;
nodesinnetwork *  allnodes[10000];

void clear(){
	for(int i=0;i<100;i++){
		cout<<"\n";
	}
}
int userno = 0;
int main()
{
    clear();
    std::hash<std::string> hasher;
    printf("\nIMPLEMENTING BLOCKCHAIN\n");
    
    //struct node a[10000];
    
    
    int prev = 0;
    int index = 0;
    string s;
    
    while(1){
        cout<<"\nMENU\n1.INSERT NEW BLOCK\n2.PRINT WHOLE BLOCKCHAIN\n3.ADD NODE IN NETWORK & MAKE IT CONSISTENT WITH NETWORK BLOCKCHAIN\n4.PRINT BLOCKCHAIN AT SPECIFIC NODE\n5.EXIT\n6.Transfer from one account to other\n7.Display Nth user's account balence\n";
        int option;
        cin>>option;
	int index1;
	nodesinnetwork * ptr;
        switch(option){
            case 1:
                
		
		for(int ii = 0; ii < 8; ++ii)
		{
    			s += genRandom();
		}

                a[index].prevhash = prev;
               
		
                a[index].transinfo = s;
                a[index].hash = (int) hasher(a[index].transinfo + to_string(a[index].prevhash));
                prev = a[index].hash;
		a[index].nonce = rand();
		++index;
		n = index;
                break;
            case 2:
		for(int i=0;i<100;i++){
			cout<<"-";
		}
                for(int i=0;i<index;i++){
                    cout<<"\nBlock Number : "<<i<<"\nprevhash : "<<a[i].prevhash<<"\tblock hash : "<<a[i].hash<<"\tmerkle root value : "<<a[i].transinfo<<"\tnonce:"<<a[i].nonce<<"\n";
                	cout<<"\n|\n";
		}
		for(int i=0;i<100;i++){
			cout<<"-";
		}
                break;
            case 5:exit(0);
	    
            case 3 : 
		 
		ptr = new nodesinnetwork;

		allnodes[in++] = ptr;
		users++;
		cout<<"\nnode added to the network with initially empty blockchain!\n";
		
		m.insert(make_pair(userno++,1000));

		break;
	    case 4 :
		cout<<"\nenter serial number of the node (starting from 0) :\n";
		cin>>index1;
		if(index1 > users-1){
			cout<<"\nERROR : This much users not present in the network! Please enter again.\n";
			break;
		} 
		ptr = allnodes[index1];
		ptr->print();
		break;	
	    case 6:
		
			cout<<"\nenter source account number :\n";
			int number1;
			cin>>number1;

			cout<<"\nenter destination account number : \n";int number2;cin>>number2;
			if(number1>userno-1){cout<<"\nsource number is incorrect\n";continue;};
			if(number2>userno-1){cout<<"\ndestination number is incorrect\n";continue;};	
		
			cout<<"\nenter amount :\n";
			int amt;

			cin>>amt;

			if(m.find(number1)->second < amt ){cout<<"\nuser does not have enough balance\n";continue;}
			m.find(number1)->second = m.find(number1)->second - amt;
			m.find(number2)->second = m.find(number2)->second + amt;
			
				
			break;

		case 7:
		cout<<"enter user number : ";
		int now;
		cin>>now;
		if(now <= userno-1){
			cout<<"\nBalence :\t"<<((m.find(now))->second)<<endl;
		}else{
			cout<<"\nuser does not exits !\n";
		}
		break;
            default: cout<<"\nCHOOSE CORRECT OPTION\n";
        }
    }
    
    return 0;
}

