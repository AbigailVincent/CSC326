#ifndef BSTCHECKER_H
#define BSTCHECKER_H

// TODO: Include any needed header files
#include "BSTNode.h"
#include <iostream>
#include <queue>
#include <vector>
class BSTChecker {
public:
   // TODO: Add any desired utility functions
   static BSTNode* CheckBST(BSTNode *node){ //this checks left<root<right 
      if(node==nullptr) return nullptr; //emptyyyyyy

      //check left child
      if(node->left){
         if(node->left->key>=node->key){  //if left node is greater or equal that root
            return node->left; //returns problem 
         }
         BSTNode *wrong=CheckBST(node->left); //recursive check part
         if(wrong){
            return wrong; //if wrong return problem
         }
      }
      //check right child
      if(node->right){
         if(node->right->key>=node->key){  //if rightnode is greater or equal that root
            return node->right; //returns problem 
         }
         BSTNode *wrong2=CheckBST(node->right); //recursive check part
         if(wrong2){
            return wrong2; //if wrong return problem
         }
      }
      return nullptr; //no violations
   }

   static BSTNode* CheckDuplicates(BSTNode *root){//given 
    if (root == nullptr) {
      return nullptr;
    }
  
    std::queue<BSTNode*> q;
    q.push(root);
    std::vector <int> keys;//store
  
    while (!q.empty()) {
      BSTNode* current = q.front();
      q.pop();
  
      for(int i=0;i<keys.size();++i){
        if(keys[i]==current->key){
            return current; //duplicate found
        }
      }
        keys.push_back(current->key); //store current

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
   return nullptr;
  }

   static BSTNode* CheckBSTValidity(BSTNode* rootNode) {
      // TODO: Type your code here (remove placeholer line below)
      if(rootNode==nullptr){
         return nullptr; //empty
      }
      BSTNode *violation=CheckBST(rootNode);
      if(violation){
         return violation;
      }
      BSTNode *violations=CheckDuplicates(rootNode);
      if(violations){
         return violations;
      }
      return nullptr;
   }
};
/*OUTPUT:
Tree 1: PASS: CheckBSTValidity() returned the node with key 50
Tree 2: FAIL: CheckBSTValidity() returned the node with key 55, but should have returned the node with key 66
Tree 3: FAIL: CheckBSTValidity() returned the node with key 1132379, but should have returned nullptr since the tree is valid
Tree 4: FAIL: CheckBSTValidity() returned the node with key 37, but should have returned the node with key 75
Tree 5: FAIL: CheckBSTValidity() returned the node with key 33, but should have returned the node with key 44
Tree 6: FAIL: CheckBSTValidity() returned the node with key 10, but should have returned the node with key 13
Tree 7: FAIL: CheckBSTValidity() returned the node with key 180600, but should have returned nullptr since the tree is valid
Tree 8: FAIL: CheckBSTValidity() returned the node with key 1211712, but should have returned nullptr since the tree is valid
Tree 9: FAIL: CheckBSTValidity() returned the node with key 57, but should have returned the node with key 63
Tree 10: PASS: CheckBSTValidity() returned the node with key 25
*/
#endif
// CheckBSTValidty() determines if the tree is a valid BST. If so, nullptr
   // is returned. If not, the first (in preorder traversal) node in violation
   // of BST requirements is returned. Such a node will be one of the following:
   // - A node in the left subtree of an ancestor with a lesser or equal key
   // - A node in the right subtree of an ancestor with a greater or equal key
   // - A node that is encountered more than once during traversal