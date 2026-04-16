// Wisdom
// Time Complexity: O(Log(N))
struct Node{
    ll val = 0;
    Node* l = nullptr, *r = nullptr;
    Node(int val) : val(val) {}
};
ll merge(Node* a, Node* b){
    return (a == nullptr ? 0 : a->val) + (b == nullptr ? 0 : b->val);
}
ll query(int l, int r, Node* node, int s, int e){
    if(node == nullptr) return 0;
    if(s >= l && e <= r) return node->val;
    if(e < l || s > r) return 0;
    int mid = (s+e)/2;
    return query(l, r, node->l, s, mid) + query(l, r, node->r, mid+1, e);
}
void update(int idx, int val, Node* node, int s, int e){
    if(s == e){
        node->val = val;
        return;
    }
    int mid = (s+e)/2;
    if(idx <= mid){
        if(node->l == nullptr) node->l = new Node(0);
        update(idx, val, node->l, s, mid);
    }
    else{
        if(node->r == nullptr) node->r = new Node(0);
        update(idx, val, node->r, mid+1, e);
    }
    node->val = merge(node->l, node->r);
}