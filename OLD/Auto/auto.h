
// Classe base astratta (e polimorfa)

class Auto
{
private: 
	unsigned int cvf; // Cavalli fiscali
	static double tassaPerCF;
public:
	virtual double tassa() const =0; 
	unsigned int getCVF() const { return cvf; }
	Auto(unsigned int x=0): cvf(x) { };
	virtual ~Auto(); // distruttore virtuale che rimane tale per tutta la gerarchia
	static double getTassaPerCF() { return tassaPerCF; }
	
};

double Auto::tassaPerCF = 5.0; 



class Diesel: public Auto
{
private: 
	static double addizionaleDiesel;	
	
public:
	Diesel(unsigned int cf=0): Auto(cf) {}
	double tassa() const {
		return getCVF() * getTassaPerCF() + addizionaleDiesel
	}
};

double Diesel::addizionaleDiesel = 100.0; 


class Benzina: public Auto
{
private:
	bool euro6;
	static double bonusEuro6;
public: 
	Benzina(unsigned int cf=0, bool e6=true): Auto(cf), euro6(e6) {}
	double tassa() const {
		// da fare
		// return euro6 ? getCVF()*getTassaPerCF
	}
};


class ACI{
private: 
	(Auto*)* veicoli; // Auto* * veicoli
	unsigned int size;
public:
	double incassaBolli() const {
		double i = 0.0; // incasso
		for(int x=0; x<size; ++x) i += veicoli(x)->tassa(); 
		return i;
	}
};







