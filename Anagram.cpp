#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/**

	This function anagram finder splits the word in half into two parts, s1 and s2
	
	if the word lengths are not equal - no chance at being an anagram
	next the words are sorted alphabetically
	after that, the function set differences on the strings will count up the number of differences
	
	reference links are posted below

*/
void anagramFinder(int n, vector<string> words){

	for (int i = 0; i < n; i++){
		string diff;
		int mid = words[i].length() / 2;
		string s1 = words[i].substr(0, mid);
		string s2 = words[i].substr(mid);

		if (s1.length() != s2.length()){
			cout << -1 << endl;
			continue;
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		
		set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(diff, diff.begin()));
		// http://en.cppreference.com/w/cpp/algorithm/set_difference
		// http://en.cppreference.com/w/cpp/iterator/inserter
		// for reference

		cout << diff.size() << endl;
	}
}


int main(void) {

	int m;
	vector <string> words;

	cin >> m;

	for (int i = 0; i<m; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}

	anagramFinder(m, words);

	return 0;
}