/*
Asked in Paytm
Problem of the Day: Quick Sort on Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/quick-sort-on-linked-list-geeksforgeeks-solution-28f28510d6ee
*/

class Solution {
  public:
    Node* quickSort(Node* head) {
        if (!head || !head->next)
            return head;
        
        Node* newHead = nullptr;
        Node* newEnd = nullptr;
        
        return quickSortRecur(head, getTail(head));
    }

  private:
    Node* getTail(Node* node) {
        while (node != nullptr && node->next != nullptr)
            node = node->next;
        return node;
    }

    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end)
            return head;
        
        Node* newHead = nullptr;
        Node* newEnd = nullptr;

        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quickSortRecur(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr, *cur = head, *tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if ((*newHead) == nullptr)
                    (*newHead) = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* temp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }

        if ((*newHead) == nullptr)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }
};
