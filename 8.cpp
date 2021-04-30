#include <iostream>

using namespace std;

unsigned long long euler(unsigned long long n)
{
    unsigned long long ans = n;
    for (unsigned long long i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	return (n > 1) ? ans - ans / n : ans;
}

int main()
{
    unsigned long long n, temp;
    cin >> n;
    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> temp;
        cout << euler(temp) << endl;
    }
    return 0;
}