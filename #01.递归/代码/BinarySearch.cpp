int BinarySearch(int *a, int x, int l, int r)
{
    int mid = (l+r)/2;
    if(x == a[mid]) return mid;
    else if(l == r && a[mid] == x) return -1;    // 没有找到
    else if(x > a[mid]) BinarySearch(a, x, mid, r);
    else if(x < a[mid]) BinarySearch(a, x, l, mid);
}