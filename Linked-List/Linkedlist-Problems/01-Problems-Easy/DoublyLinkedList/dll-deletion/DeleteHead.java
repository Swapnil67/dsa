public class DeleteHead {
    
  private static void printDLL(Node head) {
    Node temp = head;
    while(temp != null) {
      System.out.println(temp.data + " ");
      temp = temp.next;
    }
    System.out.println();
  }

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
    if(head == null) return null;
    if(head.next == null) return null;

    Node prev = head;
    head = head.next;
    head.prev = null;
    prev.next = null;
    
    return head;
   }

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    Node head = ConvertArrToDLL(arr);
    System.out.println("Before deleting head");
    printDLL(head);
    System.out.println("After deleting head");
    head = deleteHead(head);
    printDLL(head);
  }
} 
