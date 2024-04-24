public class InsertHead {

  public static Node insertAtHead(Node head, int val) {
    Node newHead = new Node(val);

    if(head == null) return newHead;

    newHead.next = head;
    return newHead;
  }

  public static void main(String[] arg) {
    int[] arr = { 1,2,3,4,5 };

    System.out.println("Before Inserting in head");
    Node head = LinkedList.ConvertArrToLL(arr);
    LinkedList.printLL(head);
    
    System.out.println("After Inserting in head");
    head = insertAtHead(head, 0);
    LinkedList.printLL(head);
  }
}
