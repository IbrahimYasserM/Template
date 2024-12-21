struct FastAccessTrie {
#define T int
    static constexpr short B = 10;
    struct node {
        node* a[B]{};
        T e=0;
    };
    node* root = new node();
    [[nodiscard]] T* get(int s) const {
        node *x = root;
        while(s){
            const short c = s%B;
            s /= B;
            if (x->a[c] == nullptr)
                x->a[c] = new node();
            x = x->a[c];
        }
        return &x->e;
    }
    [[nodiscard]] int count(int s) const {
        const node *x = root;
        while(s){
            const short c = s%B;
            s /= B;
            if (x->a[c] == nullptr)
                return 0;
            x = x->a[c];
        }
        return x->e;
    }
};
