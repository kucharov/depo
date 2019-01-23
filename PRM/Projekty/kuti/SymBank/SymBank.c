// SymBank - - symulator Banku 
// rozp. 15.12.2018
// tu musi byc wiele funkcji, budowa modularna to same plusy: D
/*0. Format pliku wejściowego
 *1. zapytanie o nazwe pliku +
 * 2. pobranie danych + kontrola +?
 * 3. Utworzenie okienek  - list
 * 4. Wpuszczenie klientów
 * 
 * 
 * zrobione menu. generator tez, format jest
 * czas na rozwiazanie problemu pobrania danych z pliku
 * 
 * 
 * 
 * 
 */
 
 //dyrektywy wstepne takie tam 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <time.h>
 


 
//strukruty
		
 typedef struct{
		double srednia;
		double odchylenie;
	 }okienko;
	 
typedef struct{
		double klienci_srednio;
		double odchylenie;
		int liczba_okienek;
		okienko *okienka;
		long int czas_symulacji;
	}dane;
	
struct osoba{
		struct osoba *nastepny;	
	};typedef struct osoba osoba; 
					
 
typedef struct{
		osoba *pierwszy;
		osoba *ostatni;
		int dlugosc;
		okienko rozklad;
	}kolejka;
	

//funkcje
void menu(void);
double gauss(double, double);
int plik_wzorcowy(void);
int kontrolapliku(char *);
dane * wczytanie(char *);
int najkrotsza(dane *);


