Important Question and Algorithm for SDE Interview Preparation.

Important Data Structures : 

**Linked List :**
Linked lists can be thought of from a high level perspective as being a series of nodes. Each node has at least a single pointer to the next node, and in the last node’s case a null pointer representing that there are no more nodes in the linked list.

In DSA our implementations of linked lists always maintain head and tail pointers so that insertion at either the head or tail of the list is a constant time operation. Random insertion is excluded from this and will be a linear operation. As such, linked lists in DSA have the following characteristics:
1. Insertion is O(1)
2. Deletion is O(n)
3. Searching is O(n)
   
Out of the three operations the one that stands out is that of insertion. In DSA we chose to always maintain pointers (or more aptly references) to the node(s) at the head and tail of the linked list and so performing a traditional insertion to either the front or back of the linked list is an O(1) operation. An exception to this rule is performing an insertion before a node that is neither the head nor tail in a singly linked list. When the node we are inserting before is somewhere in the middle of the linked list (known as random insertion) the complexity is O(n). In order to add before the designated node we need to traverse the linked list to find that node’s current predecessor. This traversal yields an O(n) run time.
This data structure is trivial, but linked lists have a few key points which at times make them very attractive:
1. the list is dynamically resized, thus it incurs no copy penalty like an array or vector would eventually incur; and
2. insertion is O(1).
**Types of Linked List : **
**Singly Linked List**
Singly linked lists are one of the most primitive data structures you will find in this book. Each node that makes up a singly linked list consists of a value, and a reference to the next node (if any) in the list.
