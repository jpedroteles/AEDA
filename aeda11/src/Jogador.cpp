#include "Jogador.h"


void Jogador::adicionaAposta(const Aposta & ap)
{
	apostas.insert(ap);
}

int Jogador::apostasNoNumero(int num) const
{
	int count = 0;
	
	for( HashApostas::const_iterator it = apostas.begin();
		it != apostas.end(); it++)
		if ((*it).contem(num))
			count++;
			
	return count;
}

HashApostas Jogador::apostasSorteadas(const tr1::unordered_set<int> & sorteio) const
{
	HashApostas money;
	money.clear();

	for( HashApostas::const_iterator it = apostas.begin();
		it != apostas.end(); it++)
		{
			if ((*it).calculaCertos(sorteio) > 3)
				money.insert(*it);
		}
			
	return money;
}
