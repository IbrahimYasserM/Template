struct Trie {
#define T int
    static constexpr char y = 'a';
    static constexpr char B = 26;
    struct node {
        node* a[B]{};
        int p=0, e=0;
    };
    node* root = new node();
    [[nodiscard]] T* get(const std::string& s) const {
        node* x = root;
        for (const auto c : s) {
            if (x->a[c-y] == nullptr)
                x->a[c-y] = new node();
            x->p++;
            x = x->a[c-y];
        }
        return &x->e;
    }
    [[nodiscard]] int count(const std::string& s) const {
        const node* x = root;
        for (const auto c : s) {
            if (x->a[c-y] == nullptr)
                return 0;
            x = x->a[c-y];
        }
        return x->e;
    }
    [[nodiscard]] int prefix(const std::string& s) const {
        const node* x = root;
        for (const auto c : s) {
            if (x->a[c-y] == nullptr)
                return 0;
            x = x->a[c-y];
        }
        return x->e + x->p;
    }
};
