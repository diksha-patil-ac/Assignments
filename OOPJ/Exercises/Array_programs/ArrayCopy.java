
public class ArrayCopy 
{
	static void copyArray(int a[])
    {
        int b[] = new int[a.length];
        for (int i = 0; i < a.length; i++)
        {
            b[i] = a[i];
        }
        System.out.println("Copied Array:");
        for (int i = 0; i < b.length; i++)
        {
            System.out.print(b[i] + " ");
        }
        System.out.println();
    }
}