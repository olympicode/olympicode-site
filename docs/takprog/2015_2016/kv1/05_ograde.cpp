#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 100000;
const int MAXQ = 100000;

int sign(long long x)
{
    if (x == 0)
    {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

bool intersects(pair<int, pair<int, int>> segment, long long x1, long long y1, long long x2, long long y2)
{
    if (x1 < x2 && (segment.first < x1 || segment.first > x2))
    {
        return false;
    }
    if (x2 < x1 && (segment.first < x2 || segment.first > x1))
    {
        return false;
    }
    int sign1 = sign((y2 - y1) * (segment.first - x1) - (segment.second.first - y1) * (x2 - x1));
    int sign2 = sign((y2 - y1) * (segment.first - x1) - (segment.second.second - y1) * (x2 - x1));
    return sign1 != sign2;
}

int main(int argc, char *argv[])
{
    string inFileName = argv[1];
    string outFileName = inFileName.substr(0, inFileName.length() - 3) + ".out";
    fstream ifs, ofs;
    ifs.open(inFileName, fstream::in);
    ofs.open(outFileName, fstream::out);
    int n;
    ifs >> n;
    int x[MAXN], y[MAXN];
    pair<int, pair<int, int>> segments[MAXQ];
    int st = 0, ed = 0;
    for (int i = 0; i < n; i++)
    {
        ifs >> x[i] >> y[i];
        if (x[i] < x[st])
        {
            st = i;
        }
        if (x[i] > x[ed])
        {
            ed = i;
        }
    }
    int q;
    ifs >> q;
    for (int i = 0; i < q; i++)
    {
        ifs >> segments[i].first >> segments[i].second.first >> segments[i].second.second;
    }
    sort(segments, segments + q);
    int ret = 0;
    for (int i = st, idx = 0, save = 0; i != ed; i = (i + 1) % n)
    {
        int j = (i + 1) % n;
        int valid = save;
        save = 0;
        while (segments[idx].first <= x[j])
        {
            if (idx < q && intersects(segments[idx], x[i], y[i], x[j], y[j]))
            {
                if (segments[idx].first == x[j])
                {
                    save = 1;
                }
                valid = 1;
            }
            idx++;
        }
        ret += valid;
    }
    for (int i = ed, idx = q - 1, save = 0; i != st; i = (i + 1) % n)
    {
        int j = (i + 1) % n;
        int valid = save;
        save = 0;
        while (idx >= 0 && segments[idx].first >= x[j])
        {
            if (intersects(segments[idx], x[i], y[i], x[j], y[j]))
            {
                if (segments[idx].first == x[j])
                {
                    save = 1;
                }
                valid = 1;
            }
            idx--;
        }
        ret += valid;
    }
    ofs << ret << endl;
    //cerr << inFileName << " " << 1.0 * ret / n << endl;
    ifs.close();
    ofs.close();
    return 0;
}