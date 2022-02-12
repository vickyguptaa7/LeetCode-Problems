class MyLinkedList {
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *head = NULL;
int l=0;
public:
    MyLinkedList() {

    }

int get(int index) {
    if(head==NULL || index>=l)
        return -1;
    
     ListNode *temp = head,*prev = NULL;
    while(temp!=NULL&&index--){
        prev=temp;
        temp=temp->next;
    }
    return temp==NULL?prev->val:temp->val;
}

void addAtHead(int val) {
     ListNode *newnode = new  ListNode(val);
    newnode->next = head;
    head = newnode;
    l++;
}

void addAtTail(int val) {
    l++;
     ListNode *newnode = new  ListNode(val);
     if(head==NULL){
         head = newnode;
         return;
     }
      ListNode *temp = head;
      while(temp->next!=NULL)
          temp = temp->next;
    temp->next = newnode;
}

void addAtIndex(int index, int val) {
    if(index>l || (index>0&&head==NULL))    return;
    l++;
    ListNode *newnode = new ListNode(val);
    if(index==0){
         newnode->next = head;
         head = newnode;
         return;
    }
     ListNode *temp = head,*prev = NULL;
    while(temp!=NULL&&index--){
        prev=temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
}

void deleteAtIndex(int index) {
    if(index>=l || head==NULL)
        return;
    l--;
    if(index==0){
        head = head->next;
        return;
    }
    ListNode *temp = head,*prev = NULL;
    while(temp!=NULL&&index--){
        prev=temp;
        temp=temp->next;
    }
    temp==NULL?prev->next=NULL:prev->next=temp->next;
}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */