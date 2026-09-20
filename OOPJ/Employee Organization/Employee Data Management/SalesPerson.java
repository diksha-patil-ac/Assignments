package SaveAndLoad;

class SalesPerson extends Employee
{
    public SalesPerson(String n, String a, int ag, boolean g, float salary)
    {
        super(n, a, ag, g, salary);
    }

    @Override
    public String getDesignation()
    {
        return "Sales Person";
    }
}