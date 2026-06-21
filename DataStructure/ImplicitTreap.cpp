typedef struct item* pitem;

struct item {
    int prior, cnt{1}, value;
    bool rev{};
    pitem l{}, r{};

    item(int value) : prior(rand()), value(value) {}
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}
void upd(pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
    }
}

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        std::swap(it->l, it->r);

        if (it->l) it->l->rev ^= true;
        if (it->r) it->r->rev ^= true;
    }
}

void merge(pitem &t, pitem l, pitem r) {
    push(l);
    push(r);

    if (!l || !r) {
        t = l ? l : r;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }

    upd(t);
}

// split by position
// l = first key elements
// r = remaining elements
void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
    if (!t) {
        l = r = nullptr;
        return;
    }

    push(t);

    int cur_key = add + cnt(t->l);

    if (key <= cur_key) {
        split(t->l, l, t->l, key, add);
        r = t;
    } else {
        split(t->r, t->r, r, key, add + 1 + cnt(t->l));
        l = t;
    }

    upd(t);
}

// reverse range [l, r], 0-indexed
void reverse_range(pitem &t, int l, int r) {
    if (l > r) return;

    pitem t1, t2, t3;

    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);

    if (t2)
        t2->rev ^= true;

    merge(t, t1, t2);
    merge(t, t, t3);
}

//output in order from 0 to n-1
void output(pitem t) {
    if (!t) return;

    push(t);

    output(t->l);
    std::cout << t->value;
    output(t->r);
}

// insert value at position pos, 0-indexed
void insert(pitem &t, int pos, int value) {
    pitem t1, t2;

    split(t, t1, t2, pos); //t1 will contain [0:pos-1], t2 will contain [pos: n-1]

    auto new_node = new item(value);

    merge(t, t1, new_node); //t will contain [0:pos-1] + pos (new value)
    merge(t, t, t2); // t = old [0 : pos-1] + [new value] + old [pos : n-1]
}

// erase element at position pos, 0-indexed
void erase(pitem &t, int pos) {
    pitem t1, t2, t3;

    split(t, t1, t2, pos); //t1 will contain [0:pos-1],t2 will contain [pos: n-1]
    split(t2, t2, t3, 1); //t2 will contain [pos:pos], t3 will contain [pos+1: n-1]

    delete t2;

    merge(t, t1, t3); //t will contain [0:pos-1] + [pos+1: n-1]
}
