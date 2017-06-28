#include <iostream>
#include <list>
using namespace std;

int main() {

	int T, N, K;
	list<int> soldiers;
	int count;

	cin >> T;

	for (int z = 0; z < T; z++)
	{
		cin >> N >> K;

		soldiers.clear();
		
		for (int i = 0; i < N; i++)
			soldiers.push_back(i + 1);
		count = N;


		list<int>::iterator iter = soldiers.begin();
		while (count > 2) {
			iter = soldiers.erase(iter);
			if (iter == soldiers.end())
				iter = soldiers.begin();

			count--;

			for (int i = 0; i < K-1; i++)
			{
				iter++;
				if (iter == soldiers.end())
					iter = soldiers.begin();
			}
		}

		for (iter=soldiers.begin(); iter != soldiers.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\n";

	}
	return 0;
}