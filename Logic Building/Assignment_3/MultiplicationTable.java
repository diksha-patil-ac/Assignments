import java.util.Scanner;

class MultiplicationTable{

	static void printMultiplicationTable() {
			
		Scanner sc = new Scanner(System.in);
			int number;
		
		System.out.println("Enter a number: ");
		number = sc.nextInt();
			
		for(int i = 1; i <= 10; i++) {
			System.out.println(number * i);
		}
	}
	
	public static void main(String args[]) {
		printMultiplicationTable();
	}
}