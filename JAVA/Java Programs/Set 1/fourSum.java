class Solution{
public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
    Arrays.sort(num);
    ArrayList<ArrayList<Integer>> res=new ArrayList<ArrayList<Integer>>();
    int i=0;
    while(i<num.length-3){
        int j=i+1;
        while(j<num.length-2){
            int left=j+1, right=num.length-1;
            while(left<right){
                if(num[left]+num[right]==target-num[i]-num[j]){
                    ArrayList<Integer> t=new ArrayList<Integer>();
                    t.add(num[i]);
                    t.add(num[j]);
                    t.add(num[left]);
                    t.add(num[right]);
                    res.add(t);
                    left++;
                    right--;
                    while(left<right && num[left]==num[left-1])
                        left++;
                    while(left<right && num[right]==num[right+1])
                        right--;
                }else if(num[left]+num[right]>target-num[i]-num[j])
                    right--;
                else
                    left++;
            }
            j++;
            while(j<num.length-2 && num[j]==num[j-1])
                j++;
        }
        i++;
        while(i<num.length-3 && num[i]==num[i-1])
            i++;
    }
    return res;
}
}
