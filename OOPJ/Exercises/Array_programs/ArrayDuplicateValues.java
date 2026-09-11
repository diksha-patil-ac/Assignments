
public class ArrayDuplicateValues 
{
	static void duplicateValues(int a[])
	{
	    System.out.println("Duplicate Values:");

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

	        for (int j = i + 1; j < a.length; j++)
	        {
	            if (a[i] == a[j])
	            {
	                System.out.println(a[i]);
	                break;
	            }
	        }
	    }
	}
}
