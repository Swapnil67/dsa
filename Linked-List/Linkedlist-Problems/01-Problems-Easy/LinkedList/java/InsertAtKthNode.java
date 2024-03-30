public class InsertAtKthNode {

  public static Node insertAtKthNode(Node head, int k, int val) {
    Node newNode = new Node(val);
    if(head == null) {
      if(k == 1) {
        return newNode;
      }
    }

    int c = 0;
    Node temp = head;
    while(temp != null) {
      c++;
      if(c == k-1) {
        newNode.next = temp.next;
        temp.next = newNode;
        break;
      }
      temp = temp.next;
    }

    return head;
  }

  public static void main(String[] arg) {
    int[] arr = { 1,2,3,4,5 };

    System.out.println("Before Inserting in head");
    Node head = LinkedList.ConvertArrToLL(arr);
    LinkedList.printLL(head);
    
    System.out.println("After Inserting in head");
    head = insertAtKthNode(head, 6, 10);
    LinkedList.printLL(head);
  }
}
