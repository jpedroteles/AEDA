
Trabalho 6 - Gestão de informação da Volta a Portugal (Parte 1)
 
Desenvolva uma aplicação em C++ para gestão de informação relativa à Volta a Portugal em bicicleta. Esta competição que anima as estradas portuguesas desde o Verão de 1927, é constituída por diversas etapas que as equipas participantes tentam ganhar. Uma equipa é caracterizada por uma designação, país e um conjunto de patrocinadores. Uma equipa possui vários ciclistas. 
 
A classificação de um ciclista é obtida como o somatório dos tempos gastos nas etapas já realizadas. 
 
Deve considerar também o facto de um ciclista desistir no decorrer da volta e não efetuar todas as etapas. O ciclista com menor tempo gasto, no somatório de todas as etapas, é considerado o vencedor da Volta a Portugal. A classificação de um diretor desportivo é a média das classificações obtidas pelos ciclistas da sua equipa.
 
O sistema deve registar e gerir de forma integrada toda a informação desportiva relativa à Volta, nomeadamente classificações e prémios obtidos do decorrer de cada etapa.
 
Alguns requisitos obrigatórios (pode e deve incluir outros que considere relevantes):
 
- Manutenção de equipas (classe Equipa)
- Manutenção de membros da equipa (ciclistas, diretor desportivo, treinadores, mecânicos e massagistas) (classe Membro)
- Manutenção de etapas (classe Etapa)
- Manutenção de dados gerais da Volta (patrocinadores, classificações, prémios…) (classe volta, patrocinadores, classificacoes. Os premios estao implementados num vetor de classificacoes na classe volta)
- Associar equipas e membros ) (Vector da classe membro, data member da classe Equipa)
- Associar etapas e ciclistas (participantes, tempos e vencedores) ) (Vector da classe ciclista, data member da classe Etapa)
- … outras associações que julgue necessárias
 
Considere o conjunto de algumas das entidades implementadas: MembroEquipa (entidade no topo da hierarquia de membros de uma equipa), Equipa, Etapa, entre outras. Usando estruturas de dados lineares, deve implementar:
 
- Manutenção do conjunto de equipas (CRUDs Equipa)
- Manutenção do conjunto de membros da equipa (CRUDs Membros)
- Manutenção do conjunto de etapas e prémios (montanha, juventude,…) (CRUDs Etapas)
- Manutenção do conjunto de patrocinadores (CRUDs Patrocinadores)
- Listagens várias (totais ou parciais com critérios a definir pelo utilizador, com possível ordenação) de, por exemplo: 
   - equipas (como opção, por patrocinador, por país, ...) (ListEquipasPorPatrocinador(),ListEquipasPorPais() )
   - membros da equipa (ciclistas, diretores desportivos,…) e respetiva classificação (como opção, por equipa, por idade, ...) (ListCiclistasPorEquipa(), ListCiclistasPorIdade() )
   - etapas (como opção, realizadas ou não, de duração x,...) (ListEtapasRealizadas(), ListEtapasPorTipo(), por duraçao?)
   - …. 
Notas: 
1. Por “manutenção de dados” entende-se as operações básicas CRUD (Create, Read, Update, Delete) 
2. O trabalho deve respeitar o que está descrito em “Notas relativas à implementação” no texto relativo aos “Enunciados e instruções” da parte 1 do trabalho prático
