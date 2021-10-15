typedef LinkedListNode* NodePtr;

NodePtr merge_sorted(NodePtr head1, NodePtr head2) {
  
  // if both lists are empty then merged list is also empty
  // if one of the lists is empty then other is the merged list
  if (head1 == nullptr) {
    return head2;
  } else if (head2 == nullptr) {
    return head1;
  }


  NodePtr mergedHead = nullptr;
  if (head1->data <= head2->data) {
    mergedHead = head1;
    head1 = head1->next;
  } else {
    mergedHead = head2;
    head2 = head2->next;
  }

  NodePtr mergedTail = mergedHead;
  
  while (head1 != nullptr && head2 != nullptr) {
    NodePtr temp = nullptr;
    if (head1->data <= head2->data) {
      temp = head1;
      head1 = head1->next;
    } else {
      temp = head2;
      head2 = head2->next;
    }

    mergedTail->next = temp;
    mergedTail = temp;
  }

  if (head1 != nullptr) {
    mergedTail->next = head1;
  } else if (head2 != nullptr) {
    mergedTail->next = head2;
  }

  return mergedHead;
}

void test(vector<int>& v1, vector<int>& v2, vector<int>& expected) {
  LinkedListNode* list_head1 = LinkedList::create_linked_list(v1);
  
  cout<<"List 1: "<<LinkedList::getList(list_head1)<<endl;

  LinkedListNode* list_head2 = LinkedList::create_linked_list(v2);
  
  cout<<"List 2: "<<LinkedList::getList(list_head2)<<endl;

  LinkedListNode* merged = merge_sorted(list_head1, list_head2);
  
  cout<<"Result: "<<LinkedList::getList(merged)<<endl;

  LinkedListNode* expected_list = LinkedList::create_linked_list(expected);
  

  assert(LinkedList::is_equal(merged, expected_list));
}

int main(int argc, char* argv[]) {

  vector<int> v1 = {1, 3, 5, 6};
  vector<int> v2 = {2, 4, 6, 20, 34};
  vector<int> expected = {1, 2, 3, 4, 5, 6, 6, 20, 34};

  test(v1, v2, expected);

  v1 = {1, 3, 5, 6};
  v2 = {};
  expected = {1, 3, 5, 6};

  test(v1, v2, expected);

  v1 = {1, 3, 5, 6};
  v2 = {2, 4, 6, 20};
  expected = {1, 2, 3, 4, 5, 6, 6, 20};

  test(v1, v2, expected);
  v1 = {4, 4};
  v2 = {4, 4, 4};
  expected = {4, 4, 4, 4 ,4};

  test(v1, v2, expected);
}
