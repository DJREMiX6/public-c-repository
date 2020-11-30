#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTS
//Constant used to print debug log on STDOUT
const bool DEBUG = true;

//ENUMS
//Enumerator to define card's seed
enum Seed {
    Null,
    Spade,
    Denari,
    Bastoni,
    Coppe
};

//STRUCTS
//Struct to define a card
struct Card {
    //Pointer to the Seed of the card
    enum Seed* seed;
    //Pointer to the value of the cart (min 1, max 10)
    int* value;
};

//METHODS
//this method return a "String" based on the Seed passed or an error message if the value is minor than 0 and major than 4
const char* getSeedName(enum Seed seme) {
    static char* semi[] = {"Null", "Spade", "Denari", "Bastoni", "Coppe"};
    static char* errMess = "Error!";
    int semeVal = seme;
    if(semeVal < 0 || semeVal > 4) {
        return errMess;
    }
    return semi[semeVal];
}

//Method called in newDeck() function if there is an error during the allocation of the deck
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

//Create a new deck and return the pointer of the deck's first element
//The deck is an array of type struct Card
struct Card* newDeck() {
    //allocating the memory for the deck
    struct Card* deck = malloc(sizeof(struct Card) * 40);
    if(deck == NULL) {
        if(DEBUG == true) {
            printf("Deck allocation error!\n");
        }
        return NULL;
    }

