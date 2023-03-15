#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s; cin >> s;
	reverse(s.begin(), s.end());

	auto ct = int{ 0 };
	auto val = int{ 0 };
	auto oss = ostringstream{};
	for (const auto& x : s) {
		if ('1' == x) {
			if (0 == ct) {
				val += 1;
			}
			else if (1 == ct) {
				val += 2;
			}
			else if (2 == ct) {
				val += 4;
			}
		}

		++ct;
		if (3 == ct) {
			oss << val;

			ct = 0;
			val = 0;
		}
	}

	if (0 < val) {
		oss << val;
	}

	auto ans = oss.str();
	if (0 == ans.size()) {
		cout << 0;
		return 0;
	}

	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}