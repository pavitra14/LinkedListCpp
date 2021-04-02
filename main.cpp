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

Node* createList(int n)
{
  //Creating Nodes
  vector<Node*> nodes; //Vector to store nodes temporarily
  for(auto i=1; i<=n; ++i)
  {
    nodes.push_back(new Node(i*10));
  }
  //Connecting individual nodes
  for(auto i=0; i<n; ++i)
  {
    nodes[i]->next = nodes[i+1];
  }
  return nodes[0];
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
  Node* LinkedList = createList(25);
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
  Node* CyclicList = createList(25);
  Node* cTemp = CyclicList;
  while(cTemp->next != NULL)
  {
    cTemp = cTemp->next;
  }
  cTemp->next = CyclicList;
  cout<<"Cycle in List: "<<checkCycle(CyclicList)<<endl;

}