#include <functional>
#include "libbin.h"

bool szukaj (int n , std::function<long long (int)> const& A , long long x)
{
    int l = 1 , p = n;
    while (l <= p)
    {
        int s = l + (p - l) / 2;

        if (A (s) == x)
        {
            return true;
        }

        if (A (l) >= A (s))
        {
            if (A (l) >= x && x > A (s))
            {
                p = s - 1;
            }
            else
            {
                l = s + 1;
            }
        }
        else
        {
            if (A (s) > x && x >= A (p))
            {
                l = s + 1;
            }
            else
            {
                p = s - 1;
            }
        }
    }
    return false;
}
