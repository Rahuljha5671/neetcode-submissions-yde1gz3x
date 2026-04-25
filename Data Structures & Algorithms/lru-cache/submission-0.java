class LRUCache {

    int capacity;
    Map<Integer,Node>mp=new HashMap<>();;

    class Node{
        int key;
        int val;
        Node next;
        Node prev;

        public Node(int key,int val){
            this.key=key;
            this.val=val;
        }
    }

    Node head=new Node(-1,-1);
    Node tail=new Node(-1,-1);

    public void addNode(Node n){
        Node temp=head.next;
        head.next=n;
        n.prev=head;
        n.next=temp;
        temp.prev=n;
    }
    public void deleteNode(Node n){
        Node temp_prev=n.prev;
        Node temp_next=n.next;
        temp_prev.next=temp_next;
        temp_next.prev=temp_prev;
    }


    public LRUCache(int capacity) {
        this.capacity=capacity;
        head.next=tail;
        tail.prev=head;
    }
    
    public int get(int key) {
        if(mp.containsKey(key)){
            Node n=mp.get(key);
            int res=n.val;
            //delete from map
            mp.remove(key);
            //delete
            deleteNode(n);
            //add
            addNode(n);
            //add in map again
            mp.put(key,head.next);
            return res;
        }

        return -1;

        
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node n=mp.get(key);
            //delete from map
            mp.remove(key);
            //delete from dll
            deleteNode(n);
            //rest steps in common
        }
        if(mp.size()==capacity){
            Node n=tail.prev;
            deleteNode(n);
            mp.remove(n.key);
        }

        addNode(new Node(key,value));
        mp.put(key,head.next);
    }
}
