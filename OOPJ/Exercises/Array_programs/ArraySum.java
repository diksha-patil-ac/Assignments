
public class ArraySum 
{
	static void sumArray(int a[])
    {
        int sum = 0;
        for (int i = 0; i < a.length; i++)
        {
            sum = sum + a[i];
        }
        System.out.println("Sum = " + sum);
    }
}