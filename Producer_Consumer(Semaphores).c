#include <stdio.h>
#include <stdlib.h>

int buffer = 0; // Number of items in the buffer
int buffer_size = 3; // Maximum buffer size

void producer() {
    if (buffer < buffer_size) {
        buffer++;
        printf("Producer produced item. Items in buffer: %d\n", buffer);
    } else {
        printf("Buffer is FULL. Producer cannot produce.\n");
    }
}

void consumer() {
    if (buffer > 0) {
        printf("Consumer consumed item. Items in buffer: %d\n", buffer - 1);
        buffer--;
    } else {
        printf("Buffer is EMPTY. Consumer cannot consume.\n");
    }
}

int main() {
    int choice;

    printf("1. PRODUCER\n2. CONSUMER\n3. EXIT\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
