


#include<string>

class FileAudio
{

private: 
	std::string titolo;
	double dimMB; 
public:
	virtual FileAudio* clone() const = 0; // Metodo di clonazione VIRTUALE, PURO e COSTANTE
	virtual bool qualita() const = 0;
	virtual ~FileAudio() {}	
	std::string getTitolo() const {return titolo;}
	double getSize() const {return dimMB;}
 // virtual bool operator==(const FileAudio& f) const = 0; // Lo teniamo in versione implementata	
	virtual bool operator==(const FileAudio& f) const {
		return titolo == f.titolo && dimMB == f.dimMB;
	}
};

class Mp3 : public FileAudio
{
private:
	unsigned int bitrate; // kbit/s
	static unsigned int qualityBitrate;
public: 
	Mp3* clone() const{
		return new Mp3(*this);
	}
	bool qualita() const {
		return bitrate >= qualityBitrate;
	}	
	bool operator==(const FileAudio& f) const {
		// Il tipo dinamico deve essere uguale a MP3
		// useremo il typeid
		return 
			typeid(f) == typeid(const Mp3&) 
			&& /*this->*/ FileAudio::operator==(f)
			&& (bitrate == (static_cast<const Mp3&>(f)).bitrate); // attenzione a NON usare f.bitrate! Viene rigettato! Devo fare un downcast
	}
	unsigned int getBitRate() const { return bitrate; }
};



class WAV: public FileAudio 
{
private: 
	unsigned int freq; // in Khz
	bool lossLess;
	static unsigned int qualityBitrate;
public: 
	WAV* clone() const{
		return new WAV(*this);
	}
	bool qualita() const {
		return freq >= qualityBitrate;
	}	
	bool operator==(const WAV& f) const {
		// Il tipo dinamico deve essere uguale a MP3
		// useremo il typeid
		return 
			typeid(f) == typeid(const Mp3&) 
			&& FileAudio::operator==(f)
			&& (freq == (static_cast<const WAV&>(f)).freq)
			&& (lossLess == (static_cast<const WAV&>(f)).lossLess);
	} 

	bool IsLossLess const { return lossLess;}
};

unsigned int WAV::qualityFreq = 92;

class iZod 
{
private: 

	// Smart pointer a file audio
	class Brano
	{
	public:
		FileAudio* punt;
		// Convertitore FileAudio* => Brano
		// Problema: non so il tipo, ma so che vi è il metodo di clonazione
		// [p->clone()] che ritorna un ptr a file audio o un suo sottotipo
		Brano(FileAudio* p): punt(p->clone()) {}		
		Brano(const Brano& b): punt(b.punt->clone()); // Copia profonda
		Brano& operator*(const Brano& b) // Assegnazione profonda
		{
			if(this != &b)
				delete punt;  // Funziona PERCHE' IL DISTRUTTORE E' VIRTUALE!!!

			punt = b.punt->clone();
		}
		~Brano() {delete punt;} // Distruzione profonda
	};

std::vector<Brano> songs;

public: 
	void insert(Mp3* p){
		vector<Brano>::iterator it = songs.begin();
		for( ; it != songs.end(); ++it)
		{	
			bool found = false;
			if(it->punt && p && !(*(it->punt) == *p)) found = true;
			//(it->punt) == *p; Chiamata polimorfa
		}

		if(!found) song.push_back(Brano(p));
	}

	vector<Mp3> mp3(double d, unsigned int b) const {
		vector<Mp3> ret; 
		vector<Brano>::const_iterator cit = songs.begin();
		for( ; cit != songs.end(); cit++)
		{
			Mp3* m = dynamic_cast<Mp3*>(cit->punt); // E' corretto solo Mp3* e meno corretto const Mp3* => conv.impl.
			if(m->getSize() >= d && m->getBitRate() >= b)
			{
				ret.push_back(*m); 
			}
			return ret;
		}
	}

	vector<FileAudio*> braniQual() const {
		vector<FileAudio*> ret;
		for(unsigned int i = 0; i < songs.size(); ++i)
		{
			// l'accesso alla i-esima posizione avviene con
			if( (songs[i].punt)->qualita()) 
				WAV* p = dynamic_cast<WAV*>(songs[i].punt); 
				if(!p || p->lossLess) ret.push_back(p);
				
				//(static_cast<WAV*>(songs[i]->punt))->IsLossLess())
		}
		return ret;
	}
};