#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = data;
        printf("%d pushed to stack\n", data);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int data = stack[top];
        top--;
        return data;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        push(str[i]);
    }

    int mid = (len % 2) ? (len / 2) + 1 : (len / 2);

    for (int i = mid; i < len; i++) {
        int popped = pop();
        if (popped != str[i]) {
            return 0; // Not Palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    int choice, data;
    char str[MAX];

    while (1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                printf("Enter string: ");
                scanf("%s", str);
                if (isPalindrome(str)) {
                    printf("%s is a palindrome\n", str);
                } else {
                    printf("%s is not a palindrome\n", str);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}