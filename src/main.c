#include <stdlib.h>
#include <stdio.h>

int reverseNum(int num, int negativeNum, int zeroendingnum) {

	float num_clone = num;
	int newnum = 0;
	int digitscounter = 0;
	while (num_clone >= 1) {
		num_clone /= 10;
		digitscounter++;

	}
	for (int i = 0; i < digitscounter; i++) {

		int p = num % 10;
		int powerIndex = 1;
		num /= 10;
		for (int j = 1; j < digitscounter - i; j++) {
			powerIndex *= 10;
		}
		newnum += p * powerIndex;
	}
	for (int g = 0; g < zeroendingnum; g++) {
		newnum *= 10;
	}
	zeroendingnum = -1;

	if (negativeNum) {
		return newnum * (-1);
	}
	return newnum;
}

int index_first_even(int arr[100], int l) {
	for (int i = 0; i < l; i++) {

		if (arr[i] % 2 == 0) {

			return i;
		}
	}

}

int index_last_odd(int arr[100], int l) {
	int lastInd = 0;

	for (int i = 0; i < l; i++) {
		if (abs(arr[i]) % 2 == 1) {
			lastInd = i;

		}
	}
	return lastInd;
}

int sum_between_even_odd(int arr[100], int l) {
	int sum = 0;
	for (int i = index_first_even(arr, l); i < index_last_odd(arr, l); i++) {
		sum += abs(arr[i]);
	}
	return sum;
}

int sum_before_even_and_after_odd(int arr[100], int l) {
	int sum = 0;
	for (int i = 0; i < l; i++) {
		sum += abs(arr[i]);
	}
	return sum - sum_between_even_odd(arr, l);
}
int main() {
	int nums[100];
	const int size = 1000;
	char string[size];
	fgets(string, 1000, stdin);
	int powIndex = 1, newnum = 0, negativeNum = 0, zeroendingnum = -1, newnumindex = 0;
	int programMode = string[0] - '0';
	for (int i = 2; i < size; i++) {

		if ((string[i] != ' ') && (string[i] != '\n') && (string[i] != '-')) {

			newnum += (string[i] - '0') * powIndex;
			powIndex *= 10;
			if (string[i] == '0') {
				zeroendingnum += 1;
			}
			else {
				zeroendingnum = 0;
			}

		}
		else if (string[i] == '-') {
			negativeNum = 1;
		}
		else if (string[i] == '\n') {
			nums[newnumindex] = reverseNum(newnum, negativeNum, zeroendingnum);
			newnumindex++;
			break;
		}
		else {
			nums[newnumindex] = reverseNum(newnum, negativeNum, zeroendingnum);
			newnumindex++;
			if (negativeNum) {
				negativeNum = 0;
			}
			powIndex = 1;
			newnum = 0;
		}
	}


	switch (programMode) {
	case(0):
		printf("%d", index_first_even(nums, newnumindex));
		break;
	case(1):
		printf("%d", index_last_odd(nums, newnumindex));
		break;
	case(2):
		printf("%d", sum_between_even_odd(nums, newnumindex));
		break;
	case(3):
		printf("%d", sum_before_even_and_after_odd(nums, newnumindex));
		break;
	default:
		printf("%s", "Данные некорректны");
	}


	return 0;
}
