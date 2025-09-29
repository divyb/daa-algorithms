import java.util.*;


class exp1
{
    public void disp(int x[])
    {
        for(int i=0; i<x.length;i++)
            System.out.print(x[i]+"\t");

        System.out.println();

    }
    public static void main(String[] args)
    {
        exp1 ob = new exp1();
        int arr[] = {12,3,7,9,2,5};
        int temp,min;

        ob.disp(arr);

        for(int i = 0; i<arr.length;i++)
        {
            min = i;
            for(int j = i+1; j<arr.length; j++)
            {
                if(arr[min]>arr[j])
                    min = j;
            }

            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            
        }
        ob.disp(arr);
        
    }

    

}