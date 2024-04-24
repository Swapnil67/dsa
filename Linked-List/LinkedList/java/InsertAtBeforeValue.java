public class InsertAtBeforeValue {

  public static Node insertBeforeValue(Node head, int nodeVal, int val) {
    Node temp = head;
    Node prev = temp;

    if(temp.data == nodeVal) {
      // * Insert At Head
      Node newNode = new Node(val);
      newNode.next = head;
      return newNode;
    }

    while(temp != null) {
      if(temp.data == nodeVal) {
        Node newNode = new Node(val);
        prev.next = newNode;
        newNode.next = temp;
        break;
      }
      prev = temp;
      temp = temp.next;
    }
    return head; 
  }

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    Node head = LinkedList.ConvertArrToLL(arr);
    LinkedList.printLL(head);
    
    head = insertBeforeValue(head, 1, 0);
    LinkedList.printLL(head);

  }
}
