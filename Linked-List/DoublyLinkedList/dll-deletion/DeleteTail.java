public class DeleteTail {

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
    for(int i=1; i<arr.length; i++) {
      Node temp = new Node(arr[i], null, prev);
      prev.next = temp;
      prev = temp;
    }
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

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    Node head = ConvertArrToDLL(arr);
    System.out.println("Before deleting tail");
    printDLL(head);
    System.out.println("After deleting tail");
    deleteTail(head);
    printDLL(head);
  }
}
