#include<iostream>
using namespace std;
int main()
{
	int n, red, score_p, score_o;
	cin >> n;
	while (n--) {
		cin >> red >> score_p >> score_o;
		if (red <= 6) {
			if (score_p + (15 - red) * red / 2 < score_o)
				cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		else {
			if (score_p + (red - 6) * 8 + 27 < score_o)
				cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
	return 0;
}