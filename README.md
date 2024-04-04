# README

## Apie:

# v1.0

Failų su pasirinktu dydžiu duomenų generavimas, skaitymas, rūšiavimas.

vector / list / deque

Specs: 

CPU: Intel Core i5 2.40GHz 4cores 8virtual

RAM: 8GB

SSD


Testavimo rezultatai(milisekundemis): 

# 1 Strategija:

![image](https://github.com/karwekarwe/OOP/assets/82239041/4b1c463e-751e-4772-8338-c1c258675183)

vector:

1000	2

10000	33

100000	369

1000000	3931

10000000 45221

list:

1000 5

10000 88

100000 648

1000000 6742

10000000 115039

deque:

1000 4

10000 56

100000 700

1000000 7689

10000000 145497

# 2 Strategija:

![image](https://github.com/karwekarwe/OOP/assets/82239041/f6c31245-f649-4921-9b1b-b5b2b1cb66cb)

Su vector ir deque - labai lėtas studentų rūšiavimas į luzeriukus ir jų trynimas...
vector:

1000	40

10000	1561

100000	150541

1000000	per ilgai

10000000 per ilgai

list:

1000 5

10000 68

100000 561

1000000 5705

10000000 86483

deque:

1000 47

10000 1030

100000 116056

1000000 per ilgai

10000000 per ilgai

# 3 Strategija:

3 strategijoje buvo panaudoti std::copy ir std::remove_if na6umo paspartinimui:

![image](https://github.com/karwekarwe/OOP/assets/82239041/1acd4de6-0494-4b91-ab91-ad517dbd789e)

vector:

1000	2

10000	30

100000	328

1000000	3390

10000000 32992

![image](https://github.com/karwekarwe/OOP/assets/82239041/18ea3071-1f43-4f83-a289-932781ebb2b6)


