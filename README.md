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

![image](https://github.com/karwekarwe/OOP/assets/82239041/86b0c35c-62d6-4faa-860e-c82ca3f6632c)

# 1 Strategija:

![image](https://github.com/karwekarwe/OOP/assets/82239041/4b1c463e-751e-4772-8338-c1c258675183)



# 2 Strategija:

![image](https://github.com/karwekarwe/OOP/assets/82239041/f6c31245-f649-4921-9b1b-b5b2b1cb66cb)



# 3 Strategija:

3 strategijoje buvo panaudoti std::copy ir std::remove_if na6umo paspartinimui:

![image](https://github.com/karwekarwe/OOP/assets/82239041/1acd4de6-0494-4b91-ab91-ad517dbd789e)

Kaip matome iš lentelės, visose trijose strategijose efektyviausia naudodi std::vector.

1 Strategija užtruko ilgiausiai su visais variantais (vector, list, deque), nes naudoti du naujus vektorius elementų padalijimui yra neefektyvu. 

2 ir 3 strategijų laikai apylygiai, std::vector programos variantas veikia daug greičiau palyginus su std::list ir std::deque.

## Paleisties proceso instrukcija

1. Visų pirma, iš https://github.com/karwekarwe/OOP reikia klonuoti repozitoriją savo darbo aplinkoje naudojant 'git clone'.
2. Atsidarius naują terminalą, nueikite į klonuotos repozitorijos aplnką.
3. Kompiliuokite programą naudojant "Makefile" failą, kuris jau bus klonuotoje repozitorijose - terminale įrašykite "make".
4. Pasirinkite su kokia programos versija norite dirbti. Norint naudoti std::vector versiją, terminale rašykite "./v". std::list - "./l". std::deque - "./d".
5. Terminale jūsų bus paklausta, ar norite dirbti su anksčiau sugeneruotais failais, ar generuoti naują failą. "Generuoti nauja ar naudoti esama? (Nauja - N. Esama - E)". Norint generuoti naują failą, spauskite "N". Norint naudoti esamą failą - spauskite "E".
6. Tada pasirinkite, su kokio dydžio failu norite dirbiti įvedant atitinkamą skaičiu (1-5): 1. 1000 2. 10000 3. 100000 4. 1000000 5. 10000000.
7. Jei pasirinksite generuoti naują failą, papildomai turėstie įvesti namų darbų pažymių skaičių.
8. Tada įveskite galutinio balo skaičiavimo metodą, rikiavimo metodą.
