class Node {
  int data;
  Node next;
  Node prev;

  Node(int d) {
    this.data = d;
    this.next = null;
    this.prev = null;
  }

  Node(int d, Node n, Node p) {
    this.data = d;
    this.next = n;
    this.prev = p;
  }

}

public class DoublyLinkedList {
  
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

  public static void main(String[] args) {
    int[] arr = { 1,2,3,4,5 };
    Node head = ConvertArrToDLL(arr);
    System.out.println("Doubly Linked List In Java");
    printDLL(head);
  }

}
