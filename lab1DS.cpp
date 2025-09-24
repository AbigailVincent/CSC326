#include <iostream>
#include <fstream> //header for ifstream
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;
class Bag{
 public:
string bakeryCollection;
string bakedGoods[20]; //array with 20 MAX
int numItems;          //keep track of number of items 
Bag(string n){         //constructor sets collectionName and amount of items as 0
    bakeryCollection=n;
    numItems=0;
}
void add(string i){     //adds items to array
    if(numItems<20){ //making sure a new item is added if there is room because array is fixed
        bakedGoods[numItems]=i;
        numItems++;
    }
}
void displayAll(){ 
    for(int i=0;i<numItems;i++){ 
        cout<<bakedGoods[i]<<endl;
    }
}
void searchMethod(string input){
    cout<<"______________________"<<endl;
    if(input.length()<3){       //case 1:displays all items if  it's less than 3
        displayAll();
    }else{
 bool success=false;        //variable to make sure we got at least one match
for(int  i=0;i<numItems;i++){       
    string n=bakedGoods[i];
    bool same=true;
    for(int k=0;k<input.length();k++){  //compare user input with begining of current word
        if( n[k]!=input[k]){ //implemented so if it's false it  stops checking
            same=false;
            break;
        }
    }
    if(same){       //if match is true it will print word
        cout<<n<<endl;
        success=true;
    }
}
}
cout<<"______________________"<<endl;
}
    };    

int main(){
//opening text file
    ifstream in;
    in.open("dogsL1.txt");
    if(!in.is_open()) {
        cout<<"unable to open txt file. "<<endl;
        return 1;
    }
Bag mybag("Abby's Bakery"); //intilaizing Bag object and using the constructor 

string l;   //adding items from txt file
while(in>>l){
    mybag.add(l);

}

//printing options first:
cout<<"______________________"<<endl;
cout<<"| "<<setw(20)<<"Options Avaliable: "<<" |"<<endl;
for(int i=0;i<mybag.numItems;i++){
    cout<<"| "<<setw(20)<<mybag.bakedGoods[i]<<" |"<<endl;
}
cout<<"______________________"<<endl;
cout<<"Enter NO to stop search"<<endl;

string input;
while(true){ //will continue unless No typed
    cout<<"Search: "<<endl;
    //input=getchar();
    getline(cin,input);
    if(input=="NO")  break;//exit
    mybag.searchMethod(input);
}
    //end of main
    return 0;
}

/*OUTPUT:
______________________
|  Options Avaliable:  |
|            Crossiant |
|                Bagel |
|                 Cake |
|              Cupcake |
|              Pudding |
|               Gelato |
|              Brownie |
|              Brookie |
______________________
Enter NO to stop search
Search: 
Br
______________________
Crossiant
Bagel
Cake
Cupcake
Pudding
Gelato
Brownie
Brookie
______________________
Search: 
Bro
______________________
Brownie
Brookie
______________________
Search: 
Brow
______________________
Brownie
______________________
Search: 
NO

*/