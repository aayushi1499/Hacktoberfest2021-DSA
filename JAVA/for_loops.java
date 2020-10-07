public class for_loops {
    public static void main(String[] args){
        int[] arr={0,1,2,3};
        for(int i=0;i<4;i++){
            System.out.println(arr[i]);
        }
        
        for(int i:arr){
            System.out.println(i);
        }
    }
    
}