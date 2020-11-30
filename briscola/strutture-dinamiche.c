#include <stdio.h>
#include <stdlib.h>

enum Seed {
    Null,
    Spade,
    Denari,
    Bastoni,
    Coppe
};

struct Card {
    enum Seed* seed;
    int* value;
};

//CONST METHODS
const char* getSeedName(enum Seed seme) {
    static char* semi[] = {"Null", "Spade", "Denari", "Bastoni", "Coppe"};
    static char* errMess = "Error!";
    int semeVal = seme;
    if(semeVal < 0 || semeVal > 4) {
        return errMess;
    }
    return semi[semeVal];
}

void freeDeckInLoop(struct Card* deck, int errorIndex) {
    if(deck != NULL) {
        printf("Freeing space of deck in loop cause of an error...");
        for(int i = 0; i <= errorIndex; i++) {
            if((deck + i)->seed != NULL) {
                free((deck + i)->seed);
            }

            if((deck + i)->value != NULL) {
                free((deck + i)->value);
            }
        }
        
        free(deck);
        printf("Space free.");
    } else {
        printf("Error during freeing space of deck, deck is NULL!");
    }
}

struct Card* newDeck() {
    struct Card* deck = malloc(sizeof(struct Card) * 40);
    if(deck == NULL) {
        printf("Deck allocation error!");
        return NULL;
    }

    int tempVal = 1;
    for(int i = 0; i < 40; i++) {
        //Inserimento Spade
        if(i < 10) {
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Spade));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                printf("Card seed allocation error at index %d!", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->seed)) = Spade;
            
            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                printf("Card value allocation error at index %d", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->value)) = tempVal;
        } 
        //Inserimento Denari
        else if(i < 20) {
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Denari));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                printf("Card seed allocation error at index %d!", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->seed)) = Denari;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                printf("Card value allocation error at index %d", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->value)) = tempVal;
        } 
        //Inserimento Bastoni
        else if(i < 30) {
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Bastoni));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                printf("Card seed allocation error at index %d!", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->seed)) = Bastoni;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                printf("Card value allocation error at index %d", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->value)) = tempVal;
        } 
        //Inserimento Coppe
        else {
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Coppe));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                printf("Card seed allocation error at index %d!", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->seed)) = Coppe;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                printf("Card value allocation error at index %d", i);
                freeDeckInLoop(deck, i);
                return NULL;
            }
            (*((deck + i)->value)) = tempVal;
        }

        tempVal ++;

        if(i == 9 || i == 19 || i == 29) {
            tempVal = 1;
        }
    }
    printf("Deck created!\n");
    return deck;
}

void disposeDeck(struct Card* deck) {
    if(deck != NULL) {
        printf("Freeing memory from deck...\n");
        for(int i = 0; i < 40; i++) {
            if((deck + i)->seed != NULL) {
                free((deck + i)->seed);
            }

            if((deck + i)->value != NULL) {
                    free((deck + i)->value);
                }
            }
        free(deck);
        printf("Memory free.\n");
    } else {
        printf("Error during disposing the deck, deck is NULL!");
    }
}

void removeCard(struct Card* deck, int index) {
    if((deck + index) != NULL) {
        free(deck + index);
    } else {
        printf("Error during removing card, deck + index is NULL!");
    }
}

void removeCard(struct Card* card) {
    if(card != NULL) {
        free(card);
    } else {
        printf("Error during removing card, card is NULL!");
    }
}

int main() {
    struct Card* deck = newDeck();
    for(int i = 0; i < 40; i++) {
        /*
        La struttura Card ha due campi (ognuno è un puntatore), deck è un puntatore.
        "(deck + i)" scorre l'indirizzo del puntatore per scorrere l'array.
        "(*((deck + i)->seed)))" dereferenzia il puntatore del campo "seed" per recuperarne il valore.
        "*pointer" (pointer è un puntatore di qualsiasi tipo) dereferenzia il puntatore per acquisirne il valore.
        Quindi:
        int numero = 20;    Creo una variabile di tipo intero con valore 20 e nome "numero"
        int* numeroPtr = &numero;   Creo un puntatore di tipo intero al quale assegno l'inidrizzo della variabile "numero" che prendo tramite "&"
        int numero2 = numeroPtr;    Questa istruzione da errore perche cerco di assegnare un indirizzo ad un valore
        int numero2 = *numeroPtr;   Questa istruzione non da errore perchè dereferenzio il puntatore tramite "*" che mi ritorna il valore del puntatore e non il puntatore
        */
        printf("Address: %p,\tSeed: %s,\tValue: %d\n", (deck + i), getSeedName((*((deck + i)->seed))), (*((deck + i)->value)));
    }

    disposeDeck(deck);
    return 0;
}