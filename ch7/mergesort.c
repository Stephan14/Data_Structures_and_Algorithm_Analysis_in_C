#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/*归并排序*/

template <typename T>
void Print(std::vector<T> y) {
	for (auto it = y.begin(); it != y.end(); ++it) {
		std::cout << *it << " ";
	}	
}

template <typename T>
void Merge(std::vector<T>& y, std::vector<T>& temp, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid;
	size_t temp_index = left;
	int num = right - left + 1; //防止size_t类型溢出

	while (i < mid && j < right) {
		if (y[i] < y[j])
			temp[temp_index++] = y[i++];
		else
			temp[temp_index++ ] = y[j++];
	}

	//将数组剩余的部分合并
	while (i < mid) {
		temp[temp_index++] = y[i++];
	}
	while (j < right) {
		temp[temp_index++] = y[j++];
	}

	for (temp_index = temp_index - 1; num > 0 && temp_index >= left; --temp_index) {
		y[temp_index] = temp[temp_index];
		--num;
	}

}

template <typename T>
void MergeSort(std::vector<T>& v, std::vector<T>& temp, size_t i, size_t j)
{
	if (j - i == 1) {
		if (v[i] > v[j]) {
			std::swap(v[i], v[j]);
		}
	} else if(j == i) {
		return;
	} else {
		size_t mid = i + (j - i)/2; //防止溢出
		MergeSort(v, temp, i, mid);
		MergeSort(v, temp, mid, j);
		Merge(v, temp, i, mid, j);
	}
}

int main(int argc, char const *argv[]) {
	double start_t, end_t;  // 计时器.

	// 内存分配计时开始.
	start_t = clock();
	// 1亿个数, 需要3GB内存, 注意链表本身没有用到这么大空间. 另外, 换成list差别不大.
	std::vector<float> L(10);
	std::vector<float> T(10);
	// 内存分配计时结束并输出时间.
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;

	// 数据赋值计时开始.
	start_t = clock();
	// 利用随机数生成器生成0.0到1.0之间的实数.
	std::default_random_engine generator(time(NULL));
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	for (auto iter = L.begin(); iter != L.end(); ++iter)
		*iter = distribution(generator);
	// 数据赋值计时结束并输出时间.
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;

	Print(L);
	// 排序计时开始.
	start_t = clock();
	// 对10亿个随机数排序, 如果用数组时间也没什么太大差别.
	MergeSort(L, T, 0, L.size());
	// 排序计时结束并输出时间.
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;
	Print(L);

	return 0;
}
