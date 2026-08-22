import java.util.Scanner;

class PositiveNumbers {

	static void askForPositiveNumbers() {
		
		Scanner sc = new Scanner(System.in);
		int number;

		do {
			System.out.println("Enter a positive number: ");
			number = sc.nextInt();
		} while(number <= 0);
			System.out.println("You entered a positive number: ");
	}

	public static void main(String args[]) {
		askForPositiveNumbers();
	}
}


		

