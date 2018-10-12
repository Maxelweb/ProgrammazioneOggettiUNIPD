
// Classe base

class ContoBancario
{
	private:
		double saldo; 
	public:
		ContoBancario(double dep): saldo(dep) {
			if(saldo < 0) saldo = 0; 
		}

		//~ContoBancario();
		
		// Precondizione d, p > 0 

		double deposita(double d){ if(d<=0) return saldo; else return saldo += d; }
		double preleva(double p){ if(p<=0) return saldo; else return saldo -= p; }
		double getSaldo(){ return saldo; }
};


// Classe derivata

class ContoCorrente: public ContoBancario
{
	private:
		static double spesaFissa;
	public: 
		ContoCorrente(double dep): ContoBancario(dep) { }
		// ridefinizioni
		double deposita(double d) { return ContoBancario::deposita(d-spesaFissa); }
		double preleva(double p) { return ContoBancario::preleva(d+spesaFissa); }
};

double ContoCorrente::spesaFissa = 1.0;

class ContoDiRisparmio: public ContoBancario
{
	// INVARIANTE DI ISTANZA : saldo (del sottoggetto) >= 0
	// eredito ContoBancario::deposita(), senza ridefinizione
	// eredito e ridefinisco preleva()

	public:
		ContoDiRisparmio(double dep): ContoBancario(dep) { }

		double preleva(double p)
		{
			return getSaldo() >= p ? ContoBancario::preleva(p) : getSaldo();
		}
};


class ContoArancio: public ContoDiRisparmio
{
	private:
		ContoCorrente& appoggio; 
	public:
		// per aprire un conto arancio, necessito di un deposito 
		// iniziale e di un conto corrente di appoggio. 
		ContoArancio(double depositoIniziale, ContoCorrente& app) : ContoDiRisparmio(depositoIniziale), appoggio(app) {}
		double deposita(double d) {
			appoggio.preleva(d); // posso andare in rosso (negativo) col saldo
			return ContoDiRisparmio::deposita(d);
		}

		double preleva(double p) 
		{
			if(getSaldo() >= p)
			{
				appoggio.deposita(p);
				return ContoDiRisparmio::preleva(p);
			}
			else // se non posso prelevare
			{
				return getSaldo();
			}
		}
};