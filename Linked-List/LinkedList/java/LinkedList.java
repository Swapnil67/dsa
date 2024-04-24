public class LinkedList {

  public static Node ConvertArrToLL(int[] arr) {
    if(arr.length == 0) return null;
    Node head = new Node(arr[0]);
    Node mover = head;
    for(int i=1; i<arr.length; i++) {
      Node newNode = new Node(arr[i]);
      mover.next = newNode;
      mover = newNode;
    }
    return head;
  }

  public static void printLL(Node head) {
    Node temp = head;
    while(temp != null) {
      System.out.print(temp.data+" ");
      temp = temp.next;
    }
    System.out.println();
  }

  public static void main(String[] args) {
    System.out.println("Linked List in java");
    int[] arr = { 1,2,3,4,5 };
    Node head = ConvertArrToLL(arr);
    printLL(head);
  }  
}
