vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    	vector<int> result;
	int rows = A.size();
	int cols = A[0].size();
	int top = 0;
	int bottom = rows-1;
	int left = 0;
	int right = cols-1;
	int dir = 0; 
	
	while(top <= bottom && left <= right){
	    if(dir == 0){
	        for(int j = left; j <= right; j++){
	            result.push_back(A[top][j]);
	        }
	        dir = 1;
	        top++;
	       
	    }
	    else if(dir == 1){
	        for(int i = top; i <= bottom; i++){
	            result.push_back(A[i][right]);
	        }
	        right--;
	        dir = 2;
	       
	    }
	    else if(dir == 2){
	        for(int j = right; j >= left; j--){
	            result.push_back(A[bottom][j]);
	        }
	        bottom--;
	        dir = 3;
	       
	    }
	    else if(dir == 3){
	        for(int i = bottom; i >= top; i--){
	            result.push_back(A[i][left]);
	        }
	        left++;
	        dir = 0;
	       
	    }
	}
	
	return result;
}

