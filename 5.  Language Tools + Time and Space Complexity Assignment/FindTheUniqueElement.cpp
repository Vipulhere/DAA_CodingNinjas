int findUnique(int *arr, int n) {
    // Write your code here
    	int value = 0;
	for(int i = 0 ; i < n ; ++i) {
		value = (value ^ arr[i]);
	}
	return value;
}