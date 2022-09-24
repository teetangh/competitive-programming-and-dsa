template <typename T>
class SegmentTree
{
public:
    SegmentTree(T n)
    {
        this->n = n;
        this->tree = new T[4 * n];
        this->lazy = new T[4 * n];
        this->build(1, 0, n - 1);
    }
    void build(T node, T start, T end)
    {
        if (start == end)
        {
            tree[node] = 0;
        }
        else
        {
            T mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    void update(T node, T start, T end, T l, T r, T val)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            tree[node] += (end - start + 1) * val;
            if (start != end)
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        T mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    T query(T node, T start, T end, T l, T r)
    {
        if (start > end || start > r || end < l)
            return 0;
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start >= l && end <= r)
            return tree[node];
        T mid = (start + end) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return (p1 + p2);
    }

private:
    T n;
    T *tree;
    T *lazy;
};
