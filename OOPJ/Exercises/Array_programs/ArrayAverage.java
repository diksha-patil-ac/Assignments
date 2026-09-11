
public class ArrayAverage 
{
	static void averageArray(int a[])
    {
        int sum = 0;
        for (int i = 0; i < a.length; i++)
        {
            sum = sum + a[i];
        }
        double average = (double) sum / a.length;
        System.out.println("Average = " + average);
    }
}