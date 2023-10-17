#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically
// largest subsequence consisting of all
// distinct characters of S only once
string lexicoMaxSubsequence(string s, int n)
{
	stack<char> st;

	// Stores if any alphabet is present
	// in the current stack
	vector<int> visited(26, 0), cnt(26, 0);

	// Findthe number of occurrences of
	// the character s[i]
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {

		// Decrease the character count
		// in remaining string
		cnt[s[i] - 'a']--;

		// If character is already present
		// in the stack
		if (visited[s[i] - 'a']) {
			continue;
		}

		// if current character is greater
		// than last character in stack
		// then pop the top character
		while (!st.empty() && st.top() < s[i]
			&& cnt[st.top() - 'a'] != 0) {
			visited[st.top() - 'a'] = 0;
			st.pop();
		}

		// Push the current character
		st.push(s[i]);
		visited[s[i] - 'a'] = 1;
	}

	// Stores the resultant string
	string s1;

	// Generate the string
	while (!st.empty()) {
		s1 = st.top() + s1;
		st.pop();
	}

	// Return the resultant string
	return s1;
}

// Driver Code
int main()
{
	string S ;
    cin>>S;
	int N = S.length();
	cout << lexicoMaxSubsequence(S, N);

	return 0;
}