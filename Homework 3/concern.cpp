//Your declarations and implementations would go here
class Concern
{
public:
	Concern(string name);
	virtual ~Concern();
	virtual string description() const = 0;
	virtual string person() const;
	virtual bool possibleFelony() const;
private:
	string m_name;
};

Concern::Concern(string name) 
{ 
	m_name = name; 
}

Concern::~Concern()
{}

string Concern::description() const
{
	return "";
}

string Concern::person() const
{
	return m_name;
}

bool Concern::possibleFelony() const
{
	return false;
}

class HushPayment: public Concern
{
public:
	HushPayment(string name, int amount);
	virtual ~HushPayment();
	virtual string description() const;
private:
	int m_amount;
};

HushPayment::HushPayment(string name, int amount) : Concern(name)
{
	m_amount = amount;
}

HushPayment::~HushPayment()
{
	cout << "Destroying " << Concern::person() << "'s hush payment" << endl;
}

string HushPayment::description() const
{
	string a = "A ";
	string b = to_string(m_amount);
	string c = " payment";
	return (a+"$"+b+c);
}

class EthicsMatter : public Concern
{
public:
	EthicsMatter(string name);
	virtual ~EthicsMatter();
	virtual string description() const;
};


EthicsMatter::EthicsMatter(string name) : Concern(name) 
{} 

EthicsMatter::~EthicsMatter()
{
	cout << "Destroying " << Concern::person() << "'s ethics matter" << endl;
}

string EthicsMatter::description() const
{
	return "An ethics matter";
}
class Investigation : public Concern
{
public:
	Investigation(string name);
	virtual ~Investigation();
	virtual string description() const;
	virtual bool possibleFelony() const;
};

Investigation::Investigation(string name) : Concern(name)
{}

Investigation::~Investigation()
{
	cout << "Destroying " << Concern::person() << "'s investigation" << endl;
}

string Investigation::description() const
{
	return "An investigation";
}

bool Investigation::possibleFelony() const
{
	return true;
}


