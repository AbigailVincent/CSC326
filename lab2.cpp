#include <iostream>
using namespace std;
struct Commit{
int hash;       //random num 
string message; //comment on commit
Commit* next;       //ptr -> next commit
Commit(int h, const std::string& msg) : hash(h), message(msg),
next(nullptr) {}    //consturctor to commit with random num with message easily
};
class CommitHistory {
    private:
    Commit* head;   //head of linked list
    public:
    CommitHistory() : head(nullptr) {}//consturctor making everything empty
    void commit(const std::string& message){ // append new node at end
  int hash=rand()%1000; //generate random number 0-999
  Commit *newCommit=new Commit(hash,message); //creating new node/commit with has and message
  if(!head){ //if empty
    head=newCommit;
  }else{//going to last node/commit
    Commit* current=head;
    while(current->next){
        current=current->next; //traversing
    }
    current->next=newCommit; //current is at last node it adds new node  at end
  }
  cout<<"Commited: "<<message<<"hash: "<<hash<<"\n";
    }
    void log() const{// display all
        Commit* current=head;
        while(current){
            cout<<current->message<<"["<<current->hash<<"]";
            if(current->next){
                cout<<"<-";
            }
            current=current->next;
        }
        cout<<endl;
        }
    void reset(){ // delete last commit/node
    if(!head) return; //if empty return
    if(!head->next){
        delete head;
    head=nullptr;
    cout<<"last commit deleted! \n";
    return;
    }
     Commit *current=head;
    while(current->next && current->next->next){//turtle and rabbit goes to second to last
    current=current->next;
    }
     delete current->next;//deletes last node
    current->next=nullptr;//fixes ptr
    cout<<"last commit deleted! \n";
    }
    static CommitHistory merge(const CommitHistory& branch1, const CommitHistory& branch2){//merge commit histories into new one
        CommitHistory merge; //storage
        //branch 1
        Commit* current1=branch1.head;
        //copy each node/commit into merge
        while(current1){
            merge.commit(current1->message);
            current1=current1->next;
        }
        Commit* current2=branch2.head;
        //copy each node/commit into merge
        while(current2){
            merge.commit(current2->message);
            current2=current2->next;
        }
        cout<<"Branches merged!!!! \n";
        return merge; //returns combined form of branch 1 and 2

    }
    ~CommitHistory(){// deconstuctor
        while(head){
            Commit *temp=head;
            head=head->next;
            delete temp;
        }
    }

};

    int main() {
        srand(time(0)); // For random hash generation
        CommitHistory master; //branch "master"
        master.commit("Initial commit");
        master.commit("Add README");
        master.commit("Implement login system");
        CommitHistory featureBranch; //branch "feature"
        featureBranch.commit("Start feature X");
        featureBranch.commit("Fix bug in feature X");
        cout << "\n== Master Branch =="; //both branches
        master.log();
        cout << "\n== Feature Branch ==";
        featureBranch.log();
        cout << "\n== Reset last commit on master =="; //reset 
        master.reset();
        master.log();
        cout << "\n== Merged History ==";//merge master and feature
CommitHistory merged = CommitHistory::merge(master, featureBranch);
merged.reset();
merged.log();
std::cout << "\n== Master Branch Unchanged after merge==";//show they're unchanged
master.log();
std::cout << "\n== Feature Branch Unchanged after merge==";
featureBranch.log();
return 0;
    }
    /* OUTPUT:
    Commited: Initial commithash: 310
Commited: Add READMEhash: 669
Commited: Implement login systemhash: 243
Commited: Start feature Xhash: 106
Commited: Fix bug in feature Xhash: 747

== Master Branch ==Initial commit[310]<-Add README[669]<-Implement login system[243]

== Feature Branch ==Start feature X[106]<-Fix bug in feature X[747]

== Reset last commit on master ==last commit deleted! 
Initial commit[310]<-Add README[669]

== Merged History ==Commited: Initial commithash: 414
Commited: Add READMEhash: 870
Commited: Start feature Xhash: 440
Commited: Fix bug in feature Xhash: 341
Branches merged!!!! 
last commit deleted! 
Initial commit[414]<-Add README[870]<-Start feature X[440]

== Master Branch Unchanged after merge==Initial commit[310]<-Add README[669]

== Feature Branch Unchanged after merge==Start feature X[106]<-Fix bug in feature X[747]

    */