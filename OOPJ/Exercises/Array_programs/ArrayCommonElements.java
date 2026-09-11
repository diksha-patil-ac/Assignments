
public class ArrayCommonElements 
{
	static void commonElements(int a[], int b[])
	{
	    System.out.println("Common Elements:");

	    for (int i = 0; i < a.length; i++)
	    {
	        boolean alreadyPrinted = false;

	        for (int k = 0; k < i; k++)
	        {
	            if (a[i] == a[k])
	            {
	                alreadyPrinted = true;
	                break;
	            }
	        }

	        if (alreadyPrinted)
	            continue;

	        for (int j = 0; j < b.length; j++)
	        {
	            if (a[i] == b[j])
	            {
	                System.out.println(a[i]);
	                break;
	            }
	        }
	    }
	}
}
