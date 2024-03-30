public class Node {
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