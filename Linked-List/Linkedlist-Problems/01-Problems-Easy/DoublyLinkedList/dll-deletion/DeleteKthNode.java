public class DeleteKthNode {
  private static void printDLL(Node head) {
    Node temp = head;
    while(temp != null) {
      System.out.print(temp.data + " ");
      temp = temp.next;
    }
    System.out.println();
  }

  // * Create DLL from array
  private static Node ConvertArrToDLL(int[] arr) {
    Node head = new Node(arr[0]);
    Node prev = head;
    for(int i=1; i<arr.length; i++){
      Node temp = new Node(arr[i], null, prev);
      prev.next = temp;
      prev = temp;
    }
    return head;
  }

  private static Node deleteHead(Node head) {
    if(head == null || head.next == null) return null;
    head = head.next;
    head.prev = null;
    return head;
  }

  // * Delete the tail
  private static void deleteTail(Node head) {
    Node temp = head;
    while(temp.next != null) {
      temp = temp.next;
    }
    Node prev = temp.prev;
    prev.next = null;
    temp.prev = null;
  }

  // * Delete the Head
  private static Node deleteKthNode(Node head, int k) {
    if(head == null) return null;
    if(head.next == null) return null;

    int c = 0;
    Node temp = head;
    while(temp.next != null) {
      c++;
      if(c == k) {
        break;
      }
      temp = temp.next;
    }

    Node back = temp.prev;
    Node front = temp.next;

    if(back == null && front == null) {
      return null;
    }
    else if(back == null) {
      // * Standing at head
      return deleteHead(head);
    } else if(front == null) {
      // * Standing at tail
      deleteTail(head);
      return head;
    }
    else {
      back.next = front;
      front.prev = back;
      temp.next = null;
      temp.prev = null;
      return head;
    }
  }

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    Node head = ConvertArrToDLL(arr);
    System.out.println("Before deleting Kth Node");
    printDLL(head);
    System.out.println("After deleting kth Node");
    head = deleteKthNode(head, 5);
    printDLL(head);
  }
}