int main(void)
{
	
//zmienne w main()
char *nazwa_wejscia;
int testwejscia, a, wchodzacy, interwal;
dane *pakiet;
long long int czas; 
kolejka *kolejki, *najkrotsza_indeks;

for(;;)
{
do{
		menu();
		printf("\nPodaj nazwe pliku z danymi wejsciowymi(powinien znajdowac sie w katalogu roboczym)\n:   ");
		nazwa_wejscia = (char *)malloc(45 * sizeof(char));
		scanf("%s", nazwa_wejscia);
		testwejscia = kontrolapliku(nazwa_wejscia);
	}while(testwejscia != 0);
	
	pakiet = wczytanie(nazwa_wejscia);
	free(nazwa_wejscia);												 //oszczednosc miejsca, nie bede juz korzystac z tej zmiennej.
	
	
{	/* printf("\nklienci: srednia: %lf  odchylenie: %lf   czas symulacji (s): %ld", pakiet->klienci_srednio, pakiet->odchylenie, pakiet->czas_symulacji);
		int testlicznik; 
		for(testlicznik=0;testlicznik<(pakiet->liczba_okienek); testlicznik++)
		{
			printf("\nokienko %d: srednia: %lf  odchylenie: %lf", testlicznik+1, pakiet->okienka[testlicznik].srednia, pakiet->okienka[testlicznik].odchylenie);
		}return 0;  */
}	







kolejki = (kolejka *)malloc(pakiet->liczba_okienek * sizeof(kolejka));
for(a=0;a<pakiet->liczba_okienek;a++) kolejki[a] = pakiet->okienka[a];



for(czas = 0; czas<pakiet->czas_symulacji; czas++) // główna pętla symulująca
	{
		while(czas%3600 == 0) //jako ze w danych sterujacych podano srednia czestotliwosc wchodzenia klientow / godzine, godzina jest wyjsciową jednostką czasu dla zmiany liczby wchodzących klientów - czyli co godzinę liczba ta się zmienia, co wykonuje niniejsza pętla while
			{
				los = gauss(pakiet->klienci_srednio, pakiet->odchylenie); 	// uzywamy mojej super funkcji
				wchodzacy = nearbyint(los);		 //tyle ludzi wejdzie do banku w ciagu aktualnej godziny. Symulacja jest realna wiec zaokraglamy do najblizszej liczby calkowitej - nikt nie widzial polowki klienta wchodzacej do banku
				interwal = (60 * 60)/wchodzacy; 		// co tyle sekund srednio wejdzie do banku nowy klient w ciagu biezacej godziny. Czesc ulamkowa i tak obcinamy, bo glowny zegar symulacji ma rozdzielczosc 1 sekundy
				
			}
			
			
		if((czas%interwal)==0) 
			{
				najkrotsza_indeks = najkrotsza(kolejki, pakiet);
				
				nowy_klient = (osoba *)malloc(sizeof(osoba));
				kolejki[najkrotsza_indeks].dlugosc++;
				kolejki[najkrotsza_indeks].
				
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	
	
}	
}


double gauss(double srednia, double odchylenie)  //funkcja generujaca losowe liczby o rozkladzie normalnym o podanej wartosci oczekiwanej (sredniej) i odchyleniu standardowym.
{
	double s, losowa1, losowa2;
	do{ 
		losowa1 = -1 + ((double)rand()/RAND_MAX) * 2;
		losowa2 = -1 + ((double)rand()/RAND_MAX) * 2; 							// https://stackoverflow.com/questions/2325472/generate-random-numbers-following-a-normal-distribution-in-c-c
		s = (losowa1 * losowa1) + (losowa2 * losowa2);}
	while (s >= 1 || s == 0);
	return srednia + (odchylenie * losowa1 * sqrt((-2*log(s)) / s));  // działa!!. na koncu tego pliku zrodlowego zawarłem zakomentarzowany kod testujący mój generator. 
}
	

void menu(void)
{
	int test, odp,kontrolawejscia, testwejscia, choragiewka = 0;
	char smietnik;
	
	
	
	for(;;)
	{
		if (choragiewka == 0) {printf("\n\n\t\t\t***SymBank - symulator kolejki w banku***\n\n\t\t\tMENU\t\t\t");
								printf("\n1 - symulacja\t\t2 - informacje o formacie pliku wejsciowego\n3 - wyjscie\n:  ");}
	
		do {
				testwejscia = 0;
				kontrolawejscia = scanf("%d", &odp);
				if ((smietnik=getchar())!='\n' || kontrolawejscia != 1) {testwejscia = 1; printf("\nNiepoprawna odpowiedz, wpisz 1, 2 lub 3. \n:   "); while((smietnik=getchar())!='\n');}
				
			}while (kontrolawejscia !=1 || testwejscia == 1 );
		
		switch (odp)
			{	
				case 1: choragiewka = 2; break;
				case 2: choragiewka = 0; if ((test = plik_wzorcowy()) == 0) printf("\nW katalogu roboczym utworzylem plik z ktorego dowiesz sie wiele o formacie pliku wejsciowego do SymBanku! \
						\nWracam do menu glownego..."); 
						break;
				case 3:	printf("\nDo zobaczenia!\n\n"); exit(0);
				default: printf("\nNieznana odpowiedz, wcisnij 1, 2 lub 3. \n:  "); choragiewka = 1;  	
			}
			if (choragiewka == 2) break;
		}
	}
	
	
int plik_wzorcowy(void)
{
	FILE *wzorzec;
	
	if ((wzorzec = fopen("SymBank_format_pliku.txt", "w")) == NULL) {printf("\nBlad tworzenia pliku wzorcowego, sprobuj jeszcze raz w innej lokalizacji.\n"); return 1;}
	
	fprintf(wzorzec, "g 36				//do wyboru s/m/g/d/l Sekundy/Minuty/Godziny/Dni/Lata - czas trwania symulacji\n.");
	fprintf(wzorzec, "\ns:4				//srednia liczba na godzine osob przychodzacych do banku\no:3				//odchylenie standardowe od sredniej\n.				// segmenty oddzielamy kropka.\n");
	fprintf(wzorzec, "okienka:3				// okreslamy liczbe okienek w banku\n.\ns:3				// po kolei - oddzielajac kropkami - podajemy parametry dla kazdego okienka\no:2.5\n.\ns:6				");
	fprintf(wzorzec, "//sredni czas w sekundach obslugi klienta przez urzedniczke\no:4				//");
	fprintf(wzorzec, "odchylenie standardowe od sredniego czasu obslugi klienta.\n.\ns:5\no:5\n.");
	
	fclose(wzorzec);
	return 0;
	
}

int kontrolapliku(char *nazwapliku)
{
	int test, okienka, licznik, blad=0;
	char testznak;
	double kontrola;
	long double sprawdzenie;
	
	
	FILE *plik;
	if ((plik = fopen(nazwapliku, "r")) == NULL) { printf("\nAlarm. Nie udalo sie odczytac pliku o podanej nazwie. Moze sie pomyliles albo jest on w innym katalogu niz program?\n"); return 1;}
	
	
	testznak = fgetc(plik);
	if((testznak != 'm') && (testznak != 's') && (testznak != 'g') && (testznak != 'l') && (testznak != 'd')) blad = 1;
	if((test = fscanf(plik, " %Lf", &sprawdzenie)) != 1) blad = 1;
	fgetc(plik);
	if((testznak = fgetc(plik)) != '.') blad = 1;
	fgetc(plik);
	if((test = fscanf(plik, "s:%lf", &kontrola)) != 1) blad = 1;
	if((test = fscanf(plik, "\no:%lf", &kontrola)) != 1) blad = 1;
	fgetc(plik);
	if((testznak = fgetc(plik)) != '.') blad = 1;
	if((test = fscanf(plik, "\nokienka:%d", &okienka)) != 1) blad = 1;
	fgetc(plik);
	if((testznak = fgetc(plik)) != '.') blad = 1;
	fgetc(plik);
	for(licznik=1;licznik<=okienka;licznik++)
	{
			if((test =fscanf(plik, "s:%lf", &kontrola)) != 1) blad = 1;
			if((test =fscanf(plik, "\no:%lf", &kontrola)) != 1) blad = 1;
			fgetc(plik);
			if((testznak = fgetc(plik)) != '.') blad = 1;
			fgetc(plik);
	}
	fclose(plik);		
	if (blad ==1) {printf("\nFormat pliku jest nieprawidlowy!\n"); return 2;}	
	return 0;
	}
	
	
dane * wczytanie(char *nazwapliku)
{
	dane *pakiet;
	long double dlugosc_symulacji;
	char jednostka_czasu;
	int licznik;

	FILE *plik = fopen(nazwapliku, "r");
	pakiet = (dane *)malloc(sizeof(dane));
	
	
	jednostka_czasu = fgetc(plik);
	fscanf(plik, " %Lf", &dlugosc_symulacji);
	fgetc(plik); fgetc(plik); fgetc(plik);
	fscanf(plik, "s:%lf", &pakiet->klienci_srednio);
	fscanf(plik, "\no:%lf", &pakiet->odchylenie);
	fgetc(plik); fgetc(plik); fgetc(plik);
	fscanf(plik, "okienka:%d", &pakiet->liczba_okienek);
	pakiet->okienka = malloc((pakiet->liczba_okienek)*sizeof(okienko));
	fgetc(plik); fgetc(plik); fgetc(plik);
	for(licznik=0;licznik<(pakiet->liczba_okienek);licznik++)
		{
			fscanf(plik, "s:%lf", &(pakiet->okienka[licznik].srednia));
			fscanf(plik, "\no:%lf", &(pakiet->okienka[licznik].odchylenie));
			fgetc(plik); fgetc(plik); fgetc(plik);										// jedno na \n, drugie na kropkę, trzecie znów na \n 
				
		}
		
	switch (jednostka_czasu)
			{
				case 's': pakiet->czas_symulacji = nearbyintl(dlugosc_symulacji); break;
				
				case 'm': pakiet->czas_symulacji = 60 * nearbyintl(dlugosc_symulacji); break;
				
				case 'g': pakiet->czas_symulacji = 60 * 60 * nearbyintl(dlugosc_symulacji); break;
				
				case 'd': pakiet->czas_symulacji = 60 * 60 * 24 * nearbyintl(dlugosc_symulacji); break;
				
				case 'l': pakiet->czas_symulacji = 60 * 60 * 24 * 365 * nearbyintl(dlugosc_symulacji); break;				
			}
		
		
		
		
			
		fclose(plik);
		return pakiet;
	}
	

int nakrotsza(kolejka *kolejki, dane *info)
{
	
	int b, minimum = kolejki[0].dlugosc, powtorzenia = 0;flaga = 0, indeks_najkrotszej = 0;
	
	
	
	for(b=1;b<info->liczba_okienek;b++)
		{
			if(kolejki[b].dlugosc < minimum) {minimum = kolejki[b].dlugosc; powtorzenia =0; flaga = 0; indeks_najkrotszej = b;}
			if(kolejki[b].dlugosc == minimum) {powtorzenia++; flaga = 1;}// jesli jest kilka najkrotszych kolejek, trzeba zrobic tak, by klient wybieral jedna z tych kolejek losowo.
			
		}
		
		if (flaga==1) 
			{
				int *tablica, dlugosc_tablicy, wylosowany_indeks;// PAMIETAJ O TYCH ZMIENNYCH
				tablica = (int *)malloc((powtorzenia+1)*sizeof(int));
				dlugosc_tablicy = powtorzenia+1;
				
				for(b=0;b<info->liczba_okienek;b++) {if (kolejki[b].dlugosc == minimum) {tablica[dlugosc_tablicy-powtorzenia-1] = b;powtorzenia--;}}    
				wylosowany_indeks = rand()%dlugosc_tablicy;  // no wiec jesli jest kilka najkrotszych kolejek, tworze tablice i umieszczam w niej ich indeksy, zeby pozniej jakis z nich wylosowac i zwrocic .
				indeks_najkrotszej = tablica[wylosowany_indeks];
				free(tablica);
				return indeks_najkrotszej;
			}
	
	return indeks_najkrotszej; 
	
}
	
	
	
	
	
	
	
	

	