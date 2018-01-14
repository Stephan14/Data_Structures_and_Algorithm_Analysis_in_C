#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>

template <typename T>
void InsertSort(std::vector<T> v)
{
	for(size_t index = 1, j = 0; index < v.size(); ++index)
  	{
		int temp = v[index];
		auto position = std::lower_bound(v.begin(), v.begin()+index, temp);
		for(auto it = v.begin()+index; it > position; --j)
			*it = *(it -1);
		*position = temp;
	}
}

int main(int argc, char const *argv[]) {
	double start_t, end_t;

	start_t = clock();
	std::vector<double> v(900000);	
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << "minutes"<< std::endl;

	// 数据赋值计时开始.
	start_t = clock();
	// 利用随机数生成器生成0.0到1.0之间的实数.
	std::default_random_engine generator(time(NULL));
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	for (size_t i = 0; i < v.size(); ++i)
		v[i] = distribution(generator);
	// 数据赋值计时结束并输出时间.
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;

	// 排序计时开始.
	start_t = clock();
	// 插入排序相当慢.
	InsertSort(v);
	// 排序计时结束并输出时间.
	end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;

	return 0;
}
