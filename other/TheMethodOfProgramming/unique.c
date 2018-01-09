#include <iostream>
#include <vector>
#include <algorithm>

void unique_old(std::vector<int> v) {
	
	if (v.size() == 0) {
		return ;
	}

	sort(v.begin(), v.end());
	for (size_t l = 0, r = 0; l < v.size(); l = r) {
		for (r = l + 1; r < v.size(); ++r) {
			if (v[r] != v[l]) {
				break;
			}
		}
		std::cout << v[l] << " : " << r - l << std::endl;
	}
}


void  unique(std::vector<int> v) {
	if (v.size() == 0) {
		return ;
	}
	sort(v.begin(), v.end());
	size_t l, r;
	for (l = 0, r = 0; r < v.size(); ++r) {
		if (v[r] != v[l]) {
			std::cout << v[l] << " : " << r - l << std::endl;
			l = r;
		}
	}

	if (v.size() > 0)
		std::cout << v[l] << " : " << r - l << std::endl;
}

int main()
{
  std::cout << "Example A: " << std::endl;
  std::vector<int> A = {7, 2, 3, 2, 5, 1, 1};
  unique(A);
  std::cout << "Example B: " << std::endl;
  std::vector<int> B = {-9};
  unique(B);
  std::cout << "Example C: " << std::endl;
  std::vector<int> C;
  unique(C);
  return 0;
}

