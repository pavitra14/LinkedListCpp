#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next = NULL;
  Node(int d)
  {
    this->data = d;
  }
};

Node* createList()
{
  Node* n1 = new Node(10);
  Node* n2 = new Node(20);
  Node* n3 = new Node(30);
  Node* n4 = new Node(40);
  Node* n5 = new Node(50);
  Node* n6 = new Node(60);
  Node* n7 = new Node(70);
  Node* n8 = new Node(80);
  Node* n9 = new Node(90);
  Node* n10 = new Node(100);
  Node* n11 = new Node(110);
  Node* n12 = new Node(120);
  Node* n13 = new Node(130);
  Node* n14 = new Node(140);
  Node* n15 = new Node(150);
  Node* n16 = new Node(160);
  Node* n17 = new Node(170);
  Node* n18 = new Node(180);
  Node* n19 = new Node(190);
  Node* n20 = new Node(200);
  Node* n21 = new Node(210);
  Node* n22 = new Node(220);
  Node* n23 = new Node(230);
  Node* n24 = new Node(240);
  Node* n25 = new Node(250);
  n1->next= n2;
  n2->next= n3;
  n3->next= n4;
  n4->next= n5;
  n5->next= n6;
  n6->next= n7;
  n7->next= n8;
  n8->next= n9;
  n9->next= n10;
  n10->next= n11;
  n11->next= n12;
  n12->next= n13;
  n13->next= n14;
  n14->next= n15;
  n15->next= n16;
  n16->next= n17;
  n17->next= n18;
  n18->next= n19;
  n19->next= n20;
  n20->next= n21;
  n21->next= n22;
  n22->next= n23;
  n23->next= n24;
  n24->next= n25;
  n25->next= NULL;
  return n1;
}

void displayList(Node* list)
{
  cout<<"----------------------------------"<<endl;
  Node* temp = list;
  while(temp->next != NULL)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<temp->data<<endl;
  cout<<"----------------------------------"<<endl;
}

int size(Node* list)
{
  int n=0;
  Node* temp = list;
  while(temp->next != NULL)
  {
    temp = temp->next;
    n++;
  }
  cout<<"Size of List is "<<n<<endl;
  return n;
}
void insert_at_last(Node* list, Node* node)
{
  Node* temp = list;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  node->next = NULL;
  temp->next = node;
}

Node* insert_at_first(Node* list, int d)
{
  Node* node = new Node(d);
  node->next = list;
  return node;
}

void insert_after_n(Node* list, Node* node, int n)
{
  Node* temp = list;
  int i=0;
  while(temp->next !=NULL && i!=n)
  {
    temp = temp->next;
    i++;
  }
  if(i!=n)
  {
    throw "LinkedList Overflow: N doesn't exist";
  }

  Node* forward = temp->next;
  temp->next = node;
  node->next = forward;
}

void remove_from_last(Node* list)
{
  Node* temp = list;
  while(temp->next->next!=NULL) {
    temp = temp->next;
  }
  temp->next = NULL;
}

void remove_n_from_last(Node* list, int n)
{
  Node* offset = list;
  Node* node = list;
  int i=0;
  while(offset->next != NULL && i!=n)
  {
    offset = offset->next;
    ++i;
  }
  if(i!=n)
  {
    throw "LinkedList Overflow: N doesn't exist";
  }
  while(offset->next!=NULL)
  {
    offset = offset->next;
    node = node->next;
  }
  Node* forward = node->next->next;
  node->next = forward;
}

Node* reverse_list(Node* list)
{
  Node* curr = list;
  Node* prev = NULL;
  while(curr != NULL)
  {
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

void middleNode(Node* list)
{
  Node* slow = list;
  Node* fast = list;
  while(fast !=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  cout<<"Middle Node is: "<<slow->data<<endl;
}

bool checkCycle(Node* list)
{
  Node* slow = list;
  Node* fast = list;
  while(fast!=NULL)
  {
    fast = fast->next;
    slow = slow->next;
    if(fast==NULL)
      break;
    fast = fast->next;
    if(slow == fast)
      return true;
  }
  return false;
}

int main() {
  // Creating a Linked List
  cout<<"Creating a LinkedList"<<endl;
  Node* LinkedList = createList();
  displayList(LinkedList);
  int s = size(LinkedList);

  // Inserting at end
  cout<<"Inserting at end"<<endl;
  insert_at_last(LinkedList, new Node(260));
  displayList(LinkedList);
  size(LinkedList);

  // Inserting at first
  cout<<"Inserting at first"<<endl;
  LinkedList = insert_at_first(LinkedList, 0);
  displayList(LinkedList);
  size(LinkedList);

  // Inserting after N
  cout<<"Inserting after n"<<endl;
  insert_after_n(LinkedList, new Node(99), 2);
  displayList(LinkedList);
  size(LinkedList);

  // Removing from last
  cout<<"Removing from Last"<<endl;
  remove_from_last(LinkedList);
  displayList(LinkedList);
  size(LinkedList);

  // Removing from n from last in 1Pass
  cout<<"Removing from n from last"<<endl;
  remove_n_from_last(LinkedList, 3);
  displayList(LinkedList);
  size(LinkedList);

  // Reversing a LinkedList
  cout<<"Reversing a LinkedList"<<endl;
  LinkedList = reverse_list(LinkedList);
  displayList(LinkedList);
  size(LinkedList);

  // middleNode of LinkedList in 1Pass
  cout<<"middleNode of LinkedList in 1Pass"<<endl;
  middleNode(LinkedList);
  displayList(LinkedList);
  size(LinkedList);

  // Check if List has a cycle
  Node* CyclicList = createList();
  Node* cTemp = CyclicList;
  while(cTemp->next != NULL)
  {
    cTemp = cTemp->next;
  }
  cTemp->next = CyclicList;
  cout<<"Cycle in List: "<<checkCycle(CyclicList)<<endl;

}