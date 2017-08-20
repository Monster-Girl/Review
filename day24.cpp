//1.实现一个位图。
#include<iostream>
using namespace std;
#include<vector>
class BitSet
{
public:
	BitSet(size_t range)
	{
		_a.resize((range >> 5) + 1);
	}

	void Set(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_a[index] |= (1 << pos);
	}

	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_a[index]=_a[index] & ~(1 << pos);
	}

	bool Test(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _a[index] & (1 << pos);
	}
protected:
	vector<int> _a;
};

void TestBitset()
{
	BitSet s1(-1);
	s1.Set(32);
	cout << s1.Test(32) << endl;
	s1.Reset(32);
	cout << s1.Test(32) << endl;

}

int main()
{
	TestBitset();
	system("pause");
	return 0;
}
//2.以下三个问题都是位图相关类似题目，请给出解决方案：
//1）给定100亿个整数，设计算法找到只出现一次的整数
//思路1：100亿个整数，如果是有符号整数，范围在-2^31-2^31-1
//因为存在正负，我们可以用两个位图来存储，并且每个位图用两位来表示。
//00不存在 01出现一次 10出现次数大于1次
//如果是无符号，也就是2^31，用一个位图来表示，同样两位表示
//占用内存大小是2^31 * 2bit=2^32/8 byte/2^10/2^10=512M

//思路2：如果服务器较多，或者是多核主机
//可以先用hash分成1000份，然后在每份内部使用bitset进行统计
//最后将出现1次的数归并起来

//2）给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集
//思路1：可以将其分成1000份，每份大小为1000万个整数，放到内存里大概是40M
//把这1000份的文件两两合并，内存是可以做到的。最后把所有的都合并就可以了。

//思路2：也可以先分成10份 ，然后用bitmap的两位来统计，占用内存250M
//00没有出现过，01第一个文件出现过，10第二个文件出现过，11两个都出现过
//然后两两归并一次，在接着去归并其他的
//直接分成两份，差不多刚好是1G，也是可以的

//3）1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
//用位图进行统计。方法同一的思路1。