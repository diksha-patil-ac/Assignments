class DaysOfWeek {
	public static void main(String args[]) {
		int day = 3;

		switch (day) {
			case 1 : 
				System.out.println("This day is Monday");
				break;

			case 2 : 
				System.out.println("This day is Tuesday");
				break;
			
			case 3 : 
				System.out.println("This day is Wednesday");
				break;

			case 4 : 
				System.out.println("This day is Thursday");
				break;

			case 5 :
				System.out.println("This day is Friday");
				break;

			case 6 :
				System.out.println("This day is Saturday");
				break;

			case 7 : 
				System.out.println("This day is Sunday");
				break;

			default:
				System.out.println("Invalid day number");
			}
	}
}