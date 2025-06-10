struct AdvancedTrie {
    static constexpr char B = 2;
    static constexpr char S = 32;
    ~AdvancedTrie() = default;
    struct node {
        node* a[B]{};
        int e=0;
    };
    node* root = new node();
    static std::string convert(int x) {
        std::string s;
        char cnt = 0;
        while (cnt++ < S) {
            s.push_back(x % B);
            x /= B;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    void add(const std::string& s) const {
        node* x = root;
        for (const auto c : s) {
            if (x->a[c] == nullptr)
                x->a[c] = new node();
            x = x->a[c];
        }
        ++x->e;
    }
    void add(const int s) const {
        add(convert(s));
    }
    [[nodiscard]] int count(const std::string& s) const {
        const node* x = root;
        for (const auto c : s) {
            if (x->a[c] == nullptr)
                return 0;
            x = x->a[c];
        }
        return x->e;
    }
    [[nodiscard]] int count(const int s) const {
        return count(convert(s));
    }
}
