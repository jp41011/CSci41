Juan Pedraza
CSCI 41 - Project 1

Part 1 - Singly Linked List
	For this Singly Linked List (SLL) I created a NodeS, this is a node that only stores a char data and a NodeS* to the next node.
print() - [O(N)]
	To print I first get the pointer to the front of the list and then 	I iterator through the list printing out the data and then going to the next node in the list. I stop once the iteroator is equal to NULL, or end of the list.
findKthNodeFromBack() - [O(N)]
	For this fucntion I create 2 node pointers and I initalize them both to the front of the list. Then I move the 2nd iterator k spaces forward. From there I move both the 1st and 2nd iteroator one node at a time until the 2nd iterator (which is a head of the 1st by k spots) reaches the last node in the list. Then it mean that the 1st iterator is in the kth node from the back so I return it. If k is greater than the number of nodes in the list i exit early and return '~' (error)
Dupliate() - [O(N)]
	For this function I get a node pointer to the front of the list and iterator through the list until I get to the end. As I get to a node I create a new node with the same data as the one i am currently at and set the next pointer to the next of the node i am currently at. Then I change the next pointer of the current node to point to the new node I just created, that has the same data, and I go to the next next node (next of the newly created node, or 2 spaces infront of the current node)
deleteDuplicate() -[O(N^2)]
	I create 2 node pointers cur and prv they are both initialized to the front of the list. then while cur is not NULL (end of list) I go through the list and for each cur node I go through the rest of the list (forward) and look for duplicates deleteing each one i find and updateing prv along the way. I do this for every node in the list until cur gets to the end.

Part 2 - Doubly Linked List (DLL)
	For this I created a NodeD which is a node class that has a char data and 2 NodeD pointers, one for next and one for prev.
insertInOrder() - [O(N)]
	First I convert the new inserting char to uppercase (all letters will be uppercase in list). I create a node pointer 'it' pointing to the front of the list. if the list in not empty I iterator through the list comparing the new char to the current data value of 'it' if the new char is less than or equal to the data (letter) in 'it' then I have found the spot to place the new node. So I create the node getting the approriate next and prev pointers from the current 'it' and insert it into the list there. If I reach the end of the list then i insert the new node at the end of the list and update the tail node pointer.
deleteKthNode() - [O(N)]
	For this function I create a node pointer starting at the front of the list and i move it to the right (next direction) k nodes, using a for loop. after the loop the iterator is at the kth node so I update the next and prev pointers of the 2 nodes beside the kth node, so that they point to eachother and then i delete the kth node. I also have to make sure to check for special cases like if the kth node was the front or the end of the list, in which cases i have to update the front and tail node pointers for the DLL class.
shiftKNodes() - [O(N)]
	For this function I start off by making the list circular, I do this by making the tail's next point to the front and making the front's prev point to the tail. Then I use a for loop to move the front and tail pointers to the left k nodes. Then once that is finished I have to unbind the ends of the list by setting the front's prev pointer to null and setting the tail's next pointer to null.