//��ķ�տ�ʼѧϰӢ�ĵ��ʣ��Ե�������ܸ���Ȥ��
//�������ķһ�鵥�ʣ����ܹ�Ѹ��ȷ���Ƿ���Խ���Щ����������һ���б��У�ʹ�ø��б����κε��ʵ�����ĸ��ǰһ���ʵ�Ϊ��ĸ��ͬ��
//���ܱ�дһ��������������ķ�����ж���

//�������� :
//�����������������ݡ�
//����ÿ��������ݣ���һ��Ϊһ��������n��������n�����ʡ�
//Ȼ����n���ַ���������n�����ʡ�
//��֤��2 <= n <= 200, ÿ�����ʳ��ȴ���1��С�ڵ���10, �����е��ʶ�����Сд��ĸ��ɡ�

//������� :
//����ÿ�����ݣ����"Yes"��"No"

//�������� :
//     3
//     abc
//     cdefg
//     ghijkl
//     4
//     abc
//     cdef
//     fghijk
//     xyz

// ������� :
//Yes
//No

#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool WordChain(int n, vector<string> v1)
{
	for (int i = 0; i < n - 1; i++)
	{
		int size = v1[i].size();
		if (v1[i][size - 1] == v1[i + 1][0])
			continue;
		else
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}
		bool ret = WordChain(n, v1);
		if (ret == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		
		break;
	}
	system("pause");
	return 0;
}

