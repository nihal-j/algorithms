#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+7;

// Calculate the prefix function as described in Cormen.
vector<int> prefix_function(string &s)
{
	int len = s.length();
	vector<int> pi (len, 0);

	for (int i = 1; i < len; i++)
	{
		int j = pi[i - 1];
		while (s[j] != s[i] && pi[j] > 0)
			j = pi[j - 1];
		if (s[j] == s[i])
			pi[i] = j + 1;
	}

	return pi;
}

// Find the first index `i` such that `s` occurs as a substring in `t[i....]`
int kmp_matcher(string &s, string &t, vector<int> &pi)
{
	int m = s.length(), n = t.length();
	int i = 0, j = 0;

	while (i < n)
	{
		while (s[j] != t[i] && pi[j] > 0)
			j = pi[j - 1];
		if (s[j] == t[i])
			j++;
		if (j == m)
			return i - m + 1;
		i++;
	}

	return -1;
}


int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s, t;
	cin >> t >> s;
	vector<int> pi = prefix_function(s);
	
	cout << kmp_matcher(s, t, pi) << "\n";

	return 0;
}