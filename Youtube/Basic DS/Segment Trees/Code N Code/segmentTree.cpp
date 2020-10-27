int buildTree(int si, int ss, int se)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return;
	}
	int mid = (ss + se) / 2;

	buildTree(2 * si, ss, mid);
	buildTree(2 * si + 1, mid + 1, se);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}
