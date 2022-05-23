/*Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell
data structure with modularity of programming language*/

#include<iostream>
using namespace std;
class heapsort
{
	int heap[20];
	int n;
	public:
		void accept();
		void disp();
		void heap_create();
		void downadj(int );
		void heap_sort();
};

void heapsort::accept()
{
	cout<<"\nEnter n: ";
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>heap[i];
}

void heapsort::disp()
{
	for(int i=1;i<=n;i++)
		cout<<"\t"<<heap[i];
}



void heapsort::heap_create()
{

	heap[0]=n;
	for(int i=n/2;i>=1;i--)
	{
		downadj(i);
		
	}
}


void heapsort::heap_sort()
{

	int t,last;
	heap[0]=n;
	while(heap[0]>1)
	{
		last=heap[0];

		t=heap[last];
		heap[last]=heap[1];
		heap[1]=t;

		heap[0]--;
		downadj(1);
		
	}

}


void heapsort::downadj(int i)
{
	int j,t;
	while(2*i<=heap[0])   
	{
		j=2*i;           
            if(j+1<=heap[0] && heap[j+1]>heap[j])
			j++;

		if(heap[i]<heap[j])
		{
			t=heap[i];
			heap[i]=heap[j];
			heap[j]=t;
			i=j;
		}
		else
			break;
	}
}

int main()
{
	heapsort h;
	h.accept();
	cout<<"\n\nData Before sort: ";
	h.disp();
	h.heap_create();
	h.heap_sort();
	cout<<"\n\nSORTED DATA: ";
	h.disp();
	return 0;

}
