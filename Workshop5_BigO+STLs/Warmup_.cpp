class Solution:
{
public:
vector<int> sortedSquares(vector<int>& A) {
        int current, Asize = A.size();
        for(int i = 0; i < Asize; i++)
        {
            current = A[i];
            A[i] = current * current; //square everything first 
        }
        sort(A.begin(),A.end()); //then sort
        return A;
        
    }
	//runtime is nlogn as sort from stl library is about nlogn.
	//constant space complexity
};

//since we know that the array is sorted in non-descending order, that means that
//we could compare the first and last index and append accordingly

class Solution
{
    
public:
vector<int> sortedSquares(vector<int>& A) {
	int pos;
	int Asize = A.size();
	vector<int> result;
    for(int i = 0; i < Asize; i++)
	{
		if(A[i] >= 0)
		{
			pos = i;
			break; // no longer need to track the other positions after
		}
	}
	for(int i = 0; i < Asize; i++)
	{
		A[i] *= A[i];
	}
	
	int k= pos,i= pos -1;
        //merging the elements such that they are increasing order.
           while(i>=0 && k<Asize){
               if(A[i]<A[k]){
                   result.push_back(A[i]);
                   i--;
               }
               else{
                   result.push_back(A[k]);
                   k++;
               }
           }
            //copy rest of elemets to result
    while(i>=0){
                result.push_back(A[i]);
				i--;
            }
    while(k<Asize){
                result.push_back(A[k]);
				k++;
            }
    return result;
    }
	//this solution has O(N) runtime but also O(N) space complexity as we create
	//a new vector for every solution. 
};