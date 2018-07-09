#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::cin;
using std::cout;
//print last k lines of a file
void print_lines(std::string path,int k) {
   std::ifstream slowIn, fastIn;
   slowIn.open(path);
   fastIn.open(path);
   std::string s;
   if (fastIn.is_open()) {
      for (int i=0;i<k;i++) {
         getline(fastIn,s);
      }
   }
   if (slowIn.is_open()) {
      while (getline(fastIn,s)) {
         getline(slowIn,s);
      }
   }
   while (getline(slowIn,s)) {
      cout << s << std::endl;
   }
}
//reverse string
void reverse_string(std::string& str) {
   size_t len = str.size();
   char tmp;
   for (int i=0; i<len/2; i++) {
      tmp = str.at(len-i-1);
      str[len-i-1] = str[i];
      str[i] = tmp;
   }
}
//smart ptr
class ref_count {
   int ref_count_;
public:
   ref_count():ref_count_(0){};
   void increment(){ref_count_++;};
   void decrement(){ref_count_--;};
   int  get(){ return ref_count_;};
};
template <typename T>
class smart_ptr {
   T* ptr_;
   ref_count ref_count_;
public:
   smart_ptr():ptr_(nullptr), ref_count_(){};
   smart_ptr(T* ptr) {
      ptr_ = ptr;
      ref_count_ = new ref_count;
      ref_count_.increment();
   }
   ~smart_ptr() {
      ref_count_.decrement();
      if (!ref_count_.get()) {
         delete ptr_;
         ptr_=nullptr;
         ref_count_.decrement();
      }
   }
   smart_ptr(const smart_ptr& copy_obj) {
      ptr_ = copy_obj.ptr_;
      ref_count_ = copy_obj.ref_count_;
      ref_count_.increment();
   }
   smart_ptr& operator = (const smart_ptr& from) {
      if (*this == from) {
         return this;
      }
      ptr_ = from.ptr_;
      ref_count_=from.ref_count_;
      ref_count_.increment();
   }
};
// remove k to last in linked list
template <typename T>
struct node{
   T data;
   node* next;
};
template <typename T>
void remove_duplicate(node<T>* head) {
   node<T>* p1,p2,tmp;
   p1 = head;
   while (p1 != nullptr && p1->next!= nullptr) {
      p2 = p1;
      while (p2->next != nullptr){
         if (p1->data == p2->next->data) {
            tmp = p2->next;
            p2->next = tmp->next;
            delete tmp;
         }else{
            p2=p2->next;
         }
      }
      p1=p1->next;
   }
}
// find n th to last node
template <typename T>
node<T>* find_n_last(node<T>* head,int n) {
   node<T>* fast = head;
   node<T>* slow = head;
   int count = 0;
   for (int i=0; i<n; i++) {
      if (fast->next == nullptr) {
         break;
      }
      fast=fast->next;
    }
   if (count <=n) {
      return head;
   }
   while (fast->next != nullptr) {
      slow= slow->next;
      fast = fast->next;
   }
   return slow;
}
// find loop in linkedlist
template <typename T>
node<T>* find_loop(node<T>* head) {
   node<T>* slow = head;
   node<T>* fast= head;
   while (slow != nullptr && fast!=nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
         return slow;
      }
      
   }
   return nullptr;
}
// queue as 2 stacks
template <typename T>
class squeue {
   std::stack<T> new_;
   std::stack<T> old_;
public:
   squeue():new_(),old_(){};
   size_t size() { new_.size() + old_.size();};
   void push(T value) { new_.push(value);};
   void shift() {
      if (old_.empty()) {
         while (new_.empty());
         old_.push(new_.top());
         new_.pop();
      }
   }
   T front() {
      shift();
      return old_.top();
   }
   void dequeue() {
      shift();
      old_.pop();
   }
};
int main ()
{
   std::string s;
   std::cin >> s;
   reverse_string(s);
   std::cout<<s;
   
   return 0;
}

