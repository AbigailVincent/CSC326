#include <iostream>     //step 1: headers
#include<map>
#include<unordered_map>
#include <string>
#include <sstream> 
using namespace std;

int main(){
//Part one:country w population
    unordered_map<string,int>population;    //step 2: created hashmap 
    population["Canada"]=1000;        //step 3: add countries w populations
    population["Mexico"]=200;  
    population["Italy"]=300;  
    population["China"]=50000;  
    population["Korea"]=200;  
for(const auto& pair:population){ //step 4: printing it countries n populations
    cout<<"Country: "<<pair.first<<" Population: "<<pair.second<<endl;
}
/*Country: Korea Population: 200
Country: China Population: 50000
Country: Italy Population: 300
Country: Mexico Population: 200
Country: Canada Population: 1000*/
string input;
cout<<"Enter a country (Canada/Mexico/Italy/China/Korea): "<<endl; //step 5: searching based on user input
cin>>input;
for(const auto& pair:population){ //step 4: printing it countries n populations
   if(pair.first==input){
    cout<<"FOUND BOOM!!!"<<endl;
   }
}

//Part two:frequency counter:
unordered_map<string,int>count;
string line;
cout<<"Enter a sentence: "<<endl;   //step 1:get text input from user
cin.ignore();
getline(cin,line);
istringstream iss(line);
string word;
while(iss >> word){
count[word]++;
}
cout<<"frequencies"<<endl;
for(const auto& pair:count){ 
    cout<<pair.first<<"   "<<pair.second<<endl;
}
}
/*OUTPUT Country: 
Korea Population: 200
Country: China Population: 50000
Country: Italy Population: 300
Country: Mexico Population: 200
Country: Canada Population: 1000
Enter a country (Canada/Mexico/Italy/China/Korea): 
FOUND BOOM!!!
Enter a sentence: 
frequencies
but   1
you   4 */