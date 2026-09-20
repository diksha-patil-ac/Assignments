
public class SalesPerson extends Employee 
{
	protected String region;
	public SalesPerson(String name,String address,int age,boolean gender,float basicsalary,String region)
	{
		super(name,address,age,gender,basicsalary);
		setRegion(region);
	}
	
	public String getRegion() 
	{
		return region;
	}
	
	public void setRegion(String region) 
	{
		this.region = region;
	}
	
	@Override
	public void display() 
	{
		super.display();
		System.out.println("regin is : "+region);
	}
}