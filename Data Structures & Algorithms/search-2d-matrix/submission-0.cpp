class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size();
        int n=matrix[0].size();

        int l=0;
        int h=m*n-1;
        bool ans=false;

        int r;
        int c;

        while(l<=h){

            int mid=(l+h)/2;

            r=mid/n;
            c=mid%n;

            if(matrix[r][c]==target){
                ans=true;
                break;
            }
            else if(matrix[r][c]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }

        }

        return ans;
        
    }
};
