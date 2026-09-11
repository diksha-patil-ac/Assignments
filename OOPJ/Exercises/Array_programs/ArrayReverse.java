
public class ArrayReverse 
{
	static void reverseArray(int a[])
    {
        System.out.println("Reverse Array:");
        for (int i = a.length - 1; i >= 0; i--)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

}