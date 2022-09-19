class SegmentTree
{
public:
    SegmentTree(int n)
    {
        this->n = n;
        this->tree = new int[4 * n];
        this->lazy = new int[4 * n];
        this->build(1, 0, n - 1);
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = 0;
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    void update(int node, int start, int end, int l, int r, int val)
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
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int query(int node, int start, int end, int l, int r)
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
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return (p1 + p2);
    }

private:
    int n;
    int *tree;
    int *lazy;
};
