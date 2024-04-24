public class InsertTail {

  public static Node insertAtTail(Node head, int val) {
    Node newNode = new Node(val);
    if(head == null) {
      return newNode;
    }

    if(head.next == null) {
      head.next = newNode;
      return head;
    }

    Node temp = head;
    while(temp.next != null) {
      temp = temp.next;
    }
    temp.next = newNode;
    return head;
  }

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    
    System.out.println("Before Inserting in Tail");
    Node head = LinkedList.ConvertArrToLL(arr);
    LinkedList.printLL(head);
       
    System.out.println("After Inserting in Tail");
    head = insertAtTail(head, 6);
    LinkedList.printLL(head);
  }
}
