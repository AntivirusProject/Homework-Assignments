package lists;

public class SingleLinkList {

	Node head;
	int size;
	
	class Node{
		int data;
		Node next;
		
		public Node(int d){		
			data = d;
			next = null;
		
			}
		}
	
	public SingleLinkList(){
		head = null;
		size = 0;
	}
	
	public void add(int d){
		Node newNode = new Node(d);
		if(isEmpty()){
			head = newNode;
		}
		else{
			newNode.next = head;
			head = newNode;
		}
			
		size++;
	}
	
	public void remove(){
		
	}
	public int size(){
		return size;
	}
	public boolean isEmpty(){
		if(size == 0){
			return true;
		}
		else{
			return false;
		}
		
		
	}
	
	
}
