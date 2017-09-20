// getSumZero.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
class solution
{
public:
	std::vector<std::vector<int>> getSumZero(std::vector<int> data) {
	

		std::vector<std::vector<int>> result;
		int size = data.size();
		/*if (size >= 3)
			for (int i = 0; i < size-1;i++) {
				for (int j = i + 1; j < size; j++) {
					if (data[i] == data[j]) {
						std:: cout << data[j] << std::endl;
						data.erase(data.begin() + j);
						size--;
						j--;
					}
				}
			}*/
		sort(data.begin(), data.end());
			for (int elem1_position = 0; elem1_position < size - 2; elem1_position++) {
				
				int elem2_position = elem1_position + 1;
				int elem3_position = size-1;
				
				if (elem1_position == 0 || data[elem1_position-1] < data[elem1_position])
					while (elem2_position < elem3_position) {
					int elem1 = data[elem1_position];
					int elem2 = data[elem2_position];
					int elem3 = data[elem3_position];
					int sum = elem1 + elem2 + elem3;
					if (sum == 0) {
						std::vector<int> temp;
						temp.push_back(elem1);
						temp.push_back(elem2);
						temp.push_back(elem3);
						sort(temp.begin(), temp.end());
						result.push_back(temp);
						elem2_position++;
						elem3_position--;
						while (elem2_position < elem3_position && data[elem2_position] == data[elem2_position - 1]) {
							elem2_position ++;
                        }  
                        while (elem2_position < elem3_position && data[elem3_position] == data[elem3_position+1]) {
							elem3_position--;
                        }  
					}
					else if (sum < 0) {
						elem2_position++;
					}
					 else if (sum > 0) {
						elem3_position--;
					}
				}

			/*	for (int elem2_position = elem1_position + 1; elem2_position < size - 1; elem2_position++) {
					int elem2 = data[elem2_position];
					for (int elem3_position = elem2_position + 1; elem3_position < size; elem3_position++) {
						int elem3 = data[elem3_position];
						if ((elem1 + elem2 + elem3) == 0) {
							std::vector<int> temp;
							temp.push_back(elem1);
							temp.push_back(elem2);
							temp.push_back(elem3);
							sort(temp.begin(), temp.end());
							result.push_back(temp);
						}
					}
				}*/
			}
		/*	int resultSize = result.size();
			for (int RESULT_ELEM1_POSITION = 0; RESULT_ELEM1_POSITION < resultSize-1; RESULT_ELEM1_POSITION++) {
				for (int RESULT_ELEM2_POSITION = RESULT_ELEM1_POSITION + 1; RESULT_ELEM2_POSITION < resultSize; RESULT_ELEM2_POSITION++) {
					if (
						result[RESULT_ELEM1_POSITION][0] == result[RESULT_ELEM2_POSITION][0] &&
						result[RESULT_ELEM1_POSITION][1] == result[RESULT_ELEM2_POSITION][1] &&
						result[RESULT_ELEM1_POSITION][2] == result[RESULT_ELEM2_POSITION][2]
						) {
						result.erase(result.begin() + RESULT_ELEM2_POSITION);
						resultSize--;
						continue;
					}
				}
			}*/

		return result;
	}
private:


};


void main() {

	std::vector<int> data = { -1, 0, 1, 2,2, -1, -4,-1 };
	solution solution;
	std::vector<std::vector<int>> result = solution.getSumZero(data);
	int size = result.size();
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < 3; k++)
			std::cout << result[i][k];
		std::cout << std::endl;
	}
	
}
