struct Trie {
#define T int
    static constexpr char y = 'a';
    static constexpr char B = 26;
    struct node {
        node* a[B]{};
        int p=0, e=0;
    };
    node* root = new node();
    static std::string convert(int x) {
        std::string s;
        while (x) {
            s.push_back(static_cast<char>(x % B));
            x /= B;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
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
    [[nodiscard]] T* get(const int s) const {
        return get(convert(s));
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
    [[nodiscard]] int count(const int s) const {
        return count(convert(s));
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
