
public class ComplexNumber 
{
	    private int number1;
	    private int number2;

	    public int getNumber1()
	    {
	        return number1;
	    }

	    public void setNumber1(int number1)
	    {
	        this.number1 = number1;
	    }

	    public int getNumber2()
	    {
	        return number2;
	    }

	    public void setNumber2(int number2)
	    {
	        this.number2 = number2;
	    }

	    public int computeComplexNumber()
	    {
	        return number1 * number2;
	    }

	    public static void main(String[] args)
	    {
	        ComplexNumber a[] = new ComplexNumber[5];

	        for (int i = 0; i < 5; i++)
	        {
	            a[i] = new ComplexNumber();

	            System.out.println("Enter number1:");
	            a[i].setNumber1(ConsoleInput.getInt());

	            System.out.println("Enter number2:");
	            a[i].setNumber2(ConsoleInput.getInt());
	        }

	        System.out.println("Results:");

	        for (int i = 0; i < 5; i++)
	        {
	            System.out.println(a[i].computeComplexNumber());
	        }
	    }
	}

