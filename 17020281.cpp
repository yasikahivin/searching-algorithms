#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <list>
using namespace std;

int SIZE=100000;


class Hash{
public:
    list<int> *table ;

    //hash table constructor
    public:
        Hash(){
            table = new list<int>[SIZE];
        }
    //
    void insertItem(int key){
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    int hashFunction(int x) {
        return (x % SIZE);
    }

    void displayHash() {
        list <int> :: iterator j;
        for (int i = 0; i < SIZE; i++){
            cout << i;
            for (j = table[i].begin();j != table[i].end(); j++) {
                cout << "-->" << *j;
            }
            cout << endl;
        }
    }

    //search the vale in hash table and find the Target sums
    int hashSearch(int x){
        list <int> :: iterator j1;
        list <int> :: iterator j2;
        int p,q;
        for (int i = 0; i < SIZE; i++){
            for (j1 = table[i].begin();j1 != table[i].end(); j1++) {
               if(x>*j1){
                    int z=x-(*j1);
                        for (int i2 = z; i2 < SIZE; i2++){
                            for (j2 = table[i2].begin();j2 != table[i2].end(); j2++) {

                                if(*j2==z){
                                    return 1;
                                    break;
                                }
                            }
                        }
                    break;
                }
            }
        }return 0;
    }


};




int main(){
    string line;
    int arr[SIZE];
    int i = 0;


    ifstream MyReadFile("HashInt_For Q1.txt");

    while(getline(MyReadFile,line)){
        stringstream number(line);
        number>>arr[i];
        i++;
        if(i==SIZE)break;
    }

    Hash h;

    for( int i=0 ; i<SIZE ; i++ ){
        h.insertItem(arr[i]);
    }

    cout<<"+++++++++++++++Processing+++++++++++++++"<<"\n";

    //h.displayHash();
    //h.hashSearch(13);

    int x[9]={231552,234756,596873,648219,726312,981237,988331,1277361,1283379};


    for(int y =0;y<9;y++){
        if(h.hashSearch(x[y])>0){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }



    return 0;

}
