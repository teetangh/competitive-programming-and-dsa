int query(int si, int ss, int se, int qs, int qe)
{
	if (qs > se || qe < ss) // Completely Outside
		return INF;

	if (ss >= qs && qe >= se) // Completely Inside
		return st[si];

	int mid = (ss + se) / 2;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);

	return min(l, r);
}
