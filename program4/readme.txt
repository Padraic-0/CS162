Name: Padraic Bergin
Description: This program allows the user to build a linked list of Nodes. These Nodes store a int value and point to another Node, meaning the get chained together.
The user can add a Node anywhere in the list, and then has the choice to sort accending or decending. These functions recursivily call for the Linked list to be split
in half, until each Node is its own " Linked list". Then in each recursivily called split function once the split function returns it begin to combine the Node into sorted order.
Problem: My merge function works if the right list is larger then the left list, but once the right side is smaller this problem occurs. The smaller value gets linked to the larger value
in the correct order, but once the merge function closes and goes back to the merge_sort the left head is still the larger value. I spent 8 hours trying to draw out where the logic was incorrect,
but i couldnt seem to find it. The left head isnt updated to become the right head the next time merge is called. This error causes those Nodes to be lost and unable to be cleared from memory, causing my mem leak :(
The decedning function has the oppositte error where if the right Node is larger it is lost.