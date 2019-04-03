#include <iostream>
#include <string>
#include <functional>

using namespace std;

struct node{
    int prevhash;
    int hash;
    string transinfo;
};

int main()
{
    std::hash<std::string> hasher;
    printf("\nIMPLEMENTING BLOCKCHAIN\n");
    
    struct node a[10000];
    
    a[0].prevhash = 0;
    a[0].transinfo = "demo-merkle-root";
    a[0].hash = (int) hasher(a[0].transinfo + to_string(a[0].prevhash));
    int prev = a[0].hash;
    int index = 0;
    string s;
    
    while(1){
        cout<<"\nMENU\n1.INSERT NEW BLOCK\n2.PRINT WHOLE BLOCKCHAIN\n3.EXIT\n";
        int option;
        cin>>option;
        switch(option){
            case 1:
                ++index;
                a[index].prevhash = prev;
                cout<<"\nenter merkle root value : \n";
                cin>>s;
		cout<<"info entered!\n";
                a[index].transinfo = s;
                a[index].hash = (int) hasher(a[index].transinfo + to_string(a[index].prevhash));
                prev = a[index].hash;
                break;
            case 2:
		for(int i=0;i<100;i++){
			cout<<"-";
		}
                for(int i=0;i<=index;i++){
                    cout<<"\nBlock Number : "<<i<<"\nprevhash : "<<a[i].prevhash<<"\tblock hash : "<<a[i].hash<<"\tmerkle root value : "<<a[i].transinfo<<"\n";
                	cout<<"\n|\n";
		}
		for(int i=0;i<100;i++){
			cout<<"-";
		}
                break;
            case 3:exit(0);
            default: cout<<"\nCHOOSE CORRECT OPTION\n";
        }
    }
    
    return 0;
}
