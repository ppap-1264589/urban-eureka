#include <bits/stdc++.h>
#define maxn 100005
#define maxb 200005
#define F first
#define S second

using namespace std;

struct data
{
    int id,from, to;
    data (int _id = 0, int _from = 0, int _to = 0)
    {
        id = _id;
        from = _from;
        to = _to;
    }
};

int m, n, k, slngang, sldoc,  lng = 0, ld = 0;
data ngang[maxn], doc[maxn];
int BIT[maxb + 2];
int xngang[2*maxn], xdoc[2*maxn];
long long ans = 0;
pair <pair <int, int>, int> l[2*maxn];

void Input()
{
    scanf("%d%d%d", &m, &n, &k);
    int x,y;
    char ch;
    slngang = sldoc = 0;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d", &x, &y);
        cin >> ch;
        xngang[++lng] = x;        
        switch (ch)
        {
            case 'E': ngang[++slngang] = data(x, y, n); break;
            case 'W': ngang[++slngang] = data(x, 1, y); break;
            case 'N': doc[++sldoc] = data(y, x, m); break;
            case 'S': doc[++sldoc] = data(y, 1, x); break;
        };
    }
    xngang[++lng] = m;
    xngang[++lng] = 1;
}



bool cp(data p, data q)
{
    if (p.id != q.id ) return (p.id < q.id);
    if (p.from != q.from ) return (p.from < q.from);
    return p.to < q.to;
}

void Prepare(data a[], int &sl)
{
    sort(a + 1, a + sl + 1, cp);
    a[sl+1].id = a[sl].id + 1;
    data doan = a[1];
    int u = 0;
    for (int i = 2; i <= sl+1; i++)
        if (a[i].id == doan.id && a[i].from <= doan.to + 1) doan.to = a[i].to;
        else
        {
            a[++u] = doan;
            doan = a[i];
        }
    sl = u;
    for (int i = 1; i <= u; i++) ans += a[i].to - a[i].from + 1;
}

void Make_Point()
{
    int sl = 0;
    for (int i = 1; i <= slngang; i++)
    {
        l[++sl] = make_pair(make_pair (ngang[i].from, ngang[i].id ), 1);
        l[++sl] = make_pair(make_pair (ngang[i].to+1, ngang[i].id ), -1);
    }
    l[++sl] = make_pair( make_pair(n+2, 0), 0);
    sort (l+1, l+sl+1);
}

void Update( int x, int val)
{
    for (; x <= maxb; x += (x & (-x)))
        BIT[x] += val;
}

int Count (int x)
{
    int an = 0;
    for (; x ; x &= (x-1)) an += BIT[x];
    return an;
}

int pos (int x)
{
    return lower_bound(xngang +1, xngang + lng + 1, x) - xngang;
}

void Calc()
{
    Make_Point();
    sort(xngang + 1, xngang + lng + 1);
    int j = 1;
    for (int i = 1; i <= sldoc ; i++)
    {
        data doan = doc[i];
        while (l[j].F.F <= doan.id)
        {
            Update(pos(l[j].F.S), l[j].second);
            j++;
        }
        ans -= Count(pos(doan.to)) - Count(pos(doan.from) - 1);
    }
}


int main()
{
    //freopen("robot.inp", "r", stdin);
	//freopen("robot.out", "w", stdout);
    Input();
   // Normalize();
    Prepare(ngang,slngang);
    Prepare(doc, sldoc);
    Calc();
    cout << ans;
    return 0;
}
