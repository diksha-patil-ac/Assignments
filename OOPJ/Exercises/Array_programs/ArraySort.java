
public class ArraySort 
	{
	    // 1. Sort numeric array
	    static void sortArray(int a[])
	    {
	        for (int i = 0; i < a.length - 1; i++)
	        {
	            for (int j = i + 1; j < a.length; j++)
	            {
	                if (a[i] > a[j])
	                {
	                    int temp = a[i];
	                    a[i] = a[j];
	                    a[j] = temp;
	                }
	            }
	        }

	        System.out.println("Sorted Array:");
	        for (int i = 0; i < a.length; i++)
	        {
	            System.out.print(a[i] + " ");
	        }
	        System.out.println();
	    }
}