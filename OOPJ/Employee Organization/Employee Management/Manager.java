
public class Manager extends Employee 
{
	protected float hra;
	
	public Manager(String name,String address,int age,boolean gender,float basicsalary,float hra)
	{
		super(name,address,age,gender,basicsalary);
		setHra(hra);	
	}

	public float getHra() 
	{
		return hra;
	}

	public void setHra(float hra) 
	{
		this.hra = hra;
	}
	
	@Override
	public void display() 
	{
		super.display();
		System.out.println("hra : "+hra);
	}
}