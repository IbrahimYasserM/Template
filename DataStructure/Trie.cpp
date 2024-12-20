struct Trie {
#define y 'a'
#define B 26
    struct node {
        node* a[B]{};
        int p=0, e=0;
    };
    node* root = new node();
    static std::string convert(int x) {
        std::string s;
        while (x) {
            s += std::to_string(x%B);
            x /= B;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
    void insert(const std::string& s) const {
        node* x = root;
        for (const auto c : s) {
            if (x->a[c-y] == nullptr)
                x->a[c-y] = new node();
            x->p++;
            x = x->a[c-y];
        }
        x->e++;
    }
    void insert(const int s) const {
        insert(convert(s));
    }
    [[nodiscard]] int search(const std::string& s) const {
        const node* x = root;
        for (const auto c : s) {
            if (x->a[c-y] == nullptr)
                return 0;
            x = x->a[c-y];
        }
        return x->e;
    }
    [[nodiscard]] int search(const int s) const {
        return search(convert(s));
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
    [[nodiscard]] int prefix(const int s) const {
        return prefix(convert(s));
    }
};
