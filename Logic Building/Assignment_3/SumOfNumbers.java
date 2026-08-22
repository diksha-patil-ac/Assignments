import java.util.Scanner;

class SumOfNumbers {

	static int sumOfTwoNumbers(int num1, int num2) {
		return num1 + num2;
	}
	
	public static void main(String args[]) {
	
	Scanner sc = new Scanner(System.in);

		System.out.println("Enter first number: ");
		int num1 = sc.nextInt();
		System.out.println("Enter second number: ");
		int num2 = sc.nextInt();
		int sum = sumOfTwoNumbers(num1,num2);
		System.out.println("The sum of " + num1 + " and " + num2 + " is " + sum);
	}
}