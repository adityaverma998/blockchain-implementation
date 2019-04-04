#include <iostream>
#include <string>
#include <functional>

using namespace std;

struct node{
    int prevhash;
    int hash;
    string transinfo;
};
int n;
struct node a[10000];
int users = 0;
class nodesinnetwork {
	public :

	struct node b[10000];
	void broadcast(){
		for(int i=0;i<n;i++){
			b[i].prevhash = a[i].prevhash;
			b[i].hash = a[i].hash;
			b[i].transinfo = a[i].transinfo;
		}		
	}
	void print(){
		cout<<"\nFor this node in network blockchain is : \n";
		for(int i=0;i<n;i++){
			cout<<"\nBlock Number : "<<i<<"\nprevhash : "<<a[i].prevhash<<"\tblock hash : "<<a[i].hash<<"\tmerkle root value : "<<a[i].transinfo<<"\n";	
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
        cout<<"\nMENU\n1.INSERT NEW BLOCK\n2.PRINT WHOLE BLOCKCHAIN\n3.ADD NODE IN NETWORK & MAKE IT CONSISTENT WITH NETWORK BLOCKCHAIN\n4.PRINT BLOCKCHAIN AT SPECIFIC NODE\n5.EXIT\n";
        int option;
        cin>>option;
	int index1;
	nodesinnetwork * ptr;
        switch(option){
            case 1:
                
		
                a[index].prevhash = prev;
                cout<<"\nenter merkle root value : \n";
                cin>>s;
		cout<<"info entered!\n";
                a[index].transinfo = s;
                a[index].hash = (int) hasher(a[index].transinfo + to_string(a[index].prevhash));
                prev = a[index].hash;
		++index;
		n = index;
                break;
            case 2:
		for(int i=0;i<100;i++){
			cout<<"-";
		}
                for(int i=0;i<index;i++){
                    cout<<"\nBlock Number : "<<i<<"\nprevhash : "<<a[i].prevhash<<"\tblock hash : "<<a[i].hash<<"\tmerkle root value : "<<a[i].transinfo<<"\n";
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
	    
            default: cout<<"\nCHOOSE CORRECT OPTION\n";
        }
    }
    
    return 0;
}

