#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

void printMedian(double arr[], int n){
	priority_queue<double> maxHeap;
	priority_queue<double,vector<double>,greater<double> > minHeap;

	double med = arr[0];
	maxHeap.push(arr[0]);
	cout << med << endl;
	for (int i=1; i < n; i++){
		double x = arr[i];
		if (maxHeap.size() > minHeap.size()){
			if (x < med){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(x);
			}
			else
				minHeap.push(x);

			med = (maxHeap.top() + minHeap.top())/2.0;
		}
		else if (maxHeap.size()==minHeap.size()){
			if (x < med){
				maxHeap.push(x);
				med = (double)maxHeap.top();
			}
			else{
				minHeap.push(x);
				med = (double)minHeap.top();
			}
		}
		else{
			if (x > med){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(x);
			}
			else
				maxHeap.push(x);

			med = (maxHeap.top() + minHeap.top())/2.0;
		}
		cout << med << endl;
	}
}

int main(){
    int size;
    cout<<"Enter the size of the stream"<<endl;
    cin>>size;
    double ar[size];
    for(int i=0;i<size;i++){
        cin>>ar[i];
        printMedian(ar, size);
    }
	return 0;
}