    int* tempVal = malloc(sizeof(int));
    *(tempVal) = 1;
    for(int i = 0; i < 40; i++) {
        //Inserimento Spade
        if(i < 10) {
            if(DEBUG == true) {
                printf("Try to alloc memory for card:\n\tSeed: Spade,\tValue: %d\n", *(tempVal));
            }
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Spade));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                if(DEBUG == true) {
                    printf("Card seed allocation error at index %d!\n", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's seed succesfully allocated at address:%p\n", (deck + i)->seed);
            }
            (*((deck + i)->seed)) = Spade;
            
            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(*tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                if(DEBUG == true) {
                    printf("Card value allocation error at index %d", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's value succesfully allocated at address:%p\n", (deck + i)->value);
            }
            (*((deck + i)->value)) = *tempVal;
        } 
        //Inserimento Denari
        else if(i < 20) {
            if(DEBUG == true) {
                printf("Try to alloc memory for card:\n\tSeed: Denari,\tValue: %d\n", *tempVal);
            }
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Denari));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                if(DEBUG == true) {
                    printf("Card seed allocation error at index %d!\n", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's seed succesfully allocated at address:%p\n", (deck + i)->seed);
            }
            (*((deck + i)->seed)) = Denari;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(*tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                if(DEBUG == true) {
                    printf("Card value allocation error at index %d", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's value succesfully allocated at address:%p\n", (deck + i)->value);
            }
            (*((deck + i)->value)) = *tempVal;
        } 
        //Inserimento Bastoni
        else if(i < 30) {
            if(DEBUG == true) {
                printf("Try to alloc memory for card:\n\tSeed: Bastoni,\tValue: %d\n", *tempVal);
            }
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Bastoni));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                if(DEBUG == true) {
                    printf("Card seed allocation error at index %d!\n", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's seed succesfully allocated at address:%p\n", (deck + i)->seed);
            }
            (*((deck + i)->seed)) = Bastoni;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(*tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                if(DEBUG == true) {
                    printf("Card value allocation error at index %d", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's value succesfully allocated at address:%p\n", (deck + i)->value);
            }
            (*((deck + i)->value)) = *tempVal;
        } 
        //Inserimento Coppe
        else {
            if(DEBUG == true) {
                printf("Try to alloc memory for card:\n\tSeed: Coppe,\tValue: %d\n", *tempVal);
            }
            //Try to alloc memory
            (deck + i)->seed = malloc(sizeof(Coppe));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->seed == NULL) {
                if(DEBUG == true) {
                    printf("Card seed allocation error at index %d!\n", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's seed succesfully allocated at address:%p\n", (deck + i)->seed);
            }
            (*((deck + i)->seed)) = Coppe;

            //Try to alloc memory
            (deck + i)->value = malloc(sizeof(*tempVal));
            //If there is an error during memory allocation then Free the memory from all the Cards
            if((deck + i)->value == NULL) {
                if(DEBUG == true) {
                    printf("Card value allocation error at index %d", i);
                }
                freeDeckInLoop(deck, i);
                return NULL;
            }
            if(DEBUG == true) {
                printf("Card's value succesfully allocated at address:%p\n", (deck + i)->value);
            }
            (*((deck + i)->value)) = *tempVal;
        }

        *tempVal = (*tempVal) + 1;

        if(i == 9 || i == 19 || i == 29) {
            *tempVal = 1;
        }
    }

    free(tempVal);
    if(DEBUG == true) {
        printf("Deck created!\n");
    }
    return deck;
}

//Method that free the memory of the entire deck
void disposeDeck(struct Card* deck) {
    if(DEBUG == true) {
        printf("Disposing deck at address: %p\n", deck);
    }
    if(deck != NULL) {
        if(DEBUG == true) {
            printf("Freeing memory from deck...\n");
        }
        for(int i = 0; i < 40; i++) {
            if(DEBUG == true) {
                printf("Trying to free card at address: %p\n", deck + i);
            }
            if((deck + i)->seed != NULL) {
                free((deck + i)->seed);
                if(DEBUG == true) {
                    printf("\tCard seed succesfully freed!\n");
                }
            }
            if((deck + i)->value != NULL) {
                free((deck + i)->value);
                if(DEBUG == true) {
                    printf("\tCard value succesfully freed!\n");
                }
            }
        }
        free(deck);
        printf("Deck disposed.\nMemory free.\n");
    } else {
        if(DEBUG == true) {
            printf("Error during disposing the deck, deck is NULL!\n");
        }
    }
}

//Method to free the memory of a card from the deck by its index
void removeCard(struct Card* deck, int index) {
    if(DEBUG == true) {
        printf("Removing card at address: %p...\n", deck + index);
    }
    if((deck + index) != NULL) {
        free(deck + index);
        if(DEBUG == true) {
            printf("Card succesfully removed!\n");
        }
    } else {
        if(DEBUG == true) {
            printf("Error during removing card, deck + index is NULL!\n");
        }
    }
}

//function that randomly shuffle the deck
void shuffleDeck(struct Card* deck) {
    if(DEBUG == true) {
        printf("Shuffling deck...");
    }

    time_t t;
    srand((unsigned)time(&t));
    int loopCycles;

    //Generate a random number of shuffling cycles
    do {
        loopCycles = rand() % 500;
    } while(loopCycles == 0);

    if(DEBUG == true) {
        printf("Shuffling loop cycles: %d\n", loopCycles);
    }

    //For each shuffliing cycle shuffle all the deck's cards
    for(int l = 0; l <= loopCycles; l ++) {
        for(int i = 0; i < 40; i++) {
            int startPos;
            int endPos;

            do{
                startPos = rand() % 40;
                endPos = rand() % 40;
            } while(startPos == endPos);


            struct Card* firstElement = (deck + startPos);
            struct Card* secondElement = (deck + endPos);
            struct Card* tempElement = malloc(sizeof(struct Card));

            tempElement->seed = secondElement->seed;
            tempElement->value = secondElement->value;

            secondElement->seed = firstElement->seed;
            secondElement->value = firstElement->value;

            firstElement->seed = tempElement->seed;
            firstElement->value = tempElement->value;

            free(tempElement);
        }
    }

    if(DEBUG == true) {
        printf("------------Cards list in ShuffleDeck()-----------------\n");
        for(int i = 0; i < 40; i++) {
            printf("Address: %p,\tSeed: %s,\tValue: %d\n", deck + i, getSeedName(*((deck + i)->seed)), *((deck + i)->value));
        }
    }
}

int main() {
    struct Card* deck = newDeck();
    if(DEBUG == true) {
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
    }
    shuffleDeck(deck);

    //disposeDeck(deck);
    return 0;
}
